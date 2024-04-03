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
#import <Diffusion/PTDiffusionFeature.h>

@class PTDiffusionBranchMappingTable;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This feature allows a client session to configure session trees.

 A session tree is a virtual view of the topic tree presented to a session by
 fetch and subscription operations. Custom session trees for different
 sessions can be configured using declarative rules maintained by the server
 to meet data security, data optimisation, or personalisation and localisation
 requirements. Each session can be presented with a unique session tree based
 on its session properties.

 A session tree is produced by applying <em>branch mappings</em> to the topic
 tree. Branch mappings are organised into <em>branch mapping tables</em>. Each
 branch mapping table is assigned to a unique path – the <em>session tree branch</em>.

 A session tree is composed of <em>session paths</em>. Each session path is
 mapped via the branch mapping tables to a unique <em>topic path</em>.

 A branch mapping table is an ordered list of (session filter, topic tree branch)
 pairs. For example, the branch mapping table for the session tree branch
 <code>market/prices</code> might be:

 <pre>
 Session filter                           Topic tree branch
 =========                                =============
 USER_TIER is '1' or $Country is 'DE'     backend/discounted_prices
 USER_TIER is '2'                         backend/standard_prices
 $Principal is ''                         backend/delayed_prices
 </pre>

 With this configuration, if an unauthenticated session (one that matches the
 <code>$Principal is ''</code> session filter) subscribes to the session path
 <code>market/prices/X</code>, and there is a topic bound to the topic path
 <code>backend/delayed_prices/X</code>, the subscription will complete. The session
 will receive a subscription notification under the session path
 <code>market/prices/X</code>, together with the topic properties and the value of
 the topic. The session is unaware that the data originates from a topic bound
 to a different topic path. If no topic is bound to
 <code>backend/delayed_prices/X</code>, the subscription will not resolve and the
 session will receive no data, even if there is a topic bound to
 <code>market/prices/X</code>.

 Session trees complement the data transformation capabilities of
 {@link PTDiffusionTopicViewsFeature topic views}. In our example, the time delayed
 time feed at <code>backend/delayed_prices</code> could be maintained by a topic
 view using the <em>delay by</em> clause.

 Branch mappings are persisted by the server and shared across a cluster, in a
 similar manner to topic views, security stores, and metric collectors. Branch
 mappings are editable using this feature, and via the management console.

 For a given session and session path, at most one branch mapping applies. The
 applicable branch mapping is chosen as follows:
 <ul>
 <li>Each branch mapping table with session tree branch that is a prefix of the
 session path is considered. For a given table, the first branch mapping with
 a condition that matches the session's properties is the one that applies. A
 branch mapping table may have no applicable branch mappings for a session.
 <li>If there are several such branch mapping tables with a branch mapping
 that for the session, the one with the longest prefix of the session path
 applies.
 <li>If no branch mapping table has a branch mapping for the session, the
 session path is translated to the identical topic path.
 </ul>

 ### Access control

 To subscribe to or fetch from a session path, a session must be granted the
 appropriate path permission to the session path for the operation
 ({@link PTDiffusionPathPermission#selectTopic SELECT_TOPIC}, or
 {@link PTDiffusionPathPermission#readTopic READ_TOPIC}). The session
 doesn't require any permissions to the topic path of the topic providing
 the data.

 To create or replace branch mappings, a session needs the
 {@link PTDiffusionPathPermission#modifyTopic MODIFY_TOPIC} path permission
 for the session tree branch of the branch mapping table,
 {@link PTDiffusionPathPermission#exposeBranch EXPOSE_BRANCH} path permission
 for the topic tree branch of each branch mapping, and (if an existing table with
 the same session tree branch is being replaced)
 {@link PTDiffusionPathPermission#exposeBranch EXPOSE_BRANCH} permission for
 each branch mapping of existing table.

 To retrieve a branch mapping table, a session needs the
 {@link PTDiffusionPathPermission#readTopic READ_TOPIC} path permission for
 its session tree branch.

 ### Accessing the feature

 This feature may be obtained from a {@link PTDiffusionSession session} as follows:
 <pre>
 PTDiffusionSessionTreesFeature *const sessionTrees = session.sessionTrees;
 </pre>

 @see PTDiffusionSession

 @since 6.7
 */
@interface PTDiffusionSessionTreesFeature : PTDiffusionFeature

/**
 @brief Create or replace a branch mapping table.

 The server ensures that there is at most one branch mapping table for a
 session tree branch. Putting a new branch mapping table will replace any previous
 branch mapping table with the same session tree branch. To remove all branch
 mappings for a session tree branch, put an empty branch mapping table.

 @param branchMappingTable the new table

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>InvalidBranchMappingError &ndash; if branchMappingTable or one of its
        branch mappings is invalid;
    <li>SessionSecurityError &ndash; if the calling
        session does not have the {@link PTDiffusionPathPermission#modifyTopic
        MODIFY_TOPIC} permission for the session tree branch of the branch
        mapping table, {@link PTDiffusionPathPermission#exposeBranch EXPOSE_BRANCH}
        permission for each branch mapping of branchMappingTable, and (if
        there is an existing table for the session tree branch)
        {@link PTDiffusionPathPermission#exposeBranch EXPOSE_BRANCH} permission for
        each branch mapping of existing table;
    <li>ClusterRoutingError &ndash; if the operation failed due to a transient
        cluster error;
    <li>SessionClosedError &ndash; if the session is closed.
 </ul>

 @since 6.7
*/
-(void) putBranchMappingTable:(PTDiffusionBranchMappingTable *)branchMappingTable
            completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;


/**
 @brief Retrieve the session tree branches of the server's branch mapping tables.

 The results will only include the session tree branches of branch mapping tables
 that have at least one branch mapping and for which the calling session
 has {@link PTDiffusionPathPermission#readTopic READ_TOPIC} path permission for
 the session tree branch.

 Individual branch mapping tables can be retrieved using
 {@link #getBranchMappingTableForSessionTreeBranch:completionHandler: getBranchMappingTable}.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and the `sessionTreeBranches` argument will not be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>SessionClosedError &ndash; if the session is closed.
 </ul>

 @since 6.7
*/
-(void) getSessionTreeBranchesWithMappings:(void (^)(NSArray<NSString *> * _Nullable sessionTreeBranches, NSError * _Nullable error)) completionHandler;


/**
 @brief Retrieve a branch mapping table from the server.

 If there is no branch mapping table at the given session tree branch, this
 method will return an empty branch mapping table.

 @param sessionTreeBranch the session tree branch that identifies the branch mapping
 table

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and the `branchMappingTable` argument will not be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>SessionSecurityError &ndash; if the calling
        session does not have the {@link PTDiffusionPathPermission#readTopic
        READ_TOPIC} permission for the session tree branch;
    <li>SessionClosedError &ndash; if the session is closed.
 </ul>

 @since 6.7
*/
-(void) getBranchMappingTableForSessionTreeBranch:(NSString *)sessionTreeBranch
                                completionHandler:(void (^)(PTDiffusionBranchMappingTable * _Nullable branchMappingTable, NSError * _Nullable error)) completionHandler;

@end

NS_ASSUME_NONNULL_END
