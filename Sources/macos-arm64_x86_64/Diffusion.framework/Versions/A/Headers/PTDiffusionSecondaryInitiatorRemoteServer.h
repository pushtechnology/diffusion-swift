//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

#include <Diffusion/PTDiffusionRemoteServer.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Secondary remote server that initiates a connection to a primary server.

 This type makes a connection from a secondary server (or each secondary
 cluster member) to a primary server. No remote server definition is
 required at the primary server.

 Use the method {@link PTDiffusionRemoteServerBuilder#createSecondaryInitiatorRemoteServer}
 to create an instance of this type.

 @since 6.10
 */
@interface PTDiffusionSecondaryInitiatorRemoteServer : PTDiffusionRemoteServer

/**
 The remote server name.

 @since 6.10
 */
@property (nonatomic, readonly) NSString *name;


/**
 The url for connection to primary server.

 @since 6.10
 */
@property (nonatomic, readonly) NSString * _Nullable url;


/**
 The principal used for the connection.

 This is used to authenticate the connection at the primary server.

 @since 6.10
 */
@property (nonatomic, readonly) NSString *principal;


/**
 The remote server connection options.

 @since 6.10
 */
@property (nonatomic, readonly) NSDictionary<PTDiffusionRemoteServerConnectionOption *, NSString *> *connectionOptions;


/**
 The missing topic notification filter expression or null if
 one has not been specified.

 @since 6.10
 */
@property (nonatomic, readonly) NSString *missingTopicNotificationFilter;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
