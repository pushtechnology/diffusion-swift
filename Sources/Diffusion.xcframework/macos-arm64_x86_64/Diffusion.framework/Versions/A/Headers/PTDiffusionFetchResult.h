//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2018 - 2023 DiffusionData Ltd., All Rights Reserved.
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

@class PTDiffusionFetchTopicResult;

/**
 @brief Base class for results from fetch operations issued to the server.

 A fetch operation is issued using a PTDiffusionFetchRequest.

 @since 6.2
 */
@interface PTDiffusionFetchResult : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The results from the fetch operation, in path order, each representing a single
 topic selected by the fetch operation.

 @since 6.2
 */
@property(nonatomic, readonly) NSArray<PTDiffusionFetchTopicResult *> * results;

/**
 Indicates whether the fetch could have returned more results if it had not been
 constrained by the PTDiffusionFetchRequest#first: ,
 PTDiffusionFetchRequest#last: or
 PTDiffusionFetchRequest#maximumResultSize: limits.

 `YES` if more results could have been returned, otherwise `NO`.

 @since 6.2
 */
@property(nonatomic, readonly, getter=hasMore) BOOL more;



/**
 The number of elements in the fetch result
 
 @return the size of the results list
 
 @since 6.5
 */
-(NSUInteger)size;


/**
 Return `YES` if the result contains zero elements
 
 @return `YES` if result list is empty
 
 @since 6.5
 */
-(BOOL)isEmpty;


@end

NS_ASSUME_NONNULL_END
