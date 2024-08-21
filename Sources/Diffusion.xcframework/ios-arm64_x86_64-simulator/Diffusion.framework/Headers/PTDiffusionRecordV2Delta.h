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

@class PTDiffusionRecordV2DeltaChange;
@class PTDiffusionRecordV2Schema;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A description of the differences between two record values.

 @since 6.0.2
 */
@interface PTDiffusionRecordV2Delta : NSObject <NSCopying>

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 Returns a list of the changes represented by the delta with reference to the
 specified schema.

 The schema supplied must comply with the data format of the delta. No
 validation takes place, so if the schema does not match the data then the
 results may be unpredictable.
 
 @param schema The schema to use for interpreting this delta.

 @param error If this method returns `nil` to indicate that an error occurred
 then this will be populated with the reason for that failure.

 @return List of the changes represented by the delta with reference to the
 specified schema.

 @since 6.0.2
 */
-(nullable NSArray<PTDiffusionRecordV2DeltaChange *> *)changesWithSchema:(PTDiffusionRecordV2Schema *)schema
                                                                   error:(NSError **)error;

/**
 Compares the receiver to the given recordV2 delta.

 @param delta The object with which to compare the receiver.

 @return `YES` if the delta is equal to the contents of the receiver, otherwise
 `NO`.

 @since 6.0.2
 */
-(BOOL)isEqualToRecordV2Delta:(nullable PTDiffusionRecordV2Delta *)delta;

@end

NS_ASSUME_NONNULL_END
