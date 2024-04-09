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

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A request to be sent using messaging.

 @see PTDiffusionBinary
 @see PTDiffusionJSON
 @see PTDiffusionMessagingFeature
 @see PTDiffusionPrimitive
 @see PTDiffusionRecordV2

 @since 6.0
 */
@interface PTDiffusionRequest : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
