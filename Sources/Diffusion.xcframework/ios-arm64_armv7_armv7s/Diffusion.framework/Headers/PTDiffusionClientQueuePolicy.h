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
 @brief Policy for managing a client message queue.

 Conflation can be enabled or disabled.

 @since 6.6
 */
@interface PTDiffusionClientQueuePolicy: NSObject


+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

/**
 @return `YES` is conflation is enabled.

 @since 6.6
 */
-(BOOL) isConflated;

@end

NS_ASSUME_NONNULL_END
