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

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionRegistration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A reference to a handler registered for a particular set of
 session properties

 A topic tree registration is provided once a handler with a server-side
 presence has been registered.

 @since 6.5
 */

@interface PTDiffusionSessionPropertiesListenerRegistration : PTDiffusionRegistration

/**
 The set of session properties registered.

 @since 6.5
 */
@property(nonatomic, readonly) NSArray<NSString *>* properties;

@end

NS_ASSUME_NONNULL_END
