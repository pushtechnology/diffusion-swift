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
#import <Diffusion/PTDiffusionSessionResponseStreamDelegate.h>

@class PTDiffusionJSON;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Methods implemented by classes handling JSON messaging responses from
 individual sessions.

 @see PTDiffusionJSON
 @see PTDiffusionMessagingFeature

 @since 6.1
 */
@protocol PTDiffusionJSONSessionResponseStreamDelegate <PTDiffusionSessionResponseStreamDelegate>

/**
 Called when a session responds to a request with JSON.

 @param stream The stream that received the response.

 @param json The response that was received.

 @param sessionId The id of the responding session.

 @since 6.1
 */
-(void)          diffusionStream:(PTDiffusionStream *)stream
      didReceiveResponseWithJSON:(PTDiffusionJSON *)json
                   fromSessionId:(PTDiffusionSessionId *)sessionId;

@end

NS_ASSUME_NONNULL_END
