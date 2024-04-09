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
 @brief Specifies the reason why a session has been closed

 This is used by the Client Control feature

 @since 6.5
 */
@interface PTDiffusionCloseReason : PTDiffusionEnumeration


/**
 The connection to the client was lost - possibly dropped by the
 client. Recoverable.

 A client may be closed for many reasons that are presented as
 CONNECTION_LOST.

 During a connection attempt, the connection can be lost.
 The server might have received a connection or reconnection request
 from a client already connected.
 The server might have received a reconnection request without
 a session Id.
 The connection may not have been authorised because the credentials
 are wrong.
 The maximum number of clients might already be connected.

 Once connected, the connection can be lost for different reasons.
 If the client closes its connection while the server is writing a
 message to the client. With the chunked encoding based connection the
 HTTP response is completed by the server.
 If the client does not open a new request within a timeout,
 the client will be closed.
 If a poll request times out and the server finds that the connection
 has already been closed by the client.

 @return Instance indicating the connection to the client was lost.

 @since 6.5
 */
+(instancetype)connectionLost;


/**
 An unexpected IO Exception occurred. Recoverable.

 While trying to perform an I/O operation an exception was generated.
 This often means that a read was attempted from a closed TCP
 connection.

 When handling SSL connections if there is a problem encrypting or
 decrypting a message the client will be closed for this reason.

 @return Instance indicating an unexpected IO Exception occurred.

 @since 6.5
 */
+(instancetype)ioException;


/**
 The client had become unresponsive.

 The client has either failed to respond to a ping message in a timely
 manner or the client has failed to open an HTTP poll for messages.
 The client does not appear to be receiving messages.

 @return Instance indicating the client has become unresponsive.

 @since 6.5
 */
+(instancetype)clientUnresponsive;


/**
 The maximum outbound queue size was reached for the client. Not
 recoverable.

 Messages sent to the client are placed in a queue. This queue has a
 maximum allowed size. If the queue limit is reached the client is
 closed and the queue discarded. The queue is intended to protect
 against slow consumers, reaching the queue limit is taken to mean
 that the client cannot keep up with the number of messages sent to
 it.

 @return Instance indicating the maximum outbound queue size was reached
 for the client.

 @since 6.5
 */
+(instancetype)messageQueueLimitReached;


/**
 The client requested close. Not recoverable.

 @return Instance indicating the client requested close.

 @since 6.5
 */
+(instancetype)closedByClient;

/**
 The client sent a message that exceeded the maximum message size that
 can be processed by the server.

 The server has a maximum message size that it can process on any
 single connector. If a client sends a message larger than this the
 server is unable to process it. When this happens the message is
 discarded and the client is closed.

 @return Instance indicating the client send a message that exceeded the
 server maximum message size.

 @since 6.5
 */
+(instancetype)messageTooLarge;


/**
 An internal error occurred.

 @return Instance indicating an internal error has occurred.

 @since 6.5
 */
+(instancetype)internalError;


/**
 An inbound message with an invalid format was received.

 A message received by the server is not a valid Diffusion message.
 The server is unable to process this and closes the client that sent
 it.

 @return Instance indicating an inbound message with an invalid format
 was received.

 @since 6.5
 */
+(instancetype)invalidInboundMessage;


/**
 The client connection was aborted by the server, possibly because the
 connection was disallowed.

 This is may be because the connection was disallowed.
 Abort messages are also sent to clients that have unrecognised
 client IDs. This may be because the server closed the client previously
 but the client is unaware of this and tried to continue interacting
 with the server.

 @return Instance indicating the client connection was aborted by
 the server.

 @since 6.5
 */
+(instancetype)aborted;


/**
 Loss of messages from the client has been detected.

 For example, whilst waiting for the arrival of missing messages in
 a sequence of messages a timeout has occurred.

 HTTP based transports use multiple TCP connections. This can cause
 the messages to be received out of order. To reorder the messages
 those sent to the server may contain a sequence number indicating the
 correct order.

 If a message is received out of order there is a short time for the
 earlier messages to be received. If the messages are not received in
 this time the client is closed.

 Missing, invalid or duplicate sequence numbers will also close the
 client for this reason.

 This cannot be recovered from as the client and the server are in
 inconsistent states.

 @return Instance indicating loss of messages from the client
 has been detected.

 @since 6.5
 */
+(instancetype)lostMessages;


/**
 The server is closing down.

 The client was closed as part of the server shutdown process.

 @return Instance indicating the server is closing down.

 @deprecated since 6.6 and will be removed in a future release.

 @since 6.5
 */
+(instancetype)serverClosing __deprecated_msg("Will be removed in a future release");


/**
 Closed by a client session.

 A control session initiated the client close.

 @return Instance indicating the sessiion was closed by another
 client session.

 @since 6.5
 */
+(instancetype)closedByController;


/**
 The session has failed over to a different Diffusion server.

 The session is still open but is now connected to a different
 Diffusion server. This server has evicted its view of the session
 from its set of local sessions.

 @return Instance indicating the session has failed over to a
 different Diffusion server.

 @since 6.5
 */
+(instancetype)failedOver;


@end

NS_ASSUME_NONNULL_END
