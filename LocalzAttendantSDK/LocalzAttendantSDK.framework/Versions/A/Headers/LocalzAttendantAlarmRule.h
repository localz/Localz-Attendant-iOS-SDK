//
//  LocalzAttendantAlarmRule.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 17/4/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantAlarmRuleAlert.h"
#import "LocalzAttendantAlarmRuleCondition.h"

@interface LocalzAttendantAlarmRule : NSObject<NSCoding>

@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *subProjectId;
@property (nonatomic, readonly) int priority;
@property (nonatomic, readonly, strong) LocalzAttendantAlarmRuleAlert *ruleAlert;
@property (nonatomic, readonly, strong) LocalzAttendantAlarmRuleCondition *ruleCondition;

- (LocalzAttendantAlarmRule *)initWithData:(NSDictionary *)data;
- (NSDictionary *) toJSON;

+ (NSArray<NSDictionary *> *)jsonifyRules: (NSArray<LocalzAttendantAlarmRule *> *)rules;


@end
