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

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Reports the number of topics removed by a call to
 {@link PTDiffusionTopicControlFeature#removeTopicsWithTopicSelectorExpression:completionHandler:
 removeTopicsWithTopicSelectorExpression}

 @since 6.6
 */
@interface PTDiffusionTopicRemovalResult : NSObject


+(instancetype)new NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;

/**
 The integer returned represents the number of topics removed by the
 operation. This does not include any derived topics created by a
 topic view which were removed as a side effect of this action.
 */
@property (nonatomic, readonly) NSUInteger removedCount;

@end

NS_ASSUME_NONNULL_END
