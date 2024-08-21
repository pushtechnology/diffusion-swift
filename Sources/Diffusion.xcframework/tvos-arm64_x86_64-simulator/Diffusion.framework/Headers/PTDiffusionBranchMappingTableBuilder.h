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

@class PTDiffusionBranchMappingTable;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Builder for {@link PTDiffusionBranchMappingTable} instances.

 @see PTDiffusionSessionTrees

 @since 6.7
 */
@interface PTDiffusionBranchMappingTableBuilder : NSObject


+(instancetype)new;

-(instancetype)init;


/**
 @brief Resets the builder.

 @return the builder
 */
-(instancetype)reset;


/**
 @brief Add a new branch mapping.

 @param sessionFilter the session filter
 
 @param topicTreeBranch the target branch in the topic tree for sessions
 matching the session filter

 @return the builder
 */
-(instancetype)addBranchMappingWithSessionFilter:(NSString *const)sessionFilter
                                 topicTreeBranch:(NSString *const)topicTreeBranch;


/**
 @brief Create a new {@link PTDiffusionBranchMappingTable}.

 @param sessionTreeBranch the session tree branch

 @return a branch mapping table
 */
-(PTDiffusionBranchMappingTable *) createTableForSessionTreeBranch:(NSString *const)sessionTreeBranch;


@end

NS_ASSUME_NONNULL_END
