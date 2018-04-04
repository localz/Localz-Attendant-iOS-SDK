//
//  LocalzAttendantPickupLocation.h
//  LocalzAttendantSDK
//
//  Created by Melvin Artemas on 24/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantPickupLocation : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *pickupId;
@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *desc;

- (instancetype)initWithData:(NSDictionary *)data;
@end
