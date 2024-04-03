//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2022 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionUpdateStream;
@class PTDiffusionTopicSpecification;
@class PTDiffusionUpdateConstraint;
@class PTDiffusionStringUpdateStream;
@class PTDiffusionNumberUpdateStream;
@class PTDiffusionBinaryUpdateStream;
@class PTDiffusionJSONUpdateStream;
@class PTDiffusionRecordV2UpdateStream;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief An update stream builder.

 Builder for  {@link PTDiffusionUpdateStream update stream} to use for updating a
 specific topic.

 The type of the topic being updated must match the update stream type.

 To create a new Update Stream Builder, please use {@link PTDiffusionTopicUpdateFeature: newUpdateStreamBuilder}.

 @since 6.9
 */
@interface PTDiffusionUpdateStreamBuilder: NSObject


+(instancetype)new NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;


/**
 Specifies a {@link PTDiffusionTopicSpecification topic specification} for this
 update stream.

 If a topic does not exist at the `path`, one will be created using the topic
 specification, otherwise the operation will fail.

 Specification is `nil` by default. Calling this method with a `nil` parameter removes
 the currently set topic specification from this builder.

 @param specification   the required specification for the topic

 @return                the builder

 @since 6.9
 */
-(instancetype)topicSpecification:(PTDiffusionTopicSpecification *const _Nullable)specification;


/**
 Constraints can be applied to the setting of a value and creation of an update stream.
 Constraints describe a condition that must be satisfied for the operation to succeed.
 The constraints are evaluated on the server.
 The available constraints are:
    - active session lock
    - absence of a topic,
    - current value of the topic being updated
    - part of the current value of the topic being updated

 Constraint is `nil` by default. Calling this method with a `nil` parameter removes
 the currently set update constraint from this builder.

 @param constraint  the constraint that must be satisfied for the update stream
                    to be validated

 @return            the builder

 @since 6.9
 */
-(instancetype)updateConstraint:(PTDiffusionUpdateConstraint * const _Nullable)constraint;


/**
 Resets the builder to its default parameters.

 @return        the builder

 @since 6.9
 */
-(instancetype)reset;


/**
 Creates an update stream to use for updating a specific topic with string
 values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.9
 */
-(PTDiffusionStringUpdateStream *)stringUpdateStreamWithPath:(NSString *)path;


/**
 Creates an update stream to use for updating a specific topic with
 double-precision floating point (Eight-byte IEEE 754) values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.9
 */
-(PTDiffusionNumberUpdateStream *)doubleFloatNumberUpdateStreamWithPath:(NSString *)path;


/**
 Creates an update stream to use for updating a specific topic with 64-bit
 integer values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.9
 */
-(PTDiffusionNumberUpdateStream *)int64NumberUpdateStreamWithPath:(NSString *)path;


/**
 Creates an update stream to use for updating a specific topic with binary
 values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.3
 */
-(PTDiffusionBinaryUpdateStream *)binaryUpdateStreamWithPath:(NSString *)path;


/**
 Creates an update stream to use for updating a specific topic with JSON values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If path is `nil`.

 @since 6.9
 */
-(PTDiffusionJSONUpdateStream *)jsonUpdateStreamWithPath:(NSString *)path;


/**
 Creates an update stream to use for updating a specific topic with RecordV2
 values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.9
 */
-(PTDiffusionRecordV2UpdateStream *)recordUpdateStreamWithPath:(NSString *)path;


@end

NS_ASSUME_NONNULL_END
