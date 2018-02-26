//
//  LocalzAttendant.h
//  LocalzAttendantSDK
//
//  Created by Daniel Sykes-Turner on 18/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantLocationStore.h"

@interface LocalzAttendant : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *attendantId;
@property (nonatomic, readonly, strong) NSString *username;
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSString *branchId;
@property (nonatomic, readonly, strong) NSString *locationId;
@property (nonatomic, readonly, strong) NSString *locationName;
@property (nonatomic, readonly, strong) NSString *defaultPickup;
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;
@property (nonatomic, readonly, strong) NSArray *attributesPresentation;
@property (nonatomic, readonly, strong) NSArray *subProjects;
@property (nonatomic, readonly, strong) LocalzAttendantLocationStore *locationStoreDetails;

- (LocalzAttendant *)initWithData:(NSDictionary *)data;

@end
