//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionSessionId.h>
#import <Diffusion/PTDiffusionCloseReason.h>
#import <Diffusion/PTDiffusionSessionPropertiesListenerRegistrationDelegate.h>
#import <Diffusion/PTDiffusionSessionPropertiesListenerRegistration.h>


NS_ASSUME_NONNULL_BEGIN

/**
 @brief Listener for Session properties events from the server.

 @see PTDiffusionClientControlFeature

 @since 6.5
 */
@protocol PTDiffusionSessionPropertiesDelegate <PTDiffusionSessionPropertiesListenerRegistrationDelegate>

/**
 A new session was opened

 @param registration The session properties registration for which this listener applies

 @param sessionId The session ID of the opened session

 @param properties The properties for the opened session

 @since 6.5
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                        sessionOpened:(PTDiffusionSessionId *)sessionId
                                       withProperties:(NSDictionary<NSString *, id>*)properties;


/**
 A session has closed

 @param registration The session properties registration for which this listener applies

 @param sessionId The session ID of the closed session

 @param closeReason The reason why the session closed

 @param properties The properties for the closed session

 @since 6.5
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                        sessionClosed:(PTDiffusionSessionId *)sessionId
                                      withCloseReason:(PTDiffusionCloseReason *) closeReason
                                        andProperties:(NSDictionary<NSString *, id>*)properties;



/**
 A session has been updated

 @param registration The session properties registration for which this listener applies

 @param sessionId The session ID of the updated session

 @param properties The properties for the updated session

 @since 6.5
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                       sessionUpdated:(PTDiffusionSessionId *)sessionId
                                       withProperties:(NSDictionary<NSString *, id>*)properties;


/**
 A session has disconnected

 @param registration The session properties registration for which this listener applies

 @param sessionId The session ID of the disconnected session

 @param properties The properties for the disconnected session

 @since 6.5
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                  sessionDisconnected:(PTDiffusionSessionId *)sessionId
                                       withProperties:(NSDictionary<NSString *, id>*)properties;


/**
 A session has reconnected

 @param registration The session properties registration for which this listener applies

 @param sessionId The session ID of the reconnected session

 @param properties The properties for the reconnected session

 @since 6.6
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                   sessionReconnected:(PTDiffusionSessionId *)sessionId
                                       withProperties:(NSDictionary<NSString *, id>*)properties;


/**
 A session has failed over to a different host

 @param registration The session properties registration for which this listener applies

 @param sessionId The session ID of the failed over session

 @param properties The properties for the failed over session

 @since 6.6
 */
-(void)diffusionSessionPropertiesListenerRegistration:(PTDiffusionSessionPropertiesListenerRegistration *)registration
                                    sessionFailedOver:(PTDiffusionSessionId *)sessionId
                                       withProperties:(NSDictionary<NSString *, id>*)properties;




@end

NS_ASSUME_NONNULL_END

