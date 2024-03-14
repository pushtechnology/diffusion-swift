//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2018, 2021 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;
#import <Diffusion/PTDiffusionFeature.h>

@class PTDiffusionRegistration;
@class PTDiffusionSessionId;
@class PTDiffusionStream;

@protocol PTDiffusionSubscriptionRoutingRequestHandler;

/**
 Values assigned to the `code` property of NSError objects generated by the
 PTDiffusionSubscriptionControlFeature.

 @since 6.1

 @deprecated since 6.7 Use PTDiffusionError instead.
 */
typedef NS_ENUM(NSInteger, PTDiffusionSubscriptionControlFeatureErrorCode) {
    /**
     The filter was rejected. The command was not sent to any clients.

     @see PTDiffusionUnderlyingErrorsKey

     @since 6.1

     @deprecated since 6.7 Use PTDiffusionError_SendToFilterRejected instead.
     */
    PTDiffusionSubscriptionControlFeatureErrorCode_SendToFilterRejected __deprecated_enum_msg("Use PTDiffusionError_SendToFilterRejected instead") = 1,
};

NS_ASSUME_NONNULL_BEGIN

/**
 The value assigned to the `domain` property of NSError objects generated by the
 PTDiffusionSubscriptionControlFeature.

 @since 6.1
 */
extern NSString *const PTDiffusionSubscriptionControlFeatureErrorDomain __deprecated_msg("Use PTDiffusion instead.");

/**
 @brief The Subscription Control feature allows a client session to subscribe
 or unsubscribe other sessions to topics, as well as also providing a mechanism
 for handling requests to subscribe to routing topics (deprecated).

 The Subscription Control feature for a session can be obtained from the
 session's `PTDiffusionSession#subscriptionControl` property.

 Requests to subscribe sessions to topics can be submitted at any time even if
 the topics do not exist at the server. @ref md_topic_selectors "Topic selectors"
 are used on subscription to match against topics at the server. The session
 will become subscribed to any topics that exist at the server that match the
 selector (unless they are already subscribed, or the session has insufficient
 permission). The subscription request is also retained at the server so that if
 any newly created topics match the selector, the session will then become
 subscribed to it (unless a subsequent unsubscription cancels it).

 Specific sessions may be subscribed/unsubscribed if the PTDiffusionSessionId is
 known.

 Subscriptions may also be requested using
 @ref md_session_filters "session filters", where all sessions that satisfy a
 particular filter expression will be subscribed/unsubscribed. The filter is
 only evaluated once against the current sessions that exist at the time - it is
 not retained and applied to any sessions that are created later. In order to be
 notified of new sessions as they are created a
 PTDiffusionSessionPropertiesListener can be used and those sessions subscribed
 as required based upon their session properties.

 A handler for routing topics belonging to a branch of the topic tree can be
 added using this feature's 'add routing subscription handler' method. When
 another session subscribes to one of the routing topics, the handler will be
 called to determine the appropriate source topic.

 ### Access control

 To subscribe other sessions to topics, a session must have `PTDiffusionGlobalPermission#modifySession`
 permission, and `PTDiffusionPathPermission#selectTopic` permission for the path prefix of the topic
 selector used for subscription. The subscribed sessions will only be subscribed
 to matching topics for which they have `PTDiffusionPathPermission#readTopic` permission.

 To unsubscribe other sessions, a session must have `PTDiffusionGlobalPermission#modifySession` permission.

 To register a routing subscription handler the session needs `PTDiffusionGlobalPermission#viewSession`,
 `PTDiffusionGlobalPermission#modifySession` and `PTDiffusionGlobalPermission#registerHandler` permissions.

 When handling a subscription request to a routing topic via a routing handler
 the target session needs `PTDiffusionPathPermission#readTopic` permission to both the routing topic
 being subscribed to and the target topic that is assigned.

 @since 6.1
 */
@interface PTDiffusionSubscriptionControlFeature : PTDiffusionFeature

/**
 Subscribe another session to topics.

 New subscriptions will be established for existing topics that match the
 provided topic selector and for which the subscribed session has `PTDiffusionPathPermission#readTopic`
 permission. The topic selector will be added to the topic selections of the
 subscribed session, and re-evaluated when new topics are added or the session's
 security roles change.

 A session that does not have `PTDiffusionPathPermission#selectTopic` permission for a topic cannot
 subscribe directly, but can be subscribed indirectly using this method.

 @param sessionId Identifies the session to subscribe.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server, identifying the topics to subscribe to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.1
 */
-(void)      subscribeSessionId:(PTDiffusionSessionId *)sessionId
    withTopicSelectorExpression:(NSString *)expression
              completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Unsubscribe another session from topics.

 @param sessionId Identifies the session to unsubscribe.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server, identifying the topics to unsubscribe from.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.1
 */
-(void)    unsubscribeSessionId:(PTDiffusionSessionId *)sessionId
    withTopicSelectorExpression:(NSString *)expression
              completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Subscribe sessions that satisfy a given session filter to topics.

 For each session that matches the filter, new subscriptions will be established
 for existing topics that match the provided topic selector and for which the
 sessions has `PTDiffusionPathPermission#readTopic` permission. The topic selector will be added to the
 topic selections of the subscribed session, and re-evaluated when new topics
 are added or the session's security roles change.

 A session that does not have `PTDiffusionPathPermission#selectTopic` permission for a topic cannot
 subscribe directly, but can be subscribed indirectly using this method.

 @param filter The @ref md_session_filters "session filter" expression.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server, identifying the topics to subscribe to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and the `count` argument indicates the number of clients
 that satisfied the filter and qualified for subscription. On failure the
 `error` argument passed to the block will not be `nil` and the `count` argument
 will be zero. The completion handler will be called asynchronously on the main
 dispatch queue.

 @note The completion handler block will be invoked with a `nil` for the `error`
 argument and zero for the `count` argument if no client sessions satisified the
 filter.

 @exception NSInvalidArgumentException If any arguments are `nil`.

 @since 6.1
 */
-(void) subscribeWithFilter:(NSString *)filter
    topicSelectorExpression:(NSString *)expression
          completionHandler:(void (^)(NSUInteger count, NSError * _Nullable error))completionHandler;

/**
 Unsubscribe sessions that satisfy a given session filter from topics.

 @param filter The @ref md_session_filters "session filter" expression.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server, identifying the topics to unsubscribe from.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and the `count` argument indicates the number of clients
 that satisfied the filter and qualified for unsubscription. On failure the
 `error` argument passed to the block will not be `nil` and the `count` argument
 will be zero. The completion handler will be called asynchronously on the main
 dispatch queue.

 @note The completion handler block will be invoked with a `nil` for the `error`
 argument and zero for the `count` argument if no client sessions satisified the
 filter.

 @exception NSInvalidArgumentException If any arguments are `nil`.

 @since 6.1
 */
-(void)unsubscribeWithFilter:(NSString *)filter
     topicSelectorExpression:(NSString *)expression
           completionHandler:(void (^)(NSUInteger count, NSError * _Nullable error))completionHandler;

/**
 Adds a handler for routing topics that belong to a branch of the topic tree.
 When another session subscribes to one of the routing topics, the handler will
 be called to determine the appropriate source topic.

 For each subscription to the routing topic, the server will select a handler
 registered for the most specific branch. If multiple handlers are registered
 for the same branch, the server will select one of them arbitrarily.

 @param handler The object which will handle the incoming subscription routing
 requests. It will be sent messages asynchronously on the main dispatch queue.
 A weak reference is maintained to this object.

 @param topicPath Identifies the branch of the topic tree to associate the
 handler with.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and the `registration` argument will point to a
 registration object which can be used to manage the registration. The
 completion handler will be called asynchronously on the main dispatch queue.

 @return Stream resulting from the registration of the given routing request handler
 for the given topic path.

 @exception NSInvalidArgumentException Raised if any arguments are `nil`.

 @since 6.1

 @deprecated since 6.7 Routing Topics are deprecated. The more powerful
 {@link PTDiffusionSessionTreesFeature Session Trees} feature should be used in their place.
 */
-(PTDiffusionStream *)addRoutingRequestHandler:(id<PTDiffusionSubscriptionRoutingRequestHandler>)handler
                                  forTopicPath:(NSString *)topicPath
                             completionHandler:(void (^)(PTDiffusionRegistration * _Nullable registration, NSError * _Nullable error))completionHandler __deprecated_msg("Will be removed in a future release.");

@end

NS_ASSUME_NONNULL_END
