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

@class PTDiffusionRemoteServerConnectionOption;

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(SInt8, PTDiffusionRemoteServerType) {
    PTDiffusionRemoteServerType_SecondaryInitiator = 1,
    PTDiffusionRemoteServerType_PrimaryInitiator = 2,
    PTDiffusionRemoteServerType_SecondaryAcceptor = 3,
};

/**
 @brief Base Interface for a remote server.

 This is used by the Remote Servers feature.

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

 @deprecated since 6.10

 For backwards compatibility this method is retained for
 secondary initiator compatibility but will be removed at
 a future release.
 */
@property (nonatomic, readonly) NSString * _Nullable url  DEPRECATED_ATTRIBUTE;


/**
 The principal used for the remote server connection

 @since 6.5

 @deprecated since 6.10

 For backwards compatibility this method is retained for
 secondary initiator compatibility but will be removed at
 a future release.
 */
@property (nonatomic, readonly) NSString *principal DEPRECATED_ATTRIBUTE;


/**
 The remote server connection options

 @since 6.5

 @deprecated since 6.10

 For backwards compatibility this method is retained for
 secondary initiator compatibility but will be removed at
 a future release.
 */
@property (nonatomic, readonly) NSDictionary<PTDiffusionRemoteServerConnectionOption *, NSString *> *connectionOptions DEPRECATED_ATTRIBUTE;


/**
 The missing topic notification filter expression or null if
 one has not been specified.

 @since 6.7

 @deprecated since 6.10

 For backwards compatibility this method is retained for
 secondary initiator compatibility but will be removed at
 a future release.
 */
@property (nonatomic, readonly) NSString *missingTopicNotificationFilter DEPRECATED_ATTRIBUTE;


/**
 The remote server type.

 A {@link PTDiffusionRemoteServer} can be cast to the corresponding sub-type to
 access all methods, as follows:

 <table border=1>
    <tr>
        <th style="text-align:center;">Type</th>
        <th style="text-align:center;">Type class</th>
    </tr>
    <tr>
        <td style="text-align:center;">{@link Type#PTDiffusionRemoteServerType_SecondaryInitiator Secondary Initiator}</td>
        <td style="text-align:center;">{@link PTDiffusionSecondaryInitiatorRemoteServer}</td>
    </tr>
    <tr>
        <td style="text-align:center;">{@link Type#PTDiffusionRemoteServerType_PrimaryInitiator Primary Initiator}</td>
        <td style="text-align:center;">{@link PTDiffusionPrimaryInitiatorRemoteServer}</td>
    </tr>
    <tr>
        <td style="text-align:center;">{@link Type#PTDiffusionRemoteServerType_SecondaryAcceptor Secondary Acceptor}</td>
        <td style="text-align:center;">{@link PTDiffusionSecondaryAcceptorRemoteServer}</td>
    </tr>
 </table>

 @since 6.10
 */
@property (nonatomic, readonly) PTDiffusionRemoteServerType type;


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
