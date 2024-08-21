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

@protocol PTDiffusionDataType;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Diffusion data type implementations.

 @since 6.0
 */
@interface PTDiffusionDataTypes : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 Data type that supports arbitrary binary data.
 
 @see PTDiffusionBinary

 @return Data type that supports arbitrary binary data.
 
 @since 6.0
 */
+(id<PTDiffusionDataType>)binary;

/**
 Data type that supports double-precision floating point numbers (Eight-byte
 IEEE 754) presented as `NSNumber` instances.

 The integer value is serialized as CBOR-format binary. A serialized value can
 be read using the #json datatype.

 This data type does not support binary deltas but does support `nil` values.

 @return Data type that supports double-precision floating point numbers.

 @see PTDiffusionPrimitive

 @since 6.0
 */
+(id<PTDiffusionDataType>)doubleFloat;

/**
 Data type that supports 64-bit, signed integer values presented as `NSNumber`
 instances.

 The integer value is serialized as CBOR-format binary. A serialized value can
 be read using the #json datatype.

 This data type does not support binary deltas but does support `nil` values.

 @return Data type that supports 64-bit, signed integer values.

 @see PTDiffusionPrimitive

 @since 6.0
 */
+(id<PTDiffusionDataType>)int64;

/**
 Data type that supports JSON "JavaScript Object Notation", a lightweight
 data-interchange format, serialized as CBOR-format binary.

 @return Data type that supports JSON values.
 
 @see PTDiffusionJSON

 @since 6.0
 */
+(id<PTDiffusionDataType>)json;

/**
 Data type that supports string values presented as `NSString` instances.

 The string value is serialized as CBOR-format binary. A serialized value can be
 read using the #json datatype.

 This data type supports binary deltas and `nil` values.

 @return Data type that supports string values.
 
 @see PTDiffusionPrimitive

 @since 6.0
 */
+(id<PTDiffusionDataType>)string;

/**
 Data type that supports data in the form of records and fields.
 
 This data type supports binary deltas but does not support `nil` values.

 @return Data type that supports data in the form of records and fields.
 
 @see PTDiffusionRecordV2

 @since 6.0
 */
+(id<PTDiffusionDataType>)recordV2;

@end

NS_ASSUME_NONNULL_END
