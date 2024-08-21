//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2018 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionEnumeration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The result of adding a topic.

 @see PTDiffusionTopicControlFeature

 @since 6.1
 */
@interface PTDiffusionAddTopicResult : PTDiffusionEnumeration

/**
 A new topic was created.

 @return Instance indicating a new topic was created.

 @since 6.1
 */
+(instancetype)created;

/**
 A topic with the same specification already exists.

 @return Instance indicating a topic with the same specification
         already exists.

 @since 6.1
 */
+(instancetype)exists;

@end

NS_ASSUME_NONNULL_END
