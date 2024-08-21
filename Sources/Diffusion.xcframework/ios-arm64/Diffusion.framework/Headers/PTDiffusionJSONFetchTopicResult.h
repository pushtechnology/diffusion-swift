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
#import <Diffusion/PTDiffusionFetchTopicResult.h>

@class PTDiffusionJSON;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Encapsulates the result from a JSON fetch operation for a single
 selected topic.

 A JSON fetch operation is issued using the
 PTDiffusionFetchRequest#fetchJSONValuesWithTopicSelectorExpression:completionHandler:
 method.

 @since 6.2
 */
@interface PTDiffusionJSONFetchTopicResult : PTDiffusionFetchTopicResult

/**
 Returns the topic value, or `nil` if the topic has no value.

 @since 6.2
 */
@property(nonatomic, readonly, nullable) PTDiffusionJSON* json;

@end

NS_ASSUME_NONNULL_END
