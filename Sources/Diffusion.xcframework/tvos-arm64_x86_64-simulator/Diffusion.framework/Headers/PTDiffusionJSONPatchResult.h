//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2019 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Result of calls to the Partial Update feature.

 See PTDiffusionTopicUpdateFeature::applyJsonPatch:toPath:completionHandler: and
 PTDiffusionTopicUpdateFeature::applyJsonPatch:toPath:withConstraint:completionHandler:

 Check `failedOperation` to determine whether any of the operations failed.

 @since 6.4

 */
@interface PTDiffusionJSONPatchResult : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 @brief an optional NSNumber which if non-null, contains the index of
 the first operation which failed
 */
@property(nonatomic, nullable, readonly) NSNumber *failedOperation;

@end

NS_ASSUME_NONNULL_END
