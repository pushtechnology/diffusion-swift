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
#import <Diffusion/PTDiffusionFeature.h>

@class PTDiffusionSessionMetricCollector;
@class PTDiffusionTopicMetricCollector;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This feature allows a client to configure metric collectors.

 Diffusion servers provide metrics which are made available in several ways:
 <ul>
    <li>Java Management Extensions (JMX) MBeans.
    <li>Through the Diffusion Management Console.
    <li>As endpoints for Prometheus.
 </ul>

 Metric collectors allow custom aggregation of metrics that are relevant to
 your application. There are no default metric collectors, only the ones that
 you create.

 There are two types of metric collector: Session Metric Collectors and Topic
 Metric Collectors.

 For full details regarding the configuration and operation of metric
 collectors see the user manual.

 ### Session Metric Collectors.

 These can be configured to record metric data for a subset of all sessions,
 specified with a session filter.

 The set of metrics recorded by each session metric collector is the same as
 those recorded for the whole server. For full details of session metrics, see
 the table in the user manual.

 If the session filters of two different session metric collectors select the
 same session, both will record metrics for that session. It is only valid to
 add the metrics of different session metric collectors if their session
 filters select distinct sets of sessions.

 You can optionally group the sessions within a collector by session
 properties.

 ### Topic Metric Collectors
 These can be configured to record metric data for a subset of all topics,
 specified with a topic selector.

 You can optionally group the topics within a collector by topic type.

 The set of metrics recorded by each topic metric collector is the same as
 those recorded for the whole server. For full details of topic metrics, see
 the table in the user manual.

 If the topic selectors of two different topic metric collectors select the
 same topic, both will record metrics for that topic. It is only valid to add
 the metrics of different topic metric collectors if their topic selectors
 select distinct sets of topics.

 ### Access control

 The following access control restrictions are applied:
 <ul>
    <li>To {@link #putSessionMetricCollector:completionHandler: put} or
        {@link #removeSessionMetricCollector:completionHandler: remove} a session metric collector, a
        session needs the {@link PTDiffusionGlobalPermission.controlServer CONTROL_SERVER}
        global permission.
    <li>To {@link #putTopicMetricCollector:completionHandler: put} or
        {@link #removeTopicMetricCollector:completionHandler: remove} a topic metric collector, a
        session needs the {@link PTDiffusionGlobalPermission.controlServer CONTROL_SERVER}
        global permission.
    <li>To list {@link #listSessionMetricCollectors: session metric collectors} or
        {@link #listTopicMetricCollectors: topic metric collectors}, a session needs
        the {@link PTDiffusionGlobalPermission.viewServer VIEW_SERVER} global permission.
  </ul>

  ### Accessing the feature
  This feature may be obtained from a {@link Session session} as follows:
  <pre>
    PTDiffusionMetricsFeature *const metrics = session.metrics;
  </pre>

 @author DiffusionData Limited

 @since 6.7
 */
@interface PTDiffusionMetricsFeature : PTDiffusionFeature

/**
 Add a session metric collector, replacing any with the same name.

 @param collector the session metric collector

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>PTDiffusionError_InvalidFilter if the metric collector session filter is invalid;
    <li>PTDiffusionError_AccessDenied if the calling session does not have the
        {@link PTDiffusionGlobalPermission.controlServer CONTROL_SERVER} permission;
    <li>PTDiffusionError_ClusterRouting if the operation failed due to a transient cluster error;
    <li>PTDiffusionError_SessionClosed if the session is closed.
 </ul>

 @since 6.7
 */
-(void)putSessionMetricCollector:(PTDiffusionSessionMetricCollector *)collector
               completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;


/**
 Retrieves the current session metric collectors.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and the `collectors` will not be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>PTDiffusionError_AccessDenied if the calling session does not have the
        {@link PTDiffusionGlobalPermission.viewServer VIEW_SERVER} permission;
    <li>PTDiffusionError_SessionClosed if the session is closed.
 </ul>

 @since 6.7
 */
-(void) listSessionMetricCollectors:(void (^)(NSArray<PTDiffusionSessionMetricCollector *>* _Nullable collectors,
                                              NSError * _Nullable error)) completionHandler;


/**
 Removes any session metric collector with the given name, if it exists.

 @param name the session metric collector name

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>PTDiffusionError_AccessDenied if the calling session does not have the
        {@link PTDiffusionGlobalPermission.controlServer CONTROL_SERVER} permission;
    <li>PTDiffusionError_ClusterRouting if the operation failed due to a transient cluster error;
    <li>PTDiffusionError_SessionClosed if the session is closed.
 </ul>

 @since 6.7
 */
-(void) removeSessionMetricCollector:(NSString *)name
                   completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;


/**
 Add a topic metric collector, replacing any with the same name.

 {@link PTDiffusionTopicMetricCollector} instance can be created using
 {@link PTDiffusionTopicMetricCollectorBuilder}.

 @param collector the topic metric collector

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>PTDiffusionError_AccessDenied if the calling session does not have the
        {@link PTDiffusionGlobalPermission.controlServer CONTROL_SERVER} permission;
    <li>PTDiffusionError_ClusterRouting if the operation failed due to a transient cluster error;
    <li>PTDiffusionError_SessionClosed if the session is closed.
 </ul>

 @since 6.7
 */
-(void) putTopicMetricCollector:(PTDiffusionTopicMetricCollector *)collector
              completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;


/**
 Retrieves the current topic metric collectors.

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil` and the `collectors` will not be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>PTDiffusionError_AccessDenied if the calling session does not have the
        {@link PTDiffusionGlobalPermission.viewServer VIEW_SERVER} permission;
    <li>PTDiffusionError_SessionClosed if the session is closed.
 </ul>

 @since 6.7
 */
-(void) listTopicMetricCollectors:(void (^)(NSArray<PTDiffusionTopicMetricCollector *>* _Nullable collectors,
                                            NSError * _Nullable error)) completionHandler;


/**
 Removes any topic metric collector with the given name, if it exists.

 @param name the topic metric collector name

 @param completionHandler Block to be called asynchronously on success or failure.
 If the operation was successful, the `error` argument passed to the block will
 be `nil`.
 The completion handler will be called asynchronously on the main dispatch queue.
 These are the common reasons for failure:
 <ul>
    <li>PTDiffusionError_AccessDenied if the calling session does not have the
        {@link PTDiffusionGlobalPermission.controlServer CONTROL_SERVER} permission;
    <li>PTDiffusionError_ClusterRouting if the operation failed due to a transient cluster error;
    <li>PTDiffusionError_SessionClosed if the session is closed.
 </ul>

 @since 6.7
 */
-(void) removeTopicMetricCollector:(NSString *)name
                 completionHandler:(void (^)(NSError * _Nullable error)) completionHandler;

@end

NS_ASSUME_NONNULL_END
