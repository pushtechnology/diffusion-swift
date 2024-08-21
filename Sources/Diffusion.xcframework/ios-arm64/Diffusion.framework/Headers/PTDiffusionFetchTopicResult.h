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

@class PTDiffusionTopicSpecification;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Encapsulates the result from a fetch operation for a single selected
 topic.

 @since 6.2
 */
@interface PTDiffusionFetchTopicResult : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The topic path.

 @since 6.2
 */
@property(nonatomic, readonly) NSString* path;

/**
 The topic specification.

 If the request specified PTDiffusionFetchRequest#withProperties, the result
 reflects the topic's specification and can be used to create an identical
 topic. If the request did not specify that properties were to be included, the
 specification's property map will be empty.

 @since 6.2
 */
@property(nonatomic, readonly) PTDiffusionTopicSpecification* specification;

@end

NS_ASSUME_NONNULL_END
