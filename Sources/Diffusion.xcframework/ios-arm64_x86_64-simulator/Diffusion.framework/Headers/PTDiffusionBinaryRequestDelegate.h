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
#import <Diffusion/PTDiffusionTopicTreeRegistrationDelegate.h>

@class PTDiffusionBinary;
@class PTDiffusionRequestContext;
@class PTDiffusionResponder;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Methods implemented by classes handling Binary messaging requests with a
 handler registered at the server.
 
 @see PTDiffusionBinary
 @see PTDiffusionMessagingFeature

 @since 6.0
 */
@protocol PTDiffusionBinaryRequestDelegate <PTDiffusionTopicTreeRegistrationDelegate>

/**
 Called when a Binary request has been received.
 
 @param registration The topic tree registration for which this handler applies.

 @param binary The request that was received.
 
 @param context Context object that provides the session ID of the session that
 sent the request along with the path and any requested session properties.
 
 @param responder Responder object to be used for responding to the request.

 @since 6.0
 */
-(void)diffusionTopicTreeRegistration:(PTDiffusionTopicTreeRegistration *)registration
          didReceiveRequestWithBinary:(PTDiffusionBinary *)binary
                              context:(PTDiffusionRequestContext *)context
                            responder:(PTDiffusionResponder *)responder;

@end

NS_ASSUME_NONNULL_END
