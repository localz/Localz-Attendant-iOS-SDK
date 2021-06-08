//
//  LocalzAttendantAlarmManager.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 17/4/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantMockNotificationCenter.h"
#import "LocalzAttendantOrder.h"
#import "LocalzAttendantAlarm.h"
#import "LocalzAttendantBeacon.h"
#import "LocalzAttendantAlarmConfig.h"

@interface LocalzAttendantAlarmManager : NSObject

// The notification center this class will use.
// Can be mocked with LocalzAttendantMockNotificationCenter
@property (nonatomic, weak) id notificationCenter API_AVAILABLE(ios(10.0));

// Get the shared instance of the alarm manager
+ (instancetype) shared;

// Configure and setup alarm rules
- (void) cacheAlarmConfig:(LocalzAttendantAlarmConfig *)alarmConfig;

// Set up beacons
- (void) cacheBeacons:(NSArray<LocalzAttendantBeacon *> *)beacons;

// Compares the orders stored in the database to the orders passed in
- (NSArray <LocalzAttendantOrder *> *) findChangedOrdersFromUpdatedOrders:(NSArray *)updatedOrders;

// Reloads the alarms for any changed orders passed in
// All orders passed in must exist in the database, but not all orders in the database have to be passed in for reprocessing
- (void) reprocessAlarmsForOrders:(NSArray *)orders withCompletion:(void(^)(void))completion;

// Removes stored alarms as well as pending and delivered notification for all orders
- (void) clearAllAlarmsWithCompletion:(void(^)(void))completion;

// Removes stored alarms as well as pending and delivered notification for specific orders
- (void) clearAlarmsForOrders:(NSArray *)orders withCompletion:(void(^)(void))completion;

// Retrieve an array of order alarm objects that have triggered and unacknowledged alarms
- (void) getTriggeredOrderAlarmsWithCompletion:(void (^)(NSArray *triggeredOrderAlarms))completion;

// Acknowledge an alarm by it's alarmId
- (void) acknowledgeAlarmId:(NSString *)alarmId;

// Filter the list of triggering alarms by pickup location
- (void) updateSelectedPickupLocations:(NSArray *)selectedPickupLocations withCompletion:(void(^)(void))completion;

// Setup alerts to be triggered based on beacon location triggers
- (NSArray<LocalzAttendantOrder *> *) processProximityAlertsForOrders:(NSArray *)orders;

- (NSString *) getScreenNameFromProximityEntryName:(NSString *)proximityEntryName;

- (NSArray *) getProximityEntryNamesFromOrder:(LocalzAttendantOrder *)order forProximityLocations:(NSArray *)proximityLocations;

- (NSArray <LocalzAttendantOrder *> *) getOrdersWithUpdatedProximities:(NSArray *)orders;

- (Boolean) isOrder: (LocalzAttendantOrder *)order diffToOldOrder: (LocalzAttendantOrder *)oldOrder byProximity: (NSString *) proximity;


@end
