//Yuwanaboon, Sitthiphol:
//Lab 9
#include "Warehouse.h"
#include<limits>

void GetOrderInput(int& count, int &OrderStatus);
void GetDeliveryInput(int& count, double& cost);

int main()
{
	Warehouse Manager;
  menuOptions UserInput;
	cout << fixed << showpoint << setprecision(2);
  int TempInput;
	int count = 0;
	double cost = 0;
	int OrderStatus = 0;
  
	do
	{
		cout << "\nMain menu options...\n"
            << "1) Submit a delivery\n"
			<< "2) Display the details of the inventory on hand\n"
			<< "3) Submit a new order\n"
			<< "4) Display the details of the outstanding orders\n"
			<< "5) Close the day and process back orders(if any) and orders received on that day\n"
			<< "6) Quit the program\n"
			<< "Enter input: ";
      cin >> TempInput;
		
    UserInput = (enum menuOptions)TempInput;


		switch (UserInput)
		{
		case Delivery: // Option to receive a delivery
			// assign a unique delivery number for each new delivery
			GetDeliveryInput(count, cost);
			Manager.EnqueueDelivery(count, cost);
			break;
		case DeliveryQueue: // Option to display the details of the inventory on hand
			Manager.PrintDeliveryQueue();
			break;
		case Order:
			// option to receive a new order
			GetOrderInput(count, OrderStatus);
			Manager.EnqueueOrder(count, OrderStatus);
			break;
		case OrderQueue:
			Manager.PrintOrderQueue();
			break;
		case TotalOrderThatDay: // option to close a day and process back orders and orders received on that day
			Manager.PrintOrderQueue();
			while (Manager.OrderSize() > Manager.InventorySize())
			{
				cout << "No back orders; there is not enough inventory to ship all orders; add more inventory!\n";
				GetDeliveryInput(count, cost);
				Manager.EnqueueDelivery(count, cost);
			}
      Manager.summary();
			Manager.ProcessOrder();
			// Show inventory on hand after day's orders have been processed.
			Manager.PrintDeliveryQueue();
     break;
		case Quit:
			cout << "Quitting program...\n";
			break;	
		default:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, please enter a valid menu option.\n";
			break;
		}
	} while (UserInput != Quit);
	return 0;
}

// Function gets order count input from user
// Pre: None
// Post: Order Count is used to call PushOrderQueue(count), to push a new node onto the order queue
void GetOrderInput(int& count, int &OrderStatus)
{
	int input;
	cout << "How many widgets would you like to order: ";
	cin >> count;
	while (cin.fail() || count <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter an whole number...\n"
			<< "How many widgets would you like to order: ";
		cin >> count;
	}

	cout << "\nWhat type of delivery would you like?\n"
		<< "1) extreme rush orders -  filled before  any other order; 100% markup\n"
		<< "2) expedite rush orders- filled after extreme rush orders but before standard; 40% markup\n"
		<< "3) standard orders -  filled in the order  received, 20% markup\n"
		<< "Enter a valid input: ";
	cin >> input;
	while (cin.fail() || input < 1 || input > 3)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid input for the type of delivery: ";
		cin >> input;
	}

	switch (input)
	{
	case 1:
		OrderStatus = Warehouse::Extreme;
		break;
	case 2:
		OrderStatus = Warehouse::Expedite;
		break;
	case 3:
		OrderStatus = Warehouse::Standard;
		break;
	default:
		break;
	}
	cout << "\n";
}

// Function gets delivery count and delivery cost to the warehouse input from user
// Pre: None
// Post: Delivery Count and delivery cost is used to call PushDeliveryQueue(count, cost),
// to push a new node onto the delivery queue
void GetDeliveryInput(int& count, double& cost)
{
	cout << "What is the delivery count: ";
	while (!(cin >> count) || (count <= 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a positive whole number...\n"
			<< "What is the delivery count: ";
	}
	cout << "What was the delivery cost: $";
	while (!(cin >> cost) || (cost <= 0))					// allow cost to equal 0
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a positive number...\n"
			<< "What was the delivery cost: $";
	}
	cout << "\n";
}


// clang++-7 -pthread -std=c++17 -o main Warehouse.cpp main.cpp
//  ./main

// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 1
// What is the delivery count: 10
// What was the delivery cost: $10

// Delivery #1 of 10 widgets, has been added to the delivery list.
// Cost to the warehouse:                       10.00


// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 2

// Details of Inventory on hand
// Number of widgets in stock:                     10
// Delivery Number:                                 1
// Delivery Count:                                 10
// Cost to the warehouse (per widget):          10.00



// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 3
// How many widgets would you like to order: 10

// What type of delivery would you like?
// 1) extreme rush orders -  filled before  any other order; 100% markup
// 2) expedite rush orders- filled after extreme rush orders but before standard; 40% markup
// 3) standard orders -  filled in the order  received, 20% markup
// Enter a valid input: 1

// Order #1 of 10 widgets, of Extreme Rush Order has been added as an order to be fullfilled by the warehouse.


// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 4

// Details of the outstanding orders
// Number of widgets that have been shipped:        0
// Number of widgets in queue:                     10

// Order Number:                                    1
// Order Count:                                    10
// Order Priority:                 Extreme Rush Order



// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 5

// Details of the outstanding orders
// Number of widgets that have been shipped:        0
// Number of widgets in queue:                     10

// Order Number:                                    1
// Order Count:                                    10
// Order Priority:                 Extreme Rush Order



// ************** SUMMARY ************

// Total Orders: 1
// Total cost to warehouse of all 1 orders: 100.00
// Total cost to customers of all 1 orders: 200.00
// Total profit of all 1 orders: 100.00

// *******************************************************

// Order Number:                                   1
// Total Quantity Shipped:                        10
// Qty Ordered:                                   10
// Rush Status:                    Extreme Rush Order
// % MakeUp                                    100.00%
// Total cost to the warehouse:                100.00
// Total cost to the customer:                 200.00
// Profit for this shipment:                   100.00

// Order#1 Details:
// Qty     UnitPrice   CostToWarehouse   CostToCustomer
// 10      10.00       100.00            200.00

// *******************************************************


// Sorry, currently no orders can be fulfilled right now.


// Details of Inventory on hand
// Number of widgets in stock:                      0
// No widgets are currently in the inventory...


// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 


// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 5

// Details of the outstanding orders
// Number of widgets that have been shipped:       10
// Number of widgets in queue:                      0

// Order list is empty.


// ************** SUMMARY ************

// Total Orders: 0
// Total cost to warehouse of all 0 orders: 0.00
// Total cost to customers of all 0 orders: 0.00
// Total profit of all 0 orders: 0.00

// Sorry, currently no orders can be fulfilled right now.


// Details of Inventory on hand
// Number of widgets in stock:                      0
// No widgets are currently in the inventory...


// Main menu options...
// 1) Submit a delivery
// 2) Display the details of the inventory on hand
// 3) Submit a new order
// 4) Display the details of the outstanding orders
// 5) Close the day and process back orders(if any) and orders received on that day
// 6) Quit the program
// Enter input: 6
// Quitting program...
//  
