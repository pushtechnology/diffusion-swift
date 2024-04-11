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

@class PTDiffusionCredentials;
@class PTDiffusionRemoteServer;
@class PTDiffusionRemoteServerConnectionOption;
@class PTDiffusionRemoteServerConnectionState;
@class PTDiffusionCheckRemoteServerResult;
@class PTDiffusionCreateRemoteServerResult;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This feature allows a client session to manage remote servers.

 A remote server provides the configuration to connect to a Diffusion server
 belonging to a different cluster. Each server in the local cluster will
 establish a session with each remote server.

 Higher level components, such as remote topic views, can specify the use of
 such remote servers by name. The connecting and disconnecting is handled
 automatically by the server (or servers in the same cluster) where the remote
 servers are defined.

 A component can specify a remote server by name even if it does not exist
 (has not yet been created) and when the remote server is created the
 connection will take place automatically.

 If a remote server is removed and there are components that depend upon it,
 those components will be disabled.

 An example of the use of remote servers is within remote topic views (those
 that indicate that their source topics are to be taken from a different
 server) where the name of such a server can be specified.

 ### Remote Server persistence and replication

 Remote server configurations created through this feature are replicated
 across a cluster and persisted to disk.

 ### Access control

 The following access control restrictions are applied:

 <ul>
    <li>To create, remove or check a remote server, a session needs the
        {@link PTDiffusionGlobalPermission#controlServer CONTROL_SERVER} permission.
    <li>To list remote servers, a session needs the
        {@link PTDiffusionGlobalPermission#viewServer VIEW_SERVER} permission.
 </ul>

 ### Accessing the feature

 This feature may be obtained from a {@link PTDiffusionSession session} as follows:

 <pre>
 PTDiffusionRemoteServersFeature *remoteServers = session.remoteServersFeature;
 </pre>

 @since 6.5
 */
@interface PTDiffusionRemoteServersFeature : PTDiffusionFeature


/**
 @brief Create a new remote server instance at the server.

 If a remote server with the same name already exists an error will be returned.

 @param remoteServer remote server definition using a {@link PTDiffusionRemoteServerBuilder
 remote server builder}.

 @param completionHandler a completion handler that returns when a response is
 received from the server, returning a full definition of the remote server created
 by the operation.
 If the remote server definition is nil, this could mean an error has occurred.
 These may include:
 <ul>
    <li>{@link PTDiffusionError_RemoteServerExists} - if a remote server with the given name already exists
    <li>{@link PTDiffusionError_ClusterRouting} or {@link PTDiffusionError_ClusterRepartition} -
        if a transient cluster error occurred
    <li>{@link PTDiffusionError_AccessDenied} - if the calling session does not have
        {@link PTDiffusionGlobalPermission#controlServer CONTROL_SERVER} permission
    <li>{@link PTDiffusionError_SessionClosed} - if the session is closed
 </ul>

 @since 6.7
 */
-(void)createRemoteServer:(PTDiffusionRemoteServer *const)remoteServer
        completionHandler:(void (^)(PTDiffusionCreateRemoteServerResult * _Nullable result,
                                    NSError * _Nullable error))completionHandler;


/**
 @brief Create a new remote server instance with default connection options.

 If a remote server with the same name already exists an error will be returned.

 @param name the name of the remote server

 @param url the URL used to connect to the primary server

 @param principal the name of a principal used by the remote server to
 connect to the primary server. A zero length string may be
 supplied to indicate an anonymous connection

 @param credentials used for connecting to the primary server

 @param completionHandler a completion handler that returns when a response is
 received from the server, returning a full definition of the remote server created
 by the operation.
 If the remote server definition is nil, this could mean an error has occurred.
 These may include:
 <ul>
    <li>{@link PTDiffusionError_RemoteServerExists} - if a remote server with the given name already exists
    <li>{@link PTDiffusionError_ClusterRouting} or {@link PTDiffusionError_ClusterRepartition} -
        if a transient cluster error occurred
    <li>{@link PTDiffusionError_AccessDenied} - if the calling session does not have
        {@link PTDiffusionGlobalPermission#controlServer CONTROL_SERVER} permission
    <li>{@link PTDiffusionError_SessionClosed} - if the session is closed
 </ul>

 @since 6.5

 @deprecated since 6.7 Use {@link createRemoteServer:completionHandler:} in preference.
 This method will be removed in a future release.
 */
-(void)createRemoteServer:(NSString *const)name
                  withURL:(NSString *const)url
                principal:(NSString *const)principal
              credentials:(PTDiffusionCredentials *const)credentials
        completionHandler:(void (^)(PTDiffusionCreateRemoteServerResult * _Nullable result,
                                    NSError * _Nullable error))completionHandler __deprecated_msg("Will be removed in a future release.");


/**
 @brief Create a new remote server instance.

 If a remote server with the same name already exists an error will be returned.

 @param name the name of the remote server

 @param url the URL used to connect to the primary server

 @param principal the name of a principal used by the remote server to
 connect to the primary server. A zero length string may be
 supplied to indicate an anonymous connection

 @param credentials used for connecting to the primary server

 @param connectionOptions map of connection option settings. Any options
 not supplied will take their default values

 @param completionHandler a completion handler that returns when a response is
 received from the server, returning a full definition of the remote server
 created by the operation.
 If the remote server definition is nil, this could mean an error has occurred.
 These may include:
 <ul>
    <li>{@link PTDiffusionError_RemoteServerExists} - if a remote server with the given name already exists
    <li>{@link PTDiffusionError_ClusterRouting} or {@link PTDiffusionError_ClusterRepartition} -
        if a transient cluster error occurred
    <li>{@link PTDiffusionError_AccessDenied} - if the calling session does not have
        {@link PTDiffusionGlobalPermission#controlServer CONTROL_SERVER} permission
    <li>{@link PTDiffusionError_SessionClosed} - if the session is closed
 </ul>

 @since 6.5

 @deprecated since 6.7 Use {@link createRemoteServer:completionHandler:} in preference.
 This method will be removed in a future release.
 */
-(void)createRemoteServer:(NSString *const)name
                  withURL:(NSString *const)url
                principal:(NSString *const)principal
              credentials:(PTDiffusionCredentials *const)credentials
        connectionOptions:(NSDictionary<PTDiffusionRemoteServerConnectionOption *, NSString *> const*)connectionOptions
        completionHandler:(void (^)(PTDiffusionCreateRemoteServerResult * _Nullable result,
                                    NSError * _Nullable error))completionHandler __deprecated_msg("Will be removed in a future release.");



/**
 @brief Check the current state of a named remote server.

 This will report back the current state of the remote server, but also
 can be used to forcibly retry a failed remote server connection.

 @param name the name of the remote server

 @param completionHandler a completion handler that returns when a response is
 received from the server, return the details of the remote server state.
 If the state is nil, this could mean an error has occurred.
 These may include:
 <ul>
    <li>{@link PTDiffusionError_AccessDenied} - if the calling session does not have
        {@link PTDiffusionGlobalPermission#controlServer CONTROL_SERVER} permission
    <li>{@link PTDiffusionError_SessionClosed} - if the session is closed
 </ul>

 @since 6.5
 */
-(void)checkRemoteServer:(NSString *const)name
       completionHandler:(void (^)(PTDiffusionCheckRemoteServerResult * _Nullable result,
                                   NSError * _Nullable error))completionHandler;


/**
 @brief List all the remote servers that have been created

 @param completionHandler a completion handler that returns when a response is
 received from the server, returning a list of remote servers.
 If the list is nil, this could mean an error has occurred.
 These may include:
 <ul>
    <li>{@link PTDiffusionError_AccessDenied} - if the calling session does not have
        {@link PTDiffusionGlobalPermission#viewServer VIEW_SERVER} permission
    <li>{@link PTDiffusionError_SessionClosed} - if the session is closed
 </ul>

 @since 6.5
 */
-(void)listRemoteServers:(void (^)(NSArray<PTDiffusionRemoteServer *> * _Nullable result,
                                   NSError * _Nullable error))completionHandler;


/**
 @brief Remove a named remote server if it exists

 If the named remote server does not exist the completionHandler
 will return without an error

 When a named remote server is removed, any components that specify it
 would be disabled.

 @param name the name of the remote server

 @param completionHandler a completion handler that returns when a response is
 received from the server.
 If the error is not nil, this means an error has occurred.
 These may include:
 <ul>
    <li>{@link PTDiffusionError_ClusterRouting} or {@link PTDiffusionError_ClusterRepartition} -
        if a transient cluster error occurred
    <li>{@link PTDiffusionError_AccessDenied} -
        if the calling session does not have
        {@link PTDiffusionGlobalPermission#controlServer CONTROL_SERVER} permission
    <li>{@link PTDiffusionError_SessionClosed} -
        if the session is closed
 </ul>

 @since 6.5
 */
-(void)removeRemoteServer:(NSString *const)name
        completionHandler:(void (^)(NSError * _Nullable error))completionHandler;


@end

NS_ASSUME_NONNULL_END
