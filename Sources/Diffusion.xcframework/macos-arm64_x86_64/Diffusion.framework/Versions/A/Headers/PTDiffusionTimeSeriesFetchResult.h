//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2018 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionFetchResult.h>

@class PTDiffusionTimeSeriesFetchTopicResult;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Encapsulates the results from a time series fetch operation issued to
 the server.

 A time series fetch operation is issued using the
 PTDiffusionFetchRequest#fetchTimeSeriesEventsWithTopicSelectorExpression:completionHandler:
 method.

 @since 6.3
 */
@interface PTDiffusionTimeSeriesFetchResult : PTDiffusionFetchResult

/**
 The results from the fetch operation, in path order, each representing a single
 topic selected by the fetch operation.

 @since 6.3
 */
@property(nonatomic, readonly) NSArray<PTDiffusionTimeSeriesFetchTopicResult *> * timeSeriesResults;

@end

NS_ASSUME_NONNULL_END
