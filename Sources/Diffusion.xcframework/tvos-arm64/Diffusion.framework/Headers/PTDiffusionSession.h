//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2015 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionClientControlFeature;
@class PTDiffusionMessagingFeature;
@class PTDiffusionPingsFeature;
@class PTDiffusionSecurityFeature;
@class PTDiffusionSessionConfiguration;
@class PTDiffusionSessionId;
@class PTDiffusionSessionLock;
@class PTDiffusionSessionLockAttempt;
@class PTDiffusionSessionLockScope;
@class PTDiffusionSessionState;
@class PTDiffusionSubscriptionControlFeature;
@class PTDiffusionTimeSeriesFeature;
@class PTDiffusionTopicControlFeature;
@class PTDiffusionTopicNotificationsFeature;
@class PTDiffusionTopicsFeature;
@class PTDiffusionTopicUpdateFeature;
@class PTDiffusionTopicViewsFeature;
@class PTDiffusionRemoteServersFeature;
@class PTDiffusionSessionTreesFeature;
@class PTDiffusionMetricsFeature;
@class PTDiffusionHTTPResponse;

@protocol PTDiffusionErrorListener;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A client session to a server or cluster of servers.

 The @ref md_quick_start "Quick Start" guide provides basic instructions on how
 to connect to a Diffusion server.

 Also see:
 - @ref md_session_filters "Session Filters".
 - @ref md_session_properties "Session Properties".

 A new session can be created by connecting to a server using
 `#openWithURL:completionHandler:` specifying the server URL.
 A `PTDiffusionSessionConfiguration` can also be configured to control
 the behaviour of the session using `#openWithURL:configuration:completionHandler:`

 The session provides a variety of operations to the application. These are
 grouped into feature interfaces, such as Topics and Messaging,
 exposed to the application through the following methods:
 <ul>
     <li>#clientControl
     <li>#messaging
     <li>#pings
     <li>#remoteServers
     <li>#security
     <li>#subscriptionControl
     <li>#timeSeries
     <li>#topicControl
     <li>#topics
     <li>#topicUpdate
     <li>#topicViews
 </ul>

 ###Session lifecycle

 Each session is managed by a server. The server assigns the session a
 unique identity, and manages the session's topic subscriptions,
 security details, and session properties.

 A session can be terminated using `close`. A session may also be
 terminated by the server because of an error or a time out, or by other
 privileged sessions using the ClientControl feature.

 A client can become disconnected from the server, and reconnect to the server
 without loss of the session. Reconnection can be configured using
 `PTDiffusionSessionConfiguration.reconnectionStrategy`. The server
 must be configured to allow reconnection.

 If a session is connected to a server that belongs to a cluster with session
 replication enabled, and then becomes disconnected, it will attempt to
 reconnect to the original server. A properly configured load balancer can
 detect that the original server is unavailable and re-route the reconnection
 request to a second server in the cluster. The second server can recover
 session data and continue the session. This process is known as "fail over".
 Unlike reconnection, in-flight messages can be lost during failover, and the
 application will be unsubscribed and re-subscribed to topics.

 The current state of the session can be retrieved with `state`.
 This property is Key-Value Observable with changes being notified on
 the main dispatch queue when the session state changes.

 ### Session locks

 The actions of multiple sessions can be coordinated using session locks. See
 PTDiffusionSession#lockWithName:completionHandler:

 @since 5.6
 */
@interface PTDiffusionSession : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


/**
 Starts asynchronously connecting to a Diffusion server using the given session configuration.

 @param url The location of the server to connect to. Encapsulates host, port and protocol to use.
 Must be absolute.

 @param configuration The configuration options to connect with.

 @param completionHandler The completion handler to call on connection success or failure.
 The completion handler will be called from the main dispatch queue and will only be called once.

 @note Your completion handler _must_ store a strong reference to the session instance in order
 for it to remain open.

 @note The completion handler block is called after the session's state property has been set
 to connected but before those observing through the notification center are informed.

 @since 5.6
 */
+(void)openWithURL:(NSURL *)url
     configuration:(PTDiffusionSessionConfiguration *)configuration
 completionHandler:(void (^)(PTDiffusionSession * _Nullable session, NSError * _Nullable error))completionHandler;


/**
 Starts asynchronously connecting to a Diffusion server using the default session configuration.

 @param url The location of the server to connect to. Encapsulates host, port and protocol to use.
 Must be absolute.

 @param completionHandler The completion handler to call on connection success or failure.
 The completion handler will be called from the main dispatch queue and will only be called once.

 @note Your completion handler _must_ store a strong reference to the session instance in order
 for it to remain open.

 @note The completion handler block is called after the session's state property has been set
 to connected but before those observing through the notification center are informed.

 @since 5.6
 */
+(void)openWithURL:(NSURL *)url
 completionHandler:(void (^)(PTDiffusionSession * _Nullable session, NSError * _Nullable error))completionHandler;


/**
 The configuration used to open the session.

 @since 5.6
 */
@property(nonatomic, readonly, copy) PTDiffusionSessionConfiguration* configuration;


/**
 The unique identifier for the session as assigned by the server it connects to.

 This property is Key-Value Observable with changes being notified on the main dispatch queue.
 */
@property(nonatomic, readonly) PTDiffusionSessionId* sessionId;


/**
 The name of the security principal associated with the session.

 @return The principal name. If the session has no associated principal, it is
 known as an anonymous session, in which case the empty string
 anonymousPrincipal will be assigned to this property.

 @since 6.0
 */
@property(nonatomic, readonly) NSString* principal;


/**
 The current state of the session.

 This property is Key-Value Observable with changes being notified on the main dispatch queue.
 KVO notifications are sent before the invocation of any callback handler blocks.

 @note Session state can also be observed using the notification center.
 See PTDiffusionSessionStateChange for details.

 @since 5.7
 */
@property(nonatomic, readonly) PTDiffusionSessionState* state;


/**
 The delegate to use to report unexpected, non-fatal errors to.

 @since 6.0
 */
@property(nonatomic, weak) id<PTDiffusionErrorListener> errorListener;


/**
 Close the session. Once closed a session cannot be restarted.

 @since 5.6
 */
-(void)close;


/**
 Attempt to acquire a session lock.

 The completion handler block will be called with the requested lock if the
 server assigns it to the session. Otherwise, the completion handler block will
 be called with an error indicating why the lock could not be acquired.

 Acquiring the lock can take an arbitrarily long time if other sessions are
 competing for the lock. The server will retain the session's request for the
 lock until it is assigned to the session, the session is closed, or the session
 cancels the CompletableFuture.

 A session can call this method multiple times. If the lock is acquired, all
 calls will complete successfully with equal SessionLocks.

 Calling cancel on the returned PTDiffusionCancellable has no effect on other
 pending calls to acquire this lock.

 Upon successful acquisition, the session owns the lock and is responsible for
 unlocking it. When calling cancel on the returned PTDiffusionCancellable, take
 care that it has not already completed by checking the return value. The
 following Swift code releases the lock if the request could not be canceled.

 let attempt = session.lock(withName: "my-lock") { (lock, error) in
 / / ..
 }

 if (!attempt.cancel()) {
    attempt.lock?.unlock() { (wasOwned, error) in }
 }

 A session that acquires a lock will remain its owner until it is unlocked or
 the session closes. The variant of this methods that takes a scope parameter
 provides the further option of releasing the lock when the session loses its
 connection to the server.

 ### Access control

 To allow fine-grained access control, lock names are interpreted as path names,
 controlled with the `PTDiffusionPathPermission.acquireLock` path permission. This allows permission to
 be granted to a session to acquire the lock `update-topic/a` while preventing
 the session from acquiring the lock `update-topic/b`, for example.

 @param name The name of the session lock.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 If this session has successfully acquired the session lock, or this session
 already owns the session lock, the completion handler will be called with the
 lock instance.

 If the completion handler is called with an error to indicate failure, this
 session does not own the session lock. Common reasons for failure include:

 - The calling session does not have the `PTDiffusionPathPermission.acquireLock` permission for this lock
 name.
 - The session is closed.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @see #lockWithName:scope:completionHandler:

 @since 6.3
 */
-(PTDiffusionSessionLockAttempt *)lockWithName:(NSString *)name
                             completionHandler:(void (^)(PTDiffusionSessionLock * _Nullable lock, NSError * _Nullable error))completionHandler;


/**
 Variant of #lockWithName:completionHandler: that provides control over when a
 lock will be released.

 If called with PTDiffusionSessionLockScope#unlockOnSessionLoss, this method
 behaves exactly like #lockWithName:completionHandler:.

 If called with PTDiffusionSessionLockScope#unlockOnConnectionLoss, any lock
 that is returned will be unlocked if the session loses its connection to the
 server. This is useful to allow another session to take ownership of the lock
 while this session is reconnecting.

 @param name The name of the session lock

 @param scope Preferred scope. The scope of a lock controls when it will be
 released automatically. If a session makes multiple requests for a lock using
 different scopes, and the server assigns the lock to the session fulfilling the
 requests, the lock will be given the weakest scope
 (PTDiffusionSessionLockScope#unlockOnConnectionLoss).

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @see #lockWithName:completionHandler:

 @since 6.3
 */
-(PTDiffusionSessionLockAttempt *)lockWithName:(NSString *)name
                                         scope:(PTDiffusionSessionLockScope *)scope
                             completionHandler:(void (^)(PTDiffusionSessionLock * _Nullable lock, NSError * _Nullable error))completionHandler;


/**
 Returns the last HTTP response received from the server.

 @since 6.3.6
 */
-(PTDiffusionHTTPResponse * _Nullable)websocketHTTPResponse;



#pragma mark - Features

/**
 The Client control feature provides the capability to listen and set session properties

 @since 6.5
 */
@property(nonatomic, readonly) PTDiffusionClientControlFeature *clientControl;


/**
 The Topics feature provides the capability to receive streamed topic updates and/or
 fetch the state of topics.

 @since 5.6
 */
@property(nonatomic, readonly) PTDiffusionTopicsFeature* topics;


/**
 The Topic Control features provides the capability to manage topics.

 @since 5.7
 */
@property(nonatomic, readonly) PTDiffusionTopicControlFeature* topicControl;


/**
 The Topic Update feature provides a client session with the ability to update
 topics.

 @since 6.3
 */
@property(nonatomic, readonly) PTDiffusionTopicUpdateFeature* topicUpdate;


/**
 The Messaging feature provides messaging capabilities.

 @since 5.6
 */
@property(nonatomic, readonly) PTDiffusionMessagingFeature* messaging;


/**
 The Security feature provides a client session with the ability to change
 the associated principal.

 @since 5.6
 */
@property(nonatomic, readonly) PTDiffusionSecurityFeature* security;


/**
 The Pings feature provides a client session with the ability to test the
 roundtrip time associated with sending a request to the server and receiving
 the associated response.

 @since 5.7
 */
@property(nonatomic, readonly) PTDiffusionPingsFeature* pings;


/**
 The Time Series feature provides a client session with the ability to update
 and query time series topics.

 @since 6.0
 */
@property(nonatomic, readonly) PTDiffusionTimeSeriesFeature* timeSeries;


/**
 The Topic Notifications feature allows a client session to receive
 notifications about changes to selected topics.

 @since 6.1
 */
@property(nonatomic, readonly) PTDiffusionTopicNotificationsFeature* topicNotifications;


/**
 The Subscription Control feature allows a client session to subscribe or
 unsubscribe other sessions to topics.

 @since 6.1
 */
@property(nonatomic, readonly) PTDiffusionSubscriptionControlFeature* subscriptionControl;


/**
 The Topic Views feature allows a client session to manage topic views.

 @since 6.3
 */
@property(nonatomic, readonly) PTDiffusionTopicViewsFeature* topicViews;


/**
 The Remote Servers feature allows a client session to create, remove, list
 and check remote servers.

 @since 6.5
 */
@property(nonatomic, readonly) PTDiffusionRemoteServersFeature* remoteServers;


/**
 The Session Trees feature allows the creation and alteration of branch mapping tables.

 @see PTDiffusionSessionTreesFeature

 @since 6.7
 */
@property(nonatomic, readonly) PTDiffusionSessionTreesFeature* sessionTrees;


/**
 The Metrics feature allows a client to configure metric collectors.

 @see PTDiffusionMetricsFeature

 @since 6.7
 */
@property(nonatomic, readonly) PTDiffusionMetricsFeature* metrics;




#pragma mark - Session properties

/**
 Value assigned to the principal property if this is an anonymous session.

 @since 6.0
 */
+(NSString *)anonymousPrincipal;


/**
 This constant can be used instead of a property key in requests for session
 property values to indicate that all fixed session properties are required.

 @since 6.0
 */
+(NSString *)allFixedProperties;


/**
 This constant can be used instead of a property key in requests for session
 property values to indicate that all user defined session properties are
 required.

 @since 6.0
 */
+(NSString *)allUserProperties;


/**
 Session property key for session roles.

 @since 6.2
 */
+(NSString *)rolesPropertyKey;


/**
 Session property key for session identifier.

 @see PTDiffusionSessionId

 @since 6.2
 */
+(NSString *)sessionIdPropertyKey;


/**
 Session property key for principal.

 @since 6.2
 */
+(NSString *)principalPropertyKey;


/**
 Session property key for connector name.

 @since 6.2
 */
+(NSString *)connectorPropertyKey;


/**
 Session property key for transport.

 @since 6.2
 */
+(NSString *)transportPropertyKey;


/**
 Session property key for client type.

 @since 6.2
 */
+(NSString *)clientTypePropertyKey;


/**
 Session property key for country code.

 @since 6.2
 */
+(NSString *)countryPropertyKey;


/**
 Session property key for language code.

 @since 6.2
 */
+(NSString *)languagePropertyKey;


/**
 Session property key for server name.

 @since 6.2
 */
+(NSString *)serverNamePropertyKey;


/**
 Session property key for client IP address.

 @since 6.2
 */
+(NSString *)clientIPPropertyKey;


/**
 Session property key for client latitude.

 @since 6.2
 */
+(NSString *)latitudePropertyKey;


/**
 Session property key for client longitude.

 @since 6.2
 */
+(NSString *)longitudePropertyKey;


/**
 Session property key for client start time.

 @since 6.2
 */
+(NSString *)startTimePropertyKey;

/**
 Session property key for gateway client type.

 @since 6.6
 */
+(NSString *)gatewayTypePropertyKey;

/**
 Session property key for gateway client id.

 @since 6.6
 */
+(NSString *)gatewayIdPropertyKey;


@end

NS_ASSUME_NONNULL_END
