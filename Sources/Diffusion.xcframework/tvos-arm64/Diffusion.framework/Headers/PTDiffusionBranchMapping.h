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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A session tree branch mapping.

 Branch mappings belong to {@link PTDiffusionBranchMappingTable branch mapping tables}.
 Each branch mapping is a pair of a {@link PTDiffusionSession session filter} and the
 target topic tree branch that applies to sessions matching the filter.

 @see PTDiffusionSessionTreesFeature

 @since 6.7
 */
@interface PTDiffusionBranchMapping : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The session filter.
 */
@property (nonatomic, readonly) NSString *sessionFilter;

/**
 The target branch in the topic tree for sessions matching the session filter
 */
@property (nonatomic, readonly) NSString *topicTreeBranch;

@end

NS_ASSUME_NONNULL_END
