//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020, 2021 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;
#import <Diffusion/PTDiffusionEnumeration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Permissions protecting access-controlled operations that are evaluated
 for a specific topic path.
 
 @see PTDiffusionGlobalPermission
 
 @since 6.5
 
 */

@interface PTDiffusionPathPermission : PTDiffusionEnumeration

/**
 Required to receive information from a topic.
 
 If a session does not have read_topic permission for a path, the path will be
 excluded from the results of subscription or fetch operations for the session,
 and the path's details cannot be retrieved by the session.
 
 @see #selectTopic

 @return Instance indicating permission to receive information from a topic.
 
 @since 6.3
 */
+(instancetype)readTopic;

/**
 Update a topic.

 @return Instance indicating permission to update a topic.
 
 @since 6.3
 */
+(instancetype)updateTopic;

/**
 Add a topic or remove a topic.

 @return Instance indicating permission to add or remove a topic.
 
 @since 6.3
 */
+(instancetype)modifyTopic;

/**
 Send a message to a handler registered with the server.

 @return Instance indicating permission to send a message to a handler
 registered with the server.
 
 @since 6.3
 */
+(instancetype)sendToMessageHandler;

/**
 Send a message to a client session.

 @return Instance indicating permission to send a message to a client session.
 
 @since 6.3
 */
+(instancetype)sendToSession;

/**
 Use a topic selector that selects the topic path.
 
 A session must have this permission for the path prefix of any topic selector
 used to subscribe or fetch.
 
 When the subscription or fetch request completes, the resulting topics are
 further filtered based on the #readTopic permission.
 
 A session that has #readTopic but not #selectTopic for a particular topic path
 cannot subscribe directly to topics belonging to the path. However, the session
 can be independently subscribed by a control session that has
 PTDiffusionGlobalPermission#modifySession permission in addition to the
 appropriate #selectTopic permission.

 @return Instance indicating permission to use a topic selector that selects
 the topic path.
 
 @since 6.3
 */
+(instancetype)selectTopic;

/**
 Evaluate queries that return a non-current view of a time series path.
 
 The #readTopic permission is required to evaluate any type of query for a time
 series path. This permission is additionally required for queries that
 potentially return a non-current view of all or part of a time series. Such
 queries include value range queries that specify an edit range, and all types
 of edit range query.

 @return Instance indicating permission to evaluate queries that return a
 non-current view of a time series path.
 
 @see PTDiffusionTimeSeriesFeature
 
 @since 6.3
 */
+(instancetype)queryObsoleteTimeSeriesEvents;

/**
 Submit edits to time series topic events.
 
 The #updateTopic permission is required to update a time series path. This
 permission is additionally required to submit edits to a time series path.

 @return Instance indicating permission to submit edits to time series
 topic events.
 
 @see PTDiffusionTimeSeriesFeature
 @see #editOwnTimeSeriesEvents
 
 @since 6.3
 */
+(instancetype)editTimeSeriesEvents;

/**
 Submit edits to time series path events which have an author which is the same
 as the principal of the calling session.
 
 This permission is a more restrictive alternative to #editTimeSeriesEvents.
 
 The #updateTopic permission is required to update a time series path. This
 permission is additionally required to submit edits to a time series path
 where the event author is the same as the principal of the calling session.

 @return Instance indicating permission to submit edits to time series path
 events which have an author identical to the principal of the
 calling session.
 
 @see PTDiffusionTimeSeriesFeature
 @see #editTimeSeriesEvents
 
 @since 6.3
 */
+(instancetype)editOwnTimeSeriesEvents;

/**
 Acquire a session lock.

 @return Instance indicating permission to acquire a session lock.
 
 @see PTDiffusionSessionLock
 
 @since 6.3
 */
+(instancetype)acquireLock;

/**
 A permission that is unsupported by the session.

 @return Instance indicating an unsupported permission.
 
 @since 6.3
 */
+(instancetype)unknownTopicPermission;


/**
 Expose a branch of the topic tree as a virtual session tree.

 The <code>EXPOSE_BRANCH</code> path permission is powerful since it allows a
 session to expose a whole branch of the topic tree under a different set
 of path permissions.

 A session granted <code>EXPOSE_BRANCH</code> for a particular path effectively
 has the permission for all descendant paths. From a security perspective,
 if a role grants <code>EXPOSE_BRANCH</code> at branch <code>X</code> it is
 ineffectual for it also to deny <code>EXPOSE_BRANCH</code> at a child branch
 <code>X/Y</code> because a branch mapping to <code>X</code> can still expose paths
 below <code>X/Y</code>.

 @return Instance indicating permission to expose branches.

 @see PTDiffusionSessionTrees
 @since 6.7
*/
+(instancetype)exposeBranch;

@end

NS_ASSUME_NONNULL_END
