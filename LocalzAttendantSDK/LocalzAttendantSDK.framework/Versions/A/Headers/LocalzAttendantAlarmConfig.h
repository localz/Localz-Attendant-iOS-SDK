//
//  LocalzAttendantAlarmConfig.h
//
//

#ifndef LocalzAttendantAlarmConfig_h
#define LocalzAttendantAlarmConfig_h
#import <Foundation/Foundation.h>
#import "LocalzAttendantProximity.h"
#import "LocalzAttendantAlarmRule.h"
#import "LocalzAttendantBeacon.h"

@interface LocalzAttendantAlarmConfig : NSObject

@property (nonatomic, strong, nullable) NSString *ver;
@property (nonatomic, strong, nullable) LocalzAttendantProximity *proximity;
@property (nonatomic, strong, nullable) NSArray<LocalzAttendantAlarmRule *> *rules;
@property (nonatomic, strong, nullable) NSArray<LocalzAttendantBeacon *> *beacons;

+ (LocalzAttendantAlarmConfig * _Nonnull) parseJson: (NSDictionary * _Nonnull) jsonAlarmConfig;
- (LocalzAttendantAlarmConfig * _Nonnull)initWithVer:(NSString * _Nullable)ver andProximity:(LocalzAttendantProximity * _Nullable) proximity andRules: (NSArray<LocalzAttendantAlarmRule *> * _Nullable) rules andBeacons: (NSArray<LocalzAttendantBeacon *> * _Nullable) beacons;

- (NSDictionary* _Nonnull) toJSON;
@end



#endif /* LocalzAttendantAlarmConfig_h */
