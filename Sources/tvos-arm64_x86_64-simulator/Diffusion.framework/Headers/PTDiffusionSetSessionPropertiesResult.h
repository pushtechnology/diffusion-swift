//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Encapsulates the result of a querying the server for the
        session properties of a particular session ID or session filter

 @since 6.5
 */
@interface PTDiffusionSetSessionPropertiesResult : NSObject


+(instancetype)new NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;


/**
 Map of the changed session properties
 The contained values in this Map are the old values prior to the change

 @since 6.5
 */
@property(nonatomic, readonly) NSDictionary<NSString *, NSString *> * changedProperties;


/**
 List of the added session properties

 @since 6.5
 */
@property(nonatomic, readonly) NSArray<NSString *> * addedProperties;

@end

NS_ASSUME_NONNULL_END
