//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020, 2021 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;
#import <Diffusion/PTDiffusionEnumeration.h>

@class PTDiffusionRemoteServerConnectionOption;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Interface for a RemoteServer specification

 This is used by the Remote Servers feature

 @since 6.5
 */
@interface PTDiffusionRemoteServer : NSObject


/**
 The remote server name

 @since 6.5
 */
@property (nonatomic, readonly) NSString *name;


/**
 The URL for connection to remote server.

 @since 6.5
 */
@property (nonatomic, readonly) NSString *url;


/**
 The principal used for the remote server connection

 @since 6.5
 */
@property (nonatomic, readonly) NSString *principal;


/**
 The remote server connection options

 @since 6.5
 */
@property (nonatomic, readonly) NSDictionary<PTDiffusionRemoteServerConnectionOption *, NSString *> *connectionOptions;


/**
 The missing topic notification filter expression or null if
 one has not been specified.

 @since 6.7
 */
@property (nonatomic, readonly) NSString *missingTopicNotificationFilter;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
