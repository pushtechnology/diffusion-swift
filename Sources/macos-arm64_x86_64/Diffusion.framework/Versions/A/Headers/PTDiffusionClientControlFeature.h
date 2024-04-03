//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020, 2021 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionFeature.h>

@protocol PTDiffusionSessionPropertiesDelegate;
@protocol PTDiffusionClientQueueEventListener;

@class PTDiffusionSessionPropertiesListenerRegistration;
@class PTDiffusionRegistration;
@class PTDiffusionGetSessionPropertiesResult;
@class PTDiffusionSetSessionPropertiesResult;
@class PTDiffusionSessionId;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The Client Control feature provides the ability for a client session
        to control other client sessions.

 It allows for notifications of client sessions starting and closing as well
 as the ability to manage client sessions (forcibly closing them etc).


 ### Access control

 A session must have `PTDiffusionGlobalPermission#viewSession` permission to be able
 to listen for notifications using `#addSessionPropertiesListener:forProperties:completionHandler:`
 or `#getSessionProperties:forSession:completionHandler:` of other sessions
 or listen for queue events. In addition, `PTDiffusionGlobalPermission#registerHandler`
 permission is required to set a session properties listener or queue event handler.

 In order to perform operations that change a session's state (such as throttling,
 conflating, or closing the session, or changing roles), both
 `PTDiffusionGlobalPermission#viewSession` and PTDiffusionGlobalPermission#modifySession`
 permission is required.


 ### Accessing the feature

 This feature may be obtained from a `PTDiffusionSession` session as follows:
 <pre>
    <code>
        PTDiffusionClientControlFeature *clientControl = session.clientControl;
    </code>
 </pre>

 @since 6.5
 */
@interface PTDiffusionClientControlFeature : PTDiffusionFeature


/**
 @brief Register a listener that will be notified when client sessions are
        opened, disconnected, reconnected, closed or when selected session
        property values are updated.

 When a listener is first set, it will be called with the required
 properties of all currently open client sessions.
 The amount of data transferred from the server is proportional to
 the number of connected clients and is potentially large.
 The amount of data can be reduced using `requiredProperties` parameter.

 Each control session can register a single listener. When the listener is
 no longer required, it may be closed using the
 PTDiffusionSessionPropertiesListenerRegistration provided by the `completionHandler`.
 To change the listener, the previous listener must first be closed.

 The `requiredProperties` parameter is used to select the property
 values required.

 The requested property set controls the level of detail provided and
 whether the listener is called for updates to sessions.
 If no properties are requested, the listener is not called when
 session properties are updated.

 @param listener the listener to be called with session notifications

 @param requiredProperties a list of required property keys.
        See `PTDiffusionSession` for a full list of available fixed property keys.
        To request no properties, supply an empty list.
        To request all fixed properties, include
        `PTDiffusionSession.allFixedProperties` as an entry.
        In this case any other fixed property keys would be ignored.
        To request all user properties, include
        `PTDiffusionSession.allUserProperties` as an entry.
        In this case any other user properties are ignored.

 @param completionHandler a completion handler than returns when the listener
        has been registered, returning a `PTDiffusionSessionPropertiesListenerRegistration`
        which can be used to unregister the listener.

        If the `registration` is nil. This could mean an error has occurred during the
        registration process. These may include:
        - SessionClosed, if the session is closed
        - HandlerConflict, if the session has already registered a queue event handler
        - Security, if the session does not have
          `PTDiffusionGlobalPermission.registerHandler` permission and/or
          `PTDiffusionGlobalPermission.viewSession` permission.

 @since 6.5
 */
-(void)addSessionPropertiesListener:(id<PTDiffusionSessionPropertiesDelegate>) listener
                      forProperties:(NSArray<NSString *> *) requiredProperties
                  completionHandler:(void (^)(PTDiffusionSessionPropertiesListenerRegistration * _Nullable registration,
                                              NSError * _Nullable error)) completionHandler;


/**
 @brief Query the server for property values of a specified client session.

 @param requiredProperties a list of required property keys.
        See `PTDiffusionSession` for a full list of available fixed property keys.
        To request no properties, supply an empty list.
        To request all fixed properties, include `PTDiffusionSession.allFixedProperties`
        as a key.
        In this case any other fixed property keys would be ignored.
        To request all user properties, include `PTDiffusionSession.allUserProperties`
        as a key.
        In this case any other user properties are ignored.

 @param sessionId identifies the client session

 @param completionHandler called with the response

 @since 6.5
 */
-(void) getSessionProperties:(NSArray<NSString *> *) requiredProperties
                  forSession:(PTDiffusionSessionId *) sessionId
           completionHandler:(void (^)(PTDiffusionGetSessionPropertiesResult * _Nullable result,
                                       NSError * _Nullable error)) completionHandler;



/**
 @brief Send a request to the server to change the user-defined session
        properties for a session.

 It is also permissible to change the values of the following fixed session
 properties :

 - `$Country` - will be normalised to upper case
 - `$Language` - will be normalised to lower case
 - `$Latitude` - Invalid value will be set to "NaN"
 - `$Longitude` - Invalid value will be set to "NaN"

 If values are provided for any other fixed session properties they will be ignored.

 @param properties the properties to change. Each entry in the map is a
        property name and the new value.
        If the value is `[NSNull null]`, any existing property with
        that name will be removed (unless it is a fixed property).
        Otherwise if the property name does not match any existing property,
        that entry will be added as a new property (although properties starting
        with `$` will be ignored).

 @param sessionId identifies the client session

 @param completionHandler a completion handler that is called when a response is received
        from the server, returning the maps of session properties that were added
        or updated.

        If the session properties were updated, the `result` will contain a map of
        properties that changed with their previous values.
        If no properties were changed, the map will be empty.
        If any new properties were added, the values in the map will be `[NSNull null]`
        to indicate that they do not have an old value.

        Otherwise, the `error` will contain an error.
        Common reasons for failure:
        - NoSuchSession, if the identified session was closed before the response was delivered
        - Security, if the calling session does not have `PTDiffusionGlobalPermission.modifySession`
          and `PTDiffusionGlobalPermission.viewSession` permission
        - SessionClosed, if the calling session is closed.

 @since 6.5
 */
-(void) setSessionProperties:(NSDictionary<NSString *, NSString *>*) properties
                  forSession:(PTDiffusionSessionId *) sessionId
           completionHandler:(void (^)(PTDiffusionSetSessionPropertiesResult * _Nullable result,
                                       NSError * _Nullable error)) completionHandler;



/**
 @brief Send a request to the server to set all sessions that satisfy a session
        filter with the new user-defined session properties.

 It is also permissible to change the values of the following fixed session
 properties :

 - `$Country` - will be normalised to upper case
 - `$Language` - will be normalised to lower case
 - `$Latitude` - Invalid value will be set to "NaN"
 - `$Longitude` - Invalid value will be set to "NaN"

 If values are provided for any other fixed session properties they will be ignored.

 @param properties the properties to change.
        Each entry in the map is a property name and the new value.
        If the value is `[NSNull null]`, any existing property with
        that name will be removed (unless it is a fixed property).
        Otherwise if the property name does not match any existing property,
        that entry will be added as a new property (although properties starting
        with `$` will be ignored).

 @param filter the session filter

 @param completionHandler a completion handler that is called when a response is received
        from the server, returning the total number of sessions that were updated with
        the filter.

        If `matches` is 0, the filter has not selected any session
        If `matches` is -1, an `error` has occurred.
        These are the common reasons for failure:
        - NoSuchSession, if the identified session was closed before the response was delivered
        - Security, if the calling session does not have `PTDiffusionGlobalPermission.modifySession`
          and `PTDiffusionGlobalPermission.viewSession` permission
        - SessionClosed, if the calling session is closed.

 @since 6.5
 */
-(void) setSessionProperties:(NSDictionary<NSString *, NSString *> *) properties
                 usingFilter:(NSString *) filter
           completionHandler:(void (^)(NSInteger matches,
                                       NSError * _Nullable error)) completionHandler;


/**
 @brief Close a client session.

 @param sessionId identifies the client session to close

 @param completionHandler a completion handler that is called then a response is received
        from the server.
        If the client session was closed successfully, the `error` will be nil

        Otherwise, the `error` will contain an error.
        These are the common reasons for failure:
        - NoSuchSession, if the identified session was closed before the response was delivered
        - Security, if the calling session does not have `PTDiffusionGlobalPermission.modifySession`
          and `PTDiffusionGlobalPermission.viewSession` permission
        - SessionClosed, if the calling session is closed.

 @since 6.6
 */
-(void)closeClientWithSessionId:(PTDiffusionSessionId *) sessionId
              completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;


/**
 @brief Close all client sessions matching a given session filter.

 @param filter matches the set of client sessions to close. For details on
        specifying session filters see `PTDiffusionSession`.

 @param completionHandler a completion handler that is called then a response is received
        from the server.
        If the operation is successful, `closedSessions` will contain the number of client
        sessions that were closed and `error` will be nil.

        Otherwise, the `error` will contain an error.
        These are the common reasons for failure:
        - NoSuchSession, if the identified session was closed before the response was delivered
        - Security, if the calling session does not have `PTDiffusionGlobalPermission.modifySession`
          and `PTDiffusionGlobalPermission.viewSession` permission
        - SessionClosed, if the calling session is closed.

 @since 6.6
 */
-(void)closeClientWithFilter:(NSString *)filter
           completionHandler:(void (^)(NSInteger closedSessions, NSError * _Nullable error)) completionHandler;


/**
 @brief Sets the client session queue conflation policy.

 Each session begins with conflation enabled or disabled based on the
 queue configuration of the connector it is using. This method allows
 conflation to be enabled or disabled for specific sessions at runtime.

 Conflation is the process of merging or discarding topic updates queued
 for a session to reduce the server memory footprint and network data.
 Conflation needs to be enabled for a session and a policy configured for
 the topic to have an effect. Policies are configured on a per-topic
 basis using the `PTDiffusionTopicSpecification.conflationPropertyKey`.

 @param conflate `true` to enable conflation, `false` to disable conflation

 @param sessionId identifies the client session

 @param completionHandler a completion handler that is called when a response is received
        from the server. If the conflation policy was updated for the identified session,
        the error will be `nil`.

        Otherwise, the `error` will contain an error.
        These are the common reasons for failure:
        - NoSuchSession, if the identified session was closed before the response was delivered
        - Security, if the calling session does not have `PTDiffusionGlobalPermission.modifySession`
          and `PTDiffusionGlobalPermission.viewSession` permission
        - SessionClosed, if the calling session is closed.

 @since 6.6
 */
-(void)setQueueConflation:(BOOL)conflate forSession:(PTDiffusionSessionId *)sessionId
        completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;


/**
 @brief Sets the queue conflation policy for all client sessions
        matching a given session filter.

 Each session begins with conflation enabled or disabled based on the
 queue configuration of the connector it is using. This method allows
 conflation to be enabled or disabled for specific sessions at runtime.

 Conflation is the process of merging or discarding topic updates queued
 for a session to reduce the server memory footprint and network data.
 Conflation needs to be enabled for a session and a policy configured for
 the topic to have an effect. Policies are configured on a per-topic
 basis using the `PTDiffusionTopicSpecification.conflationPropertyKey`.

 @param conflate `true` to enable conflation, `false` to disable conflation

 @param filter matches the set of client sessions to close. For details on
        specifying session filters see `PTDiffusionSession`.

 @param completionHandler a completion handler that is called when a response is received
        from the server. If the conflation policy was updated for the identified session,
        the error will be `nil`.

        Otherwise, the `error` will contain an error.
        These are the common reasons for failure:
        - NoSuchSession, if the identified session was closed before the response was delivered
        - Security, if the calling session does not have `PTDiffusionGlobalPermission.modifySession`
          and `PTDiffusionGlobalPermission.viewSession` permission
        - SessionClosed, if the calling session is closed.

 @since 6.6
 */
-(void)setQueueConflation:(BOOL)conflate withFilter:(NSString *)filter
        completionHandler:(void (^)(NSInteger matchedSessions, NSError * _Nullable error)) completionHandler;


/**
 @brief Register a delegate for client queue threshold events

 Each control session can register a single handler. When the handler is
 no longer required, it may be closed using the `PTDiffusionRegistration`
 provided by the completion handler. To set a different handler the
 current handler must first be closed. For each event, the server will
 select a single handler.

 The control session may choose to act upon queue events for a session by
 activating conflation for the session.

 @param listener the queue handler listener to set

 @param completionHandler a completion handler than returns when the listener
        has been registered, returning a `PTDiffusionRegistration`
        which can be used to unregister the listener.

        If the `registration` is nil. This could mean an error has occurred during the
        registration process. These may include:
        - SessionClosed, if the session is closed
        - HandlerConflict, if the session has already registered a queue event handler
        - Security, if the session does not have
          `PTDiffusionGlobalPermission.registerHandler` permission and/or
          `PTDiffusionGlobalPermission.viewSession` permission.

 @since 6.6
 */
-(void)setQueueEventHandler:(id<PTDiffusionClientQueueEventListener>)listener
          completionHandler:(void (^)(PTDiffusionRegistration *registration, NSError * _Nullable error)) completionHandler;

@end

NS_ASSUME_NONNULL_END
