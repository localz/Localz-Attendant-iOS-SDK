//
//  LocalzAttendantProximity.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 23/8/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantProximity : NSObject <NSCoding>

@property (nonatomic, readonly, strong) NSString *subProjectId;
@property (nonatomic, readonly, strong) NSArray<NSString *> *orderStatuses;
@property (nonatomic, readonly, strong) NSString *soundFileName;

- (LocalzAttendantProximity *)initWithData:(NSDictionary *)data;
- (NSDictionary *) toJSON;
@end
