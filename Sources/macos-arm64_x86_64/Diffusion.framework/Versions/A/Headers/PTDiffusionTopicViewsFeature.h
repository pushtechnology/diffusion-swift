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
#import <Diffusion/PTDiffusionFeature.h>

@class PTDiffusionTopicView;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This feature allows a client session to manage topic views.

 A topic view maps one part of a server's topic tree to another. It
 dynamically creates a set of <em>reference topics</em> from a set of
 <em>source topics</em>, based on a declarative <em>topic view
 specification</em>. The capabilities of topic views range from simple
 mirroring of topics within the topic tree to advanced capabilities including
 publication of partial values, expanding a single topic value into many
 topics, changing topic values, inserting values from other topics, throttling
 the rate of publication, and applying a fixed delay to the publication.

 A topic view can also map topics from another server (in a different
 cluster). This capability is referred to as 'remote topic views'. The view
 can specify the server that the <em>source topics</em> are hosted on in terms
 of a <em>remote server</em> (see {@link PTDiffusionRemoteServersFeature} for details of how to
 create and maintain remote servers).

 Each reference topic has a single source topic and has the same topic type as
 its source topic. Reference topics are read-only (they cannot be updated),
 nor can they be created or removed directly. Otherwise, they behave just like
 standard topics. A client session can subscribe to a reference topic, and can
 fetch the reference topic's current value if it has one.

 The source topics of a topic view are defined by a topic selector. One or
 more reference topics are created for each source topic, according to the
 topic view. If a source topic is removed, reference topics that are derived
 from it will automatically be removed. If a topic is added that matches the
 source topic selector of a topic view, corresponding reference topics will be
 created. Removing a topic view will remove all of its reference topics.


 ## Topic view specifications

 Topic views are specified using a Domain Specific Language (DSL) which
 provides many powerful features for manipulating topic data. For a full and
 detailed description of the topic views DSL see the <a href="https://docs.diffusiondata.com/docs/latest/manual/html/developerguide/client/topics/topiccontrol/topic_views.html">user
 manual</a>.

 The following is a simple topic view specification that mirrors all topics
 below the path `a` to reference topics below the path `b`.

 <pre>
 map ?a// to b/<path(1)>
 </pre>

 A topic view with this specification will map a source topic at the path
 `a/x/y/z` to a reference topic at the path `b/x/y/z`.
 The specification is simple, so the reference topic will exactly mirror the
 source topic. Other topic views features allow a single topic to be mapped to
 many reference topics and have the data transformed in the process.


 ## Topic view persistence and replication

 Reference topics are neither replicated nor persisted. They are created and
 removed based on their source topics. However, topic views are replicated and
 persisted. A server that restarts will restore topic views during recovery.
 Each topic view will then create reference topics based on the source topics
 that have been recovered.

 The server records all changes to topic views in a persistent store. Topic
 views are restored if the server is started.

 If a server belongs to a cluster, topic views (and remote servers) will be
 replicated to each server in the cluster. Topic views are evaluated locally
 within a server. Replicated topic views that select non-replicated source
 topics can create different reference topics on each server in the cluster.
 When remote topic views are in use, each server in the cluster will make a
 connection to the specified remote server and will separately manage their
 remote topic views.

 A view with a delay clause uses temporary storage to record delayed events.
 If there is a high volume of updates, temporary per-server disk files will be
 used to save server memory​. The storage is per-server, and does not survive
 server restart. When a server is started, no data will be published by a view
 with a delay clause until the delay time has expired.

 ## Access control

 To list the topic views a session needs {@link PTDiffusionGlobalPermission#readTopicViews readTopicViews}
 permission.
 To create or remove a topic view a session needs
 {@link PTDiffusionGlobalPermission#modifyTopicViews modifyTopicViews}
 permission, {@link PTDiffusionPathPermission#selectTopic selectTopic} permission for the prefix of
 the source topic selector and {@link PTDiffusionPathPermission#modifyTopic modifyTopic} permission
 for the prefix of the path mapping.

 ## Accessing the feature

 The Topic Views feature for a session can be obtained from the session's
 {@link PTDiffusionSession#topicViews topicViews} property.

 @see PTDiffusionSession

 @since 6.3
 */
@interface PTDiffusionTopicViewsFeature : PTDiffusionFeature

/**
 Create a new named topic view.

 If a view with the same name already exists the new view will update the
 existing view.

 @param name The name of the view.

 @param specification The specification of the view using the DSL.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param view the created topic view if the operation was successful.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.3
 */
-(void)createTopicViewWithName:(NSString *)name
                 specification:(NSString *)specification
             completionHandler:(void (^)(PTDiffusionTopicView * _Nullable view, NSError * _Nullable error))completionHandler;

/**
 List all the topic views that have been created.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `views` will contain a list of views sorted by their
 creation order. The completion handler will be called asynchronously on the
 main dispatch queue.

 @param views the topic views that have been created if the operation was successful.

 @exception NSInvalidArgumentException If completionHandler is `nil`.

 @since 6.3
 */
-(void)listTopicViewsWithCompletionHandler:(void (^)(NSArray<PTDiffusionTopicView *> * _Nullable views, NSError * _Nullable error))completionHandler;

/**
 Remove a named topic view if it exists.

 If the named view does not exist then the operation is considered successful
 and the completion handler is called accordingly.

 @param name The name of the view.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.3
 */
-(void)removeTopicViewWithName:(NSString *)name
             completionHandler:(void (^)(NSError * _Nullable error))completionHandler;


/**
 Get a named Topic View.

 @param name the name of the view.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `view` will contain the named view if it exists.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.8
 */
-(void)getTopicViewWithName:(NSString *)name
          completionHandler:(void (^)(PTDiffusionTopicView * _Nullable view, NSError * _Nullable error))completionHandler;


@end

NS_ASSUME_NONNULL_END
