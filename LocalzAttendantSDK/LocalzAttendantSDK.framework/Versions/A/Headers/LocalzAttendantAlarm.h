//
//  LocalzAttendantAlarm.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 1/5/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantAlarm : NSObject <NSCopying>

@property (nonatomic, strong) NSString *alarmId;
@property (nonatomic, strong) NSString *type;
@property (nonatomic) int priority;
@property (nonatomic, strong) NSString *repeat;
@property (nonatomic, strong) NSString *soundFileName;
@property (nonatomic, strong) NSString *alarmStatus;
@property (nonatomic) BOOL triggered;
@property (nonatomic) int delaySeconds;
@property (nonatomic, strong) NSDate *created;
@property (nonatomic, strong) NSDate *updated;

@end
