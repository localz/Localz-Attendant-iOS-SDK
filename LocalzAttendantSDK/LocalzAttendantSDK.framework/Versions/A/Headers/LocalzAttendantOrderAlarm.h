//
//  LocalzAttendantOrderAlarm.h
//  LocalzAttendantSDK
//
//  Created by Daniel Sykes-Turner on 21/5/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantOrder.h"
#import "LocalzAttendantAlarm.h"

@interface LocalzAttendantOrderAlarm : NSObject
@property (nonatomic, strong, readonly) LocalzAttendantOrder *order;
@property (nonatomic, strong, readonly) LocalzAttendantAlarm *alarm;
- (LocalzAttendantOrderAlarm *)initWithOrder:(LocalzAttendantOrder *)order alarm:(LocalzAttendantAlarm *)alarm;
@end
