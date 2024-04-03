//  Diffusion Client Library for iOS, OS X and tvOS
//
//  Copyright (c) 2019 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionJSON;
@class PTDiffusionJSONDeltaChangeMap;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief An immutable structural delta describing the differences between two
 JSON values.

 Unlike a binary delta, a structural delta can be queried to determine its
 effect.

 JSON deltas are useful for identifying small changes to complex JSON values.

 @see PTDiffusionJSON

 @since 6.3
 */
@interface PTDiffusionJSONDelta : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The parts of the first JSON value not found in the second JSON value.

 @note The pointer references used for the change map keys are relative to the
 first JSON value.

 @since 6.3
 */
@property(nonatomic, readonly) PTDiffusionJSONDeltaChangeMap* removed;

/**
 The parts of the second JSON value not found in the first JSON value.

 @note The pointer references used for the change map keys are relative to the
 second JSON value.

 @since 6.3
 */
@property(nonatomic, readonly) PTDiffusionJSONDeltaChangeMap* inserted;

/**
 Whether the two JSON values used to create this instance are different.

 @since 6.3
 */
@property(nonatomic, readonly, getter=hasChanges) BOOL changes;

@end

NS_ASSUME_NONNULL_END
