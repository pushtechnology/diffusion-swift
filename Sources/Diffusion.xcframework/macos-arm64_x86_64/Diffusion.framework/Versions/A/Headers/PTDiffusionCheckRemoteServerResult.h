//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionRemoteServer;
@class PTDiffusionRemoteServerConnectionState;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Interface for the result of checking the state
        of a remote server

 This is used by the Remote Servers feature

 @since 6.5
 */
@interface PTDiffusionCheckRemoteServerResult : NSObject


/**
 The remote server's connection state

 @since 6.5
 */
@property (nonatomic, readonly) PTDiffusionRemoteServerConnectionState *state;


/**
 Message from the server if the connection state for
 the specified remote server is `failed` or `retrying`.

 @since 6.5
 */
@property (nonatomic, readonly) NSString *failureMessage;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
