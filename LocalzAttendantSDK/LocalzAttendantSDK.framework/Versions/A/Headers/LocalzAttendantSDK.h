//
//  LocalzAttendantSDK.h
//  LocalzAttendantSDK
//
//  Created by Daniel Sykes-Turner on 31/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

@import CoreLocation;

#import <Foundation/Foundation.h>
#import <SpotzSDK/SpotzSDK.h>
#import <UserNotifications/UserNotifications.h>

#import "LocalzAttendant.h"
#import "LocalzAttendantOrderAlarm.h"

extern NSString * _Nonnull const kLocalzEnv;

#ifdef DEBUG
extern NSString * _Nonnull const kLocalzDebugEnable;
#endif


#pragma mark Notification Events
extern NSString * _Nonnull const LocalzAttendantCheckinOrderNotification;
extern NSString * _Nonnull const LocalzAttendantAcknowledgedOrderNotification;
extern NSString * _Nonnull const LocalzAttendantCompletedOrderNotification;
extern NSString * _Nonnull const LocalzAttendantHelpRequestNotification;
extern NSString * _Nonnull const LocalzAttendantUnassignedOrdersNotification;
extern NSString * _Nonnull const LocalzAttendantForceLogoutNotification;
extern NSString * _Nonnull const LocalzAttendantOrderSyncNotification;
extern NSString * _Nonnull const LocalzAttendantOrdersChangedNotification;
extern NSString * _Nonnull const LocalzAttendantOrderAlarmsUpdateNotification;
extern NSString * _Nonnull const LocalzAttendantResetOrderNotification;

@protocol LocalzAttendantSDKDelegate <NSObject>
- (void) localzAttendantSDKInit:(NSError * _Nullable)error;
@optional
/**
 * Order management delegates
 */
- (void) localzAttendantSDKOrdersChanged:(LocalzAttendantOrder *  _Nonnull)order data:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKCheckinOrder:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKAcknowledgedOrderNumber:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKCompletedOrderNumber:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKResetOrderNumber:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKHelpRequestWithData:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKReminderWithNumberOfUnassignedOrderNumbers:(NSArray * _Nonnull)orders;
- (void) localzAttendantSDKForceLogout:(NSDictionary * _Nullable)data;
- (void) localzAttendantSDKOrderSync:(BOOL)syncing;
- (void) localzAttendantSDKOrderAlarmsUpdate:(NSDictionary * _Nullable)data;

@end

@protocol LocalzAttendantSDKDataSource <NSObject>
@end

@interface LocalzAttendantSDK : NSObject

+ (instancetype _Nonnull)shared;

#pragma mark SDK management

/**
 * Initialise the SDK. All keys are available on the Localz web console. If you have no access to the console, please contact your one of Localz's reps.
 * @param appId Application ID
 * @param appKey Application Key
 * @param delegate LocalzAttendantSDKDelegate instance to handle the SDK events (optional)
 * @param options Additional configuration options. Please see Localz's documentation for more details. (optional)
 */
+ (void)initWithAppId:(NSString * _Nonnull)appId appKey:(NSString * _Nonnull)appKey delegate:(id<LocalzAttendantSDKDelegate> _Nullable)delegate options:(NSDictionary * _Nullable)options;

/**
 * Initialise the SDK. All keys are available on the Localz web console. If you have no access to the console, please contact your one of Localz's reps.
 * @param appId Application ID
 * @param appKey Application Key
 * @param cncKey CNC Key is required to enable features such as creating a new order from the app
 * @param delegate LocalzAttendantSDKDelegate instance to handle the SDK events (optional)
 * @param options Additional configuration options. Please see Localz's documentation for more details. (optional)
 */
+ (void) initWithAppId:(NSString * _Nonnull)appId appKey:(NSString * _Nonnull)appKey cncKey:(NSString * _Nullable)cncKey delegate:(id<LocalzAttendantSDKDelegate> _Nullable)delegate options:(NSDictionary * _Nullable)options;

/**
 * Starts the Push notification. This will initialise push notification service and prompt user for enabling push notification if not yet enabled.
 */
- (void) startPush;

/**
 * Resets the SDK. This will clear caches and stops the SpotzSDK.
 */
- (void) resetSDK;

/**
 * Indicates whether SDK has been initialisfed.
 * @returns True if device and configuration have been registered successfully in the SDK.
 */
- (BOOL) isInitialised;

#pragma mark User Management

/**
 * Login user with username / password. This is one of the login method which requires the username and password be setup through the Localz web console. See other login implementations for more details.
 * @param username Username
 * @param password The password
 * @param branchId The main site/branch where this user's orders or jobs are linked
 * @param force Force logout the other user's session if exists. If user has logged in elsewhere and force is false, an error will be returned in the completion block
 * @param options Additional login options (optional)
 * @param completion Completion block returns LocalzAttendant object if successful or error if any
 */
- (void) loginWithUsername:(NSString * _Nonnull)username password:(NSString * _Nonnull)password branchId:(NSString * _Nonnull)branchId force:(BOOL)force options:(NSDictionary * _Nullable)options completion:(void (^_Nullable)(NSError * _Nullable error, LocalzAttendant * _Nullable user))completion;

/**
 * Is user currently logged in?
 * @returns True if user is logged in
 */
- (BOOL) isLoggedIn;

/**
 * Logs the user out of the device.
 *
 * This method will throw an error if
 * - Offline data exists
 * - Network connection error
 * You can override the above by setting force = true
 *
 * @param force Will force logout of the device, regardless of network status.
 * @param completion Sets the error if logout was unsuccessful
 */
- (void) logoutWithForce:(BOOL)force completion:(void (^_Nullable)(NSError * _Nullable error))completion;

#pragma mark Awesome core functions

/**
 * Returns the unique device ID for this device.
 * @returns The device Id if already initialised, otherwise returns a nil.
 */
- (NSString * _Nullable) deviceId;

#pragma mark Order management

/**
 * Create or update a new order for the attendant. This will require cncKey (Attendant Key) to be supplied into the SDK
 * @param order LocalzAttendantOrder with the details of the order
 * @param completion The completion block which will return error if any
 */
- (void) createOrUpdateOrder:(LocalzAttendantOrder * _Nonnull)order completion:(void (^ _Nullable)(NSError * _Nullable))completion;

/**
 * Updates a specific payload to order. This will require cncKey (Attendant Key) to be supplied into the SDK
 * @param specific Specific payload to update
 * @param orderNumber  order number
 * @param completion The completion block which will return error if any
 */
- (void) updateOrderSpecific:(NSDictionary * _Nonnull)specific orderNumber:(NSString * _Nonnull) orderNumber subProjectId:(NSString * _Nullable) subProjectId  completion:(void (^ _Nullable)(NSError * _Nullable))completion;

/**
 * Checks in and automatically acknowledge the given order to the current attendant for a sub-project
 * @param orderNumber The order number
 * @param pickupId The id of the location the order is being picked up from
 * @param subProjectId The id of the projects subproject to check in the order to
 * @param completion The completion block which will return error if any
 */
- (void) checkinOrderNumber:(NSString * _Nonnull)orderNumber pickupId:(NSString * _Nonnull)pickupId subProjectId:(NSString * _Nullable)subProjectId completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Checks in and automatically acknowledges the given order to the current attendant
 * @param orderPin The pin supplied by the customer to verify their order
 * @param completion The completion block which will return error if any
 */
- (void) checkinOrderPin:(NSString * _Nonnull)orderPin completion:(void(^ _Nullable)(NSError * _Nullable error, LocalzAttendantOrder * _Nullable order))completion;

/**
 * Acknowledges the given order to the current attendant into a sub-project
 * @param orderNumber The order number
 * @param subProjectId The id of the projects subproject to check in the order to
 * @param completion The completion block which will return error if any
 */
- (void) acknowledgeOrderNumber:(NSString * _Nonnull)orderNumber subProjectId:(NSString * _Nullable)subProjectId completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Completes the given order for a sub-project
 * @param orderNumber The order number
 * @param signature The image of the captured signature (optiona)
 * @param notes Additional notes (optional)
 * @param subProjectId The id of the projects subproject to check in the order to
 * @param completion The completion block which will return error if any
 */
- (void) completeOrderNumber:(NSString * _Nonnull)orderNumber signature:(UIImage * _Nullable)signature notes:(NSString * _Nullable)notes subProjectId:(NSString * _Nullable)subProjectId completion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 * Reset the given order by number for a sub-project
 * @param orderNumber The order number
 * @param subProjectId The id of the projects subproject to check in the order to
 * @param completion The completion block which will return error if any
 */
- (void) resetOrderNumber:(NSString * _Nonnull)orderNumber subProjectId:(NSString * _Nullable)subProjectId completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Retrieves orders for the current attendant's store location
 * @param completion The completion block which will return error if any
 */
- (void) retrieveOrdersWithCompletion:(void (^ _Nullable)(NSError * _Nullable error, NSArray * _Nullable orders))completion;

/**
 * Retrieves non-completed orders for the current attendant's store location
 * @param completion The completion block which will return error if any
 */
- (void) retrieveNonCompleteOrdersWithCompletion:(void (^ _Nullable)(NSError * _Nullable error, NSArray * _Nullable orders))completion;

/**
 * Verified that an order number (and sub-project id if it exists) match the an order pin
 * @param orderNumber The order's order number to compare to the order's pin
 * @param subProjectId The order's sub-project id to compare to the order's pin (if it exists)
 * @param orderPin The order's orderPin to compare to the order number and sub-project id
 * @param completion The completion block with a true/false value of whether the parameters matched up or not
 */
- (void) verifyOrderNumber:(NSString * _Nonnull)orderNumber subProjectId:(NSString * _Nullable)subProjectId withOrderPin:(NSString * _Nonnull)orderPin completion:(void(^ _Nullable)(BOOL verified))completion;

/**
 * Retrieves orders and their subsequent alarms
 * @param completion The completion block containing an array of LocalzAttendantOrderAlarm objects that are currently unacknowledged
 */
- (void) getTriggeredOrderAlarmsWithCompletion:(void (^)(NSArray * _Nonnull triggeredOrderAlarms))completion;

/**
 * Acknowledges an alarm for a particular order
 * @param alarmId The id of the alarm to acknowledge
 */
- (void) acknowledgeAlarmId:(NSString * _Nonnull)alarmId;

 /**
 * Update the selected pickup locations
 * @param selectedPickupLocations The selected pickup locations (array of string IDs) that will be updated in the SDK.
 * @param completion The completion block called when the selected pickup locations have finished updating
 */
- (void) updateSelectedPickupLocations:(NSArray <NSString *> * _Nonnull)selectedPickupLocations withCompletion:(void(^)(void))completion;

/**
 * Update the selected alarm pickup locations
 * @param selectedAlarmPickupLocations The selected pickup locations (array of string IDs) that will be updated in the SDK.
 */
- (void) updateAlarmPickupLocations:(NSArray <NSString *> * _Nonnull)selectedAlarmPickupLocations __deprecated_msg("Please use updateSelectedPickupLocations: withCompletion: instead");


#pragma mark Offline cached data handler

/**
 * Indicates whether there are offline data in the cached that needs syncing with the server
 * Ensure you check this method prior to logging out as logging out will wipe all un-synced data.
 * @return true if there is cached data
 */
- (BOOL) isCachedData;

/**
 * Counts the number of orders currently waiting to be synced to the server due to an offline connection
 * @param completion The block called upon completion of retrieving the count of out of sync orders
 */
- (void) countOrdersOutOfSync:(void (^_Nullable)(int ordersOutOfSync))completion;

/**
 * Force sync data with the server. This method is only run if there are cached data and a connection to the Localz server.
 * @param completion Returns error if it was not successful
 */
- (void) syncDataWithCompletion:(void (^_Nullable)(NSError * _Nullable error))completion;

#pragma mark Push notification management

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData * _Nonnull)deviceToken;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError * _Nonnull)error;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For versions before iOS 10
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
- (void) applicationDidRegisterUserNotificationSettings:(UIUserNotificationSettings * _Nonnull)notificationSettings;
#pragma GCC diagnostic pop

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo applicationState:(UIApplicationState)state;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo applicationState:(UIApplicationState)state fetchCompletionHandler:(void (^_Nullable)(UIBackgroundFetchResult))completionHandler;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationHandleActionWithIdentifier:(NSString * _Nonnull)identifier forRemoteNotification:(NSDictionary * _Nullable)userInfo applicationState:(UIApplicationState)state completionHandler:(void (^_Nullable)(void))completionHandler;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For versions of iOS 10 and later
 */
- (void) userNotificationCenter:(UNUserNotificationCenter * _Nonnull)center willPresentNotification:(UNNotification * _Nullable)notification withCompletionHandler:(void (^_Nullable)(UNNotificationPresentationOptions))completionHandler NS_AVAILABLE_IOS(10.0);

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For versions of iOS 10 and later
 */
- (void) userNotificationCenter:(UNUserNotificationCenter * _Nonnull)center didReceiveNotificationResponse:(UNNotificationResponse * _Nullable)response withCompletionHandler:(void (^_Nullable)(void))completionHandler NS_AVAILABLE_IOS(10.0);

@end

