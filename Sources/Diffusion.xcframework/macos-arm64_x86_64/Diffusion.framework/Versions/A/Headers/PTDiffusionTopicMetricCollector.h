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
 @brief The definition of a topic metric collector.

 These can be configured to record metric data for a subset of all
 topics, specified with a topic selector.

 @since 6.7
 */
@interface PTDiffusionTopicMetricCollector : PTDiffusionMetricCollector

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


/**
 The topic selector.

 @since 6.7
 */
@property(nonatomic, readonly) NSString *topicSelector;


/**
 Indicates whether the collector groups by topic type.

 @since 6.7
 */
@property(nonatomic, readonly) BOOL groupsByTopicType;


/**
 Indicates whether the collector groups by topic view.

 @since 6.9
 */
@property(nonatomic, readonly) BOOL groupsByTopicView;


/**
 @brief The number of leading parts of the topic path to group by.

 The number of leading parts of the topic pathh to group by,
 or 0 if the collector does not group by path prefix.

 @since 6.8
 */
@property(nonatomic, readonly) NSInteger groupByPathPrefixParts;





@end

NS_ASSUME_NONNULL_END
