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
#import <Diffusion/PTDiffusionDefaultStreamDelegate.h>
#import <Diffusion/PTDiffusionTopicNotificationListener.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Default delegate implementation which may be used as an abstract base
 for sub-protocol implementations.

 It logs received messages at PTDiffusionLoggingLevel::debug level.

 @see PTDiffusionLogging

 @since 6.1
 */
@interface PTDiffusionDefaultTopicNotificationListener : PTDiffusionDefaultStreamDelegate <PTDiffusionTopicNotificationListener>

@end

NS_ASSUME_NONNULL_END
