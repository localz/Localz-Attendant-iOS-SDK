//
//  LocalzAttendantTodayWorkingHours.h
//  LocalzAttendantSDK
//
//  Created by Melvin Artemas on 24/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantTodayWorkingHours : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSNumber *openingHour;
@property (nonatomic, readonly, strong) NSNumber *openingMinute;
@property (nonatomic, readonly, strong) NSNumber *closingHour;
@property (nonatomic, readonly, strong) NSNumber *closingMinute;

- (instancetype)initWithData:(NSDictionary *)data;
@end
