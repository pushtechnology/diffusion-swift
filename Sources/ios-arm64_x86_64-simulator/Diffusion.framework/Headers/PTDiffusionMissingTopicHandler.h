//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2016 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionTopicTreeRegistrationDelegate.h>

@class PTDiffusionMissingTopicNotification;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Handler called when a client session subscribes or fetches using a topic
 selector that matches no topics.
 
 @see PTDiffusionTopicControlFeature

 @since 5.7
 */
@protocol PTDiffusionMissingTopicHandler <PTDiffusionTopicTreeRegistrationDelegate>

/**
 Called when a session requests a topic that does not exist, and the
 topic path belongs to part of the topic tree for which this handler
 was registered.

 @param registration The topic tree registration for which this handler applies.

 @param notification The missing topic notification.

 @since 5.7
 */
-(void)diffusionTopicTreeRegistration:(PTDiffusionTopicTreeRegistration *)registration
          hadMissingTopicNotification:(PTDiffusionMissingTopicNotification *)notification;

@end

NS_ASSUME_NONNULL_END
