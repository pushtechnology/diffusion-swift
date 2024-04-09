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
#import <Diffusion/PTDiffusionRecordV2SchemaNode.h>

@class PTDiffusionRecordV2SchemaField;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A record definition within a schema.
 
 @since 6.0
 */
@interface PTDiffusionRecordV2SchemaRecord : PTDiffusionRecordV2SchemaNode

/**
 An ordered list of the field definitions within the record.
 
 There will be at least one.
 
 @since 6.0
 */
@property(nonatomic, readonly) NSArray<PTDiffusionRecordV2SchemaField *>* fields;

/**
 Compares the receiver to the given schema record.

 @param record The schema record object with which to compare the receiver.

 @return `YES` if the record is equal to the contents of the receiver, otherwise
 `NO`.

 @since 6.0
 */
-(BOOL)isEqualToRecordV2SchemaRecord:(nullable PTDiffusionRecordV2SchemaRecord *)record;

@end

NS_ASSUME_NONNULL_END
