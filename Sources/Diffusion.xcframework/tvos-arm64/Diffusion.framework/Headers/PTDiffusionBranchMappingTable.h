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

@import Foundation;

@class PTDiffusionBranchMapping;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A session tree branch mapping table.

 A branch mapping table is a list of {@link PTDiffusionBranchMapping branch mappings}
 assigned to a session tree branch

 To create a branch mapping table, obtain a new a builder instance using
 {@link PTDiffusionBranchMappingTableBuilder}, call
 {@link PTDiffusionBranchMappingTableBuilder#addBranchMappingWithSessionFilter:targetPath:
 addBranchMapping} for each branch mapping, then
 {@link PTDiffusionBranchMappingTableBuilder#createTableForSessionTreeBranch: createTable}.
 The result can then be sent to the server using
 {@link PTDiffusionSessionTreesFeature#putBranchMappingTable: putBranchMappingTable}

 @see PTDiffusionSessionTreesFeature

 @since 6.7
 */
@interface PTDiffusionBranchMappingTable : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The branch of the session tree to which this table is bound
 */
@property (nonatomic, readonly) NSString *sessionTreeBranch;

/**
 The branch mappings
 */
@property (nonatomic, readonly) NSArray<PTDiffusionBranchMapping *> *branchMappings;

@end

NS_ASSUME_NONNULL_END
