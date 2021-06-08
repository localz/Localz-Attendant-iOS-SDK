//
//  LocalzAttendantOrderAlarmLink.h
//  CocoaLumberjack
//
//  Created by Daniel Sykes-Turner on 24/5/18.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantOrderAlarmLink : NSObject <NSCopying>
@property (nonatomic, strong) NSString *alarmId;
@property (nonatomic, strong) NSString *orderNumber;
@property (nonatomic, strong) NSString *subProjectId;
@property (nonatomic, strong) NSString *ruleName;
@end

