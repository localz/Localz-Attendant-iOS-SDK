//
//  LocalzAttendantOrderNominees.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 31/8/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantOrderNominees : NSObject <NSSecureCoding>

@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *phone;
@property (nonatomic, readonly, strong) NSString *email;

- (LocalzAttendantOrderNominees *)initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;

@end
