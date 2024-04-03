//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionEnumeration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Represents the current connection state of the remote server

 This is used by the Remote Servers feature

 @since 6.5
 */
@interface PTDiffusionRemoteServerConnectionState : PTDiffusionEnumeration


/**
 The connection is inactive.

 This means that the remote server can successfully connect but a
 physical connection is not being maintained as there are no
 components that require the remote server.

 If in an inactive or failed state, a test connection will have
 been tried to check that the connection can be made and the
 connection will then have been closed.

 @return Instance representing the inactive connection state.

 @since 6.5
 */
+(instancetype)inactive;


/**
 The remote server is connected and actively in use by components
 that require it.

 @return Instance representing the connected connection state.

 @since 6.5
 */
+(instancetype)connected;


/**
 The connection has failed but a retry is scheduled.

 In this case `[PTDiffusionCheckRemoteServerResult failureMessage]`
 will provide details of the failure that resulted in a retry.

 @return Instance representing the retrying connection state.

 @since 6.5
 */
+(instancetype)retrying;


/**
 The connection failed to establish.

 If the connection was in an inactive or failed state state, a
 test connection was tried and failed.

 In this case `[PTDiffusionCheckRemoteServerResult failureMessage]`
 will provide more detail.

 @return Instance representing the failed connection state.

 @since 6.5
 */
+(instancetype)failed;


/**
 The named remote server did not exist.

 @return Instance representing the remote server missing connection state.

 @since 6.5
 */
+(instancetype)missing;

@end

NS_ASSUME_NONNULL_END
