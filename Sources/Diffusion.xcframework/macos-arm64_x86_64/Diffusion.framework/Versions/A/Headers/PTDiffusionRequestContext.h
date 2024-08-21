//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2017 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionSessionId;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A request context provides additional contextual information for
 received messaging requests.

 @since 6.0
 */
@interface PTDiffusionRequestContext : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The ID of the session that sent the request.
 
 @since 6.0
 */
@property(nonatomic, readonly) PTDiffusionSessionId* sessionId;

/**
 The message path of the request.
 
 @since 6.0
 */
@property(nonatomic, readonly) NSString* path;

/**
 Properties of the session that sent the request.

 @since 6.0
 */
@property(nonatomic, readonly) NSDictionary<NSString *, NSString *>* sessionProperties;

@end

NS_ASSUME_NONNULL_END
