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

#import <Diffusion/PTDiffusionEnumeration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief An operator used in a constraint comparison.

 @see PTDiffusionUpdateConstraint

 @since 6.10
 */
@interface PTDiffusionUpdateConstraintOperator : PTDiffusionEnumeration

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 * @brief Strict binary equality.
 *
 * This operator requires that the binary topic value is exactly
 * equivalent to the value supplied for comparison.
 *
 * @return Instance representing the strict binary equality operator.
 *
 * @since 6.10
 */
+(instancetype)is;


/**
 * @brief Lenient equals.
 *
 * This operator requires that the topic value is logically equal to the
 * supplied value.
 *
 * If the supplied value is a string, the string representation of the
 * specified topic value is compared for string equality.
 *
 * If the supplied value is a number (`Long` or `Double`),
 * the corresponding topic value may be a number or a string containing
 * a parseable number and will be compared for numeric equality.
 *
 * If the supplied value is null, the condition will be satisfied if the
 * value at a specified pointer is JSON null.
 *
 * @return Instance representing the lenient equals operator.
 *
 * @since 6.10
 */
+(instancetype)eq;


/**
 * @brief Lenient not equals.
 *
 * This operator requires that the topic value is logically not equal to
 * the supplied value.
 *
 * If the supplied value is a string, the string representation of the
 * specified topic value is compared for string equality.
 *
 * If the supplied value is a number (`Long` or `Double`),
 * the corresponding topic value may be a number or a string containing
 * a parseable number and will be compared for numeric equality.
 *
 * If the supplied value is null, the condition will be satisfied if the
 * value at a specified pointer is JSON null.
 *
 * @return Instance representing the lenient not equals operator.
 *
 * @since 6.10
 */
+(instancetype)ne;


/**
 * @brief Lenient greater than.
 *
 * This operator requires that the topic value is greater than the
 * supplied value.
 *
 * The supplied value must be a number (`Long` or `Double`).
 * The corresponding topic value may be a number or a string containing
 * a parseable number and the condition will be satisfied if the topic
 * value is greater than the supplied value.
 *
 * @return Instance representing the lenient greater than operator.
 *
 * @since 6.10
 */
+(instancetype)gt;


/**
 * @brief Lenient greater than or equals.
 *
 * This operator requires that the topic value is greater than or equal
 * to the supplied value.
 *
 * The supplied value must be a number (`Long` or `Double`).
 * The corresponding topic value may be a number or a string containing
 * a parseable number and the condition will be satisfied if the topic
 * value is greater than or equal to the supplied value.
 *
 * @return Instance representing the lenient greater than or equals operator.
 *
 * @since 6.10
 */
+(instancetype)ge;


/**
 * @brief Lenient less than.
 *
 * This operator requires that the topic value is less than the
 * supplied value.
 *
 * The supplied value must be a number (`Long` or `Double`).
 * The corresponding topic value may be a number or a string containing
 * a parseable number and the condition will be satisfied if the topic
 * value is less than the supplied value.
 *
 * @return Instance representing the lenient less than operator.
 *
 * @since 6.10
 */
+(instancetype)lt;


/**
 * @brief Lenient less than or equals.
 *
 * This operator requires that the topic value is less than or equal
 * to the supplied value.
 *
 * The supplied value must be a number (`Long` or `Double`).
 * The corresponding topic value may be a number or a string containing
 * a parseable number and the condition will be satisfied if the topic
 * value is less than or equal to the supplied value.
 *
 * @return Instance representing the lenient less than or equals operator.
 *
 * @since 6.10
 */
+(instancetype)le;



@end

NS_ASSUME_NONNULL_END
