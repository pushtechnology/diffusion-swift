//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2021 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

@import Foundation;

@class PTDiffusionRemoteServerConnectionOption;
@class PTDiffusionRemoteServer;
@class PTDiffusionCredentials;

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
 */
-(PTDiffusionRemoteServer *)createWithName:(NSString *)name
                                    andURL:(NSString *)url;


@end

NS_ASSUME_NONNULL_END
