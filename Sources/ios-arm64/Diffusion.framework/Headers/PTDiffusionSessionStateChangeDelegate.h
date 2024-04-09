//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionSession;
@class PTDiffusionSessionState;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The optional delegate for a session which may be used to receive state notifications.

 By default a session will not have a listener.

 @since 6.10
 */
@protocol PTDiffusionSessionStateChangeDelegate


/**
 Called whenever the state of a session changes.

 @param session         the session
 @param previousState   the previous state
 @param state           the current state

 @since 6.10
 */
-(void)onSession:(PTDiffusionSession *)session
 stateChangeFrom:(PTDiffusionSessionState *)previousState
              to:(PTDiffusionSessionState *)state;


@end

NS_ASSUME_NONNULL_END
