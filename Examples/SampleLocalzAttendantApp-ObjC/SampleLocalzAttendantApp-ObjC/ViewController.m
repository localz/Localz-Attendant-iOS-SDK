//
//  ViewController.m
//  SampleLocalzAttendantApp-ObjC
//
//  Created by Daniel Sykes-Turner on 13/2/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import "ViewController.h"
#import <LocalzAttendantSDK/LocalzAttendantSDK.h>

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, weak) IBOutlet UITableView *tableView;
@property (nonatomic, weak) IBOutlet UITextField *txtOrderNumber;
@property (nonatomic, strong) NSMutableArray *orders;
@property (nonatomic, strong) NSString *attendantUsername;
@property (nonatomic, strong) NSString *attendantPassword;
@property (nonatomic, strong) NSString *storeBranchId;
@property (nonatomic, strong) NSString *storePickupId;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.attendantUsername = @"enter_attendant_username_here";
    self.attendantPassword = @"enter_attendant_password_here";
    self.storeBranchId = @"enter_store_branch_id_here";
    self.storePickupId = @"enter_store_pickup_id_here";
    
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    [[LocalzAttendantSDK shared] loginWithUsername:self.attendantUsername password:self.attendantPassword branchId:self.storeBranchId force:true options:nil completion:^(NSError * _Nullable error, LocalzAttendant * _Nullable user) {
        NSLog(@"Attendant logged in");
        [self reloadOrders];
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)reloadOrders {
    
    [[LocalzAttendantSDK shared] retrieveOrdersWithCompletion:^(NSError * _Nullable error, NSArray * _Nullable orders) {
        self.orders = orders.mutableCopy;
        [self.tableView reloadData];
    }];
}

#pragma mark - Order Flow

- (IBAction)createOrder:(id)sender {
    
    NSString *orderNumber = self.txtOrderNumber.text;
    if (orderNumber.length == 0) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"No Order Number" message:@"Please enter a number to create an order" preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
        [self presentViewController:alert animated:true completion:nil];
    } else {
        LocalzAttendantOrder *order = [[LocalzAttendantOrder alloc] initWithData:@{
                                                                             @"orderNumber":orderNumber,
                                                                             @"shopperId":@"customer1234",
                                                                             @"specific":@{
                                                                                     @"address":@"412 Collins Street, Melbourne, Victoria"
                                                                                     }
                                                                             }];
        
        [[LocalzAttendantSDK shared] createOrUpdateOrder:order completion:^(NSError * _Nullable error) {
            [self reloadOrders];
        }];
    }
    
    [self.txtOrderNumber resignFirstResponder];
}

- (void)checkinOrder:(NSString *)orderNumber {
    
    [[LocalzAttendantSDK shared] checkinOrderNumber:orderNumber pickupId:self.storePickupId subProjectId:nil completion:^(NSError * _Nullable error) {
        [self reloadOrders];
    }];
}

- (void)acknowledgeOrder:(NSString *)orderNumber {
    
    [[LocalzAttendantSDK shared] acknowledgeOrderNumber:orderNumber subProjectId:nil completion:^(NSError * _Nullable error) {
        [self reloadOrders];
    }];
}

- (void)completeOrder:(NSString *)orderNumber {
    
    [[LocalzAttendantSDK shared] completeOrderNumber:orderNumber signature:nil notes:nil subProjectId:nil completion:^(NSError * _Nullable error) {
        [self reloadOrders];
    }];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return self.orders.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"cell"];
    }
    
    LocalzAttendantOrder *order = self.orders[indexPath.row];
    cell.textLabel.text = order.orderNumber;
    cell.detailTextLabel.text = order.status;
    
    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    
    LocalzAttendantOrder *order = self.orders[indexPath.row];
    if ([order.status isEqualToString:ORDER_STATUS_PENDING] || [order.status isEqualToString:ORDER_STATUS_READY]) {
        [self checkinOrder:order.orderNumber];
    } else if ([order.status isEqualToString:ORDER_STATUS_UNASSIGNED]) {
        [self acknowledgeOrder:order.orderNumber];
    } else if ([order.status isEqualToString:ORDER_STATUS_ASSIGNED]) {
        [self completeOrder:order.orderNumber];
    } else {
        NSLog(@"Unhandled order status: %@", order.status);
    }
}

@end
