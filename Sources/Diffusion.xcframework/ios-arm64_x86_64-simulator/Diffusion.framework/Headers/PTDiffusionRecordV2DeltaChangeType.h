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
 @brief The type of change represented by a record delta.

 @since 6.0.2
 */
@interface PTDiffusionRecordV2DeltaChangeType : PTDiffusionEnumeration

/**
 The change indicates that a field had its value changed.

 This could be a field that has had its value changed or a new field that has
 been added at the end of a variable length record.

 The change will contain name and index details of both the record and the
 field.

 @return Instance indicating that a field had its value changed.
 
 @since 6.0.2
 */
+(instancetype)fieldChanged;

/**
 The change indicates that one or more field values have been added.

 This will only occur when variable multiplicity fields are used within records.

 The change will contain name and index of the record and the name and index of
 the first field added.

 @return Instance indicating that one or more field values have been added.
 
 @since 6.0.2
 */
+(instancetype)fieldsAdded;

/**
 The change indicates that a field value has been removed.

 This will only occur when variable multiplicity fields are used within records.

 The change will contain name and index details of the record and the name and
 index of the first field removed.

 @return Instance indicating that a field value has been removed.
 
 @since 6.0.2
 */
+(instancetype)fieldsRemoved;

/**
 The change indicates that one or more records have been added.

 This will only occur when variable multiplicity records are in use.

 The change will contain only the record name and the index of the first record
 added.

 @return Instance indicating that one or more records have been added.
 
 @since 6.0.2
 */
+(instancetype)recordsAdded;

/**
 The change indicates that one or more records have been removed.

 This will only occur when variable multiplicity records are in use.

 The change will contain only the record name and the index of the first record
 removed.

 @return Instance indicating that one or more records have been removed.
 
 @since 6.0.2
 */
+(instancetype)recordsRemoved;

@end

NS_ASSUME_NONNULL_END
