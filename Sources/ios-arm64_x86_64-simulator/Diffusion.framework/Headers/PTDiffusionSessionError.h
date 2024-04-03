//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2017 - 2022 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The value assigned to the `domain` property of NSError objects generated when
 establishing or reestablishing a session's connection to the server.
 
 @see PTDiffusionSessionErrorCode

 @since 6.0

 @deprecated since 6.7, use PTDiffusion instead.
 */
extern NSString *const PTDiffusionSessionErrorDomain __deprecated_msg("Use PTDiffusion instead.");

/**
 Values assigned to the `code` property of NSError objects generated when
 establishing or reestablishing a session's connection to the server.
 
 @see PTDiffusionSessionErrorDomain

 @since 6.0

 @deprecated since 6.7 Use PTDiffusionError instead.
 */
typedef NS_ENUM(NSInteger, PTDiffusionSessionErrorCode) {
    /**
     The session was closed after being unexpectedly disconnected.

     @since 6.0

     @deprecated since 6.7, use @deprecated since 6.7, use PTDiffusionError_Disconnected instead. instead.
     */
    PTDiffusionSessionErrorCode_Disconnected __deprecated_enum_msg("Use PTDiffusionError_Disconnected instead.") = 2,

    /**
     The session was closed locally.

     @since 6.0

     @deprecated since 6.7, use @deprecated since 6.7, use PTDiffusionError_ClosedByClient instead. instead.
     */
    PTDiffusionSessionErrorCode_ClosedByClient __deprecated_enum_msg("Use PTDiffusionError_ClosedByClient instead.") = 3,

    /**
     There was a problem when establishing a session.

     The session is closed. No further operations are possible.
     
     @since 6.0

     @deprecated since 6.7, use PTDiffusionError_Establishment instead.
     */
    PTDiffusionSessionErrorCode_Establishment __deprecated_enum_msg("Use PTDiffusionError_Establishment instead.") = 4,

    /**
     The session operation failed due to a security constraint.
     
     Repeating the operation with the same security credentials is likely to
     fail.

     @since 6.0

     @deprecated since 6.7, use PTDiffusionError_Security instead.
     */
    PTDiffusionSessionErrorCode_Security __deprecated_enum_msg("Use PTDiffusionError_Security instead.") = 5,

    /**
     The session operation failed due to an unrecognised response code.

     @since 6.3

     @deprecated since 6.7, use PTDiffusionError_UnrecognizedResponseCode instead.
     */
    PTDiffusionSessionErrorCode_UnrecognisedResponseCode __deprecated_enum_msg("Use PTDiffusionError_UnrecognizedResponseCode instead.") = 6,

    /**
     The session was closed remotely.

     @since 6.6

     @deprecated since 6.7, use PTDiffusionError_ClosedByServer instead.
     */
    PTDiffusionSessionErrorCode_ClosedByServer __deprecated_enum_msg("Use PTDiffusionError_ClosedByServer instead") = 7,
};

NS_ASSUME_NONNULL_END
