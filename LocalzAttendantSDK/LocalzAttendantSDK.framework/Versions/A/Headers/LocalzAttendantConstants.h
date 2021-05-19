//
//  LocalzAttendantConstants.h
//  LocalzAttendantSDK
//
//  Created by Melvin Artemas on 4/10/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//
// Notification of network status
extern NSString * const SPOTZ_CNC_NETWORK_NOTIFICATION;
extern NSString * const SELECTED_PICKUP_LOCATIONS;

extern NSString * const ALARM_REPEAT_ONCE;
extern NSString * const ALARM_REPEAT_REPEAT;
extern NSString * const ALARM_REPEAT_NOW_REPEAT;

extern NSString * const ALARM_CREATE_PER_ORDER;
extern NSString * const ALARM_CREATE_PER_ALLORDERS;
extern NSString * const ALARM_CREATE_PER_NEWORDERS;

extern NSString * const ALARM_STATUS_ACTIVE;
extern NSString * const ALARM_STATUS_SUSPENDED;
extern NSString * const ALARM_STATUS_CANCELED;

extern NSString * const LOCALZ_ATTENDANT_VERSION;
extern NSString * const LOCALZ_ATTENDANT_PROXIMITY;

extern NSString * const PROXIMITY_ATTRIBUTE_NAME_PREFIX;
extern NSString * const PROXIMITY_ATTRIBUTE_ACK_PREFIX;


extern int const SPOTZ_CNC_IGNORE_ALERT_NOTIFICATION_PERIOD;
typedef enum {
    EPushInitError = 510,
    EPinCheckinOrderNotFound = 3001,
    EPinCheckinOrderNotReady = 3002,
    EPinCheckinOrderCompleted = 3003,
    EOrderAlreadyActioned = 4001,
    ESyncInProgress = 5001,
    ECacheExists = 5002
} LocalzAttendantErrorType;
