//
//  LocalzAttendantCustomer.h
//  LocalzAttendantSDK
//
//  Created by Daniel Sykes-Turner on 21/08/2015.
//  Copyright (c) 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantOrder.h"
@interface LocalzAttendantCustomer : NSObject
@property (nonatomic, readonly, strong) NSString *customerId;
@property (nonatomic, readonly, strong) NSString *title;
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSString *email;
@property (nonatomic, readwrite) BOOL isVerified;

- (LocalzAttendantCustomer *)initWithData:(NSDictionary *)data email:(NSString *)email;

- (void)encodeWithCoder:(NSCoder *)encoder;
- (id)initWithCoder:(NSCoder *)decoder;
@end
