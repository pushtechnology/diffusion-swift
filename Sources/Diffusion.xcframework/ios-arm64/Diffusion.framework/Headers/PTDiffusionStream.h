//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2015 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@protocol PTDiffusionStreamDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A stream represents an asynchronous, variable length feed of updates from the
 Diffusion server.

 @see PTDiffusionTopicsFeature
 @see PTDiffusionMessagingFeature

 @since 5.6
 */
@interface PTDiffusionStream : NSObject <NSCopying>

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The delegate receiving the streaming updates for the receiver.

 @since 5.6
 */
@property(nonatomic, readonly, weak) id<PTDiffusionStreamDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
