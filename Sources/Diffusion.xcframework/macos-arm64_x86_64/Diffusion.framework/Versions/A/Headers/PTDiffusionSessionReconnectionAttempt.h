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

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A session reconnection attempt can either be started or aborted.
 
 @see PTDffusionSessionReconnectionStrategy

 @since 5.6
 */
@interface PTDiffusionSessionReconnectionAttempt : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 Request that the session starts the reconnection attempt.

 @since 5.6
 */
-(void)start;

/**
 Request that the session aborts the reconnection attempt.

 @since 5.6
 */
-(void)abort;

@end

NS_ASSUME_NONNULL_END
