//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2022 - 2023 DiffusionData Ltd., All Rights Reserved.
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
 @brief Defines a retry strategy.

 A retry strategy will be applied when an initial to attempt to open a session
 fails with a SessionEstablishmentTransientException

 The strategy is defined in terms of the number of milliseconds between retries and
 the maximum number of retries to attempt.

 @since 6.9
 */
@interface PTDiffusionRetryStrategy : NSObject <NSCopying>

/**
 The retry strategy that indicates that no retry is to be attempted.
 */
+(instancetype)NO_RETRY;

/**
 Creates a new retry strategy object.

 @param interval    the number of milliseconds before the first retry and between
                    subsequent retries
 @param attempts    the number of retry attempts

 @return            the new retry strategy

 @since 6.9
 */
-(instancetype)initWithInterval:(const NSUInteger) interval andAttempts:(const NSInteger) attempts;


/**
 Creates a new retry strategy that will retry indefinitely at the
 specified interval.

 @param interval    the number of milliseconds before the first retry and between
                    subsequent retries

 @return            the new retry strategy

 @since 6.9
 */
-(instancetype)initWithInterval:(const NSUInteger) interval;


/**
 No retry constructor

 @return            the new retry strategy

 @since 6.9
 */
-(instancetype)init;


/**
 The number of milliseconds between retries

 @since 6.9
 */
@property(nonatomic, readonly) NSUInteger interval;


/**
 The maximum number of retries to attempt

 @since 6.9
 */
@property(nonatomic, readonly) NSInteger attempts;


@end

NS_ASSUME_NONNULL_END
