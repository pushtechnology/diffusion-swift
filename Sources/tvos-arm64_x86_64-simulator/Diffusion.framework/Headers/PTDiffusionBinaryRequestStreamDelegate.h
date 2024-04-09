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
#import <Diffusion/PTDiffusionStreamDelegate.h>

@class PTDiffusionBinary;
@class PTDiffusionResponder;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Methods implemented by classes handling Binary messaging requests.

 @see PTDiffusionBinary
 @see PTDiffusionMessagingFeature

 @since 6.0
 */
@protocol PTDiffusionBinaryRequestStreamDelegate <PTDiffusionStreamDelegate>

/**
 Called when a Binary request has been received.
 
 @param stream The stream that received the request.

 @param binary The request that was received.
 
 @param responder Responder object to be used for responding to the request.

 @since 6.0
 */
-(void)         diffusionStream:(PTDiffusionStream *)stream
    didReceiveRequestWithBinary:(PTDiffusionBinary *)binary
                      responder:(PTDiffusionResponder *)responder;

@end

NS_ASSUME_NONNULL_END
