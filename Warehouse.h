//Yuwanaboon, Sitthiphol:
//Lab 9


/****Intructor feedback DO NOT DELETE:

****/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum menuOptions
{
    Delivery = 1,
    DeliveryQueue = 2,
    Order = 3,
    OrderQueue = 4,
    TotalOrderThatDay=5,
    Quit = 6
};

class Warehouse
{
public:
	Warehouse();
	~Warehouse();

	bool isOrderQueueEmpty();
	bool isDeliveryQueueEmpty();

	bool isOrderQueueFull();
	bool isDeliveryQueueFull();

	void EnqueueOrder(int Count, int OrderStatus);
	void EnqueueDelivery(int Count, double Cost);

	void PrintOrderQueue();
	void PrintDeliveryQueue();

	void DequeueOrder();
	void DequeueDelivery();

	void ProcessOrder();

	int CountShipmentFromBatch();

	void ClearTotalData();
	void PrintTotalData();
  void PrintTableData();
	int PeekOrderNumber();
	int PeekOrderCount();
	int PeekOrderPriority();
	double PeekMarkup();

	int PeekDeliveryNumber();
	int PeekDeliveryCount();
	double PeekDeliveryCost();

	void MakeOrderQueueEmpty();
	void MakeDeliveryQueueEmpty();

	string RushStatus(int);

	enum StatusType { Extreme, Expedite, Standard };

	int OrderSize();

	int InventorySize();

	// filler helper functions
	inline int getLeftChildIndex(int parentIndex) {return 2 * parentIndex + 1;}
	inline int getRightChildIndex(int parentIndex) {return 2 * parentIndex + 2;}
	inline int getParentIndex(int childIndex) { return (childIndex - 1);}

	inline bool hasLeftChild(int index) {return getLeftChildIndex(index) < OrderQueueSize;}
	inline bool hasRightChild(int index) {return getRightChildIndex(index) < OrderQueueSize;}
	inline bool hasParent(int index) {return getParentIndex(index) >= 0;}

	inline int leftChild(int index) {return OrderList[getLeftChildIndex(index)].Priority;}
	inline int rightChild(int index) {return OrderList[getRightChildIndex(index)].Priority;}
	inline int parent(int index) {return OrderList[getParentIndex(index)].Priority;}

	void swap(int indexOne, int indexTwo);


	void heapifyUp();

	void heapifyDown();
  void summary();

private:
	int WidgetsShipped;
	int WidgetsInStock;
	int OrdersInQueue;
  int BatchItemsShipped;
	int OrderNumber;
	int DeliveryNumber;

	int TotalOrdersProcessed;
	double TotalWarehouseCost;
	const double ExtremeCost = 1.0, ExpediteCost = .40, StandardCost = .20;

	int OrderQueueSize;
	const int MaxOrderSize = 100;

	struct OrderQueueType
	{
		int OrderQueueItemNumber;
		int OrderCount;
		int Priority;
		double Markup;
	};

	struct OrderQueueType OrderList[100];

	// Delivery Queue struct
	typedef struct DeliveryQueueNodeType
	{
		int DeliveryQueueItemNumber;
		int DeliveryCount;
		double DeliveryQueueItemCost;
		DeliveryQueueNodeType* NextDelivery;	// each delivery node has an itemnumber, delivery count and delivery price
	} *DeliveryQueueNodeTypePointer;
	DeliveryQueueNodeTypePointer FrontDelivery;
	DeliveryQueueNodeTypePointer RearDelivery;
	DeliveryQueueNodeTypePointer TempDelivery;
};
