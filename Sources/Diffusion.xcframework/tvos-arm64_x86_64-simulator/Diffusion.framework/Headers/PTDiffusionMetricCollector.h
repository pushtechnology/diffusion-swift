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

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The common base interface for metric collectors.

 @since 6.7
 */
@interface PTDiffusionMetricCollector: NSObject


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


/**
 Name of the metric collector

 @since 6.7
 */
@property(nonatomic, readonly) NSString *name;


/**
 Indicates whether the metric collector exports to Prometheus.

 @since 6.7
 */
@property(nonatomic, readonly) BOOL exportsToPrometheus;


/**
 @brief Limit the number of groups maintained by this metric collector.

 Session metric collectors can {@link PTDiffusionSessionMetricCollector#groupByProperties
 group metrics by property}.
 Topic metric collectors can {@link PTDiffusionSessionTopicCollector#groupsByTopicType
 group metrics by topic type}.
 This property places an upper limit on the number of groups that will be maintained for the
 metric collector.

 For example, if a session metric collector groups by `$SessionId` and `maximumGroups` is 10,
 then metrics will only be collected for the first 10 sessions.

 @since 6.8
 */
@property(nonatomic, readonly) NSInteger maximumGroups;


@end

NS_ASSUME_NONNULL_END
