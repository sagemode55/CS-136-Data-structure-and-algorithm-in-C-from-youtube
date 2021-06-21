//Yuwanaboon, Sitthiphol:
//Lab 9


/****Intructor feedback DO NOT DELETE:
NG 6/3/21 
-- does not comply with the assignment description
-- not approved

****/
#include "Warehouse.h"
#include<vector>

// Notes:
// show total number of orders processed along with their total
// cost to the warehouse, total profit, and total cost to the customers

// Function initializes class members to default value
// Pre: Object is created
// Post: Class members are initialized to default values
Warehouse::Warehouse()
{
	WidgetsShipped = 0;
	WidgetsInStock = 0;
	OrdersInQueue = 0;
	OrderNumber = 1;
	DeliveryNumber = 1;
	TotalOrdersProcessed = 0;
	TotalWarehouseCost = 0;
	OrderQueueSize = 0;

	FrontDelivery = nullptr;
	RearDelivery = nullptr;
	TempDelivery = nullptr;

	ClearTotalData();
	MakeOrderQueueEmpty();
	MakeDeliveryQueueEmpty();
}

// Function initializes clas members to default values
// Pre: Object is out of scope
// Post: Class members are initialized to default values
Warehouse::~Warehouse()
{
	WidgetsShipped = 0;
	WidgetsInStock = 0;
	OrdersInQueue = 0;
	OrderNumber = 1;
	DeliveryNumber = 1;
	TotalOrdersProcessed = 0;
	TotalWarehouseCost = 0;
	OrderQueueSize = 0;

	FrontDelivery = nullptr;
	RearDelivery = nullptr;
	TempDelivery = nullptr;

	ClearTotalData();
	MakeOrderQueueEmpty();
	MakeDeliveryQueueEmpty();
}

// Function checks if the order queue is empty
// Pre: None
// Post: Either 1(True) or a 0(False) is returned stating if the order queue is empty
bool Warehouse::isOrderQueueEmpty()
{
	return OrderQueueSize == 0;
}

// Function checks if the delivery queue is empty
// Pre: None
// Post: Either 1(True) or a 0(False) is returned stating if the delivery queue is empty
bool Warehouse::isDeliveryQueueEmpty()
{
	return FrontDelivery == nullptr && RearDelivery == nullptr;
}

// Function returns the value of the top node's item number of the order queue
// Pre: None
// Post: The value of the top node's item number of the order queue is returned
int Warehouse::PeekOrderNumber()
{
	if (!isOrderQueueEmpty())
	{
		return OrderList[0].OrderQueueItemNumber;
	}
	else
		return -1;
}

// Function returns the value of the top node's order count of the order queue
// Pre: None
// Post: The value of the top node's order count of the order queue is returned
int Warehouse::PeekOrderCount()
{
	if (!isOrderQueueEmpty())
	{
		return OrderList[0].OrderCount;
	}
	else
		return -1;
}

int Warehouse::PeekOrderPriority()
{
	if (!isOrderQueueEmpty())
	{
		return OrderList[0].Priority;
	}
	else
		return -1;
}

double Warehouse::PeekMarkup()
{
	if (!isOrderQueueEmpty())
	{
		return OrderList[0].Markup;
	}
	else
		return -1;
}

// Function returns the value of the top node's item number of the delivery queue
// Pre: None
// Post: The value of the top node's item number of the delivery queue is returned
int Warehouse::PeekDeliveryNumber()
{
	if (!isDeliveryQueueEmpty())
	{
		return FrontDelivery->DeliveryQueueItemNumber;
	}
	else
		return -1;
}

// Function returns the value of the top node's delivery count of the delivery queue
// Pre: None
// Post: The value of the top node's delivery count of the delivery queue is returned
int Warehouse::PeekDeliveryCount()
{
	if (!isDeliveryQueueEmpty())
	{
		return FrontDelivery->DeliveryCount;
	}
	else
		return -1;
}

// Function returns the value of the top node's delivery cost of the delivery queue
// Pre: None
// Post: The value of the top node's delivery cost of the delivery queue is returned
double Warehouse::PeekDeliveryCost()
{
	if (!isDeliveryQueueEmpty())
	{
		return FrontDelivery->DeliveryQueueItemCost;
	}
	else
		return -1;
}

// Function checks if the order queue is full
// Pre: None
// Post: Either 1 (True) or a 0 (False) is returned for determining if the order queue is full
bool Warehouse::isOrderQueueFull()
{
	return OrderQueueSize == MaxOrderSize;
}

// Function checks if the delivery queue is full
// Pre: None
// Post: Either 1 (True) or a 0 (False) is returned for determining if the delivery queue is full
bool Warehouse::isDeliveryQueueFull()
{
	try								
	{
		DeliveryQueueNodeTypePointer newNode = new DeliveryQueueNodeType;
		delete newNode;
		newNode = nullptr;
	}
	catch (bad_alloc & ex)				
	{
		return 1;
	}
	return 0;
}

// Function attempts to add a new order to the heap
// Pre: User enters valid input for an order count
// Post: A new order is attempted to be added to its priority position of the queue
// and displays information about the order successfully added
void Warehouse::EnqueueOrder(int count, int PriorityTemp)
{
	if (isOrderQueueFull())
	{
		cout << "Order List is full. Unable to take any orders...\n";
	}
	else
	{
		OrderList[OrderQueueSize].OrderQueueItemNumber = OrderNumber++;
		OrderList[OrderQueueSize].OrderCount = count;
		OrderList[OrderQueueSize].Priority = PriorityTemp;

		switch (PriorityTemp)
		{
		case Extreme:
			OrderList[OrderQueueSize].Markup = ExtremeCost;
			break;
		case Expedite:
			OrderList[OrderQueueSize].Markup = ExpediteCost;
			break;
		case Standard:
			OrderList[OrderQueueSize].Markup = StandardCost;
			break;
		default:
			// Reaching default statement is not possible unless something went wrong in the program
			// if triggers then nullptr is being used in memory for either queue
			cerr << "Error, Exiting program...\n";
			system("pause");
			exit(1);
			break;
		}
		cout << "Order #" << OrderList[OrderQueueSize].OrderQueueItemNumber <<
			" of " << OrderList[OrderQueueSize].OrderCount << " widgets, "
			<< "of " << RushStatus(OrderList[OrderQueueSize].Priority)
			<< " has been added as an order to be fullfilled by the warehouse.\n\n";
		OrdersInQueue += count;
		OrderQueueSize++;

		int i = OrderQueueSize - 1;


	/*	while (i != 0 && OrderList[parent(i)].Priority > OrderList[i].Priority)
		{
			swap(i, parent(i));
			i = parent(i);
		}*/

		heapifyUp();
	}
}

// Function attempts to add a new node to the rear of the delivery queue
// Pre: User enters valid input for an delivery count and delivery cost
// Post: A new node is attempted to be added to the rear of the delivery queue
// and displays information about the node successfully added
void Warehouse::EnqueueDelivery(int count, double cost)
{
	DeliveryQueueNodeTypePointer newNode;
	if (isDeliveryQueueFull())
	{						
		cout << "Delivery list is full. Unable to take any deliveries." << endl;
	}
	else
	{
			try
			{
				newNode = new DeliveryQueueNodeType;
				newNode->DeliveryQueueItemNumber = DeliveryNumber++;
				newNode->DeliveryCount = count;
				newNode->DeliveryQueueItemCost = cost;
				newNode->NextDelivery = nullptr;
				if (FrontDelivery == nullptr)
				{
					FrontDelivery = newNode;
					RearDelivery = newNode;
				}
				else
				{
					RearDelivery->NextDelivery = newNode;
					RearDelivery = newNode;
				}
				RearDelivery->NextDelivery = nullptr;
				WidgetsInStock += count;
			}
			catch (bad_alloc & ex)
			{
				cerr << "No more deliveries can be processed...\n";
				system("pause");
				exit(1);
			}
			cout << "Delivery #" << RearDelivery->DeliveryQueueItemNumber
				<< " of " << RearDelivery->DeliveryCount << " widgets, has been added to the delivery list.\n"
				<< setw(30) << left << "Cost to the warehouse:  " << setw(20) << right << RearDelivery->DeliveryQueueItemCost << "\n\n";
			    //<< setw(30) << left <<  "To be sold for:        " << setw(20) << right << RearDelivery->DeliveryQueueItemCost * 1.5 << "\n\n";
	}
	
}

// Function prints the details of the outstanding orders
// Pre: User selects option that calls PrintOrderQueue()
// Post: None
void Warehouse::PrintOrderQueue()
{
  double CustomerCost;
  double Profit;
  double CostWarhouse;
	cout << "\nDetails of the outstanding orders\n"
		 << setw(30) << left << "Number of widgets that have been shipped: " << setw(8) << right << WidgetsShipped << "\n"
		 << setw(30) << left << "Number of widgets in queue:               " << setw(8) << right << OrdersInQueue << "\n\n";
	if (isOrderQueueEmpty())
	{
		cout << "Order list is empty.\n\n";
	}
	else
	{
		int i = 0;
		while (i < OrderQueueSize)
		{
        // CostWarhouse += (OrderList[i].OrderCount)*(RearDelivery[i].DeliveryQueueItemCost);
        // CustomerCost +=(OrderList[i].OrderCount)*(1.0 + OrderList[0].Markup)*(RearDelivery[i].DeliveryQueueItemCost);
        
			cout << setw(30) << left << "Order Number:    " << setw(20) << right << OrderList[i].OrderQueueItemNumber << "\n"
				 << setw(30) << left << "Order Count:     " << setw(20) << right << OrderList[i].OrderCount << "\n"
				 << setw(30) << left << "Order Priority:  " << setw(20) << right << RushStatus(OrderList[i].Priority) << "\n\n";
			i++;
		}
    // Profit  = CustomerCost-CostWarhouse;

	// cout << setw(30) << left << "Total cost to the warehouse: " << setw(20) << right <<  CostWarhouse << "\n"
	// 	 << setw(30) << left << "Total cost to the customer: " << setw(20) << right << CustomerCost << "\n"
	// 	 << setw(30) << left << "Total profit to the warehouse: " << setw(19) << right << Profit << "\n\n";
		cout << "\n";
	}
}

void Warehouse::PrintTableData(){
  
  
  double CustomerCost = TotalWarehouseCost * (1 + PeekMarkup());
	double Profit = CustomerCost - TotalWarehouseCost;
	cout << setw(30) << left << "\nTotal number of orders processed: " << setw(16) << right << TotalOrdersProcessed << "\n"
		 << setw(30) << left << "Total cost to the warehouse: " << setw(20) << right <<  TotalWarehouseCost << "\n"
		 << setw(30) << left << "Total cost to the customer: " << setw(20) << right << CustomerCost << "\n"
		 << setw(30) << left << "Total profit to the warehouse: " << setw(19) << right << Profit << "\n\n";
}


// Function prints the details of the inventory on hand
// Pre: User selects option that calls PrintDeliveryQueue()
// Post: None
void Warehouse::PrintDeliveryQueue()
{
	cout << "\nDetails of Inventory on hand\n"
		 << setw(30) << left << "Number of widgets in stock: " << setw(20) << right << WidgetsInStock << "\n";
	if (FrontDelivery == nullptr)
	{
		cout << "No widgets are currently in the inventory...\n\n";
	}
	else
	{
		TempDelivery = FrontDelivery;
		while (TempDelivery != nullptr)
		{
			cout << setw(30) << left << "Delivery Number:       " << setw(20) << right << TempDelivery->DeliveryQueueItemNumber << "\n"
				<< setw(30) << left << "Delivery Count:        " << setw(20) << right << TempDelivery->DeliveryCount << "\n"
				<< setw(30) << left << "Cost to the warehouse (per widget): " << setw(14) << right << TempDelivery->DeliveryQueueItemCost << "\n\n";
				 //<< setw(30) << left << "Cost to the customer (per widget):  " << setw(14) << right  << TempDelivery->DeliveryQueueItemCost * 1.5 << "\n\n";
			TempDelivery = TempDelivery->NextDelivery;
		}
		cout << "\n";
	}
}

// Function attempts to remove a node from the front of the order queue
// Pre: The entire widget order (front node of order queue) have been processed
// Post: If the order queue is not empty, then the node will be removed from the front of the order queue
void Warehouse::DequeueOrder()
{
	if (isOrderQueueEmpty())
	{
		cout << "No widgets are currently in the order list\n";
	}
	else
	{
			OrderList[0] = OrderList[OrderQueueSize - 1];
			OrderQueueSize--;
			heapifyDown();
	}
}

// Function attempts to remove a node from the front of the delivery queue
// Pre: The entire widget delivery (front node of delivery queue) have been processed
// Post: If the delivery queue is not empty, then the node will be removed from the front of the delivery queue
void Warehouse::DequeueDelivery()
{
	if (isDeliveryQueueEmpty())
	{
		cout << "No widgets are currently in the inventory...\n\n";
	}
	else
	{
		if (FrontDelivery == RearDelivery)
		{
			delete FrontDelivery;
			FrontDelivery = nullptr;
			RearDelivery = nullptr;
		}
		else
		{
			TempDelivery = FrontDelivery;
			FrontDelivery = FrontDelivery->NextDelivery;
			delete TempDelivery;
			TempDelivery = nullptr;
		}
	}
}


//utility
template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(' ') << t;
}

//to store order data being processed
vector<int> qty;
vector<double> unitPrice, costWarehouse, costCustomer;

// Function processes as many orders as possible
// Pre: Either Order Enqueue or Delivery Enqueue function have been called successfully
// Post: Atleast one full or partial order have been processed
void Warehouse::ProcessOrder()
{

	BatchItemsShipped = CountShipmentFromBatch();
	double BatchCost = BatchItemsShipped * PeekDeliveryCost();

	if (isOrderQueueEmpty() || isDeliveryQueueEmpty())	// no orders can be fulfilled if either queue is empty
	{
		cout << "Sorry, currently no orders can be fulfilled right now.\n\n";
	}
	else
	{
		// cout << "\nProcessed order that have been fulfilled...\n" 
		// 	 << setw(30) << left << "Order Number:              " << setw(20) << right <<  PeekOrderNumber() << "\n"
		// 	 << setw(30) << left << "Delivery Batch Number:     " << setw(20) << right << PeekDeliveryNumber() << "\n"
		// 	 << setw(30) << left << "Rush Status:               " << setw(20) << right << RushStatus(PeekOrderPriority()) << "\n"
		// 	 << setw(30) << left << "Total quantity shipped:    " << setw(20) << right << BatchItemsShipped << "\n"
		// 	 << setw(30) << left << "Total quantity ordered:    " << setw(20) << right << PeekOrderCount() << "\n"
		// 	 << setw(30) << left << "Batch cost to warehouse:   " << setw(20) << right << BatchCost << "\n"
		// 	 << setw(30) << left << "Batch cost to customer:    " << setw(20) << right << BatchCost* (1 + PeekMarkup()) << "\n"
		// 	 << setw(30) << left << "Profit from batch:         " << setw(20) << right << (BatchCost * (1 + PeekMarkup())) - (BatchCost) << "\n"
		// 	 << setw(30) << left << "Percentage of markup:      " << setw(18) << right << PeekMarkup()*100 << " %\n";
		
		qty.push_back(BatchItemsShipped);
		unitPrice.push_back(PeekDeliveryCost());
		costWarehouse.push_back(BatchCost);
		costCustomer.push_back(BatchCost* (1 + PeekMarkup()));
		
		TotalOrdersProcessed += BatchItemsShipped;
		TotalWarehouseCost += BatchCost;

		FrontDelivery->DeliveryCount -= BatchItemsShipped;
		OrderList[0].OrderCount -= BatchItemsShipped;

		if (PeekDeliveryCount() <= 0)
		{
			DequeueDelivery();
		}
		if (PeekOrderCount() <= 0)
		{
			PrintTotalData();
			DequeueOrder();
			ClearTotalData();
		}

		WidgetsInStock -= BatchItemsShipped;
		OrdersInQueue -= BatchItemsShipped;
		WidgetsShipped += BatchItemsShipped;
    // PrintTableData();

		ProcessOrder();							// Try to process as many orders based on batches as possible
												   // if either queue is empty, then the function will end
	}
}

// Function determines how many items to send out for batch shipment
// Pre: ProcessedOrder() is called, then ProcessedOrder() calls this function
// Post: int value of Batch items to ship is returned
int Warehouse::CountShipmentFromBatch()
{
	if (PeekOrderCount() > PeekDeliveryCount())
		return PeekDeliveryCount();
	else
		return PeekOrderCount();
}

// Function clears the counters that count the total Orders processed and totalwarehousecost
// Pre: none
// Post: none
void Warehouse::ClearTotalData()
{
	TotalOrdersProcessed = 0;
	TotalWarehouseCost = 0;
}
// Function prints data of the total order processed
// Pre: none
// Post: none
void Warehouse::PrintTotalData()
{
	// show total number of orders processed along with their total
	// cost to the warehouse, total profit, and total cost to the customers
	double CustomerCost = TotalWarehouseCost * (1 + PeekMarkup());
	double Profit = CustomerCost - TotalWarehouseCost;

	cout<<"*******************************************************\n";

	cout << setw(30) << left << "\nOrder Number: " << setw(20) << right << PeekOrderNumber() << "\n"
    << setw(30) << left << "Total Quantity Shipped:" << setw(19)  << right <<BatchItemsShipped << "\n"
		 << setw(30) << left << "Qty Ordered: " << setw(19) << right << TotalOrdersProcessed << "\n"
		 << setw(30) << left << "Rush Status: " << setw(20) << right << RushStatus(PeekOrderPriority()) << "\n"
     << setw(30) << left << "% MakeUp " << setw(20) << right << PeekMarkup()*100 <<"%\n"
		 //<< setw(30) << left << "Total number of orders processed: " << setw(20) << right << TotalOrdersProcessed << "\n"
		 << setw(30) << left << "Total cost to the warehouse: " << setw(20) << right <<  TotalWarehouseCost << "\n"
		 << setw(30) << left << "Total cost to the customer: " << setw(20) << right << CustomerCost << "\n"
		 << setw(30) << left << "Profit for this shipment: " << setw(20) << right << Profit << "\n\n";

	cout<<"Order#"<<PeekOrderNumber()<<" Details:\n";
	printElement("Qty", 8);
	printElement("UnitPrice", 12);
	printElement("CostToWarehouse", 18);
	printElement("CostToCustomer", 0);
	cout<<"\n";
	for(int i=0; i<qty.size(); i++) {
		printElement(qty[i], 8);
		printElement(unitPrice[i], 12);
		printElement(costWarehouse[i], 18);
		printElement(costCustomer[i], 0);
		cout<<"\n";
	}

	cout<<"\n*******************************************************\n\n\n";

	//clear data so that next order can be recorded
	qty.clear();
	unitPrice.clear();
	costWarehouse.clear();
	costCustomer.clear();
}





// Function will remove every node from the order queue
// Pre: A constructor/deconstructor calls MakeOrderQueueEmpty()
// Post: All nodes have been removed from the order queue
void Warehouse::MakeOrderQueueEmpty()
{
	while (!isOrderQueueEmpty())
	{
		DequeueOrder();
	}
}

// Function will remove every node from the delivery queue
// Pre: A constructor/deconstructor calls MakeDeliveryQueueEmpty()
// Post: All nodes have been removed from the delivery queue
void Warehouse::MakeDeliveryQueueEmpty()
{
	while (!isDeliveryQueueEmpty())
	{
		DequeueDelivery();
	}
}


// Function returns a string of description of the Order status for a recent order
// Pre: Function is called by Push() for orders
// Post: String description of rush status is returned
string Warehouse::RushStatus(int status)
{
	switch(status)
	{
		case Extreme:
			return "Extreme Rush Order";
		case Expedite:
			return "Expedite Rush Order";
		case Standard:
			return "Standard Order";
		default:
			cerr << "Error, exiting program...\n";			// if triggers then nullptr is being used in memory for either queue
			system("pause");
			exit(1);
			break;
	}
}

// Function returns int value of the size of the OrderQueue by using a counter
// that moves on enqueue and dequeue function for orders
// Pre: None
// Post: None
int Warehouse::OrderSize()
{
	return OrdersInQueue;
}

// Function returns the int value of the size of the InventoryQueue by using a counter
// that moves on enqueue and dequeue function for deliveries
// Pre: None
// Post: None
int Warehouse::InventorySize()
{
	return WidgetsInStock;
}

// Function swaps the indexes of array using given arguments
// Pre: function is called with two elements of array to swap
// Post: Array has swapped two elements
void Warehouse::swap(int indexOne, int indexTwo)
{
	OrderQueueType temp = OrderList[indexOne];
	OrderList[indexOne] = OrderList[indexTwo];
	OrderList[indexTwo] = temp;
}

// Function moves an element up the heap to its appropriate position
// Pre: None
// Post: elements are in correct position
void Warehouse::heapifyUp()
{
	int index = OrderQueueSize - 1;
	while (hasParent(index) && parent(index) > OrderList[index].Priority)
	{
		swap(getParentIndex(index), index);
		index = getParentIndex(index);
	}
}

// Function moves elements down the heap to their appropriate position
// Pre: None
// Post: elements are in correct position
void Warehouse::heapifyDown()
{
	int index = 0;
	while (hasLeftChild(index))
	{
		int smallerChildIndex = getLeftChildIndex(index);
		if (hasRightChild(index) && rightChild(index) < leftChild(index))
		{
			smallerChildIndex = getRightChildIndex(index);
		}

		if (OrderList[index].Priority < OrderList[smallerChildIndex].Priority)
		{
			break;
		}
		else
		{
			swap(index, smallerChildIndex);
		}
		index = smallerChildIndex;
	}
}

void Warehouse::summary() {
	double costToCustomers = 0.0;
	double costToWarehouse = 0.0;
  double totalProfit= 0.0;
	int deliveryQueueSize=0;
	//int OrderQueueSizeCopy = OrderQueueSize;

	OrderQueueType OrderListCopy[OrderQueueSize];
	for(int i=0; i<OrderQueueSize; i++) {
		OrderListCopy[i].Markup = OrderList[i].Markup;
		OrderListCopy[i].OrderCount =  OrderList[i].OrderCount;
		OrderListCopy[i].OrderQueueItemNumber = OrderList[i].OrderQueueItemNumber;
		OrderListCopy[i].Priority = OrderList[i].Priority;
	}

	DeliveryQueueNodeTypePointer currDelivery = FrontDelivery;
	DeliveryQueueNodeTypePointer deliveryList = nullptr;
	DeliveryQueueNodeTypePointer deliveryListRear = nullptr;
	
	while(currDelivery != nullptr) {
		deliveryQueueSize++;
		DeliveryQueueNodeTypePointer newNode = new DeliveryQueueNodeType;
		newNode->DeliveryQueueItemNumber = currDelivery->DeliveryQueueItemNumber;
		newNode->DeliveryCount = currDelivery->DeliveryCount;
		newNode->DeliveryQueueItemCost = currDelivery->DeliveryQueueItemCost;
		newNode->NextDelivery = nullptr;
		if(deliveryList == nullptr) {
			deliveryList = newNode;
			deliveryListRear = newNode;
		} else {
			deliveryListRear->NextDelivery = newNode;
			deliveryListRear = newNode;
		}
		deliveryListRear->NextDelivery = nullptr;
		currDelivery = currDelivery->NextDelivery;
	}

	currDelivery = deliveryList;

	int ordersDelivered = 0;
	int deliveriesUsed = 0;

	while(ordersDelivered != OrderQueueSize && deliveriesUsed != deliveryQueueSize) {
		int toShip = OrderListCopy[ordersDelivered].OrderCount;
		int canShip = currDelivery->DeliveryCount;
	
		if(canShip >= toShip) {
			double cost = currDelivery->DeliveryQueueItemCost*toShip;
			costToWarehouse += cost;
			costToCustomers += cost*(1+OrderListCopy[ordersDelivered].Markup);
			currDelivery->DeliveryCount -= OrderListCopy[ordersDelivered].OrderCount;
			ordersDelivered++;
			if(ordersDelivered == OrderQueueSize)
				break;
		}

		if(canShip < toShip) {
			double cost = currDelivery->DeliveryQueueItemCost*canShip;
			costToWarehouse += cost;
			costToCustomers += cost*(1+OrderListCopy[ordersDelivered].Markup);
			OrderListCopy[ordersDelivered].OrderCount -= currDelivery->DeliveryCount;
			deliveriesUsed++;
			if(deliveriesUsed == deliveryQueueSize)
				break;
			currDelivery = currDelivery->NextDelivery;
		}
	}
  totalProfit =costToCustomers-costToWarehouse;
	cout<<"\n************** SUMMARY ************\n";
	cout<<"\nTotal Orders: "<<OrderQueueSize;
	cout<<"\nTotal cost to warehouse of all "<<OrderQueueSize<<" orders: "<<costToWarehouse;
	cout<<"\nTotal cost to customers of all "<<OrderQueueSize<<" orders: "<<costToCustomers;
  cout<<"\nTotal profit of all "<<OrderQueueSize<<" orders: "<<totalProfit;
	cout<<"\n\n";
}
