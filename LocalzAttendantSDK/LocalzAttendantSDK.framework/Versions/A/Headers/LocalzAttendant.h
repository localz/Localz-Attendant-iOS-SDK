//
//  LocalzAttendant.h
//  LocalzAttendantSDK
//
//  Created by Daniel Sykes-Turner on 18/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantLocationStore.h"
#import "LocalzAttendantAttributesPresentation.h"

@interface LocalzAttendant : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *attendantId;
@property (nonatomic, readonly, strong) NSString *username;
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;
@property (nonatomic, readonly, strong) NSArray <LocalzAttendantAttributesPresentation *> *attributesPresentation;
@property (nonatomic, readonly, strong) NSArray *subProjects;
@property (nonatomic, readonly, strong) LocalzAttendantLocationStore *location;

// Deprecated
@property (nonatomic, readonly, strong) NSString *branchId __deprecated_msg("Please use location.branchId instead");
@property (nonatomic, readonly, strong) NSString *locationId __deprecated_msg("Please use location.locationId instead");
@property (nonatomic, readonly, strong) NSString *locationName __deprecated_msg("Please use location.locationName instead");
@property (nonatomic, readonly, strong) NSString *defaultPickup __deprecated_msg("Please use location.defaultPickup instead");
@property (nonatomic, readonly, strong) LocalzAttendantLocationStore *locationStoreDetails __deprecated_msg("Please use location instead");

- (LocalzAttendant *)initWithData:(NSDictionary *)data;

@end
