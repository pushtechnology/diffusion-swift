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
#import <Diffusion/PTDiffusionRemoteServer.h>

@class PTDiffusionRemoteServerConnectionOption;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A Primary Initiator Remote Server.

 This type makes a connection from a primary server (cluster) to a
 secondary server (or all secondary cluster members) with a
 Secondary Acceptor Remote Server of the same name.

 Use{@link PTDiffusionRemoteServerBuilder#createPrimaryInitiatorRemoteServer}
 to create an instance of this type.

 @since 6.10
 */
@interface PTDiffusionPrimaryInitiatorRemoteServer : PTDiffusionRemoteServer


/**
 The remote server name

 @since 6.10
 */
@property (nonatomic, readonly) NSString *name;


/**
 The urls for connection to secondary servers.

 @since 6.10
 */
@property (nonatomic, readonly) NSArray<NSString *> *urls;


/**
 The connector that the primary initiator will use to
 establish a connection between the secondary server and the primary
 server.

 @since 6.10
 */
@property (nonatomic, readonly) NSString *connector;


/**
 The interval in milliseconds between connection retries.
 If a primary initiator cannot connect to a secondary server, or loses
 the connection, this is the amount of time before it will try to
 connect again.

 @since 6.10
 */
@property (nonatomic, readonly) NSInteger retryDelay;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
