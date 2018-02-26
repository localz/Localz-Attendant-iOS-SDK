//
//  LocalzAttendantLocationStore.h
//  LocalzAttendantSDK
//
//  Created by Melvin Artemas on 24/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantLocationStore : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *identifier;
@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *defaultPickup;
@property (nonatomic, readonly, strong) NSArray *todayWorkingHours;
@property (nonatomic, readonly, strong) NSString *branchId;
@property (nonatomic, readonly, strong) NSArray *locationPickups;
@property (nonatomic, readonly, strong) NSString *timezone;

- (instancetype)initWithData:(NSDictionary *)data;

@end
