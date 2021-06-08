//
//  LocalzAttendantAlarmRuleCondition.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 17/4/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantAlarmRuleCondition : NSObject<NSCoding>

@property (readonly) BOOL acknowledgedDeviceOnly;
@property (nonatomic, readonly, strong) NSString *status;
@property (nonatomic, readonly, strong) NSArray *attributes;
/*
 Expected format for attribtues:
 [{
     key : '<specific.some_attribute>',
     constraints : {
         '$gt':<int_value>,
         '$gte':<int_value>,
         '$lte':<int_value>,
         '$lt'<int_value>,
    }
 }]
*/

- (LocalzAttendantAlarmRuleCondition *)initWithData:(NSDictionary *)data;
- (void)updateAttributes:(NSArray *)attributes;
- (void)addAttributes:(NSArray *)attributes;
- (NSDictionary *) toJSON;

@end
