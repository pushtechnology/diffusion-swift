//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionUpdateStream.h>


NS_ASSUME_NONNULL_BEGIN


@interface PTDiffusionRecoverableUpdateStream<ObjectType> : NSObject


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


/**
 The latest value of the topic set using this update stream, from local cache.

 This value reflects the last value that has been set, before it is sent to the
 server.

 If the server rejects a set operation, the topic value will not change and this
 update stream will be invalidated.

 @since 6.10
 */
@property(nonatomic, readonly) ObjectType value;


/**
 Indicates if the recoverable update stream is currently in recovery.

 @since 6.10
 */
@property(atomic, readonly) BOOL inRecovery;


/**
 Validates the update stream.

 Update streams are validated lazily when setting the value. This method allows
 the stream to be validated before a value needs to be set.

 If the update stream has not been validated yet, calling this method checks the
 topic exists, the topic type is correct, the constraint is satisfied and the
 session has permission to update the topic. Once it has been validated calling
 this method checks the topic has not been removed, no other stream has been
 created for the topic, the value of the topic has not been changed by anything
 else and the session still has permission to update the topic.

 This method may fail with an "incompatible existing topic" error if it is the
 first call to validate, set has not been called and a
 PTDiffusionTopicSpecification was provided when creating the update stream,
 otherwise it will never fail with this error.

 The first call to this method may fail with a "no such topic" or "incompatible
 topic" error. Subsequent calls may fail with "invalid update stream". Any call
 can fail with a "cluster repartition", "session security" or "session closed"
 error.

 If a PTDiffusionUpdateConstraint was provided when creating the update stream,
 the first call to this method may also fail with an "unsatisified constraint"
 error.

 If the update stream was created with one of the "create update stream"
 methods, the first call to this method may also fail with an "incompatible
 existing topic" error and it will not fail with a "no such topic" error.

 If this method fails all subsequent calls to 'set' or 'validate' will fail with
 an "invalid update stream" error.

 If the task fails, the completionHandler will be called with an error. Common
 reasons for failure include:

 - **no such topic** if there is no topic bound to `path`.
 - **incompatible topic** if updates cannot be applied to the topic, for example
   if a topic view has bound a reference topic to the path.
 - **incompatible topic state** if the topic is managed by a component (such as
   fan-out) that prohibits updates from the caller.
 - **unsatisfied constraint** if the `constraint` is not  satisfied by the topic
   `path`.
 - **invalid update stream** if the update stream has been invalidated.
 - **cluster repartition** if the cluster was repartitioning.
 - **session security** if the calling session does not have the `MODIFY_TOPIC` or
   `UPDATE_TOPIC` permission for `path`.
 - **session closed** if the session is closed.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If completionHandler is `nil`.

 @since 6.10
 */
-(BOOL)validateWithCompletionHandler:(PTDiffusionUpdateStreamHandlerBlock)completionHandler
                               error:(NSError **)error;



/**
 Sets the topic to a specified value.

 The first call to this method may fail with a "no such topic" or "incompatible
 topic" error. Subsequent calls may fail with "invalid update stream". Any call
 can fail with a "cluster repartition", "session security" or "session closed"
 error.

 If a PTDiffusionUpdateConstraint was provided when creating the update stream,
 the first call to this method may also fail with an "unsatisified constraint"
 error.

 If the update stream was created with one of the "create update stream"
 methods, the first call to this method may also fail with an "incompatible
 existing topic" error and it will not fail with a "no such topic" error.

 If this method fails all subsequent calls to 'set' or 'validate' will fail with
 an "invalid update stream" error.

 If the task fails, the completionHandler will be called with an error. Common
 reasons for failure include:

 - **no such topic** if there is no topic bound to `path`.
 - **incompatible topic** if updates cannot be applied to the topic, for example
 if a topic view has bound a reference topic to the path.
 - **incompatible topic state** if the topic is managed by a component (such as
 fan-out) that prohibits updates from the caller.
 - **unsatisfied constraint** if the `constraint` is not  satisfied by the topic
 `path`.
 - **invalid update stream** if the update stream has been invalidated.
 - **invalid topic path** if `path` is not a valid topic path.
 - **invalid topic specification** if the specification is invalid, possibly
   because mandatory properties were not supplied.
 - **topic license limit** if the topic could not be added as it would breach a
   licensing limit.
 - **cluster repartition** if the cluster was repartitioning.
 - **session security** if the calling session does not have the `MODIFY_TOPIC` or
 `UPDATE_TOPIC` permission for `path`.
 - **session closed** if the session is closed.

 @param value The value to set the topic to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If either value or completionHandler is
 `nil`.

 @since 6.10
 */
-(BOOL)      setValue:(ObjectType)value
    completionHandler:(PTDiffusionUpdateStreamHandlerBlock)completionHandler
                error:(NSError **)error;


/**
 Begins the procedure to attempt recovery from a transient error.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @since 6.10
 */
-(BOOL)recover:(NSError **)error;


/**
 Indicates if the error is recoverable by the update stream.

 @param error   The error.

 @return        True if the error is recoverable, false otherwise.

 @since 6.10
 */
+(BOOL) isErrorRecoverable:(NSError *)error;


@end

NS_ASSUME_NONNULL_END