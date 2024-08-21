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

/**
 @file PTDiffusionTopicUnsubscriptionReason.h
 
 The reason that an unsubscription occurred.

 @since 5.6
 */
typedef NS_ENUM(NSUInteger, PTDiffusionTopicUnsubscriptionReason) {
    /**
     Unsubscribed by the subscribing client.

     @since 5.6
     */
    PTDiffusionTopicUnsubscriptionReason_Requested = 0,

    /**
     The unsubscription was requested either by another client or by the server.

     @since 5.6
     */
    PTDiffusionTopicUnsubscriptionReason_Control = 1,

    /**
     The unsubscription occurred because the topic was removed.

     @since 5.6
     */
    PTDiffusionTopicUnsubscriptionReason_Removal = 2,

    /**
     The unsubscription occurred because the session is no longer authorized
     to access the topic.

     @since 5.9
     */
    PTDiffusionTopicUnsubscriptionReason_Authorization = 3,

    /**
     A reason that is unsupported by the session.
     
     @since 6.1
     */
    PTDiffusionTopicUnsubscriptionReason_Unknown = 4,

    /**
     The server has a significant backlog of messages f`or the session, and
     the topic specification has the
     {@link PTDiffusionTopicSpecification#conflationPropertyKey
     conflation topic property} set to "unsubscribe". The session can
     resubscribe to the topic. The unsubscription is not persisted to the
     cluster. If the session fails over to a different server it will be
     resubscribed to the topic.
     */
    PTDiffusionTopicUnsubscriptionReason_BackPressure = 5,

    /**
     The unsubscription occurred because branch mapping rules changed.

     @since 6.7
     @see PTDiffusionSessionTrees
    */
    PTDiffusionTopicUnsubscriptionReason_BranchMappings = 6,

    /**
     The server has re-subscribed this session to the topic. Existing streams
     are unsubscribed because the topic type and other attributes may have changed.

     This can happen if a set of servers is configured to use session replication,
     and a session connected to one server reconnects ("fails over") to a
     different server.

     @since 5.9
     */
    PTDiffusionTopicUnsubscriptionReason_SubscriptionRefresh = 0xfffffff0,

    /**
     A fallback stream has been unsubscribed due to the addition of a stream
     that selects the topic.

     @since 5.9
     */
    PTDiffusionTopicUnsubscriptionReason_StreamChange = 0xfffffff1,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Returns a string representation of a topic unsubscription reason.

 @since 5.6
 */
NSString *PTDiffusionTopicUnsubscriptionReasonToString(PTDiffusionTopicUnsubscriptionReason reason);

NS_ASSUME_NONNULL_END
