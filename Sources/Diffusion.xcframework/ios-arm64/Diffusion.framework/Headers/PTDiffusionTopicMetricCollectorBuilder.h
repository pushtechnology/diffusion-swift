//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2021 - 2022 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;
#import <Diffusion/PTDiffusionMetricCollectorBuilder.h>

@class PTDiffusionTopicMetricCollector;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A topic metric collector builder.

 @since 6.7
 */
@interface PTDiffusionTopicMetricCollectorBuilder: PTDiffusionMetricCollectorBuilder


/**
 Specifies whether the metric collector should group by topic
 type.

 By default, a topic metric collector does not group by topic type.

 @param groupByTopicType true to indicate that the collector
 should group by topic type

 @return the builder

 @since 6.7
 */
-(instancetype)groupByTopicType:(BOOL)groupByTopicType;


/**
 Specifies whether the metric collector should group by topic
 view.

 By default, a topic metric collector does not group by topic view.

 @param groupByTopicView true to indicate that the collector
 should group by topic view

 @return the builder

 @since 6.9
 */
-(instancetype)groupByTopicView:(BOOL)groupByTopicView;


/**
 Specified the number of leading parts of the topic path the
 metric collector should use to group results.

 By default a topic metric collector does not group by the topic
 path prefix. If a positive number of parts is specified, it
 will enable grouping.

 @param parts the number of leading parts of the topic path to
 group by; set to 0 to disable grouping by path

 @return the builder

 @since 6.8
 */
-(instancetype)groupByPathPrefixParts:(NSInteger)parts;


/**
 @brief Create a new {@link PTDiffusionTopicMetricCollector} using the values
 currently known to this builder.

 @param name the name of the {@link PTDiffusionTopicMetricCollector}

 @param topicSelector the selector pattern that specifies the topics for which
 metrics are to be collected.

 @return a new {@link PTDiffusionTopicMetricCollector} with all of the
 current settings of this builder.

 @since 6.7
 */
-(PTDiffusionTopicMetricCollector *) createCollectorWithName:(NSString *const)name
                                            andTopicSelector:(NSString *const)topicSelector;

@end

NS_ASSUME_NONNULL_END
