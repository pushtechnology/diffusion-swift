//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2015 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

/**
 @file PTDiffusionTopicType.h

 The topic type determines the type of the data values a topic publishes to
 subscribers.

 ### Source Topics

 Most topics are source topics. The characteristics of each type of source
 topic are summarized in the following table.

 | Topic type                       | State                         | Data type                                         |
 | -------------------------------- | ----------------------------- | ------------------------------------------------- |
 | #PTDiffusionTopicType_String     | Single scalar value.          | String.                                           |
 | #PTDiffusionTopicType_Int64      | Single scalar value.          | 64-bit integer.                                   |
 | #PTDiffusionTopicType_Double     | Single scalar value.          | Double precision floating point number.           |
 | #PTDiffusionTopicType_Binary     | Single scalar value.          | Arbitrary binary data.                            |
 | #PTDiffusionTopicType_RecordV2   | Single composite value.       | #PTDiffusionRecordV2 &ndash; Diffusion-specific data type. A list of records, each composed of field values, with an optional schema. |
 | #PTDiffusionTopicType_JSON       | Single composite value.       | #PTDiffusionJSON, backed by CBOR-format binary.   |
 | #PTDiffusionTopicType_TimeSeries | Append-only log of events.    | #PTDiffusionTimeSeriesEvent containing a value of a \link #PTDiffusionDataTypes well-known data type\endlink. |

 @see PTDiffusionTopicSpecification

 @since 5.6
 */
typedef NS_ENUM(NSUInteger, PTDiffusionTopicType) {
    /**
     Topic that stores and publishes binary values. Based on the
     PTDiffusionBinary data type.

     Supports delta-streams.

     @since 5.7
     */
    PTDiffusionTopicType_Binary = 13,

    /**
     Topic that stores and publishes JSON (JavaScript Object Notation) values.
     Based on the PTDiffusionJSON data type.

     Supports delta-streams.

     @since 5.7
     */
    PTDiffusionTopicType_JSON = 14,

    /**
     Topic that stores and publishes IEEE 754 double-precision floating point
     numbers. Based on the double data type.

     Supports `nil` values.

     The topic does not support delta-streams — only complete values are
     transmitted.

     @since 6.0
     */
    PTDiffusionTopicType_Double = 15,

    /**
     Topic that stores and publishes 64-bit integer values. Based on the int64
     data type.

     Supports `nil` values.

     The topic does not support delta-streams — only complete values are
     transmitted.

     @since 6.0
     */
    PTDiffusionTopicType_Int64 = 16,

    /**
     Topic that stores and publishes string values. Based on the string data
     type.

     Supports `nil` values.

     Supports delta-streams.

     @since 6.0
     */
    PTDiffusionTopicType_String = 17,

    /**
     A time series is a sequence of events. Each event contains a value and has
     server-assigned metadata comprised of a sequence number, timestamp, and
     author.

     A time series topic allows sessions to access a time series that is
     maintained by the server. A time series topic has an associated event data
     type that determines the type of value associated with each event.

     ### Retained range

     The [PTDiffusionTopicSpecification timeSeriesSubscriptionRange] property
     configures the range of historic events retained by a time series topic.
     If the property is not specified, a time series topic will retain the ten
     most recent events.

     ### Subscription range

     The [PTDiffusionTopicSpecification timeSeriesSubscriptionRange] property
     configures a time series topic to send a range of historic events from the
     end of the time series to new subscribers. This is a convenient way to
     synchronize new subscribers without requiring the use of a range query.

     By default, new subscribers will be sent the latest event if delta streams
     are enabled and no events if delta streams are disabled.

     ### Mandatory properties

     The [PTDiffusionTopicSpecification timeSeriesEventValueType] property must
     be provided when creating a time series topic.

     @since 6.0
     */
    PTDiffusionTopicType_TimeSeries = 18,

    /**
     Topic that stores and publishes data in the form of records and fields.

     Supports delta-streams.

     @since 6.0
     */
    PTDiffusionTopicType_RecordV2 = 19,

    /**
     A topic type that is unsupported by the session.

     @since 6.1
     */
    PTDiffusionTopicType_Unknown = 20,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Returns a localized string representation of the given topic type.

 @param topicType The topic type for which a description is to be returned.

 @return localized string representation of the given topic type.

 @since 5.7
 */
NSString* PTDiffusionTopicTypeToString(PTDiffusionTopicType topicType);

/**
 Returns the name of this topic type constant, exactly as declared in its
 enum declaration in the Diffusion API for Java.

 @param topicType The topic type for which the name is to be returned.

 @return name of given topic type constant, exactly as declared in its
 enum declaration.

 @since 5.9
 */
NSString* PTDiffusionTopicTypeToName(PTDiffusionTopicType topicType);

NS_ASSUME_NONNULL_END
