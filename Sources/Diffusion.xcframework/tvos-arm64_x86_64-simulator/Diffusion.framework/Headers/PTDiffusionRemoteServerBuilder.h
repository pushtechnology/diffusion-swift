//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2021 - 2023 DiffusionData Ltd., All Rights Reserved.
//
//  Use is subject to licence terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of DiffusionData. The intellectual and technical
//  concepts contained herein are proprietary to DiffusionData and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

@class PTDiffusionRemoteServerConnectionOption;
@class PTDiffusionRemoteServer;
@class PTDiffusionCredentials;
@class PTDiffusionPrimaryInitiatorRemoteServer;
@class PTDiffusionSecondaryInitiatorRemoteServer;
@class PTDiffusionSecondaryAcceptorRemoteServer;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A Remote Server builder.

 A builder of this type is used to create instances of {@link PTDiffusionRemoteServer}
 that can be supplied to {@link PTDiffusionRemoteServersFeature#createRemoteServer:completionHandler: createRemoteServer:}.

 @since 6.7
 */
@interface PTDiffusionRemoteServerBuilder : NSObject

/**
 Reset the builder.

 @return this builder.

 @since 6.7
 */
-(instancetype)reset;


/**
 Specifies the name of a principal used by the remote server to
 connect to the primary server.

 The default, if not specified, is the anonymous principal.

 @param principal principal name of a zero length string to indicate an
 anonymous connection.

 @return this builder.

 @since 6.7
 */
-(instancetype)principal:(NSString * _Nullable)principal;


/**
 Specifies the credentials to use when connecting to the primary server.

 The default, if not specified, is {@link PTDiffusionCredentials.noCredentials}.

 @param credentials the credentials to use.

 @return this builder.

 @since 6.7
 */
-(instancetype)credentials:(PTDiffusionCredentials * _Nullable)credentials;


/**
 Specifies a map of {@link PTDiffusionRermoteServerConnectionOption} settings.

 This will replace any options currently set for the builder.

 Any options not supplied will take their default values.

 If no connection options are specified, either using this method or
 {@link PTDiffusionRemoteServerBuilder#connectionOption:withValue:} then all options
 will take their default values.

 @param connectionOptions the map of options.

 @return this builder.

 @since 6.7
 */
-(instancetype)connectionOptions:(NSDictionary<PTDiffusionRemoteServerConnectionOption *, NSString *>* _Nullable)connectionOptions;


/**
 Specifies a single connection option.

 This will add to the options currently specified to the builder, or replace a value if
 it has already been specified.

 @param option the connection option.

 @param value the connection option value or null to remove the option.

 @return this builder.

 @since 6.7
 */
-(instancetype)connectionOption:(PTDiffusionRemoteServerConnectionOption *)option
                      withValue:(NSString * _Nullable)value;


/**
 Specifies a topic selector expression which will filter missing
 topic notifications propagated from secondary to primary servers.

 {@link PTDiffusionMissingTopicNotification}s are notified when a client
 subscribes using a topic selector that matches no existing topics.
 By specifying a missing topic notification filter, all notifications that
 match the filter on the secondary server will be propagated to the primary server.

 A match occurs if the path prefix of the subscription selector matches the path
 prefix of the specified selector.

 If no filter is specified then no missing topic notifications will be propagated.

 The special selector expression `*.*` may be used to indicate that all missing topic
 notifications should be propagated.

 Only the path prefix of the specified selector(s) is considered when matching therefore,
 any use of regular expressions would be ignored.

 @param filter a topic selector expression specifying the filter to apply or null to remove
 any existing filter.

 @return this builder.

 @since 6.7
 */
-(instancetype)missingTopicNotificationFilter:(NSString * _Nullable)filter;


/**
 Creates a remote server object using the current values known
 to this builder.

 @param name the name of the remote server.

 @param url the URL to use to connect to the primary server.

 @return a new remote server instance.

 @since 6.7

 @deprecated since 6.10

 For backwards compatibility this method is retained for
 secondary initiator compatibility but will be removed at
 a future release.
 */
-(PTDiffusionRemoteServer *)createWithName:(NSString *)name
                                    andURL:(NSString *)url __deprecated_msg("Will be removed in a future release");


/**
 @brief Builds a secondary initiator using the current values known to
        this builder.

 @param name        the name of the primary initiator which must
                    correspond to the name of a {@link PTDiffusionSecondaryAcceptorRemoteServer}
                    defined on the secondary server.

 @param urls        the list of URLs to use to initiate connections to
                    the secondary servers.

 @param connector   the name of the connector used to establish the
                    connection with the secondary server.

 @return            a new primary initiator remote server instance.

 @since 6.10
 */
-(PTDiffusionSecondaryInitiatorRemoteServer *)createSecondaryInitiatorWithName:(NSString *)name
                                                                        andURL:(NSString *)url;


/**
 @brief Builds a secondary initiator using the current values known to
        this builder.

 @param name   the remote server name. This is the name that will be
               specified in topic views.

 @param url    the URL to use to connect to the primary server.

 @return        a new secondary initiator remote server instance.

 @since 6.10
 */
-(PTDiffusionPrimaryInitiatorRemoteServer *)createPrimaryInitiatorWithName:(NSString *)name
                                                                      urls:(NSArray<NSString *>*)urls
                                                              andConnector:(NSString *)connector;


/**
 @brief Builds a secondary acceptor using the current values known to
        this builder.

 @param name                the remote server name. A primary initiator of the
                            same name will be able to connect to this acceptor. This
                            is the name that will be specified in topic views.

 @param primaryHostName     the primary server host name that will be
                            used in SSL validation of the primary server.

 @return                    a new secondary acceptor remote server instance.

 @since 6.10
 */
-(PTDiffusionSecondaryAcceptorRemoteServer *)createSecondaryAcceptorWithName:(NSString *)name
                                                          andPrimaryHostName:(NSString *)primaryHostName;

@end

NS_ASSUME_NONNULL_END
