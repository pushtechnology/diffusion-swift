//  Diffusion Client Library for iOS, OS X and tvOS
//
//  Copyright (c) 2019, 2020 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionJSON;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief An immutable map describing the changes to a JSON value.

 The map contains an entry for each change, as follows:

 - The key is a [JSON Pointer](https://tools.ietf.org/html/rfc6901) syntax
   reference locating the change in the complete value. Since a JSON value is a
   list of zero or more data items, the reference always begins with an array
   index. For example, the first part is identified by the JSON Pointer `/0`.
 - The value is part of the complete value. It is returned as a JSON object that
   can be parsed independently as a unit, or converted to a Foundation object or
   JSON string.

 @since 6.3
 */
@interface PTDiffusionJSONDeltaChangeMap : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The entries forming the change map.
 */
@property(nonatomic, readonly) NSDictionary<NSString *, PTDiffusionJSON *>* map;

/**
 Returns a view of the portion of this map whose keys are descendants of
 `pointer`. If `pointer` is contained in this map, it will be included in the
 result.

 @param pointer JSON pointer

 @param error Location to store a reason in case of failure. May be `nil`.

 @return JSON delta change map containing the descendants of given pointer.

 @exception NSInvalidArgumentException If `pointer` is `nil`.

 @since 6.3
 */
-(nullable PTDiffusionJSONDeltaChangeMap *)descendantsOfPointer:(NSString *)pointer
                                                          error:(NSError **)error;

/**
 Returns a view of the portion of this map whose keys are descendants or parents
 of `pointer`. If `pointer` is contained in this map, it will be included in the
 result.

 This method can be used to determine whether a structural delta affects a
 particular part of a JSON value.

 @param pointer JSON pointer

 @param error Location to store a reason in case of failure. May be `nil`.

 @return JSON delta change map containing the intersection of given pointer.

 @exception NSInvalidArgumentException If `pointer` is `nil`.

 @since 6.3
 */
-(nullable PTDiffusionJSONDeltaChangeMap *)intersectionOfPointer:(NSString *)pointer
                                                           error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
