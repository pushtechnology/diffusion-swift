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

NS_ASSUME_NONNULL_BEGIN

/**
 The type definition for a block accepting formatted log messages.
 
 @see PTDiffusionLoggingDestinationConfiguration

 @since 6.0
 */
typedef void (^PTDiffusionLoggingMessagePrinter)(NSString* message);

NS_ASSUME_NONNULL_END
