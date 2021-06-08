//
//  LocalzAttendantAlarmRuleAlert.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 17/4/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

//extern NSString * const ALARM_REPEAT_ONCE;
//extern NSString * const ALARM_REPEAT_REPEAT;
//extern NSString * const ALARM_REPEAT_NOW_REPEAT;
//
//extern NSString * const ALARM_CREATE_PER_ORDER;
//extern NSString * const ALARM_CREATE_PER_ALLORDERS;
//extern NSString * const ALARM_CREATE_PER_NEWORDERS;


@interface LocalzAttendantAlarmRuleAlert : NSObject<NSCoding>

@property (nonatomic, readonly) int reminder;
@property (nonatomic, readonly, strong) NSString *repeatMode;
@property (nonatomic, readonly, strong) NSString *createMode;
@property (nonatomic, readonly, strong) NSString *soundFileName;

- (LocalzAttendantAlarmRuleAlert *)initWithData:(NSDictionary *)data;
- (NSDictionary *) toJSON;
@end
