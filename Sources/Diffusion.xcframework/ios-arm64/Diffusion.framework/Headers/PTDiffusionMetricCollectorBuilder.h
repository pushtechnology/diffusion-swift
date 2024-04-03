//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2021 Push Technology Ltd., All Rights Reserved.
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
 @brief The common base interface for metric collectors.

 @since 6.7
 */
@interface PTDiffusionMetricCollectorBuilder: NSObject


/**
 @brief Resets the builder.

 @return the builder
 */
-(instancetype)reset;


/**
 @brief Specifies whether the metric collector should export metrics
 to Prometheus or not.

 The default is that metrics are not exported to Prometheus.

 @param export true to export metrics to Prometheus.

 @return the builder
 */
-(instancetype)exportToPrometheus:(BOOL)exportToPrometheus;


/**
 @brief Set the maximum number of groups maintained by the metric collector.

 By default, the number of groups is not limited.

 @param limit a positive integer

 @return the builder
 */
-(instancetype)maximumGroups:(NSInteger)limit;


@end

NS_ASSUME_NONNULL_END
