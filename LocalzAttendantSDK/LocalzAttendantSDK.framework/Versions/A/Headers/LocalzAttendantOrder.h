//
//  LocalzAttendantOrder.h
//  LocalzAttendantSDK
//
//  Created by Daniel Sykes-Turner on 4/09/2015.
//  Copyright (c) 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzAttendantOrderItem.h"
#import "LocalzAttendantOrderNominees.h"

extern NSString * const ORDER_STATUS_PENDING;
extern NSString * const ORDER_STATUS_PENDING_PACKED;
extern NSString * const ORDER_STATUS_READY;
extern NSString * const ORDER_STATUS_UNASSIGNED;
extern NSString * const ORDER_STATUS_ASSIGNED;
extern NSString * const ORDER_STATUS_HANDOVER;
extern NSString * const ORDER_STATUS_COMPLETE;
extern NSString * const ORDER_STATUS_DELETED;

@interface LocalzAttendantOrder : NSObject <NSSecureCoding>
@property (nonatomic, readonly, strong) NSString *orderNumber;
@property (nonatomic, readonly, strong) NSString *orderStatus;
@property (nonatomic, readonly, strong) NSString *orderAmount;
@property (nonatomic, readonly, strong) NSDate *orderDate;
@property (nonatomic, readonly, strong) NSDate *pickupStart;
@property (nonatomic, readonly, strong) NSDate *pickupEnd;
@property (nonatomic, readonly, strong) NSString *pickupLocation;
@property (nonatomic, readonly, strong) NSString *shopperId;
@property (nonatomic, readonly, strong) NSString *deliveryName;
@property (nonatomic, readonly, strong) NSString *deliveryEmail;
@property (nonatomic, readonly, strong) NSString *deliveryPhone;
@property (nonatomic, readonly, strong) NSString *checkinPin;
@property (nonatomic, readonly, strong) NSString *allocatedAttendantLogin;
@property (nonatomic, readonly, strong) NSDate *staffLocNotified;
@property (nonatomic, readonly, strong) NSArray *items;
@property (nonatomic, readonly, strong) NSNumber *totalItems;
@property (nonatomic, readonly, strong) NSDictionary *specific;
@property (nonatomic, readonly) BOOL shouldGiveFeedback; // whether the user should provide feedback on the order after completion
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;
@property (nonatomic, readonly, strong) NSString *subProjectId;
@property (nonatomic, readonly, strong) NSString *staffName;
@property (nonatomic, readonly) BOOL isPriority;
@property (nonatomic, readonly) BOOL returnCustomer;
@property (nonatomic, readonly, strong) LocalzAttendantOrderNominees *nominees;

// Deprecated
@property (nonatomic, readonly, strong) NSString *status __deprecated_msg("Please use orderStatus instead");
@property (nonatomic, readonly, strong) NSDate *expectedDateFrom __deprecated_msg("Please use pickupStart instead");
@property (nonatomic, readonly, strong) NSDate *expectedDateTo __deprecated_msg("Please use pickupEnd instead");
@property (nonatomic, readonly, strong) NSArray *orderItems __deprecated_msg("Please use items instead");
@property (nonatomic, readonly, strong) NSString *locationId __deprecated_msg("locationId is no longer available");
@property (nonatomic, readonly, strong) NSString *branchId __deprecated_msg("branchId is no longer available");

- (LocalzAttendantOrder *)initWithData:(NSDictionary *)data;

/**
 * Is order is still within the expected period?
 * @returns False if order is outside the expected period, true if it is still within.
 */
- (BOOL) isWithinExpectedWindow;

- (void) updateOrderItems:(NSArray *)items;

/**
 * Updates the order status. If status == LocalzAttendantOrderStatusComplete, all orderItems are set to status "COMPLETE".
 * NOTE 1: This may not be the desired outcome as orderItem.status == PENDING should not be COMPLETED
 * Instead use completOrderIfReady which will only complete those orderItem with status of READY
 * NOTE 2: moving from complete status to other statuses will not revert the orderItem's status
 */
- (void) updateStatus:(NSString *)status;

/**
 * This completes orderItem.status == READY to COMPLETE and set the orderStatus = LocalzAttendantOrderStatusComplete
 * if all orderItems are COMPLETE and LocalzAttendantOrderStatusNotReady if only some are COMPLETE
 */
- (void) completeOrderIfReady;

- (NSDictionary *) toJSON;
@end
