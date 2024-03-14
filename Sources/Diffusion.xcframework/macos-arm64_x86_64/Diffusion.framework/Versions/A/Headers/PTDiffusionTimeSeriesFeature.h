//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2017, 2021 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;
#import <Diffusion/PTDiffusionFeature.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This feature allows a session to update and query time series topics.

 ## Time series topics

 A <em>time series</em> is a sequence of events. Each event contains a value
 and has server-assigned metadata comprised of a sequence number, timestamp,
 and author. Events in a time series are ordered by increasing sequence
 number. Sequence numbers have values between `0` and `NSIntegerMax`
 and are contiguous: an event with sequence number
 `n` will be followed by one with sequence number `n + 1`. Two
 events with the same sequence number will be equal &ndash; having the same
 timestamp, author, and value.

 A time series topic allows sessions to access a time series that is
 maintained by the server. A time series topic has an associated
 {@link PTDiffusionDataType event data type}, such as `PTDiffusionBinary`,
 `PTDiffusionPrimitive  `, or `PTDiffusionJSON`, that determines the type of value
 associated with each event.

 This feature provides a historic query API for time series topics, allowing a
 session to query arbitrary sub-sequences of a time series. The
 {@link PTDiffusionTopicControlFeature topic control} and {@link PTDiffusionTopicsFeature topics}
 features complete the API, providing ways to create and subscribe to a
 time series topic.

 The API presents a time series as an append-only data structure of immutable
 events that is only changed by adding new events.

 ### Edit events

 Although a time series is append-only, an event can be overridden by
 appending an <em>edit event</em>. An edit event is a special type of event
 that overrides an earlier event in the time series (referred to as the
 <em>original event</em>) with a new value. When an edit event is added to a
 time series, the server retains both the original event and the edit event,
 allowing subscription and query results to reflect the edit.

 For example, suppose a time series has two events with the values `A`
 and `B`, and the first event has been overridden by a later edit event
 that provides a new value of `X`. The server has the following
 information about the time series.

 <table>
    <tr>
        <th>Sequence</th>
        <th>Value</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>0</td>
        <td>A</td>
        <td><em>original event</em></td>
    </tr>
    <tr>
        <td>1</td>
        <td>B</td>
        <td><em>original event</em></td>
    </tr>
    <tr>
        <td>2</td>
        <td>X</td>
        <td><em>edit of sequence 0</em></td>
    </tr>
 </table>

 The current value of the event with sequence number 0 is `X`.

 If an original event has several edit events, the latest edit event (the one
 with the highest sequence number) determines its current value. Each edit
 event refers to an original event, never to another edit event.

 Extending the example by appending a further edit event to the time series:

 <table>
    <tr>
        <th>Sequence</th>
        <th>Value</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>3</td>
        <td>Y</td>
        <td><em>second edit of sequence 0</em></td>
    </tr>
 </table>

 The current value of the event with sequence number 0 is now `Y`.


 ### Retained range

 A time series topic retains a range of the most recent events. When a new
 event is added to the time series, older events that fall outside of the
 range are discarded. By default, this range includes the ten most recent
 events. A different range can be configured by setting the
 {@link PTDiffusionTopicSpecification#timeSeriesRetainedRangePropertyKey
 timeSeriesRetainedRange} property.

 ## Subscribing to a time series topic

 A session can {@link PTDiffusionTopicsFeature#subscribeWithTopicSelectorExpression:completionHandler:
 subscribe} to a time series topic and add a value stream to receive updates
 about events appended to the time series. Events are represented by
 {@link PTDiffusionTimeSeriesEvent event} instances. Each event has a value and
 {@link PTDiffusionTimeSeriesEventMetadata metadata}. An edit event has two sets of
 metadata &ndash; its own metadata and that of the original event that it
 replaces.

 ### Subscription range

 New subscribers are sent a range of events from the end of the time series.
 This is known as the <em>subscription range</em>. Configuring a subscription
 range is a convenient way to provide new subscribers with an appropriate
 subset of the latest events.

 The default subscription range depends on whether the topic is configured to
 publish delta streams. If delta streams are enabled, new subscribers are sent
 the latest event if one exists. If delta streams are disabled, new
 subscribers are sent no events. Delta streams are enabled by default and can
 be disabled by setting the {@link PTDiffusionTopicSpecification#publishValuesOnlyPropertyKey
 publishValuesOnly} property to `true`.

 A larger subscription range can be configured by setting the
 {@link PTDiffusionTopicSpecification#timeSeriesSubscriptionRangePropertyKey
 timeSeriesSubscriptionRange} property. Regardless of the
 `timeSeriesSubscriptionRange` property, if delta streams are
 enabled, new subscribers will be sent at least the latest event if one
 exists.

 If the range of events is insufficient, the subscribing session can use a
 {@link PTDiffusionTimeSeriesRangeQuery range query} to retrieve older events.

 When configuring a non-default subscription range for a time series topic,
 register value streams before subscribing to the topic. The session only
 maintains a local cache of the latest value received for a topic, not the
 full subscription range. If a value stream is added after a session has
 subscribed to a matching time series topic, the new stream will only be
 notified of the latest value.

 ## Updating a time series topic

 A session can use `appendToTopicPath:value:completionHandler` to submit a value to be added to a
 time series. The server will add an event to the end of the time series based
 on the supplied value, with a new sequence number, timestamp, and the author
 set to the authenticated principal of the session.

 Using `appendToTopicPath:value:timestamp:completionHandler` allows a session
 to submit a value and supplied <a href="https://developer.apple.com/documentation/foundation/nsdate">timestamp</a>.
 This provides control over  the timestamp of the event.
 The supplied instant must not be before the  latest event stored by the time
 series topic. There are no other restrictions.

 A session can use `editAtTopicPath:originalSequence:value:completionHandler:`
 to submit an edit to an original time series event, identified by its sequence number.
 The server will add an edit event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 Time series topics can also be updated using the functionality provided by
 the {@link PTDiffusionTopicUpdateFeature topic update} feature. This includes
 `setWithPath:toValue:completionHandler:`, `addWithPath:specification:andSetToJSONValue:completionHandler:`
 and {@link PTDiffusionUpdateStream update streams}. This usage performs
 an append operation with the added benefits of {@link PTDiffusionUpdateConstraint update constraints},
 topic creation when updating (upsert), and delta streams. When using methods
 from {@link PTDiffusionTopicUpdateFeature topic update} the sequence number, timestamp and author metadata
 will be generated using the same rules as
 `appendToTopicPath:value:timestamp:completionHandler` but the associated
 {@link PTDiffusionTimeSeriesEventMetadata event metadata} will not be returned to the caller.

 ## Querying a time series topic

 {@link PTDiffusionTimeSeriesRangeQuery} is a builder for configuring a query that selects a range
 of a time series. There are two types of range query that differ in how edits
 are processed &ndash; value range queries and edit range queries.

 ### Value range queries

 A value range query returns a merged view of part of a time series. This is
 the most common time series query and appropriate for most applications.

 The result of a value range query reflects the latest available edits and the
 {@link PTDiffusionTimeSeriesQueryResultEventArrayStructure#valueEventStream
 query result stream} is ordered by the original
 event sequence number, presenting edit events instead of the original events
 they replace. Original events that have no edit events are included verbatim.
 Original events that have edit events are replaced by the latest edit event.

 A value range query of the example time series, with no range constraints so
 the entire time series is selected, returns two events:

 <pre>
    sequence=3, value=Y; original event sequence=0
    sequence=1, value=B
 </pre>

 The original value of the first event is not provided. It's apparent that the
 first event is an edit event because it provides the metadata of the original
 event it replaces.

 ### Edit range queries

 Applications with auditing and other administrative requirements can access
 original event values using an edit range query. An edit range query returns
 an unmerged view of a time series that can include both original events and
 the edit events that replace them. Edit range queries are rarely needed
 &ndash; value range queries satisfy most use cases.

 Edit range queries provide a detailed view of a time series. Because this is
 potentially sensitive information, an edit range query can only be performed
 by a session that has the {@link PTDiffusionPathPermission#queryObsoleteTimeSeriesEvents
 queryObsoleteTimeSeriesEvents} permission for the target topic.

 There are two sub-types of edit range query.

 A full audit trail of edit events can be obtained using an <em>all edits</em>
 edit range query. The result contains all original events selected by the
 query, together with all subsequent edit events that affect the original
 events. The query result stream provides events in time series order. An all
 edits query of the example time series, with no range constraints so the
 entire time series is selected, returns four events:

 <pre>
    sequence=0; value=A
    sequence=1; value=B
    sequence=2; value=X; original event sequence=0
    sequence=3; value=Y; original event sequence=0
 </pre>

 A <em>latest edits</em> edit range query returns a query result stream in
 time series order that contains all original events selected by the query,
 together with the latest edit events that affect the original events. A
 latest edits query of the example time series, with no range constraints so
 the entire time series is selected, returns three events:

 <pre>
    sequence=0; value=A
    sequence=1; value=B
    sequence=3; value=Y; original event sequence=0
 </pre>

 The initial range of events delivered for a subscription to a time series
 topic is derived from a <em>latest edits</em> edit range query. See
 <em>Subscription Range</em>.

 When evaluated for a time series that has no edit events, an edit range query
 will return the same results as a similarly configured value range query.

 ## Changes to a time series made outside the API

 The API presents a time series as an append-only data structure of immutable
 events that is only changed by adding new events. The API does not allow
 events to be deleted or edited.

 There are circumstances in which events can be removed from a time series by
 server operations outside the API. For example, a time series topic can be
 configured to discard or archive older events to save storage space; or the
 time series may be held in memory and lost if the server restarts. Subscribed
 sessions are not notified when events are removed in this way, but a session
 can infer the removal of events that are no longer included in query results.
 Similarly, an event's value can be changed on the server. For example, if an
 administrator changes its value to redact sensitive data. Again, subscribed
 sessions are not notified when events are modified, but a session can infer
 this has happened from query results.

 Whether such changes can happen for a particular time series topic depends on
 the topic specification, and the administrative actions that are allowed. To
 write a robust application, do not rely on two Event instances with the same
 sequence number but obtained though different API calls, being equal; nor
 that there are no sequence number gaps between events in query results.

 ## Access control

 The session must have the {@link PTDiffusionPathPermission#readTopic readTopic}
 permission for a topic to query a time series topic. The
 {@link PTDiffusionPathPermission#queryObsoleteTimeSeriesEvents
 queryObsoleteTimeSeriesEvents} permission is additionally required
 to evaluate an {@link PTDiffusionTimeSeriesRangeQuery#forEdits edit range} query, or a
 {@link PTDiffusionTimeSeriesRangeQuery#forValues value range query} with an
 {@link PTDiffusionTimeSeriesRangeQuery#editRange edit range}.

 The session must have the {@link PTDiffusionPathPermission#updateTopic updateTopic}
 permission for a topic to `appendToTopicPath:value:completionHandler:`
 a new event to a time series topic. The
 {@link PTDiffusionPathPermission#editTimeSeriesEvents editTimeSeriesEvents}
 permission is additionally required to submit an edit via
 `editAtTopicPath:originalSequence:value:completionHandler:` to any time series
 topic event. The more restrictive
 {@link PTDiffusionPathPermission#editOwnTimeSeriesEvents editOwnTimeSeriesEvents}
 permission allows a session to submit edits to time series topic
 events that are authored by the principal of the calling session.

 The Time Series feature for a session can be obtained from the session's
 {@link PTDiffusionSession#timeSeries timeSeries} property.

 @see PTDiffusionSession
 @since 6.0
 */
@interface PTDiffusionTimeSeriesFeature : PTDiffusionFeature

@end

NS_ASSUME_NONNULL_END
