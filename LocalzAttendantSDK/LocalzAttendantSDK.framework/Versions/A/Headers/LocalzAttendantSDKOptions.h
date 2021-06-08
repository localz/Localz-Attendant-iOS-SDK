//
//  LocalzAttendantSDKOptions.h
//
//
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantBeacon.h"
#import "LocalzAttendantAlarmConfig.h"

@interface LocalzAttendantSDKOptions : NSObject
@property (nonatomic, strong, nonnull) NSString *env;
@property (nonatomic) Boolean debug;
@property (nonatomic, strong, nullable) LocalzAttendantAlarmConfig *alarmConfig;


- (LocalzAttendantSDKOptions * _Nonnull) initWithEnv:(NSString * _Nonnull) env andAlarmConfig: (LocalzAttendantAlarmConfig * _Nullable) alarmConfig;
- (LocalzAttendantSDKOptions * _Nonnull) initWithEnv:(NSString * _Nonnull) env andAlarmConfig: (LocalzAttendantAlarmConfig * _Nullable) alarmConfig withDebug: (Boolean ) debug;
- (NSDictionary * _Nonnull) toJSON;

@end
