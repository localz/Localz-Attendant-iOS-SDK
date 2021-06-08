//
//  LocalzAttendantBeacon.h
//
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantBeacon : NSObject <NSCoding>

@property (nonatomic, strong, nonnull) NSString *name;
@property (nonatomic, strong, nonnull) NSString *displayName;

- (LocalzAttendantBeacon * _Nonnull)initWithName:(NSString * _Nonnull)name displayName:(NSString * _Nonnull) displayName;
- (NSDictionary * _Nonnull) toJSON;

// Class methods
+ (NSArray<NSDictionary *> * _Nullable) jsonifyBeacons: (NSArray<LocalzAttendantBeacon *> * _Nullable) beacons;
@end
