//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2015 - 2024 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionTopicUpdateFeature.h>
#import <Diffusion/PTDiffusionTopicUnsubscriptionReason.h>

@class PTDiffusionFetchRequest;
@class PTDiffusionStream;
@class PTDiffusionTopicSelector;
@class PTDiffusionValueStream;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The Topics feature provides a client session with the capability to receive streamed
 topic updates and/or fetch the state of topics.

 This feature allows a client session to subscribe to topics to receive
 streamed topic updates, fetch the state of topics and/or update topics with
 new values.

 Specifically, the feature provides the ability to:
 <ul>
    <li>Subscribe to topics and specify streams to receive updates;
    <li>Fetch the current state of topics (even if not subscribed);
    <li>By extending the topic update feature, update topics with new values;
    <li>By extending the topic views feature, manage topic views.
 </ul>

 ###Subscription and unsubscription

 A session can issue requests to subscribe to topics at any time, even if the
 topics do not exist at the server. Each subscription request provides a
 topic selector that is evaluated by the server to
 select matching topics. The session will be subscribed to any topics that
 match the selector unless they are already subscribed, or the session has
 insufficient permission. The subscription request is also retained at the
 server and the session will be automatically subscribed to newly created
 topics that match the selector (unless a subsequent unsubscription cancels
 the request).

 Sessions receive notifications from topics that they are subscribed to via
 <em>subscription streams</em> (see below). When a session is subscribed to a
 topic, all matching streams will first receive a subscription notification
 that provides details about the topic. If the server has a value for the
 topic, the value will be delivered to the streams before any other
 notifications.

 A session can unsubscribe from topics at any time. This is also specified
 using a topic selector. On unsubscription, matching streams are notified via
 the `#PTDiffusionTopicUnsubscriptionReason` notification. This notification will give the
 reason for unsubscription (for example, by request of the session, request of
 the server, or topic removal).

 Subscriptions and unsubscriptions can occur for reasons other than requests
 from the session. A session can be subscribed to or unsubscribed from a topic
 by another session using the `PTDiffusionSubscriptionControlFeature`. The removal
 of a topic also automatically causes unsubscription for subscribed sessions.

 Subscription requests are subject to authorization checks. The session must
 have `PTDiffusionPathPermission#selectTopic` permission for the
 topic selector used to subscribe. Matching topics will be further filtered to
 those for which the session has `PTDiffusionPathPermission#readTopic`
 permission.

 ###Subscription streams

 A session can listen to subscription events and updates for a selection of
 topics by adding one or more streams. A stream is registered using a topic
 selector which specifies the topics that the stream applies to. When an
 update is received for a topic then it will be routed to every stream that
 matches both the topic selector and the stream's value type. If more than one
 stream matches, all will receive the update; the order in which they are
 notified is not defined.

 A stream can be added several times for different selectors. If the same
 stream is registered for
 several selectors that match an event, the stream will only be notified of
 the event once. The mapping of topic selectors to streams is maintained
 locally in the client process.

 It is also possible to add one or more <em>fallback</em> streams which will
 receive updates that do not match any stream registered with a selector. This
 is useful for default processing or simply to catch unprocessed updates. A
 fallback stream can be added using `PTDiffusionTopicsFeature#addFallbackStream:error:`.
 Zero, one, or more fallback streams may be assigned. If
 no fallback stream is specified, any updates that are not routed to any other
 stream will simply be discarded.

 If the session is already subscribed to a topic when a matching stream is
 added, the stream will immediately receive a subscription notification. For
 most topic types, the latest value is locally cached and will be provided to
 the stream following the subscription notification.

 A stream will receive a `PTDiffusionStreamDelegate#diffusionDidCloseStream:`
 callback when unregistered and a `PTDiffusionStreamDelegate#diffusionStream:didFailWithError:`
 callback if the session is closed.

 ###Value streams

 A `PTDiffusionValueStream` receives values for matching topics as and
 when updates are received from the server. Delta updates received from the
 server are automatically applied to locally cached values so that the stream
 always receives full values for each update.

 Value streams are typed to a specified value class and only updates for
 compatible topics will be routed to the stream. The following table shows how
 the value class maps to compatible topic types that will be routed to the
 stream:

 <table>
    <tr>
        <th>Value Class</th>
        <th>Compatible Topic Types</th>
    </tr>
    <tr>
        <td>JSON</td>
        <td>JSON STRING
            INT64 DOUBLE</td>
    </tr>
    <tr>
        <td>String</td>
        <td>STRING</td>
    </tr>
    <tr>
        <td>Long</td>
        <td>INT64</td>
    </tr>
    <tr>
        <td>Double</td>
        <td>DOUBLE</td>
    </tr>
    <tr>
        <td>Binary</td>
        <td>BINARY</td>
    </tr>
    <tr>
        <td>Bytes</td>
        <td>JSON STRING
            INT64 DOUBLE
            BINARY RECORD_V2</td>
    </tr>
    <tr>
        <td>RecordV2</td>
        <td>RECORD_V2</td>
    </tr>
 </table>

 Value stream implementations can be added using
 `PTDiffusionTopicsFeature#addStream:withSelector:error`.

 A value stream can be added to received updates from time
 series topics. The following table shows how the value class specified
 when adding the stream maps to the event value class of time series topics
 that will be routed to the stream:

 <table>
    <tr>
        <th>Event Value Class</th>
        <th>Time Series Event Value Class</th>
    </tr>
    <tr>
        <td>JSON</td>
        <td>JSON STRING
            INT64 DOUBLE</td>
    </tr>
    <tr>
        <td>String</td>
        <td>STRING</td>
    </tr>
    <tr>
        <td>Long</td>
        <td>INT64</td>
    </tr>
    <tr>
        <td>Double</td>
        <td>DOUBLE</td>
    </tr>
    <tr>
        <td>Binary</td>
        <td>BINARY</td>
    </tr>
    <tr>
        <td>Bytes</td>
        <td>JSON STRING
            INT64 DOUBLE
            BINARY RECORD_V2</td>
    </tr>
    <tr>
        <td>RecordV2</td>
        <td>RECORD_V2</td>
    </tr>
 </table>

 ###Fetch

 A session can issue a request to fetch details of a topic or topics (subject
 to authorization) at any time. The topics required are specified using a
 topic selector.

 The results of a fetch will return the topic path and type of each selected
 topic. The results may also optionally return the topic values and/or
 properties.

 A new request can be created using `PTDiffusionTopicsFeature.fetchRequest` and modified to
 specify additional requirements of the fetch operation. The request is issued
 to the server using the `PTDiffusionFetchRequest#fetchWithTopicSelectorExpression:completionHandler:]`
 method on the request. This will return the results via a `completionHandler`.

 ###Access control

 A session must have `PTDiffusionPathPermission.selectTopic`
 permission for the path prefix of the topic selector used to
 subscribe or fetch.
 The topics that result from a subscription or fetch request are further
 filtered using the `PTDiffusionPathPermission.readTopic` permission.

 No access control restrictions are applied to unsubscription.

 ###Accessing the feature

 This feature can be obtained from a `PTDiffusionSession` as follows:

 <pre>
    PTDiffusionTopicsFeature *topics = session.topics;
 </pre>

 @see PTDiffusionSession

 @since 5.6
 */
@interface PTDiffusionTopicsFeature : PTDiffusionTopicUpdateFeature

/**
 Request subscription to topics.

 The session will become subscribed to each existing topic matching
 the selector unless the session is already subscribed to the topic,
 or the session does not have `READ_TOPIC` permission for the topic
 path. For each topic to which the session becomes subscribed, a
 subscription notification and initial value (if any) will be
 delivered to registered value streams before the completion handler
 is called.

 The subscription request is also retained at the server and the session
 will be automatically subscribed to newly created topics that match the
 selector (unless a subsequent unsubscription cancels the request).

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 5.6
 */
-(void)subscribeWithTopicSelectorExpression:(NSString *)expression
                          completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Request unsubscription from topics.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated by the server.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 5.6
 */
-(void)unsubscribeFromTopicSelectorExpression:(NSString *)expression
                            completionHandler:(void (^)(NSError * _Nullable error))completionHandler;



/**
 Request subscription to topics.

 The session will become subscribed to each existing topic matching
 the selector unless the session is already subscribed to the topic,
 or the session does not have `READ_TOPIC` permission for the topic
 path. For each topic to which the session becomes subscribed, a
 subscription notification and initial value (if any) will be
 delivered to registered value streams before the completion handler
 is called.

 The subscription request is also retained at the server and the session
 will be automatically subscribed to newly created topics that match the
 selector (unless a subsequent unsubscription cancels the request).

 @param selector The @ref md_topic_selectors "topic selector" to be
 evaluated by the server.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 
 @param error Populated in case of an invalid argument passed to the method.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.
 
 @return true is arguments are valid, false otherwise.

 @since 6.11
 */
-(BOOL)subscribeWithTopicSelector:(PTDiffusionTopicSelector *)selector
                completionHandler:(void (^)(NSError * _Nullable))completionHandler
                            error:(NSError *__autoreleasing *const)error;



/**
 Request unsubscription from topics.

 @param selector The @ref md_topic_selectors "topic selector" to be
 evaluated by the server.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 
 @param error Populated in case of an invalid argument passed to the method.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.
 
 @return true is arguments are valid, false otherwise.

 @since 6.11
 */
-(BOOL)unsubscribeFromTopicSelector:(PTDiffusionTopicSelector *)selector
                  completionHandler:(void (^ const)(NSError *))completionHandler
                              error:(NSError *__autoreleasing *const)error;


/**
 When a matching update is received from the server for a topic, it will be
 passed on to all value streams that have been added with matching selectors.
 If no value stream is registered with a matching selector, the fallback value
 streams that have been registered using this method will be called instead.

 Zero, one, or many fallback value streams can be set.
 If there is no fallback value stream, updates that match no other will be
 discarded.

 @param stream Handler of value stream events not handled by an explicitly
 registered topic selector.
 The delegate associated with this stream will be sent messages asynchronously
 on the main dispatch queue.

 @exception NSInvalidArgumentException Raised if the supplied `stream` argument
 is `nil`.

 @since 5.9

 @deprecated since 6.5 Use `addFallBackStream:error:`
 */
-(void)addFallbackStream:(PTDiffusionValueStream *)stream
__deprecated_msg("Will be removed in a future release.");

/**
 When a matching update is received from the server for a topic, it will be
 passed on to all value streams that have been added with matching selectors.
 If no value stream is registered with a matching selector, the fallback value
 streams that have been registered using this method will be called instead.

 Zero, one, or many fallback value streams can be set.
 If there is no fallback value stream, updates that match no other will be
 discarded.

 @param stream Handler of value stream events not handled by an explicitly
 registered topic selector.
 The delegate associated with this stream will be sent messages asynchronously
 on the main dispatch queue.

 @param error May be 'nil'. Is supplied then will contain reason on failure.

 @return YES if stream was successfully added

 @exception NSInvalidArgumentException Raised if the supplied `stream` argument
 is `nil`.

 @since 6.5
 */
-(BOOL)addFallbackStream:(PTDiffusionValueStream *)stream
                   error:(NSError **)error;

/**
 Add a value stream to receive topic updates for topics that match the given
 topic selector.

 When a value update is received from the server, it will be passed to all
 streams that have been added with matching selectors.
 If there is more than one match, the order in which the streams are called is
 not defined.
 If there is no matching stream, the fallback stream(s) will be called instead.

 @param stream Handler of value stream events against this selector.
 The delegate associated with this stream will be sent messages asynchronously
 on the main dispatch queue.

 @param selector The @ref md_topic_selectors "topic selector" to be evaluated locally.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 5.9

 @deprecated since 6.5 Use `addStream:withSelector:error:`
 */
-(void)addStream:(PTDiffusionValueStream *)stream
    withSelector:(PTDiffusionTopicSelector *)selector
__deprecated_msg("Will be removed in a future release.");

/**
 Add a value stream to receive topic updates for topics that match the given
 topic selector.

 When a value update is received from the server, it will be passed to all
 streams that have been added with matching selectors.
 If there is more than one match, the order in which the streams are called is
 not defined.
 If there is no matching stream, the fallback stream(s) will be called instead.

 @param stream Handler of value stream events against this selector.
 The delegate associated with this stream will be sent messages asynchronously
 on the main dispatch queue.

 @param selector The @ref md_topic_selectors "topic selector" to be evaluated locally.

 @param error May be 'nil'. Is supplied then will contain reason on failure.

 @return YES if stream was successfully added

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.5
 */
-(BOOL)addStream:(PTDiffusionValueStream *)stream
    withSelector:(PTDiffusionTopicSelector *)selector
           error:(NSError **)error;

/**
 Add a value stream to receive topic updates for topics that match the given
 topic selector expression.

 This convenience method calls addStream:withSelector: having constructed a
 PTDiffusionTopicSelector instance using the given expression.

 @param stream Handler of value stream events against this selector.
 The delegate associated with this stream will be sent messages asynchronously
 on the main dispatch queue.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated locally.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0

 @deprecated since 6.5 Use `addStream:withSelectorExpression:error:`
 */
-(void)          addStream:(PTDiffusionValueStream *)stream
    withSelectorExpression:(NSString *)expression
__deprecated_msg("Will be removed in a future release.");

/**
 Add a value stream to receive topic updates for topics that match the given
 topic selector expression.

 This convenience method calls addStream:withSelector: having constructed a
 PTDiffusionTopicSelector instance using the given expression.

 @param stream Handler of value stream events against this selector.
 The delegate associated with this stream will be sent messages asynchronously
 on the main dispatch queue.

 @param expression The @ref md_topic_selectors "topic selector" expression to be
 evaluated locally.

 @param error May be 'nil'. Is supplied then will contain reason on failure.

 @return YES if stream was successfully added

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.5
 */
-(BOOL)          addStream:(PTDiffusionValueStream *)stream
    withSelectorExpression:(NSString *)expression
                     error:(NSError **)error;

/**
 Remove a topic or value stream that was previously added using a topic selector
 or as a fallback.

 @param stream The stream to remove.

 @return `YES` if the stream was removed.

 @note If the supplied `stream` argument is `nil` or the stream has already been
 removed from the feature then calls to this method do nothing and return `NO`.

 @since 5.9
 */
-(BOOL)removeStream:(nullable PTDiffusionStream *)stream;

/**
 Creates an unconfigured fetch request.

 If the request is invoked by calling
 PTDiffusionFetchRequest#fetchWithTopicSelectorExpression:completionHandler:
 the fetch result will provide the paths and types of all of the topics which
 the session has permission to read.

 You will usually want to restrict the query to a subset of the topic tree, and
 to retrieve the topic values and/or properties. This is achieved by applying
 one or more of the builder methods to produce more refined requests.

 For example (Swift):

     topics.fetchRequest()
         .fetchStringValues(withTopicSelectorExpression: "*A/B//")
         {
             (result: PTDiffusionStringFetchResult?, error: Error?) in
             / / TODO Handle result, if not `nil`, otherwise handle error.
         }

 @return a new unconfigured fetch request

 @since 6.2
 */
-(PTDiffusionFetchRequest *)fetchRequest;

@end

NS_ASSUME_NONNULL_END
