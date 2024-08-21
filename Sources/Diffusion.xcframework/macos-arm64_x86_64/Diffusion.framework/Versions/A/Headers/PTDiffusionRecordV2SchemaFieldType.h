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
#import <Diffusion/PTDiffusionEnumeration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Type of field defined within a schema.
 
 @since 6.0
 */
@interface PTDiffusionRecordV2SchemaFieldType : PTDiffusionEnumeration

/**
 Plain string.

 @return Instance representing the plain string schema field type.

 @since 6.0
 */
+(instancetype)string;

/**
 Integer.

 @return Instance representing the integer schema field type.

 @since 6.0
 */
+(instancetype)integer;

/**
 Decimal.

 @return Instance representing the decimal schema field type.

 @since 6.0
 */
+(instancetype)decimal;

@end

NS_ASSUME_NONNULL_END
