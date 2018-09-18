//
//  LocalzAttendantAttributesPresentation.h
//  LocalzAttendantSDK
//
//  Created by Rashmi Sivaramareddy on 15/8/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzAttendantAttributesPresentation : NSObject

@property (nonatomic, readonly, strong) NSString *field;
@property (nonatomic, readonly, strong) NSString *fieldPres;
@property (nonatomic, readonly, strong) NSString *fieldType;

- (LocalzAttendantAttributesPresentation *)initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;

@end
