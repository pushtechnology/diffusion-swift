//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2019 - 2023 DiffusionData Ltd., All Rights Reserved.
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
 @brief Permissions that protect globally scoped, access-controlled operations.

 There is no related object, permission is granted globally.

 @see PTDiffusionPathPermission

 @since 6.3
 */
@interface PTDiffusionGlobalPermission : PTDiffusionEnumeration

/**
 Add an authentication handler.

 @return Instance indicating the permission to add an authentication handler.

 @since 6.3
 */
+(instancetype)authenticate;

/**
 List or listen to client sessions.

 @return Instance indicating the permission to list of listen to client sessions.

 @since 6.3
 */
+(instancetype)viewSession;

/**
 Alter a client session. This covers a range of actions including:

 - subscribe session to topic
 - throttle session
 - enable conflation for session
 - close session

 @return Instance indicating permission to alter a client session.

 @since 6.3
 */
+(instancetype)modifySession;

/**
 Required to register any server-side handler.

 This restricts clients from consuming resources by registering long lived
 handlers (or example, addMessageHandler). Typically these would never be called
 due to lack of other permissions.

 @return Instance indicating permission to register any server-side handler.

 @since 6.3
 */
+(instancetype)registerHandler;

/**
 View the server's runtime state - for example, read metrics.

 @return Instance indicating permission to view the server's runtime state.

 @since 6.3
 */
+(instancetype)viewServer;

/**
 Change the server's runtime state - for example, shut it down.

 @return Instance indicating permission to change the server's runtime state.

 @since 6.3
 */
+(instancetype)controlServer;

/**
 Read the security configuration.

 @return Instance indicating permission to read the security configuration.

 @since 6.3
 */
+(instancetype)viewSecurity;

/**
 Change the security configuration.

 @return Instance indicating permission to change the security configuration.

 @since 6.3
 */
+(instancetype)modifySecurity;

/**
 A permission that is unsupported by the session.

 @return Instance indicating an unsupported permission by the session.

 @since 6.3
 */
+(instancetype)unknownGlobalPermission;

/**
 Read topic views.

 @return Instance indicating the permission to read topic views.

 @since 6.3
 */
+(instancetype)readTopicViews;

/**
 Modify topic views.

 @return Instance indicating the permission to modify topic views.

 @since 6.3
 */
+(instancetype)modifyTopicViews;

@end

NS_ASSUME_NONNULL_END
