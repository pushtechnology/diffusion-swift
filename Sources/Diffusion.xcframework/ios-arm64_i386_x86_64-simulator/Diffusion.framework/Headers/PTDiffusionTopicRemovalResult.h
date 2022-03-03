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

@import Foundation;

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
