//
//  ViewController.swift
//  SampleLocalzAttendantApp-Swift
//
//  Created by Daniel Sykes-Turner on 13/2/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var txtOrderNumber: UITextField!
    var orders: [LocalzAttendantOrder]! = [LocalzAttendantOrder]()
    
    let attendantUsername = "enter_attendant_username_here"
    let attendantPassword = "enter_attendant_password_here"
    let attendantBranchId = "enter_store_branch_id_here"
    let storePickUpId = "enter_store_pickup_id"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.tableView.delegate = self
        self.tableView.dataSource = self
        
        LocalzAttendantSDK.shared().login(withUsername: attendantUsername, password: attendantPassword, branchId: attendantBranchId, force: true, options: nil) { (error:Error?, attendant:LocalzAttendant?) in
            print("Attendant logged in")
            self.reloadOrders()
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func reloadOrders() {
        
        LocalzAttendantSDK.shared().retrieveOrders { (error:Error?, orders:[Any]?) in
            if let orders = orders as? [LocalzAttendantOrder] {
                self.orders = orders
            }
            self.tableView.reloadData()
        }
    }
    
    // MARK: - Order Flow
    
    @IBAction func createOrder() {
        
        let orderNumber:String! = self.txtOrderNumber.text
        if orderNumber == "" {
            let alert = UIAlertController.init(title: "No Order Number", message: "Please enter a number to create an order", preferredStyle: UIAlertControllerStyle.alert)
            alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: nil))
            self.present(alert, animated: true, completion: nil)
        } else {
            let order:LocalzAttendantOrder! = LocalzAttendantOrder.init(data: [
                "orderNumber":orderNumber,
                "shopperId":"customer1234",
                "specific":[
                    "address":"412 Collins St, Melbourne, Victoria"
                ]
                ])
            
            LocalzAttendantSDK.shared().createOrUpdate(order) { (error:Error?) in
                self.reloadOrders()
            }
        }
        
        self.txtOrderNumber.resignFirstResponder()
    }
    
    func checkInOrder(orderNumber: String!) {
        
        LocalzAttendantSDK.shared().checkinOrderNumber(orderNumber, pickupId: storePickUpId, subProjectId: nil) { (error:Error?) in
            self.reloadOrders()
        }
    }
    
    func acknowledgeOrder(orderNumber: String!) {
        
        LocalzAttendantSDK.shared().acknowledgeOrderNumber(orderNumber, subProjectId: nil) { (error:Error?) in
            self.reloadOrders()
        }
    }
    
    func completeOrder(orderNumber: String!) {
        
        LocalzAttendantSDK.shared().completeOrderNumber(orderNumber, signature: nil, notes: nil, subProjectId: nil) { (error:Error?) in
            self.reloadOrders()
        }
    }
    
    // MARK: - UITableViewDataSource
    
    func numberOfSections(in tableView: UITableView) -> Int {
        
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return self.orders.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        var cell = tableView.dequeueReusableCell(withIdentifier: "cell")
        if cell == nil {
            cell = UITableViewCell.init(style: UITableViewCellStyle.subtitle, reuseIdentifier: "cell")
        }
        
        let order = self.orders[indexPath.row]
        cell?.textLabel?.text = order.orderNumber
        cell?.detailTextLabel?.text = order.status
        
        return cell!
    }
    
    // MARK: - UITableViewDelegate
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        tableView.deselectRow(at: indexPath, animated: true)
        
        let order = self.orders[indexPath.row]
        if order.status == ORDER_STATUS_PENDING || order.status == ORDER_STATUS_READY {
            self.checkInOrder(orderNumber: order.orderNumber)
        } else if order.status == ORDER_STATUS_UNASSIGNED {
            self.acknowledgeOrder(orderNumber: order.orderNumber)
        } else if order.status == ORDER_STATUS_ASSIGNED {
            self.completeOrder(orderNumber: order.orderNumber)
        } else {
            print("Unhandled order status: \(order.status)")
        }
    }
}

