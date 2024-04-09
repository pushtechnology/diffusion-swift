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
#import <Diffusion/PTDiffusionMetricCollectorBuilder.h>

@class PTDiffusionSessionMetricCollector;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A session metric collector builder.

 @since 6.7
 */
@interface PTDiffusionSessionMetricCollectorBuilder: PTDiffusionMetricCollectorBuilder


/**
 Adds the name of a session property to group by to the list known
 to this builder.

 @param propertyName the name of the session property.
 See {@link PTDiffusionSession Session} for details of session properties.

 @return the builder

 @since 6.7
 */
-(instancetype)groupByProperty:(NSString *)propertyName;


/**
 Specifies a list of session property names to group by, replacing
 any current list known to this builder.

 @param propertyNames a list of session property names.
 See {@link PTDiffusionSession Session} for details of session properties.

 @return the builder

 @since 6.7
 */
-(instancetype)groupByProperties:(NSArray<NSString *>*) propertyNames;


/**
 Specifies whether the metric collector should remove any metrics
 that have no matches.

 The default is that the metric collector will not remove metrics
 with no matches.

 @param remove true to indicate that metrics with no matches
 should be removed.

 @return the builder

 @since 6.7
 */
-(instancetype)removeMetricsWithNoMatches:(BOOL)remove;


/**
 @brief Create a new {@link PTDiffusionSessionMetricCollector} using the values
 currently known to this builder.

 @param name the name of the {@link PTDiffusionSessionMetricCollector}

 @param sessionFilter the session filter indicating the sessions
 this filter should apply to. The format of a session property
 filter is documented in {@link PTDiffusionSession}

 @return a new {@link PTDiffusionSessionMetricCollector} with all of the
 current settings of this builder.

 @since 6.7
 */
-(PTDiffusionSessionMetricCollector *) createCollectorWithName:(NSString *const)name
                                              andSessionFilter:(NSString *const)sessionFilter;

@end

NS_ASSUME_NONNULL_END
