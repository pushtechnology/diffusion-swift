//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2017 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionTimeSeriesEvent.h>

@class PTDiffusionJSON;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief An event in a time series whose value may be interpreted as JSON.

 @since 6.0
 */
@interface PTDiffusionJSONTimeSeriesEvent : PTDiffusionTimeSeriesEvent

/**
 The JSON value associated with the event.

 @since 6.0
 */
@property(nonatomic, readonly) PTDiffusionJSON* json;

@end

NS_ASSUME_NONNULL_END
