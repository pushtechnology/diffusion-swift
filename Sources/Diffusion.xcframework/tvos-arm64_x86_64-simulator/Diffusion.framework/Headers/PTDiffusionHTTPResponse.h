//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2020 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/**
 Representation of the HTTP Response received from the server.
 */
@interface PTDiffusionHTTPResponse : NSObject

+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 @brief Status code as defined by <a href="https://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html">RFC 2616, section 6.1.1.</a>

 The Status-Code element is a 3-digit integer result code of the
 attempt to understand and satisfy the request.

 */
@property(nonatomic, readonly) NSInteger statusCode;

/**
 @brief Reason Phrase as defined by <a href="https://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html">RFC 2616, section 6.1.1.</a>

 The Reason-Phrase is intended to give a short textual description of the Status-Code.
 */
@property(nonatomic, readonly) NSString* reasonPhrase;

/**
@brief The headers of the HTTP response.
 */
@property(nonatomic, readonly) NSDictionary<NSString *, NSString *>* headers;

/**
 @brief The message body of the HTTP response

 Will be nil if there was no message body.
 */
@property(nonatomic, readonly, nullable) NSData* bodyData;

@end

NS_ASSUME_NONNULL_END
