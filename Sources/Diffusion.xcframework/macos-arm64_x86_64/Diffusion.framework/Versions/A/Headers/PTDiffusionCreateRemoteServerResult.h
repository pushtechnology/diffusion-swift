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

@class PTDiffusionRemoteServer;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Interface for the result from the creation of a remote server.

 This is used by the Remote Servers feature.

 @since 6.5
 */
@interface PTDiffusionCreateRemoteServerResult : NSObject


/**
 The remote server.

 @since 6.5
 */
@property (nonatomic, readonly) PTDiffusionRemoteServer *remoteServer;


/**
 Whether the response successfully creates a remote server or not.

 @since 6.5
 */
@property (nonatomic, readonly, getter=isSuccess) BOOL success;


/**
 The list of errors resulting from attempting to create a remote server.

 @since 6.5
 */
@property (nonatomic, readonly) NSArray<NSError *> *errors;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
