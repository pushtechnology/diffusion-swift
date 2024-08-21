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
#import <Diffusion/PTDiffusionEnumeration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Connection option key for a remote server

 This is used by the Remote Servers feature

 @since 6.5
 */
@interface PTDiffusionRemoteServerConnectionOption : PTDiffusionEnumeration


/**
 Specifies the reconnection timeout session attribute.

 This is the total time in milliseconds that will be allowed to
 reconnect a failed connection to the remote server.

 For reconnection to work the remote server connector must have
 been configured to support reconnection.

 If a value is not specified
 `PTDiffusionSessionConfiguration.reconnectionTimeout` is used.

 @return Instance representing the key for the reconnection timeout session attribute.

 @since 6.5
 */
+(instancetype)reconnectionTimeout;


/**
 Specifies the delay after losing a connection before attempting a
 reconnection.

 The value is specified in milliseconds. Default 1000 (1 second).

 @return Instance representing the key for the delay after losing a
 connection before attempting a reconnection.

 @since 6.5
 */
+(instancetype) retryDelay;


/**
 Specifies the recovery buffer size session attribute.

 If the remote server is configured to support reconnection, a
 session established with a non-zero reconnect-timeout retains a
 buffer of sent messages. If the session disconnects and
 reconnects, this buffer is used to re-send messages that the
 server has not received.

 The default value is 10,000 messages. If reconnect-timeout is 0
 then this value is ignored.

 @return Instance representing the key for the recovery buffer size
 session attribute.

 @since 6.5
 */
+(instancetype)recoveryBufferSize;


/**
 Specifies the input buffer size session attribute.

 This is the size of the input buffer to use for the connection
 with the remote server. It is used to receive messages from the
 remote server. This should be set to the same size as the output
 buffer used at the remote server.

 If not specified, a default of 1024k is used.

 @return Instance representing the key for the input buffer size
 session attribute.

 @since 6.5
 */
+(instancetype)inputBufferSize;


/**
 Specifies the output buffer size session attribute.

 This is the size of the output buffer to use for the connection
 with the remote server. It is used to send messages to the remote
 server. This should be set to the same size as the input buffer
 used by the remote server.

 If not specified, a default of 1024k is used.

 @return Instance representing the key for output buffer size
 session attribute.

 @since 6.5
 */
+(instancetype)outputBufferSize;


/**
 Specifies the maximum queue size session attribute.

 This is the maximum number of messages that can be queued to send
 to the remote server. If this number is exceeded, the connection
 will be closed. This must be sufficient to cater for messages
 that may be queued whilst disconnected (awaiting reconnect).

 The default value is 10,000 messages.

 @return Instance representing the key for the maximum queue size
 session attribute.

 @since 6.5
 */
+(instancetype)maximumQueueSize;


/**
 Specifies the connection timeout session attribute value (in
 milliseconds).

 If a value is not specified
 `PTDiffusionSessionConfiguration.connectionTimeout` is used.

 @return Instance representing the key for the connection timeout
 session attribute.

 @since 6.5
 */
+(instancetype)connectionTimeout;



/**
 Specifies the write timeout session attribute value (in
 milliseconds).

 @return Instance representing the key for the write timeout
 session attribute.

 @since 6.5
 */
+(instancetype)writeTimeout;


@end

NS_ASSUME_NONNULL_END
