//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;

@class PTDiffusionRegistration;
@class PTDiffusionClientQueuePolicy;
@class PTDiffusionSessionId;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Listener for client message queue events from the server.

 @see PTDiffusionClientControlFeature

 @since 6.6
 */
@protocol PTDiffusionClientQueueEventListener


/**
 Called when the message queue policy changes

 @param registration The message queue event listener registration for which this listener applies

 @param policy The new message queue policy for the session

 @param sessionId The session ID of the affected session

 @since 6.6
 */
-(void)diffusionQueueEventListenerRegistration:(PTDiffusionRegistration *)registration
                         didReportPolicyChange:(PTDiffusionClientQueuePolicy *)policy
                                    forSession:(PTDiffusionSessionId *)sessionId;


/**
 Called if the handler is closed.

 No further calls will be made to this handler.

 @param registration The message queue event listener registration for which this listener applies

 @since 6.6
 */
-(void)diffusionQueueEventListenerRegistrationDidClose:(PTDiffusionRegistration *)registration;



/**
 Called in the event of a contextual error relating to this handler.

 No further calls will be made to this handler.

 @param registration The message queue event listener registration for which this listener applies.

 @param error The failure reason.

 @since 6.6
 */
-(void)diffusionQueueEventListenerRegistration:(PTDiffusionRegistration *)registration
                              didFailWithError:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
