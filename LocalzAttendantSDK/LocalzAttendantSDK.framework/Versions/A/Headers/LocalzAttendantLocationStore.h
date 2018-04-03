//
//  LocalzAttendantLocationStore.h
//  LocalzAttendantSDK
//
//  Created by Melvin Artemas on 24/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantTodayWorkingHours.h"
#import "LocalzAttendantPickupLocation.h"

@interface LocalzAttendantLocationStore : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *branchId;
@property (nonatomic, readonly, strong) NSString *locationId;
@property (nonatomic, readonly, strong) NSString *locationName;
@property (nonatomic, readonly, strong) NSString *defaultPickup;
@property (nonatomic, readonly, strong) LocalzAttendantTodayWorkingHours *locationTodayWorkingHours;
@property (nonatomic, readonly, strong) NSString *locationTimezoneName;
@property (nonatomic, readonly, strong) NSArray *pickupLocations;

// Deprecated
@property (nonatomic, readonly, strong) NSString *identifier __deprecated_msg("Please use locationId instead");
@property (nonatomic, readonly, strong) NSString *name __deprecated_msg("Please use locationName instead");
@property (nonatomic, readonly, strong) NSString *timezone __deprecated_msg("Please use locationTimezoneName instead");
@property (nonatomic, readonly, strong) NSArray *locationPickups __deprecated_msg("Please use pickupLocations instead");
@property (nonatomic, readonly, strong) NSArray *todayWorkingHours __deprecated_msg("Please use locationTodayWorkingHours instead");

- (instancetype)initWithData:(NSDictionary *)data;

@end
