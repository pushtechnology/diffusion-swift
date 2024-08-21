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
#import <Diffusion/PTDiffusionSubscriberStreamDelegate.h>

@class PTDiffusionJSONTimeSeriesEvent;
@class PTDiffusionTopicSpecification;
@class PTDiffusionValueStream;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Methods implemented by classes handling streamed time series events with
 JSON values.

 This protocol defines the methods to be implemented by classes wishing to
 receive streamed time series events when updates are received from the server
 with JSON values.
 
 @since 6.0
 */
@protocol PTDiffusionJSONTimeSeriesEventValueStreamDelegate <PTDiffusionSubscriberStreamDelegate>

/**
 An update was received for a topic path handled by a JSON value stream.

 @param stream The value stream that received the update.

 @param topicPath The topic path that was updated.

 @param specification The specification for the updated topic.
 
 @param oldJsonEvent The previous event. If `nil` then this is the first event.
 
 @param newJsonEvent The new event derived from the last update received from
 the server.

 @since 6.0
 */
-(void)          diffusionStream:(PTDiffusionValueStream *)stream
    didUpdateTimeSeriesTopicPath:(NSString *)topicPath
                   specification:(PTDiffusionTopicSpecification *)specification
                    oldJSONEvent:(nullable PTDiffusionJSONTimeSeriesEvent *)oldJsonEvent
                    newJSONEvent:(PTDiffusionJSONTimeSeriesEvent *)newJsonEvent;

@end

NS_ASSUME_NONNULL_END
