//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2016 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionFeature.h>
#import <Diffusion/PTDiffusionTopicType.h>

@class PTDiffusionAddTopicResult;
@class PTDiffusionBytes;
@class PTDiffusionMissingTopicNotification;
@class PTDiffusionTopicSpecification;
@class PTDiffusionTopicTreeRegistration;
@class PTDiffusionTopicRemovalResult;

@protocol PTDiffusionMissingTopicHandler;

typedef NS_ENUM(NSInteger, PTDiffusionTopicControlFeatureErrorCode) {
    /**
     @deprecated since 6.7 Enumeration is unused.
     */
    PTDiffusionTopicControlFeatureErrorCode_ServerFailedToAddTopic __deprecated_enum_msg("Enumeration is unused.") = 1,
};

NS_ASSUME_NONNULL_BEGIN

/**
 @since 5.7
 */
extern NSString *const PTDiffusionTopicControlFeatureErrorDomain __deprecated_msg("Use PTDiffusion instead");

/**
 @brief The Topic Control feature provides a client session with the ability to
 manage topics.

 This feature allows a session to manage topics. It provides the following
 capabilities:

 1. Adding and removing topics.
 2. Missing topic notifications — listening for requests to subscribe to
 topics that do not exist thus allowing dynamic topic creation on demand.

 ### Topics

 The Diffusion server stores data in topics. Each topic is bound to a topic
 path in the topic tree, and may have a current value. Sessions can subscribe
 to topics. Updates to topic values are broadcast to subscribing sessions.
 There are several types of topic. The {@link PTDiffusionTopicType topic type} determines
 the type of the data values a topic publishes to subscribers.

 ### Adding topics

 #### Creating topics

 The simplest way to create a topic is to call
 `#addTopicWithPath:type:completionHandler:`, supplying a topic type. For example, to
 create a {@link PTDiffusionTopicType_JSON JSON} topic bound to the topic path `foo`:

 <pre>
<code>
    [topicControl addTopicWithPath:\@"foo"
                            type:PTDiffusionTopicType_JSON
                completionHandler:^(PTDiffusionAddTopicResult *const result, NSError *const error)
    {
        ...
    }];
</code>
 </pre>

 Success or failure is reported asynchronously through the `completionHandler`
 arguments.

 The nature of a topic depends primarily on its topic type, but can be
 customized using topic properties. Some types of topic cannot be created
 without supplying mandatory topic properties. Topic properties can be
 supplied in a {@link PTDiffusionTopicSpecification topic specification} using
 {@link #addTopicWithPath:specification:completionHandler:}. Topic
 specifications can be created using `PTDiffusionTopicSpecification#initWithType:} and
 further customized with builder methods. For example, to create a
 {@link PTDiffusionTopicType_JSON JSON} topic bound to the topic path `foo` with
 the {@link PTDiffusionTopicSpecification#validateValuesPropertyKey validate values} property set
 to `true`:

 <pre>
 <code>
    PTDiffusionTopicSpecification *topicSpecification =
        [PTDiffusionTopicSpecification alloc] initWithType:PTDiffusionTopicType_JSON
                                                properties:\@{PTDiffusionTopicSpecification.validateValuesPropertyKey : PTDiffusionTopicSpecification.truePropertyValue}];
    [topicControl addTopicWithPath:\@"foo"
                     specification:topicSpecification
                 completionHandler:^(PTDiffusionAddTopicResult *const result, NSError *const error)
    {
        ...
    }];
 </code>
 </pre>

 See {@link PTDiffusionTopicSpecification} for details of the available topic properties
 and their effects on the different types of topic.

 Topic creation is idempotent. If {@link #addTopicWithPath:specification:completionHandler:}
 is called and there is already a topic bound
 to `path` with a topic specification equal to `specification`,
 the call will complete normally with an `PTDiffusionAddTopicResult#exists` result.
 However, if there is a topic bound to `path` with a different topic
 specification, the completionHandler will return an error.

 ### Removing topics

 Topics can be removed using {@link PTDiffusionTopicControlFeature#removeTopicsWithTopicSelectorExpression:completionHandler:
 removeTopicsWithTopicSelectorExpression}.
 Only those selected topics that the caller has `PTDiffusionPathPermission#modifyTopic`
 permission to will be removed, any others will remain.

 Topics can also be automatically removed according to a removal criteria
 specified using the `PTDiffusionTopicSpecification#removalPropertyKey` topic
 property.

 ### Managing topic tree hierarchies

 A topic can be bound to any path in the topic tree namespace. The only
 restriction is that two topics can not have the same path.

 In the following example a topic can be created with the path `A/B/foo`
 even though there are no topics with path `A` or `A/B`:

 <pre>
 <code>
    [topicControl addTopicWithPath:\@"A/B/foo"
                              type:PTDiffusionTopicType_JSON
                 completionHandler:^(PTDiffusionAddTopicResult *const result, NSError *const error)
    {
        ...
    }];
 </code>
 </pre>

 Topics bound to the paths `A` or `A/B` can be created later.

 Topics can be removed without affecting the topics subordinate to them in the
 topic tree using {@link #removeDiscreteWithTopicSelectorExpression:completionHandler:}
 providing a path topic selector. By using the `//` topic selector qualifier it
 is possible to remove a topic and all of its descendant topics, that is to
 remove whole topic tree branches.

 ### Access control

 To add or remove a topic, a session needs `PTDiffusionPathPermission#modifyTopic`
 permission for the topic path. When removing topics with a topic selector that
 matches more than one topic, only topics with paths for which the session has
 `PTDiffusionPathPermission#modifyTopic` permission will be removed.

 To successfully register a missing topic handler using
 `#addMissingTopicHandler:forTopicPath:completionHandler:`, the session needs
 `PTDiffusionGlobalPermission#registerHandler` permission.

 ### Accessing the feature

 The Topic Control feature for a session can be obtained from the session's
 `PTDiffusionSession#topicControl` property.

 @see PTDiffusionSession

 @since 5.7
 */
@interface PTDiffusionTopicControlFeature : PTDiffusionFeature

/**
 Register a handler of requests for a branch of the topic tree.

 The provided handler is called when a client subscribes using a
 topic selector that matches no existing topics. This allows a control client
 session to be notified when another session requests a topic that does
 not exist.

 A session can register multiple handlers, but may only register a single
 handler for a given topic path.
 A handler will only be called for topic selectors with a path prefix that starts
 with or is equal to topicPath. If the path prefix matches multiple handlers,
 the one registered for the most specific (longest) topic path will be called.

 @param handler The handler to use for notifying topics at or below the `topicPath`
 (unless there is a handler registered for a more specific branch).

 @param topicPath Identifies a branch of the topic tree.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and the `registration` argument will not be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.

 @note If the session is closing or closed when this method is called, the
 completion handler block will be called with an error, while the missing topic
 handler will receive no messages.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 5.7
 */
-(void)addMissingTopicHandler:(id<PTDiffusionMissingTopicHandler>)handler
                 forTopicPath:(NSString *)topicPath
            completionHandler:(void (^)(PTDiffusionTopicTreeRegistration * _Nullable registration, NSError * _Nullable error))completionHandler;

/**
 Send a request to the server to add a topic.

 This is a convenience method which creates the topic with default details for
 the given type.

 @param path The full path of the topic to be created.

 @param type The type of topic to be created.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and `result` will be non-`nil`.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil` or value has been
 supplied for a topic type that is not stateful.

 @since 6.1
 */
-(void)addTopicWithPath:(NSString *)path
                   type:(PTDiffusionTopicType)type
      completionHandler:(void (^)(PTDiffusionAddTopicResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Send a request to the server to add a topic.

 The topic will be initialized with the given value, if specified non-`nil`,
 during creation and therefore the value must be compatible with the topic type.

 @param path The full path of the topic to be created.

 @param specification Defines the topic to be created.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and `result` will be non-`nil`.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil` or value has been
 supplied for a topic type that is not stateful.

 @since 6.1
 */
-(void)addTopicWithPath:(NSString *)path
          specification:(PTDiffusionTopicSpecification *)specification
      completionHandler:(void (^)(PTDiffusionAddTopicResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Send a request to remove one or more topics.

 All topics that match the provided topic selector that the caller has
 permission to remove will be removed.

 The selector's descendant pattern qualifier (a trailing `/` or `//`), can be
 used to remove descendant topics. If a single `/` qualifier is specified, all
 descendants of the matched topic paths will be removed. If `//` is specified,
 the matched paths and all descendants of the matched paths (complete branches)
 will be removed.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 5.9

 @deprecated since 6.6. Use {@link PTDiffusionTopicControlFeature#removeTopicsWithTopicSelectorExpression:completionHandler:
 removeTopicsWithTopicSelectorExpression} instead.
 */
-(void)removeDiscreteWithTopicSelectorExpression:(NSString *)expression
                               completionHandler:(void (^)(NSError * _Nullable error))completionHandler
__deprecated_msg("Will be removed in a future release");


/**
 Send a request to remove one or more topics.

 All topics that match the provided topic selector that the caller has
 permission to remove will be removed.

 The selector's descendant pattern qualifier (a trailing `/` or `//`), can be
 used to remove descendant topics. If a single `/` qualifier is specified, all
 descendants of the matched topic paths will be removed. If `//` is specified,
 the matched paths and all descendants of the matched paths (complete branches)
 will be removed.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and `result` will be non-`nil`. `result` provides the number of topics
 removed via {@link PTDiffusionTopicRemovalResult#removedCount removedCount}.

 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.6
 */
-(void)removeTopicsWithTopicSelectorExpression:(NSString *)expression
                             completionHandler:(void (^)(PTDiffusionTopicRemovalResult * _Nullable result, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
