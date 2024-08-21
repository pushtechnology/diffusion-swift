//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2017 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionFetchRequest.h>
#import <Diffusion/PTDiffusionMessagingFeature.h>
#import <Diffusion/PTDiffusionPartialJSONUpdateConstraint.h>
#import <Diffusion/PTDiffusionResponder.h>
#import <Diffusion/PTDiffusionTimeSeriesFeature.h>
#import <Diffusion/PTDiffusionTopicUpdateFeature.h>

@class PTDiffusionNumberFetchResult;
@class PTDiffusionNumberTimeSeriesQueryResult;
@class PTDiffusionNumberUpdateStream;
@class PTDiffusionRequest;
@class PTDiffusionRequestHandler;
@class PTDiffusionRequestStream;
@class PTDiffusionSessionResponseStream;
@class PTDiffusionStringFetchResult;
@class PTDiffusionStringTimeSeriesQueryResult;
@class PTDiffusionStringUpdateStream;
@class PTDiffusionTimeSeriesEventMetadata;
@class PTDiffusionTimeSeriesRangeQuery;
@class PTDiffusionTopicCreationResult;
@class PTDiffusionTopicSpecification;
@class PTDiffusionUpdateConstraint;
@class PTDiffusionValueStream;
@class PTDiffusionUpdateConstraintOperator;

@protocol PTDiffusionNumberRequestDelegate;
@protocol PTDiffusionNumberRequestStreamDelegate;
@protocol PTDiffusionNumberSessionResponseStreamDelegate;
@protocol PTDiffusionNumberTimeSeriesEventValueStreamDelegate;
@protocol PTDiffusionNumberValueStreamDelegate;
@protocol PTDiffusionStringRequestDelegate;
@protocol PTDiffusionStringRequestStreamDelegate;
@protocol PTDiffusionStringSessionResponseStreamDelegate;
@protocol PTDiffusionStringTimeSeriesEventValueStreamDelegate;
@protocol PTDiffusionStringValueStreamDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Support for creating value streams for primitive values including
 string and numeric types.

 @since 6.0
 */
@interface PTDiffusionPrimitive : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 Creates a value stream capable of receiving double-precision floating point
 numbers (Eight-byte IEEE 754).

 @param delegate The object which will handle the incoming stream. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be added as a
 receiver of values using the Topics feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionTopicsFeature

 @since 6.0
 */
+(PTDiffusionValueStream *)doubleFloatNumberValueStreamWithDelegate:(id<PTDiffusionNumberValueStreamDelegate>)delegate;

/**
 Creates a value stream capable of receiving 64-bit integer values.

 @param delegate The object which will handle the incoming stream. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be added as a
 receiver of values using the Topics feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionTopicsFeature

 @since 6.0
 */
+(PTDiffusionValueStream *)int64NumberValueStreamWithDelegate:(id<PTDiffusionNumberValueStreamDelegate>)delegate;

/**
 Creates a value stream capable of receiving string values.

 @param delegate The object which will handle the incoming stream. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be added as a
 receiver of values using the Topics feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionTopicsFeature

 @since 6.0
 */
+(PTDiffusionValueStream *)stringValueStreamWithDelegate:(id<PTDiffusionStringValueStreamDelegate>)delegate;

/**
 Creates a value stream capable of receiving double-precision floating point
 numeric time series events.

 @param delegate The object which will handle the incoming stream. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be added as a
 receiver of values using the Topics feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionTopicsFeature

 @since 6.0
 */
+(PTDiffusionValueStream *)doubleFloatNumberTimeSeriesEventValueStreamWithDelegate:(id<PTDiffusionNumberTimeSeriesEventValueStreamDelegate>)delegate;

/**
 Creates a value stream capable of receiving 64-bit integer time series events.

 @param delegate The object which will handle the incoming stream. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be added as a
 receiver of values using the Topics feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionTopicsFeature

 @since 6.0
 */
+(PTDiffusionValueStream *)int64NumberTimeSeriesEventValueStreamWithDelegate:(id<PTDiffusionNumberTimeSeriesEventValueStreamDelegate>)delegate;

/**
 Creates a value stream capable of receiving string time series events.

 @param delegate The object which will handle the incoming stream. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be added as a
 receiver of values using the Topics feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionTopicsFeature

 @since 6.0
 */
+(PTDiffusionValueStream *)stringTimeSeriesEventValueStreamWithDelegate:(id<PTDiffusionStringTimeSeriesEventValueStreamDelegate>)delegate;

/**
 Creates a request handler capable of receiving double-precision floating point
 numeric requests (Eight-byte IEEE 754) for a handler registered at the server.

 @param delegate The object which will handle the incoming requests. A weak
 reference is maintained to this object by the returned handler.

 @return An object reliant on the supplied delegate that can be registered at
 the server using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequestHandler *)doubleFloatRequestHandlerWithDelegate:(id<PTDiffusionNumberRequestDelegate>)delegate;

/**
 Creates a request handler capable of receiving 64-bit integer requests for a
 handler registered at the server.

 @param delegate The object which will handle the incoming requests. A weak
 reference is maintained to this object by the returned handler.

 @return An object reliant on the supplied delegate that can be registered at
 the server using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequestHandler *)int64RequestHandlerWithDelegate:(id<PTDiffusionNumberRequestDelegate>)delegate;

/**
 Creates a request handler capable of receiving string requests for a handler
 registered at the server.

 @param delegate The object which will handle the incoming requests. A weak
 reference is maintained to this object by the returned handler.

 @return An object reliant on the supplied delegate that can be registered at
 the server using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequestHandler *)stringRequestHandlerWithDelegate:(id<PTDiffusionStringRequestDelegate>)delegate;

/**
 Creates a request stream capable of receiving double-precision floating point
 numeric requests.

 @param delegate The object which will handle the incoming requests. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be set as the
 receiver of requests using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequestStream *)doubleFloatRequestStreamWithDelegate:(id<PTDiffusionNumberRequestStreamDelegate>)delegate;

/**
 Creates a request stream capable of receiving 64-bit integer requests.

 @param delegate The object which will handle the incoming requests. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be set as the
 receiver of requests using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequestStream *)int64RequestStreamWithDelegate:(id<PTDiffusionNumberRequestStreamDelegate>)delegate;

/**
 Creates a request stream capable of receiving string requests.

 @param delegate The object which will handle the incoming requests. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be set as the
 receiver of requests using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequestStream *)stringRequestStreamWithDelegate:(id<PTDiffusionStringRequestStreamDelegate>)delegate;

/**
 Creates a response stream capable of receiving double-precision floating point
 numeric responses from discrete sessions.

 @param delegate The object which will handle the incoming responses. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be set as the
 receiver of requests using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(PTDiffusionSessionResponseStream *)doubleFloatSessionResponseStreamWithDelegate:(id<PTDiffusionNumberSessionResponseStreamDelegate>)delegate;

/**
 Creates a response stream capable of receiving 64-bit integer responses from
 discrete sessions.

 @param delegate The object which will handle the incoming responses. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be set as the
 receiver of requests using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(PTDiffusionSessionResponseStream *)int64SessionResponseStreamWithDelegate:(id<PTDiffusionNumberSessionResponseStreamDelegate>)delegate;

/**
 Creates a response stream capable of receiving string responses from discrete
 sessions.

 @param delegate The object which will handle the incoming responses. A weak
 reference is maintained to this object by the returned stream.

 @return An object reliant on the supplied delegate that can be set as the
 receiver of requests using the Messaging feature.

 @exception NSInvalidArgumentException Raised if the delegate argument is `nil`.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(PTDiffusionSessionResponseStream *)stringSessionResponseStreamWithDelegate:(id<PTDiffusionStringSessionResponseStreamDelegate>)delegate;

/**
 Creates a request that can be used to send the given double-precision floating
 point (Eight-byte IEEE 754) value using messaging.

 @param value The value to send as the request.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequest *)requestWithDouble:(double)value;

/**
 Creates a request that can be used to send the given double-precision floating
 point (Eight-byte IEEE 754) value using messaging.

 @param number The value to send as the request. This may be `nil` in order to
 create a 'null' request.

 @param error Location to store a reason if this method returns `nil` to
 indicate failure.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(nullable PTDiffusionRequest *)requestWithDoubleFloatNumber:(nullable NSNumber *)number
                                                       error:(NSError **)error;

/**
 Creates a request that can be used to send the given 64-bit integer value using
 messaging.

 @param value The value to send as the request.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(PTDiffusionRequest *)requestWithLongLong:(long long)value;

/**
 Creates a request that can be used to send the given 64-bit integer value using
 messaging.

 @param number The value to send as the request. This may be `nil` in order to
 create a 'null' request.

 @param error Location to store a reason if this method returns `nil` to
 indicate failure.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(nullable PTDiffusionRequest *)requestWithInt64Number:(nullable NSNumber *)number
                                                 error:(NSError **)error;

/**
 Creates a request that can be used to send the given string using messaging.

 @param string The value to send as the request. This may be `nil` in order to
 create a 'null' request.

 @param error Location to store a reason if this method returns `nil` to
 indicate failure.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.0
 */
+(nullable PTDiffusionRequest *)requestWithString:(nullable NSString *)string
                                            error:(NSError **)error;

/**
 Creates a response that can be used to send the given double-precision floating
 point (Eight-byte IEEE 754) value using messaging.

 @param value The value to send as the response.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(PTDiffusionResponse *)responseWithDouble:(double)value;

/**
 Creates a response that can be used to send the given double-precision floating
 point (Eight-byte IEEE 754) value using messaging.

 @param number The value to send as the response. This may be `nil` in order to
 create a 'null' response.

 @param error Location to store a reason if this method returns `nil` to
 indicate failure.

 @return The new response, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(nullable PTDiffusionResponse *)responseWithDoubleFloatNumber:(nullable NSNumber *)number
                                                         error:(NSError **)error;

/**
 Creates a response that can be used to send the given 64-bit integer value
 using messaging.

 @param value The value to send as the response.

 @return The new request, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(PTDiffusionResponse *)responseWithLongLong:(long long)value;

/**
 Creates a response that can be used to send the given 64-bit integer value
 using messaging.

 @param number The value to send as the response. This may be `nil` in order to
 create a 'null' response.

 @param error Location to store a reason if this method returns `nil` to
 indicate failure.

 @return The new response, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(nullable PTDiffusionResponse *)responseWithInt64Number:(nullable NSNumber *)number
                                                   error:(NSError **)error;

/**
 Creates a response that can be used to send the given string using messaging.

 @param string The value to send as the response. This may be `nil` in order to
 create a 'null' response.

 @param error Location to store a reason if this method returns `nil` to
 indicate failure.

 @return The new response, or `nil` on failure.

 @see PTDiffusionMessagingFeature

 @since 6.1
 */
+(nullable PTDiffusionResponse *)responseWithString:(nullable NSString *)string
                                              error:(NSError **)error;

/**
 Returns an update constraint requiring the current value of a topic to exactly match
 the given double-precision floating point (Eight-byte IEEE 754) value.

 This is exactly equivalent to calling {@link PTDiffusionPrimitive#updateConstraintWithDouble:comparisonOperator:error},
 specifying the {@link PTDiffusionUpdateConstraintOperator#is IS} operator.

 Use PTDiffusionUpdateConstraint#noValue to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param value   The value to be matched against the topic value.

 @return        The new constraint, or `nil` on failure.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPrimitive#updateConstraintWithDouble:comparisonOperator:error} instead.
 */
+(PTDiffusionUpdateConstraint *)updateConstraintWithDouble:(double)value __deprecated_msg("Will be removed in a future release");


/**
 Returns an update constraint comparing the current value of a topic to the
 given double-precision floating point (Eight-byte IEEE 754) value.

 This update constraint will work with {@link PTDiffusionTopicType_String STRING},
 {@link PTDiffusionTopicType_Int64 INT64} or {@link PTDiffusionTopicType_Double DOUBLE}
 topics (or {@link PTDiffusionTopicType_TimeSeries TIME_SERIES} topics with a
 primitive event type) only.

 {@link PTDiffusionTopicType_String STRING} topics can only be compared if they contain
 a value that can be parsed as a number.

 If the value of a {@link PTDiffusionTopicType_String STRING} topic cannot be parsed
 as a number, or the topic is of any other non-number type, the constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS}) can
 be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 When a {@link PTDiffusionTopicType_String STRING}, {@link PTDiffusionTopicType_Int64 INT64}
 or {@link PTDiffusionTopicType_Double DOUBLE} topic is updated to a `null` value,
 the topic is set to have no value. Use the {@link PTDiffusionUpdateConstraint#noValue}
 constraint to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param value               The value to be compared against the topic value.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason if this method returns `nil` to
                            indicate failure.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithDouble:(double)value
                                                 comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                                              error:(NSError *__autoreleasing *const)error;


/**
 Returns an update constraint requiring the current value of a topic to exactly match
 the given double-precision floating point (Eight-byte IEEE 754) value.

 This is exactly equivalent to calling {@link PTDiffusionPrimitive#updateConstraintWithDoubleFloatNumber:comparisonOperator:error},
 specifying the {@link PTDiffusionUpdateConstraintOperator#is IS} operator.

 Use PTDiffusionUpdateConstraint#noValue to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param number  The value to be matched against the topic value.
 @param error   Location to store a reason if this method returns `nil` to
                indicate failure.

 @return        The new constraint, or `nil` on failure.

 @exception     NSInvalidArgumentException If the number argument is `nil`.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPrimitive#updateConstraintWithDoubleFloatNumber:comparisonOperator:error} instead.
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithDoubleFloatNumber:(NSNumber *)number
                                                                         error:(NSError *__autoreleasing *const)error __deprecated_msg("Will be removed in a future release");


/**
 Returns an update constraint comparing the current value of a topic to the
 given double-precision floating point (Eight-byte IEEE 754) value.

 This update constraint will work with {@link PTDiffusionTopicType_String STRING},
 {@link PTDiffusionTopicType_Int64 INT64} or {@link PTDiffusionTopicType_Double DOUBLE}
 topics (or {@link PTDiffusionTopicType_TimeSeries TIME_SERIES} topics with a
 primitive event type) only.

 {@link PTDiffusionTopicType_String STRING} topics can only be compared if they contain
 a value that can be parsed as a number.

 If the value of a {@link PTDiffusionTopicType_String STRING} topic cannot be parsed
 as a number, or the topic is of any other non-number type, the constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS}) can
 be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 When a {@link PTDiffusionTopicType_String STRING}, {@link PTDiffusionTopicType_Int64 INT64}
 or {@link PTDiffusionTopicType_Double DOUBLE} topic is updated to a `null` value,
 the topic is set to have no value. Use the {@link PTDiffusionUpdateConstraint#noValue}
 constraint to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param number              The value to be compared against the topic value.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason if this method returns `nil` to
                            indicate failure.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithDoubleFloatNumber:(nullable NSNumber *)number
                                                            comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                                                         error:(NSError *__autoreleasing *const)error;


/**
 Returns an update constraint requiring the current value of a topic to exactly match
 the given 64-bit integer value.

 This is exactly equivalent to calling {@link PTDiffusionPrimitive#updateConstraintWithLongLong:comparisonOperator:error},
 specifying the {@link PTDiffusionUpdateConstraintOperator#is IS} operator.

 Use PTDiffusionUpdateConstraint#noValue to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param value   The value to be matched against the topic value.

 @return        The new constraint, or `nil` on failure.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPrimitive#updateConstraintWithLongLong:comparisonOperator:error} instead.
 */
+(PTDiffusionUpdateConstraint *)updateConstraintWithLongLong:(long long)value __deprecated_msg("Will be removed in a future release");


/**
 Returns an update constraint comparing the current value of a topic to the
 given 64-bit integer value.

 This update constraint will work with {@link PTDiffusionTopicType_String STRING},
 {@link PTDiffusionTopicType_Int64 INT64} or {@link PTDiffusionTopicType_Double DOUBLE}
 topics (or {@link PTDiffusionTopicType_TimeSeries TIME_SERIES} topics with a
 primitive event type) only.

 {@link PTDiffusionTopicType_String STRING} topics can only be compared if they contain
 a value that can be parsed as a number.

 If the value of a {@link PTDiffusionTopicType_String STRING} topic cannot be parsed
 as a number, or the topic is of any other non-number type, the constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS}) can
 be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 When a {@link PTDiffusionTopicType_String STRING}, {@link PTDiffusionTopicType_Int64 INT64}
 or {@link PTDiffusionTopicType_Double DOUBLE} topic is updated to a `null` value,
 the topic is set to have no value. Use the {@link PTDiffusionUpdateConstraint#noValue}
 constraint to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param value               The value to be compared against the topic value.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason if this method returns `nil` to
                            indicate failure.

 @return The new constraint, or `nil` on failure.

 @since 6.10
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithLongLong:(long long)value
                                                   comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                                                error:(NSError *__autoreleasing *const)error;


/**
 Returns an update constraint requiring the current value of a topic to exactly match
 the given 64-bit integer value.

 This is exactly equivalent to calling {@link PTDiffusionPrimitive#updateConstraintWithInt64Number:comparisonOperator:error},
 specifying the {@link PTDiffusionUpdateConstraintOperator#is IS} operator.

 Use PTDiffusionUpdateConstraint#noValue to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param number  The value to be matched against the topic value.
 @param error   Location to store a reason if this method returns `nil` to
                indicate failure.

 @return        The new constraint, or `nil` on failure.

 @exception     NSInvalidArgumentException If the number argument is `nil`.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPrimitive#updateConstraintWithInt64Number:comparisonOperator:error} instead.
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithInt64Number:(NSString *)number
                                                                   error:(NSError *__autoreleasing *const)error __deprecated_msg("Will be removed in a future release");


/**
 Returns an update constraint comparing the current value of a topic to the
 given 64-bit integer value.

 This update constraint will work with {@link PTDiffusionTopicType_String STRING},
 {@link PTDiffusionTopicType_Int64 INT64} or {@link PTDiffusionTopicType_Double DOUBLE}
 topics (or {@link PTDiffusionTopicType_TimeSeries TIME_SERIES} topics with a
 primitive event type) only.

 {@link PTDiffusionTopicType_String STRING} topics can only be compared if they contain
 a value that can be parsed as a number.

 If the value of a {@link PTDiffusionTopicType_String STRING} topic cannot be parsed
 as a number, or the topic is of any other non-number type, the constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS}) can
 be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 When a {@link PTDiffusionTopicType_String STRING}, {@link PTDiffusionTopicType_Int64 INT64}
 or {@link PTDiffusionTopicType_Double DOUBLE} topic is updated to a `null` value,
 the topic is set to have no value. Use the {@link PTDiffusionUpdateConstraint#noValue}
 constraint to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param value               The value to be compared against the topic value.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason if this method returns `nil` to
                            indicate failure.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithInt64Number:(nullable NSNumber *)number
                                                      comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                                                   error:(NSError *__autoreleasing *const)error;


/**
 Returns an update constraint requiring the current value of a topic to exactly match
 the given string value.

 This is exactly equivalent to calling {@link PTDiffusionPrimitive#updateConstraintWithString:comparisonOperator:error},
 specifying the {@link PTDiffusionUpdateConstraintOperator#is IS} operator.

 Use PTDiffusionUpdateConstraint#noValue to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param string  The value to be matched against the topic value.
 @param error   Location to store a reason if this method returns `nil` to
                indicate failure.

 @return        The new constraint, or `nil` on failure.

 @exception     NSInvalidArgumentException If the number argument is `nil`.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPrimitive#updateConstraintWithString:comparisonOperator:error} instead.
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithString:(NSString *)string
                                                              error:(NSError *__autoreleasing *const)error __deprecated_msg("Will be removed in a future release");


/**
 Returns an update constraint comparing the current value of a topic to the
 given string value.

 If the operator is {@link PTDiffusionUpdateConstraintOperator#eq EQ} or
 {@link PTDiffusionUpdateConstraintOperator#ne NE}, the string representation of
 the topic will be compared to the supplied value.

 This can only be used with primitive topic types (or {@link PTDiffusionTopicType_TimeSeries
 TIME_SERIES} topics with a primitive event type).

 Other operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS}) are
 not permitted with String values.

 When a {@link PTDiffusionTopicType_String STRING}, {@link PTDiffusionTopicType_Int64 INT64}
 or {@link PTDiffusionTopicType_Double DOUBLE} topic is updated to a `null` value,
 the topic is set to have no value. Use the {@link PTDiffusionUpdateConstraint#noValue}
 constraint to check if the topic has no value.

 This constraint is unsatisfied if no topic is present at the path.

 @param string              The value to be compared against the topic value.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason if this method returns `nil` to
                            indicate failure.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
+(nullable PTDiffusionUpdateConstraint *)updateConstraintWithString:(nullable NSString *)string
                                                 comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                                              error:(NSError *__autoreleasing *const)error;

@end



/**
 @brief Extension adding support for responding to requests using primitive
 values.

 @since 6.0
 */
@interface PTDiffusionResponder (PTDiffusionPrimitive)

/**
 Dispatch a double-precision floating point (Eight-byte IEEE 754) response to a
 request.

 @param value The value to send in response.

 @since 6.0
 */
-(void)respondWithDouble:(double)value;

/**
 Dispatch a double-precision floating point (Eight-byte IEEE 754) response to a
 request.

 @param number The value to send in response. This may be `nil` in order to send
 a 'null' response.

 @param error Location to store a reason if this method returns `NO` to
 indicate failure.

 @return `YES` if a response was queued for dispatch or `NO` if the supplied
 number could not be encoded using this data type.

 @since 6.0
 */
-(BOOL)respondWithDoubleFloatNumber:(nullable NSNumber *)number
                              error:(NSError **)error;

/**
 Dispatch a 64-bit integer response to a request.

 @param value The value to send in response.

 @since 6.0
 */
-(void)respondWithLongLong:(long long)value;

/**
 Dispatch a 64-bit integer response to a request.

 @param number The value to send in response. This may be `nil` in order to send
 a 'null' response.

 @param error Location to store a reason if this method returns `NO` to
 indicate failure.

 @return `YES` if a response was queued for dispatch or `NO` if the supplied
 number could not be encoded using this data type.

 @since 6.0
 */
-(BOOL)respondWithInt64Number:(nullable NSNumber *)number
                        error:(NSError **)error;

/**
 Dispatch a string response to a request.

 @param string The value to send in response. This may be `nil` in order to send
 a 'null' response.

 @param error Location to store a reason if this method returns `NO` to
 indicate failure.

 @return `YES` if a response was queued for dispatch or `NO` if the supplied
 string could not be encoded using this data type.

 @since 6.0
 */
-(BOOL)respondWithString:(nullable NSString *)string
                   error:(NSError **)error;

@end

/**
 @brief Extension adding support to the Messaging feature for sending requests
 accepting a primitive value in response.

 @since 6.0
 */
@interface PTDiffusionMessagingFeature (PTDiffusionPrimitive)

/**
 Send a request for which a string response is expected.

 The message will be routed to an appropriately registered control handler for
 the given path.

 @param request The request to send.

 @param path The path to send the request to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)         sendRequest:(PTDiffusionRequest *)request
                     toPath:(NSString *)path
    stringCompletionHandler:(void (^)(NSString * _Nullable string, NSError * _Nullable error))completionHandler;

/**
 Send a request for which a double-precision floating point (Eight-byte IEEE 754)
 response is expected.

 The message will be routed to an appropriately registered control handler for
 the given path.

 @param request The request to send.

 @param path The path to send the request to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)                    sendRequest:(PTDiffusionRequest *)request
                                toPath:(NSString *)path
    doubleFloatNumberCompletionHandler:(void (^)(NSNumber * _Nullable number, NSError * _Nullable error))completionHandler;

/**
 Send a request for which a 64-bit integer response is expected.

 The message will be routed to an appropriately registered control handler for
 the given path.

 @param request The request to send.

 @param path The path to send the request to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)              sendRequest:(PTDiffusionRequest *)request
                          toPath:(NSString *)path
    int64NumberCompletionHandler:(void (^)(NSNumber * _Nullable number, NSError * _Nullable error))completionHandler;


/**
 Send a request to a session for which a string response is expected.

 @param request The request to send.

 @param sessionId The session to send the request to.

 @param path The path to send the request to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.5
 */
-(void)         sendRequest:(PTDiffusionRequest *)request
                toSessionId:(PTDiffusionSessionId *)sessionId
                       path:(NSString *)path
    stringCompletionHandler:(void (^)(NSString * _Nullable string, NSError * _Nullable error))completionHandler;

/**
 Send a request to a session for which a double-precision floating point
 (Eight-byte IEEE 754) response is expected.

 @param request The request to send.

 @param sessionId The session to send the request to.

 @param path The path to send the request to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.5
 */
-(void)                    sendRequest:(PTDiffusionRequest *)request
                           toSessionId:(PTDiffusionSessionId *)sessionId
                                  path:(NSString *)path
    doubleFloatNumberCompletionHandler:(void (^)(NSNumber * _Nullable string, NSError * _Nullable error))completionHandler;

/**
 Send a request to a session for which a 64-bit integer response is expected.

 @param request The request to send.

 @param sessionId The session to send the request to.

 @param path The path to send the request to.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.5
 */
-(void)              sendRequest:(PTDiffusionRequest *)request
                     toSessionId:(PTDiffusionSessionId *)sessionId
                            path:(NSString *)path
    int64NumberCompletionHandler:(void (^)(NSNumber * _Nullable string, NSError * _Nullable error))completionHandler;


@end


/**
 @brief Extension adding support to the Time Series feature for appending and
 editing events using primitive values.

 @since 6.0
 */
@interface PTDiffusionTimeSeriesFeature (PTDiffusionPrimitive)

/**
 Update a time series topic by appending a new string value.

 The server will add an event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param value The event value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)appendToTopicPath:(NSString *)topicPath
             stringValue:(nullable NSString *)value
       completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new string value with a supplied
 timestamp.

 The server will add an event to the end of the time series based on the
 supplied value and timestamp, with a new sequence number, and the author
 set to the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param value The event value.

 @param timestamp The supplied timestamp, must be greater or equal to that
 of the most recent event appended to the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.6
 */
-(void)appendToTopicPath:(NSString *)topicPath
             stringValue:(nullable NSString *)value
               timestamp:(NSDate *)timestamp
       completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new double-precision floating point
 (Eight-byte IEEE 754) value.

 The server will add an event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param value The event value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)  appendToTopicPath:(NSString *)topicPath
    doubleFloatNumberValue:(nullable NSNumber *)value
         completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new double-precision floating point
 (Eight-byte IEEE 754) value with a supplied timestamp.

 The server will add an event to the end of the time series based on the
 supplied value and timestamp, with a new sequence number, and the author
 set to the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param value The event value.

 @param timestamp The supplied timestamp, must be greater or equal to that
 of the most recent event appended to the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.6
 */
-(void)  appendToTopicPath:(NSString *)topicPath
    doubleFloatNumberValue:(nullable NSNumber *)value
                 timestamp:(NSDate *)timestamp
         completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new 64-bit integer value.

 The server will add an event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param value The event value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)appendToTopicPath:(NSString *)topicPath
        int64NumberValue:(nullable NSNumber *)value
       completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new 64-bit integer value with a supplied
 timestamp.

 The server will add an event to the end of the time series based on the
 supplied value and timestamp, with a new sequence number, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param value The event value.

 @param timestamp The supplied timestamp, must be greater or equal to that
 of the most recent event appended to the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.6
 */
-(void)appendToTopicPath:(NSString *)topicPath
        int64NumberValue:(nullable NSNumber *)value
               timestamp:(NSDate *)timestamp
       completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new string value that overrides the
 value of an existing event.

 The existing event is identified by its sequence number and must be an original
 event.

 The server will add an edit event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param originalSequence The sequence number of the original event to edit.

 @param value The event value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any of the topicPath, value or
 completionHandler arguments are `nil`. Also raised if the originalSequence
 argument exceeds `INT64_MAX`.

 @since 6.0
 */
-(void)editAtTopicPath:(NSString *)topicPath
      originalSequence:(UInt64)originalSequence
           stringValue:(nullable NSString *)value
     completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new double-precision floating point
 (Eight-byte IEEE 754) value that overrides the value of an existing event.

 The existing event is identified by its sequence number and must be an original
 event.

 The server will add an edit event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param originalSequence The sequence number of the original event to edit.

 @param value The event value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any of the topicPath, value or
 completionHandler arguments are `nil`. Also raised if the originalSequence
 argument exceeds `INT64_MAX`.

 @since 6.0
 */
-(void)    editAtTopicPath:(NSString *)topicPath
          originalSequence:(UInt64)originalSequence
    doubleFloatNumberValue:(nullable NSNumber *)value
         completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Update a time series topic by appending a new 64-bit integer value that
 overrides the value of an existing event.

 The existing event is identified by its sequence number and must be an original
 event.

 The server will add an edit event to the end of the time series based on the
 supplied value, with a new sequence number, timestamp, and the author set to
 the authenticated principal of the session.

 @param topicPath The path of the time series topic to update.

 @param originalSequence The sequence number of the original event to edit.

 @param value The event value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any of the topicPath, value or
 completionHandler arguments are `nil`. Also raised if the originalSequence
 argument exceeds `INT64_MAX`.

 @since 6.0
 */
-(void)editAtTopicPath:(NSString *)topicPath
      originalSequence:(UInt64)originalSequence
      int64NumberValue:(nullable NSNumber *)value
     completionHandler:(void (^)(PTDiffusionTimeSeriesEventMetadata * _Nullable eventMetadata, NSError * _Nullable error))completionHandler;

/**
 Evaluate a query for a time series topic where events have string values.

 @param query The configured query.

 @param topicPath The path of the time series topic to query.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)       evaluateQuery:(PTDiffusionTimeSeriesRangeQuery *)query
                atTopicPath:(NSString *)topicPath
    stringCompletionHandler:(void (^)(PTDiffusionStringTimeSeriesQueryResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Evaluate a query for a time series topic where events have double-precision
 floating point (Eight-byte IEEE 754) values.

 @param query The configured query.

 @param topicPath The path of the time series topic to query.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)                  evaluateQuery:(PTDiffusionTimeSeriesRangeQuery *)query
                           atTopicPath:(NSString *)topicPath
    doubleFloatNumberCompletionHandler:(void (^)(PTDiffusionNumberTimeSeriesQueryResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Evaluate a query for a time series topic where events have 64-bit integer
 values.

 @param query The configured query.

 @param topicPath The path of the time series topic to query.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.0
 */
-(void)            evaluateQuery:(PTDiffusionTimeSeriesRangeQuery *)query
                     atTopicPath:(NSString *)topicPath
    int64NumberCompletionHandler:(void (^)(PTDiffusionNumberTimeSeriesQueryResult * _Nullable result, NSError * _Nullable error))completionHandler;

@end

/**
 @brief Extension adding support to Topics feature fetch requests allowing them
 to be constrained to only those topics with a data type compatible with
 primitive values.

 @since 6.2
 */
@interface PTDiffusionFetchRequest (PTDiffusionPrimitive)

/**
 Sends a fetch request to the server, specifying that values should be returned
 for selected topics, constraining the selection to only those topics with a
 data type compatible with string.

 The string data type constrains the topic types. So, any topic types specified
 in a previous call to PTDiffusionFetchRequest::topicTypes: that cannot be read as strings will be
 removed from the list of topic types.

 Results are returned for all topics matching the selector that satisfy the
 request constraints within any range defined by PTDiffusionFetchRequest::fromTopicPath: /
 PTDiffusionFetchRequest::afterTopicPath: and/or PTDiffusionFetchRequest::toTopicPath: /
 PTDiffusionFetchRequest::beforeTopicPath:

 @param expression Specifies a @ref md_topic_selectors "topic selector",
 evaluated at the server, which selects the topics to be fetched.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.2
 */
-(void)fetchStringValuesWithTopicSelectorExpression:(NSString *)expression
                                  completionHandler:(void (^)(PTDiffusionStringFetchResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Sends a fetch request to the server, specifying that values should be returned
 for selected topics, constraining the selection to only those topics with a
 data type compatible with double-precision floating point (Eight-byte IEEE
 754).

 The doubleFloat data type constrains the topic types. So, any topic types
 specified in a previous call to PTDiffusionFetchRequest::topicTypes: that cannot be read as
 double-precision floating point (Eight-byte IEEE 754) will be removed from the
 list of topic types.

 Results are returned for all topics matching the selector that satisfy the
 request constraints within any range defined by PTDiffusionFetchRequest::fromTopicPath: /
 PTDiffusionFetchRequest::afterTopicPath: and/or PTDiffusionFetchRequest::toTopicPath: /
 PTDiffusionFetchRequest::beforeTopicPath:

 @param expression Specifies a @ref md_topic_selectors "topic selector",
 evaluated at the server, which selects the topics to be fetched.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.2
 */
-(void)fetchDoubleFloatNumberValuesWithTopicSelectorExpression:(NSString *)expression
                                             completionHandler:(void (^)(PTDiffusionNumberFetchResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Sends a fetch request to the server, specifying that values should be returned
 for selected topics, constraining the selection to only those topics with a
 data type compatible with 64-bit integer.

 The int64 data type constrains the topic types. So, any topic types specified
 in a previous call to PTDiffusionFetchRequest::topicTypes: that cannot be read as 64-bit integer will
 be removed from the list of topic types.

 Results are returned for all topics matching the selector that satisfy the
 request constraints within any range defined by PTDiffusionFetchRequest::fromTopicPath: /
 PTDiffusionFetchRequest::afterTopicPath: and/or PTDiffusionFetchRequest::toTopicPath: /
 PTDiffusionFetchRequest::beforeTopicPath:

 @param expression Specifies a @ref md_topic_selectors "topic selector",
 evaluated at the server, which selects the topics to be fetched.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException Raised if any supplied arguments are `nil`.

 @since 6.2
 */
-(void)fetchInt64NumberValuesWithTopicSelectorExpression:(NSString *)expression
                                       completionHandler:(void (^)(PTDiffusionNumberFetchResult * _Nullable result, NSError * _Nullable error))completionHandler;

@end

/**
 @brief Extension adding support to the Topic Update feature for updating topics
 with primitive values.

 @since 6.3
 */
@interface PTDiffusionTopicUpdateFeature (PTDiffusionPrimitive)

/**
 Sets a topic to a specified string value, or null.

 @param path The path of the topic.

 @param value The value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If either path or completionHandler are
 `nil`.

 @since 6.3
 */
-(BOOL)   setWithPath:(NSString *)path
        toStringValue:(nullable NSString *)value
    completionHandler:(void (^)(NSError * _Nullable error))completionHandler
                error:(NSError **)error;

/**
 Sets a topic to a specified double-precision floating point (Eight-byte IEEE
 754) value.

 @param path The path of the topic.

 @param value The value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException If either path or completionHandler are
 `nil`.

 @since 6.3
 */
-(void)   setWithPath:(NSString *)path
        toDoubleValue:(double)value
    completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Sets a topic to a specified double-precision floating point (Eight-byte IEEE
 754) number value, or null.

 @param path The path of the topic.

 @param value The value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If either path or completionHandler are
 `nil`.

 @since 6.3
 */
-(BOOL)          setWithPath:(NSString *)path
    toDoubleFloatNumberValue:(nullable NSNumber *)value
           completionHandler:(void (^)(NSError * _Nullable error))completionHandler
                       error:(NSError **)error;

/**
 Sets a topic to a specified 64-bit integer value.

 @param path The path of the topic.

 @param value The value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException If either path or completionHandler are
 `nil`.

 @since 6.3
 */
-(void)   setWithPath:(NSString *)path
      toLongLongValue:(long long)value
    completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Sets a topic to a specified 64-bit integer number value, or null.

 @param path The path of the topic.

 @param value The value.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If either path or completionHandler are
 `nil`.

 @since 6.3
 */
-(BOOL)    setWithPath:(NSString *)path
    toInt64NumberValue:(nullable NSNumber *)value
     completionHandler:(void (^)(NSError * _Nullable error))completionHandler
                 error:(NSError **)error;

/**
 Sets a topic to a specified string value, or null, if a constraint is
 satisfied.

 @param path The path of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of path, constraint or
 completionHandler are `nil`.

 @since 6.3
 */
-(BOOL)   setWithPath:(NSString *)path
        toStringValue:(nullable NSString *)value
           constraint:(PTDiffusionUpdateConstraint *)constraint
    completionHandler:(void (^)(NSError * _Nullable error))completionHandler
                error:(NSError **)error;

/**
 Sets a topic to a specified double-precision floating point (Eight-byte IEEE
 754) value if a constraint is satisfied.

 @param path The path of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException If any of path, constraint or
 completionHandler are `nil`.

 @since 6.3
 */
-(void)   setWithPath:(NSString *)path
        toDoubleValue:(double)value
           constraint:(PTDiffusionUpdateConstraint *)constraint
    completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Sets a topic to a specified double-precision floating point (Eight-byte IEEE
 754) number value, or null, if a constraint is satisfied.

 @param path The path of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of path, constraint or
 completionHandler are `nil`.

 @since 6.3
 */
-(BOOL)          setWithPath:(NSString *)path
    toDoubleFloatNumberValue:(nullable NSNumber *)value
                  constraint:(PTDiffusionUpdateConstraint *)constraint
           completionHandler:(void (^)(NSError * _Nullable error))completionHandler
                       error:(NSError **)error;

/**
 Sets a topic to a specified 64-bit integer value if a constraint is satisfied.

 @param path The path of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException If any of path, constraint or
 completionHandler are `nil`.

 @since 6.3
 */
-(void)   setWithPath:(NSString *)path
      toLongLongValue:(long long)value
           constraint:(PTDiffusionUpdateConstraint *)constraint
    completionHandler:(void (^)(NSError * _Nullable error))completionHandler;

/**
 Sets a topic to a specified 64-bit integer number value, or null, if a
 constraint is satisfied.

 @param path The path of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of path, constraint or
 completionHandler are `nil`.

 @since 6.3
 */
-(BOOL)    setWithPath:(NSString *)path
    toInt64NumberValue:(nullable NSNumber *)value
            constraint:(PTDiffusionUpdateConstraint *)constraint
     completionHandler:(void (^)(NSError * _Nullable error))completionHandler
                 error:(NSError **)error;

/**
 Ensures a topic exists and sets it to a string value, or null.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:completionHandler:.

 @param path The path of the topic.

 @param value The value.

 @param specification The required specification of the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of the path, specification or
 completionHandler arguments are `nil`. Also if the topic type defined in the
 specification is incompatible with PTDiffusionDataTypes#string.

 @since 6.3
 */
-(BOOL)     addWithPath:(NSString *)path
          specification:(PTDiffusionTopicSpecification *)specification
    andSetToStringValue:(nullable NSString *)value
      completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler
                  error:(NSError **)error;

/**
 Ensures a topic exists and sets it to a double-precision floating point
 (Eight-byte IEEE 754) value.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:completionHandler:.

 @param path The path of the topic.

 @param value The value.

 @param specification The required specification of the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any of the path, specification or
 completionHandler arguments are `nil`. Also if the topic type defined in the
 specification is incompatible with PTDiffusionDataTypes#doubleFloat.

 @since 6.3
 */
-(void)     addWithPath:(NSString *)path
          specification:(PTDiffusionTopicSpecification *)specification
    andSetToDoubleValue:(double)value
      completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Ensures a topic exists and sets it to a double-precision floating point
 (Eight-byte IEEE 754) number value, or null.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:completionHandler:.

 @param path The path of the topic.

 @param value The value.

 @param specification The required specification of the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of the path, specification or
 completionHandler arguments are `nil`. Also if the topic type defined in the
 specification is incompatible with PTDiffusionDataTypes#doubleFloat.

 @since 6.3
 */
-(BOOL)                addWithPath:(NSString *)path
                     specification:(PTDiffusionTopicSpecification *)specification
    andSetToDoubleFloatNumberValue:(nullable NSNumber *)value
                 completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler
                             error:(NSError **)error;

/**
 Ensures a topic exists and sets it to a 64-bit integer value.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:completionHandler:.

 @param path The path of the topic.

 @param value The value.

 @param specification The required specification of the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any of the path, specification or
 completionHandler arguments are `nil`. Also if the topic type defined in the
 specification is incompatible with PTDiffusionDataTypes#int64.

 @since 6.3
 */
-(void)        addWithPath:(NSString *)path
             specification:(PTDiffusionTopicSpecification *)specification
     andSetToLongLongValue:(long long)value
         completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Ensures a topic exists and sets it to a 64-bit integer number value, or null.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:completionHandler:.

 @param path The path of the topic.

 @param value The value.

 @param specification The required specification of the topic.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of the path, specification or
 completionHandler arguments are `nil`. Also if the topic type defined in the
 specification is incompatible with PTDiffusionDataTypes#int64.

 @since 6.3
 */
-(BOOL)          addWithPath:(NSString *)path
               specification:(PTDiffusionTopicSpecification *)specification
    andSetToInt64NumberValue:(nullable NSNumber *)value
           completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler
                       error:(NSError **)error;

/**
 Ensures a topic exists and sets it to a string value, or null, if a constraint
 is satisfied.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:constraint:completionHandler:.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of the path, specification or
 completionHandler arguments are `nil`. Also if the topic type defined in the
 specification is incompatible with PTDiffusionDataTypes#string.

 @since 6.3
 */
-(BOOL)     addWithPath:(NSString *)path
          specification:(PTDiffusionTopicSpecification *)specification
    andSetToStringValue:(nullable NSString *)value
             constraint:(PTDiffusionUpdateConstraint *)constraint
      completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler
                  error:(NSError **)error;

/**
 Ensures a topic exists and sets it to a double-precision floating point
 (Eight-byte IEEE 754) value if a constraint is satisfied.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:constraint:completionHandler:.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any of the path, specification,
 constraint or completionHandler arguments are `nil`. Also if the topic type
 defined in the specification is incompatible with
 PTDiffusionDataTypes#doubleFloat.

 @since 6.3
 */
-(void)     addWithPath:(NSString *)path
          specification:(PTDiffusionTopicSpecification *)specification
    andSetToDoubleValue:(double)value
             constraint:(PTDiffusionUpdateConstraint *)constraint
      completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Ensures a topic exists and sets it to a double-precision floating point
 (Eight-byte IEEE 754) number value, or null, if a constraint is satisfied.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:constraint:completionHandler:.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of the path, specification,
 constraint or completionHandler arguments are `nil`. Also if the topic type
 defined in the specification is incompatible with
 PTDiffusionDataTypes#doubleFloat.

 @since 6.3
 */
-(BOOL)                addWithPath:(NSString *)path
                     specification:(PTDiffusionTopicSpecification *)specification
    andSetToDoubleFloatNumberValue:(nullable NSNumber *)value
                        constraint:(PTDiffusionUpdateConstraint *)constraint
                 completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler
                             error:(NSError **)error;

/**
 Ensures a topic exists and sets it to a 64-bit integer value if a constraint is
 satisfied.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:constraint:completionHandler:.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any of the path, specification,
 constraint or completionHandler arguments are `nil`. Also if the topic type
 defined in the specification is incompatible with PTDiffusionDataTypes#int64.

 @since 6.3
 */
-(void)        addWithPath:(NSString *)path
             specification:(PTDiffusionTopicSpecification *)specification
     andSetToLongLongValue:(long long)value
                constraint:(PTDiffusionUpdateConstraint *)constraint
         completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler;

/**
 Ensures a topic exists and sets it to a 64-bit integer number value, or null,
 if a constraint is satisfied.

 If a topic does not exist at the path, one will be created using the
 specification. If a topic does exist, its specification must match
 specification, otherwise the operation will fail.

 In other respects this method works in the same way as
 setWithPath:toJSONValue:constraint:completionHandler:.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param value The value.

 @param constraint The constraint that must be satisfied for the topic to be
 updated.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `result` will be non-`nil`. The completion handler will
 be called asynchronously on the main dispatch queue.

 @param error If this method returns `NO` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return `YES` on success; or `NO` if an error occurred, in which case `*error`
 will be populated with the failure reason.

 @exception NSInvalidArgumentException If any of the path, specification,
 constraint or completionHandler arguments are `nil`. Also if the topic type
 defined in the specification is incompatible with PTDiffusionDataTypes#int64.

 @since 6.3
 */
-(BOOL)          addWithPath:(NSString *)path
               specification:(PTDiffusionTopicSpecification *)specification
    andSetToInt64NumberValue:(nullable NSNumber *)value
                  constraint:(PTDiffusionUpdateConstraint *)constraint
           completionHandler:(void (^)(PTDiffusionTopicCreationResult * _Nullable result, NSError * _Nullable error))completionHandler
                       error:(NSError **)error;

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

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionStringUpdateStream *)stringUpdateStreamWithPath:(NSString *)path __deprecated_msg("Will be removed in a future release.");

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

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)doubleFloatNumberUpdateStreamWithPath:(NSString *)path __deprecated_msg("Will be removed in a future release.");

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

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)int64NumberUpdateStreamWithPath:(NSString *)path __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for updating a specific topic with string
 values if a constraint is satisfied.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param constraint The constraint that must be satisfied for the update stream
 to be validated.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionStringUpdateStream *)stringUpdateStreamWithPath:(NSString *)path
                                                  constraint:(PTDiffusionUpdateConstraint *)constraint __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for updating a specific topic with
 double-precision floating point (Eight-byte IEEE 754) values if a constraint is
 satisfied.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param constraint The constraint that must be satisfied for the update stream
 to be validated.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)doubleFloatNumberUpdateStreamWithPath:(NSString *)path
                                                             constraint:(PTDiffusionUpdateConstraint *)constraint __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for updating a specific topic with 64-bit
 integer values if a constraint is satisfied.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param constraint The constraint that must be satisfied for the update stream
 to be validated.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)int64NumberUpdateStreamWithPath:(NSString *)path
                                                       constraint:(PTDiffusionUpdateConstraint *)constraint __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for creating and updating a specific topic with
 string values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil` or the topic
 type defined in the specification is incompatible with
 PTDiffusionDataTypes#string.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionStringUpdateStream *)stringUpdateStreamWithPath:(NSString *)path
                                               specification:(PTDiffusionTopicSpecification *)specification __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for creating and updating a specific topic with
 double-precision floating point (Eight-byte IEEE 754) values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil` or the topic
 type defined in the specification is incompatible with
 PTDiffusionDataTypes#doubleFloat.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)doubleFloatNumberUpdateStreamWithPath:(NSString *)path
                                                          specification:(PTDiffusionTopicSpecification *)specification __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for creating and updating a specific topic with
 64-bit integer values.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil` or the topic
 type defined in the specification is incompatible with
 PTDiffusionDataTypes#int64.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)int64NumberUpdateStreamWithPath:(NSString *)path
                                                    specification:(PTDiffusionTopicSpecification *)specification __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for creating and updating a specific topic with
 string values if a constraint is satisfied.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param constraint The constraint that must be satisfied for the update stream
 to be validated.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil` or the topic
 type defined in the specification is incompatible with
 PTDiffusionDataTypes#string.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionStringUpdateStream *)stringUpdateStreamWithPath:(NSString *)path
                                               specification:(PTDiffusionTopicSpecification *)specification
                                                  constraint:(PTDiffusionUpdateConstraint *)constraint __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for creating and updating a specific topic with
 double-precision floating point (Eight-byte IEEE 754) values if a constraint is
 satisfied.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param constraint The constraint that must be satisfied for the update stream
 to be validated.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil` or the topic
 type defined in the specification is incompatible with
 PTDiffusionDataTypes#doubleFloat.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)doubleFloatNumberUpdateStreamWithPath:(NSString *)path
                                                          specification:(PTDiffusionTopicSpecification *)specification
                                                             constraint:(PTDiffusionUpdateConstraint *)constraint __deprecated_msg("Will be removed in a future release.");

/**
 Creates an update stream to use for creating and updating a specific topic with
 64-bit integer values if a constraint is satisfied.

 Update streams send a sequence of updates for a specific topic. The updates may
 be delivered to the server as binary deltas. They do not provide exclusive
 access to the topic. If exclusive access is required update streams should be
 used with session locks as constraints.

 Streams are validated lazily when the first 'set' or 'validate' operation is
 completed. Once validated a stream can be invalidated, after which it rejects
 future updates.

 @param path The path of the topic.

 @param specification The required specification of the topic.

 @param constraint The constraint that must be satisfied for the update stream
 to be validated.

 @return An update stream.

 @exception NSInvalidArgumentException If any argument is `nil` or the topic
 type defined in the specification is incompatible with
 PTDiffusionDataTypes#int64.

 @deprecated since 6.9. Use {@link PTDiffusionTopicUpdateFeature#newUpdateStreamBuilder} instead

 @since 6.3
 */
-(PTDiffusionNumberUpdateStream *)int64NumberUpdateStreamWithPath:(NSString *)path
                                                    specification:(PTDiffusionTopicSpecification *)specification
                                                       constraint:(PTDiffusionUpdateConstraint *)constraint __deprecated_msg("Will be removed in a future release.");

@end



/**
 @brief Extension adding support to partial JSON update constraints for
 requiring primitive values at locations referenced with a JSON pointer.

 @since 6.3
 */
@interface PTDiffusionPartialJSONUpdateConstraint (PTDiffusionPrimitive)

/**
 Require a double-precision floating point (Eight-byte IEEE 754) value at a
 specific position in the JSON object.

 @param value   The value expected at the location referenced by pointer.
 @param pointer A [JSON Pointer](https://tools.ietf.org/html/rfc6901) syntax
                reference locating the value in the JSON object.
 @param error   Location to store a reason in case of failure. May be `nil`.

 @return        Primitive instance initialized with the given double value at the
                given specific position in the JSON object.

 @exception NSInvalidArgumentException If pointer is `nil`.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPartialJSONUpdateConstraint#withDoubleValue#atPointer:comparisonOperator:error instead}.
 */
-(nullable instancetype)withDoubleValue:(double)value
                              atPointer:(NSString *)pointer
                                  error:(NSError **)error __deprecated_msg("Will be removed in a future release.");


/**
 Compares a location within the JSON topic value to a double-precision floating
 point (Eight-byte IEEE 754) specified number.

 If there is no value found at the specified pointer position, the
 constraint will be unsatisfied.

 The value will be compared with the number value at the topic location.
 This will work with JSON string or number values only.
 JSON strings can only be compared if they contain a value that can be
 parsed as a number.
 If a string value at the location cannot be parsed as a number, the
 constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 can be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 @param value               The value to be compared against the topic value.
 @param pointer             A {@link https://tools.ietf.org/html/rfc6901 JSON Pointer) syntax
                            reference locating the value in the JSON object.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason in case of failure. May be `nil`.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
-(nullable instancetype)withDoubleValue:(double)value
                              atPointer:(nonnull NSString *)pointer
                     comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                  error:(NSError *__autoreleasing *const)error;


/**
 Require a double-precision floating point (Eight-byte IEEE 754) number value at
 a specific position in the JSON object.

 @param number The value expected at the location referenced by pointer.

 @param pointer A [JSON Pointer](https://tools.ietf.org/html/rfc6901) syntax
 reference locating the value in the JSON object.

 @param error Location to store a reason in case of failure. May be `nil`.

 @return Primitive instance initialized with the given number value at the
 given specific position in the JSON object.

 @exception NSInvalidArgumentException If number or pointer is `nil`.

 @note To match a JSON `null` at the referenced location use
 PTDiffusionPartialJSONUpdateConstraint#withNullAt:error:

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPartialJSONUpdateConstraint#withDoubleFloatNumberValue#atPointer:comparisonOperator:error instead}.
 */
-(nullable instancetype)withDoubleFloatNumberValue:(NSNumber *)number
                                         atPointer:(NSString *)pointer
                                             error:(NSError **)error __deprecated_msg("Will be removed in a future release.");


/**
 Compares a location within the JSON topic value to a double-precision floating
 point (Eight-byte IEEE 754) specified number.

 If there is no value found at the specified pointer position, the
 constraint will be unsatisfied.

 The value will be compared with the number value at the topic location.
 This will work with JSON string or number values only.
 JSON strings can only be compared if they contain a value that can be
 parsed as a number.
 If a string value at the location cannot be parsed as a number, the
 constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 can be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 If a `null` value is supplied and the operator is {@link PTDiffusionUpdateConstraintOperator#eq EQ}
 or {@link PTDiffusionUpdateConstraintOperator#ne NE}, the topic value at
 the given pointer will be compared to JSON null.
 Other operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 are not permitted with a `null` value.

 @param value               The value to be compared against the topic value.
 @param pointer             A {@link https://tools.ietf.org/html/rfc6901 JSON Pointer) syntax
                            reference locating the value in the JSON object.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason in case of failure. May be `nil`.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
-(nullable instancetype)withDoubleFloatNumberValue:(nonnull NSNumber *)number
                                         atPointer:(nonnull NSString *)pointer
                                comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                             error:(NSError *__autoreleasing *const)error;


/**
 Require a 64-bit integer value at a specific position in the JSON object.

 @param value The value expected at the location referenced by pointer.

 @param pointer A [JSON Pointer](https://tools.ietf.org/html/rfc6901) syntax
 reference locating the value in the JSON object.

 @param error Location to store a reason in case of failure. May be `nil`.

 @return Primitive instance initialized with the given long value at the
 given specific position in the JSON object.

 @exception NSInvalidArgumentException If pointer is `nil`.

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPartialJSONUpdateConstraint#withLongLongValue#atPointer:comparisonOperator:error instead}.
 */
-(nullable instancetype)withLongLongValue:(long long)value
                                atPointer:(NSString *)pointer
                                    error:(NSError **)error __deprecated_msg("Will be removed in a future release.");


/**
 Compares a location within the JSON topic value to a 64-bit integer specified value.

 If there is no value found at the specified pointer position, the
 constraint will be unsatisfied.

 The value will be compared with the number value at the topic location.
 This will work with JSON string or number values only.
 JSON strings can only be compared if they contain a value that can be
 parsed as a number.
 If a string value at the location cannot be parsed as a number, the
 constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 can be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 @param value               The value to be compared against the topic value.
 @param pointer             A {@link https://tools.ietf.org/html/rfc6901 JSON Pointer) syntax
                            reference locating the value in the JSON object.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason in case of failure. May be `nil`.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
-(nullable instancetype)withLongLongValue:(long long)value
                                atPointer:(nonnull NSString *)pointer
                       comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                    error:(NSError *__autoreleasing *const)error;


/**
 Require a 64-bit integer number value at a specific position in the JSON
 object.

 @param number The value expected at the location referenced by pointer.

 @param pointer A [JSON Pointer](https://tools.ietf.org/html/rfc6901) syntax
 reference locating the value in the JSON object.

 @param error Location to store a reason in case of failure. May be `nil`.

 @return Primitive instance initialized with the given 64-bit number value
 at the given specific position in the JSON object.

 @exception NSInvalidArgumentException If number or pointer is `nil`.

 @note To match a JSON `null` at the referenced location use
 PTDiffusionPartialJSONUpdateConstraint#withNullAt:error:

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPartialJSONUpdateConstraint#withInt64NumberValue#atPointer:comparisonOperator:error instead}.
 */
-(nullable instancetype)withInt64NumberValue:(NSNumber *)number
                                   atPointer:(NSString *)pointer
                                       error:(NSError **)error __deprecated_msg("Will be removed in a future release.");


/**
 Compares a location within the JSON topic value to a 64-bit integer specified value.

 If there is no value found at the specified pointer position, the
 constraint will be unsatisfied.

 The value will be compared with the number value at the topic location.
 This will work with JSON string or number values only.
 JSON strings can only be compared if they contain a value that can be
 parsed as a number.
 If a string value at the location cannot be parsed as a number, the
 constraint will be unsatisfied.

 Any of the operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 can be used with such number comparisons.

 Decimal numbers can be compared with integral numbers so `1` is equal to `1.0`, `"1"`, or `"1.0"`.

 If a `null` value is supplied and the operator is {@link PTDiffusionUpdateConstraintOperator#eq EQ}
 or {@link PTDiffusionUpdateConstraintOperator#ne NE}, the topic value at
 the given pointer will be compared to JSON null.
 Other operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 are not permitted with a `null` value.

 @param value               The value to be compared against the topic value.
 @param pointer             A {@link https://tools.ietf.org/html/rfc6901 JSON Pointer) syntax
                            reference locating the value in the JSON object.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason in case of failure. May be `nil`.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
-(nullable instancetype)withInt64NumberValue:(nonnull NSNumber *)number
                                   atPointer:(nonnull NSString *)pointer
                          comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                       error:(NSError *__autoreleasing *const)error;


/**
 Require a string value at a specific position in the JSON object.

 @param string The value expected at the location referenced by pointer.

 @param pointer A [JSON Pointer](https://tools.ietf.org/html/rfc6901) syntax
 reference locating the value in the JSON object.

 @param error Location to store a reason in case of failure. May be `nil`.

 @return Primitive instance initialized with the given string value at the
 given specific position in the JSON object.

 @exception NSInvalidArgumentException If string or pointer is `nil`.

 @note To match a JSON `null` at the referenced location use
 PTDiffusionPartialJSONUpdateConstraint#withNullAt:error:

 @since 6.3

 @deprecated since 6.10. Use {@link PTDiffusionPartialJSONUpdateConstraint#withStringValue#atPointer:comparisonOperator:error instead}.
 */
-(nullable instancetype)withStringValue:(NSString *)string
                              atPointer:(NSString *)pointer
                                  error:(NSError **)error __deprecated_msg("Will be removed in a future release.");


/**
 Compares a location within the JSON topic value to a string specified value.

 If there is no value found at the specified pointer position, the
 constraint will be unsatisfied.

 If the operator is {@link PTDiffusionUpdateConstraintOperator#eq EQ} or
 {@link PTDiffusionUpdateConstraintOperator#ne NE}, the string representation
 of the topic value at the given pointer will be compared to the supplied value.

 If the value at the pointer position is not a string or number the constraint will be unsatisfied.
 Other operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS}) are not permitted with String values.

 If a `null` value is supplied and the operator is {@link PTDiffusionUpdateConstraintOperator#eq EQ}
 or {@link PTDiffusionUpdateConstraintOperator#ne NE}, the topic value at
 the given pointer will be compared to JSON null.
 Other operators (other than {@link PTDiffusionUpdateConstraintOperator#is IS})
 are not permitted with a `null` value.

 @param value               The value to be compared against the topic value.
 @param pointer             A {@link https://tools.ietf.org/html/rfc6901 JSON Pointer) syntax
                            reference locating the value in the JSON object.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason in case of failure. May be `nil`.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
-(nullable instancetype)withStringValue:(nonnull NSString *)string
                              atPointer:(nonnull NSString *)pointer
                     comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                  error:(NSError *__autoreleasing *const)error;


/**
 Compares a location within the JSON topic value to a boolean specified value.

 If there is no value found at the specified pointer position, the
 constraint will be unsatisfied.

 If the operator is {@link PTDiffusionUpdateConstraintOperator#eq EQ}, the topic value
 at the given pointer will be compared to the boolean value.
 Other operators are not permitted with a boolean value.

 @param value               The value to be compared against the topic value.
 @param pointer             A {@link https://tools.ietf.org/html/rfc6901 JSON Pointer) syntax
                            reference locating the value in the JSON object.
 @param comparisonOperator  The comparison operator. See {@link PTDiffusionUpdateConstraintOperator}.
 @param error               Location to store a reason in case of failure. May be `nil`.

 @return                    The new constraint, or `nil` on failure.

 @since 6.10
 */
-(nullable instancetype)withBooleanValue:(bool)value
                               atPointer:(nonnull NSString *)pointer
                      comparisonOperator:(nonnull PTDiffusionUpdateConstraintOperator *)comparisonOperator
                                   error:(NSError *__autoreleasing *const)error;

@end

NS_ASSUME_NONNULL_END
