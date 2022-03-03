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

@class PTDiffusionSessionPropertiesListenerRegistration;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Common protocol for delegates that establish a server side control presence for the
 client session at a particular set of session properties.

 @since 6.5
 */
@protocol PTDiffusionSessionPropertiesListenerRegistrationDelegate

/**
 Called if the handler is closed.

 No further calls will be made to this handler.

 @param registration The session properties registration for which this delegate applies.

 @since 6.5
 */
-(void)diffusionSessionPropertiesListenerRegistrationDidClose:(PTDiffusionSessionPropertiesListenerRegistration *)registration;

/**
 Called in the event of a contextual error relating to this handler.

 No further calls will be made to this handler.

 @param registration The session properties registration for which this delegate applies.

 @param error The failure reason.

 @since 6.5
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                     didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
