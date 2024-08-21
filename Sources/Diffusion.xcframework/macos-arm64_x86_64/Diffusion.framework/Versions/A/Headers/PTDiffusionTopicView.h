//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2019 - 2023 DiffusionData Ltd., All Rights Reserved.
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
 @brief Description of a topic view that has been created.

 @see PTDiffusionTopicViewsFeature

 @since 6.3
 */
@interface PTDiffusionTopicView : NSObject <NSCopying>

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The name of the topic view. If the name is empty, the operation will fail.

 @since 6.3
 */
@property(nonatomic, readonly) NSString * name;

/**
 The specification of the topic view.

 @since 6.3
 */
@property(nonatomic, readonly) NSString * specification;

/**
 The roles used by the topic view when evaluating permissions.

 @since 6.3
 */
@property(nonatomic, readonly) NSArray<NSString *> * roles;

/**
 Compares the receiver to the given topic view.

 @param topicView The topic view object with which to compare the receiver.

 @return `YES` if it matches the receiver, otherwise `NO`.

 @since 6.3
 */
-(BOOL)isEqualToTopicView:(nullable PTDiffusionTopicView *)topicView;

@end

NS_ASSUME_NONNULL_END
