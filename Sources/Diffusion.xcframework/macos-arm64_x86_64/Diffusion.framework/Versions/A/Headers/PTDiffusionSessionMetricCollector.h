//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2021 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionMetricCollector.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The definition of a session metric collector.

 These can be configured to record metric data for a subset of all
 sessions, specified with a session filter.

 @since 6.7
 */
@interface PTDiffusionSessionMetricCollector : PTDiffusionMetricCollector

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


/**
 The session filter.

 @since 6.7
 */
@property(nonatomic, readonly) NSString *sessionFilter;


/**
 The list of properties to group by.

 @since 6.7
 */
@property(nonatomic, readonly) NSArray<NSString *>* groupByProperties;


/**
 Indicates whether metrics with no matches should be removed.

 @since 6.7
 */
@property(nonatomic, readonly) BOOL removesMetricsWithNoMatches;


@end

NS_ASSUME_NONNULL_END
