//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2015 - 2023 DiffusionData Ltd., All Rights Reserved.
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
 @brief Credentials contain the proof material to support an authentication request.
 
 The server passes the credentials through to the configured authentication
 handlers for interpretation.

 A credentials object is immutable.

 @see PTDiffusionSessionConfiguration

 @since 5.6
 */
@interface PTDiffusionCredentials : NSObject <NSCopying>

/**
 Returns a credentials object initialized with the given plain-text password to use as proof material.

 @param password The plain-text password to authenticate with.

 @return Credentials instance initialized with the given plain-text password.

 @since 5.6
 */
-(instancetype)initWithPassword:(NSString *)password;

/**
 Returns a credentials object initialized with the given custom data to use as proof material.

 @param data The application-specific, custom credentials to authenticate with.

 @return Credentials instance initialized with the given custom data.

 @since 5.6
 */
-(instancetype)initWithData:(NSData *)data;

/**
 Returns a credentials object initialized with an empty type and password.

 @return Credentials objects initialized with an empty type and password.

 @since 6.5
 */
+(instancetype)noCredentials;

/**
 The data defining the receiver.
 
 @since 5.6
 */
@property(nonatomic, readonly) NSData *data;

/**
 Compares the receiver to the given credentials.

 @param credentials The credentials object with which to compare the receiver.

 @return `YES` if the receiver and the given credentials have the same type and data.

 @since 5.6
 */
-(BOOL)isEqualToCredentials:(nullable PTDiffusionCredentials *)credentials;

@end

NS_ASSUME_NONNULL_END
