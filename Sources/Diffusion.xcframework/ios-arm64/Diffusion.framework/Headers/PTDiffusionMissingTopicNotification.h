//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2016 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionSessionId;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Notification that a session has made a request using a selector that does
 not match any topics.

 @see PTDiffusionMissingTopicHandler

 @since 5.7
 */
@interface PTDiffusionMissingTopicNotification : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 The identity of the client session that made the request.

 @since 5.7
 */
@property(nonatomic, readonly) PTDiffusionSessionId* sessionId;


/**
 The topic selector expression that triggered this notification.

 @since 5.7
 */
@property(nonatomic, readonly) NSString* topicSelectorExpression;


/**
 The list of the names of the servers through which the notification
 has been routed.

 The first name in this list will be the name of the server to which
 the originating session was connected. If the notification was routed
 through remote server connections before reaching the recipient then
 those servers will also be listed in the order that the notification
 passed through them.

 @since 6.7
 */
@property (nonatomic, readonly) NSArray<NSString *>* serverNames;


/**
 The session properties of the session that made the request.
 
 @since 6.7
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *>* sessionProperties;


@end

NS_ASSUME_NONNULL_END
