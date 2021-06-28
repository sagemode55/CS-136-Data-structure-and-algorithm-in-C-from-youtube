//Yuwanaboon, Sitthiphol:
//Lab 6

/****Intructor feedback DO NOT DELETE:

****/


#include <iostream>
#include <cctype>
#include "Warehouse.h"

using namespace std;
void  getDelivery(int& itemCount, double& itemCost);
void  getOrder(int& itemCount);
int main() {
    int count =0;
    double cost=0.0;
    Warehouse Manager;
    menuOptions userChoice;
    int tempChoice;

    do {

        cout << "Choose a menu listed option.\n" 
            << "1) Submit an order for widgets\n" 
            << "2) Submit a delivery of widgets to the warehouse\n" 
            << "3) Print details of the outstanding orders\n"
            << "4) Print details of the inventory on hand\n" 
            << "5) Quit inventory program\n" 
            << "Please enter your choice: ";

        cin >> tempChoice;

        userChoice = (enum menuOptions)tempChoice;

        switch (userChoice)
        {
        case Order:
            getOrder(count);
            Manager.setOrder('B', count);
            Manager.processOrder();
            break;
        case Delivery:
            getDelivery(count,cost);
            Manager.setDelivery(cost, count);
            Manager.processOrder();
            break;
        case OutstandingOrders:
            Manager.getPendingOrders();
            break;
        case StockInHand:
            Manager.getStockInHand();
            break;
        case Quit:
            cout << "Quitting inventory manager..." << endl << endl;
            break;
        default:
            cout << "Invalid choice, enter a menu listed input..." << endl << endl;
            break;
        }

    } while (tempChoice != Quit);



    return 0;
}


//Function that input the delivery details including total widgets and per unit price 
    //from the user
    //Pre: None
    //Post: Total widget quantity and unit price in a particular delivery is passed to setDelivery
    //function to store the details in the stack
    void  getDelivery(int& itemCount, double& itemCost)
    {
        cout << endl << "What is the delivery count: ";
        cin >> itemCount;

       while (cin.fail() || itemCount <= 0)
       {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a positive whole number..." << endl
                << "What is the delivery count: ";
            cin >> itemCount;
        }

        cout << "What was the delivery cost to the warehouse: $";

        cin >> itemCost;

        while (cin.fail() || itemCost <= 0)
        {
            cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a positive whole number..." << endl
                << "What was the delivery cost: $";
            cin >> itemCost;
        }

        // Manager.setDelivery(itemCost, itemCount);
    }
 void  getOrder(int& itemCount)
    {
        cout << endl << "How many widgets would you like to order: ";
        cin >> itemCount;

        while ( cin.fail()||itemCount <= 0)
	{
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a positive whole number..." << endl
                << "How many widgets would you like to order: ";
            cin >> itemCount;
        }

        // Manager.setOrder('B', itemCount);
    }

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 1

// How many widgets would you like to order: 10

// Order #1 of 10 widgets, has been added to the order list

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 1

// How many widgets would you like to order: 10

// Order #2 of 10 widgets, has been added to the order list

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 3

//   Pending Order List
// Order number                  2
// Quantity Ordered              10
// Quantity Shipped              0
// Quantity Remaining            10
// Status[P:Partial|B:Backorder] B

// Order number                  1
// Quantity Ordered              10
// Quantity Shipped              0
// Quantity Remaining            10
// Status[P:Partial|B:Backorder] B

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 2

// What is the delivery count: 40
// What was the delivery cost to the warehouse: $10

// Delivery #1 of 40 widgets, has been added to the delivery list
// Cost to warehouse:            10                            
// To be sold for:               20                            


// Details for the new order processed: 
// Order Number                       2
// Widgets Ordered                    10
// Widgets Previously Delivered       0
// Current Shipment Size              10
// Backorder Quantity                 0
// Per Unit Cost                      10
// Shipment Cost(Warehouse)           100
// Shipment Cost(Customer)            200
// Shipment Profit                    100


// Details for the new order processed: 
// Order Number                       1
// Widgets Ordered                    10
// Widgets Previously Delivered       0
// Current Shipment Size              10
// Backorder Quantity                 0
// Per Unit Cost                      10
// Shipment Cost(Warehouse)           100
// Shipment Cost(Customer)            200
// Shipment Profit                    100

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 4

//                            Stock In Hand
// Delivery #     Quantity       Unit Price     Cost to Warehouse   Cost to Customer    
// 1              20             10             200                 400                 

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 3

// there is zero pending order in the Inventory

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 2

// What is the delivery count: 1  
// What was the delivery cost to the warehouse: $10

// Delivery #2 of 1 widgets, has been added to the delivery list
// Cost to warehouse:            10                            
// To be sold for:               20                            

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 1

// How many widgets would you like to order: 1

// Order #3 of 1 widgets, has been added to the order list


// Details for the new order processed: 
// Order Number                       3
// Widgets Ordered                    11
// Widgets Previously Delivered       10
// Current Shipment Size              1
// Backorder Quantity                 0
// Per Unit Cost                      10
// Shipment Cost(Warehouse)           10
// Shipment Cost(Customer)            20
// Shipment Profit                    10

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 1

// How many widgets would you like to order: 1

// Order #4 of 1 widgets, has been added to the order list


// Details for the new order processed: 
// Order Number                       4
// Widgets Ordered                    12
// Widgets Previously Delivered       11
// Current Shipment Size              1
// Backorder Quantity                 0
// Per Unit Cost                      10
// Shipment Cost(Warehouse)           10
// Shipment Cost(Customer)            20
// Shipment Profit                    10

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 4

//                            Stock In Hand
// Delivery #     Quantity       Unit Price     Cost to Warehouse   Cost to Customer    
// 1              19             10             190                 380                 

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 3

// there is zero pending order in the Inventory

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 2 

// What is the delivery count: 10
// What was the delivery cost to the warehouse: $10

// Delivery #3 of 10 widgets, has been added to the delivery list
// Cost to warehouse:            10                            
// To be sold for:               20                            

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 4

//                            Stock In Hand
// Delivery #     Quantity       Unit Price     Cost to Warehouse   Cost to Customer    
// 3              10             10             100                 200                 
// 1              19             10             190                 380                 

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 2

// What is the delivery count: 10
// What was the delivery cost to the warehouse: $10

// Delivery #4 of 10 widgets, has been added to the delivery list
// Cost to warehouse:            10                            
// To be sold for:               20                            

// Sorry, no order can be delivered right now!

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 3

// there is zero pending order in the Inventory

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 4

//                            Stock In Hand
// Delivery #     Quantity       Unit Price     Cost to Warehouse   Cost to Customer    
// 4              10             10             100                 200                 
// 3              10             10             100                 200                 
// 1              19             10             190                 380                 

// Choose a menu listed option.
// 1) Submit an order for widgets
// 2) Submit a delivery of widgets to the warehouse
// 3) Print details of the outstanding orders
// 4) Print details of the inventory on hand
// 5) Quit inventory program
// Please enter your choice: 
