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

@class PTDiffusionSession;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A feature is a unit of functionality that is available to a client session.
 
 This is the base interface for features that may be added directly to a client session.
 
 @see PTDiffusionSession

 @since 5.6
 */
@interface PTDiffusionFeature : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The session associated with the receiver.

 @since 5.6
 */
@property(nonatomic, readonly, weak) PTDiffusionSession* session;

@end

NS_ASSUME_NONNULL_END
