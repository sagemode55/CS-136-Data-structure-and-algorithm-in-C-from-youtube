//Yuwanaboon, Sitthiphol:
//Lab 6


/****Intructor feedback DO NOT DELETE:

****/
#include <iostream>
#include <exception>
#include<iomanip>
#include<array>

using namespace std;

enum menuOptions
{
    Order = 1,
    Delivery = 2,
    OutstandingOrders = 3,
    StockInHand = 4,
    Quit = 5
};

class Widgets
{
private:
    double costPrice;
    double salePrice;
    double makeup=2.0;


public:
  
   Widgets();
   ~Widgets();
   double getCostPrice();
   void setCostPrice(double tempPrice);
   double getSalePrice();
};
// Constructor initializes class members to default value
    // Pre: Object is created
    // Post: Class members are initialized to default values
    Widgets::Widgets()
    {
        costPrice = 0.0;
        salePrice = 0.0;
    }
    Widgets:: ~Widgets()
    {
        costPrice = 0.0;
        salePrice = 0.0;
    }

    //Function that return the cost price of a widget
    //Pre: None
    //Post: value of costPrice property of an object of Widget class is returned
    double Widgets::getCostPrice()
    {
        return costPrice;
    }

    //Function that stores the value of costPrice and salePrice of a Widget
    //Pre: User enters the valid costPrice of a Widget
    //Post: value of costPrice and salePrice properties of Widget object is assigned
    void Widgets::setCostPrice(double tempPrice)
    {
        costPrice = tempPrice;
        salePrice = tempPrice *makeup;
    }

    //Function that return the sale price of a widget
    //Pre: None
    //Post: sale price of the widget is returned
    double Widgets::getSalePrice()
    {
        return salePrice;
    }


class Inventory
{
private:
    Widgets product;
    int number;
    int quantity;

public:
Inventory();
~Inventory();
int getQuantity();
void addQuantity(int tempQuantity);
void deductQuantity(int tempQuantity);
void addPrice(int tempPrice);
double getCost();
double getSalePrice();
int getNumber();
void setNumber(int tNumber);
};

    // Constructor initializes class members to default value
    // Pre: Object is created
    // Post: Class members are initialized to default values
    Inventory::Inventory()
    {
        product.setCostPrice(0.0);
        number = 0;
        quantity = 0;
    }
    Inventory::~Inventory()
    {
        product.setCostPrice(0.0);
        number = 0;
        quantity = 0;
    }

    //Function that returns the total quantity of widgets received in a delivery
    //Pre: None
    //Post: Valid Quantity of widgets delivered in one a delivery is returned
    int Inventory:: getQuantity()
    {
        return quantity;
    }

    //Function that adds the quantity of widgets to be delivered
    //Pre: Valid quantity of widgets to be added to the current delivery
    //Post: Adds the total widgets delivered to the quantity. The initial value of
    //quantity if 0.
    void Inventory::addQuantity(int tempQuantity)
    {
        quantity += tempQuantity;
    }

    //Function that deducts the quantity of widgets sold in a particular order
    //Pre: Valid quantity of widgets that are sold
    //Post: Deduct the quantity of widgets to be sold in the order from the total widgets
    //available with a particular delivery stack
    void Inventory::deductQuantity(int tempQuantity)
    {
        quantity -= tempQuantity;
    }

    //Function that adds the cost price of widget per unit in a delivery stack
    //Pre: Valid unit price of the widget
    //Post: cost price of the widget stored in costPrice property of Widget object instance
    //using the inbuilt setCostPrice method
    void Inventory::addPrice(int tempPrice)
    {
        product.setCostPrice(tempPrice);
    }

    //Function that returns the unit price of the widget in a particular delivery
    //Pre: None
    //Post: return a valid unit price
    double Inventory::getCost()
    {
        return product.getCostPrice();
    }

    //Function that returns the per unit sale price of a widget of a particular delivery
    //Pre: None
    //Post: returns a valid sale price per unit
    double Inventory::getSalePrice()
    {
        return product.getSalePrice();
    }

    //Function that returns the delivery number of a delivery stack
    //Pre: None
    //Post: returns a valid delivery number
    int Inventory::getNumber()
    {
        return number;
    }

    //Function that sets the delivery number of a delivery stack
    //Pre: valid unique delivery number entered by the user
    //Post: store the delivery number in the property
    void Inventory::setNumber(int tNumber)
    {
        number = tNumber;
    }


class myOrder
{
private:

    char orderType;
    int number;
    int purchaseQuantity;
    int deliveredQuantity;

public:
    myOrder();
    ~myOrder();
    char getOrderStatus();   
    void setOrderStatus(char tempStatus); 
    int getPurchaseQuantity();
    void addPurchaseQuantity(int tempQuantity);
    int getDeliveredQuantity();
    void addDeliveredQuantity(int tempQuantity);
    int getNumber();
    void setNumber(int tNumber);
};
// Constructor initializes class members to default value
    // Pre: Object is created
    // Post: Class members are initialized to default values
    myOrder::myOrder()
    {
        orderType = 'B';
        number = 0;
        purchaseQuantity = 0.0;
        deliveredQuantity = 0.0;
    }
    myOrder::~myOrder()
    {
        orderType = 'B';
        number = 0;
        purchaseQuantity = 0.0;
        deliveredQuantity = 0.0;
    }
    //Function to get the order status/type for a particular shipment
    //Pre: None
    //Post: Returns whether an order is backorder, partial, or complete
    char  myOrder::getOrderStatus()
    {
        return orderType;
    }

    //Function that sets the order status/type for a particular order
    //Pre: valid character that represents the order status [C,P,B], entered by the user
    //Post: stores the order status/type in the property of the order
    void  myOrder::setOrderStatus(char tempStatus)
    {
        orderType = tempStatus;
    }

    //Function that returns the total quantity purchased in a particular order
    //Pre: None
    //Post: returns the valid whole number of an order quantity
    int  myOrder::getPurchaseQuantity()
    {
        return purchaseQuantity;
    }

    //Function that adds the purchase quantity to an order
    //Pre: valid order quantity of an order
    //Post: adds the purchase quantity to the initial quantity i.e. 0.
    void  myOrder::addPurchaseQuantity(int tempQuantity)
    {
        purchaseQuantity += tempQuantity;
    }

    //Function that returns the quantity delivered till the time for a particular order
    //Pre: None
    //Post: returns the valid quantity delivered till the time.
    int  myOrder::getDeliveredQuantity()
    {
        return deliveredQuantity;
    }

    //Function that adds the quantity delivered for an order
    //Pre: valid quantity entered by the user
    //Post: adds the quantity entered by the user to the previous delivered quantity
    void  myOrder::addDeliveredQuantity(int tempQuantity)
    {
        deliveredQuantity += tempQuantity;
    }

    //Function that returns the number for a particular order
    //Pre: None
    //Post: returns the valid order number.
    int  myOrder::getNumber()
    {
        return number;
    }

    //Function that stores the order number
    //Pre: valid unique order number entered by the user
    //Post: adds the number entered by the user to the order
    void  myOrder::setNumber(int tNumber)
    {
        number = tNumber;
    }


class Warehouse
{
private:
    Inventory* deliveryRegister;
    int deliveryCount;
    int orderCount;
    int dIndex;
    int oIndex;
    // double makeup =3.0;
    // int itemCount;
    // double itemCost;
    myOrder* orderRegister;

public:

 Warehouse();
 ~Warehouse();
 void setDelivery(double costPrice, int quantity);
//  void getDelivery();
 bool isDeliveryStackFull();
 void getStockInHand();
 void setOrder(char Status, int quantity);
 bool isOrderStackFull();
 void getOrder();
 void getPendingOrders();
 void processOrder();

};
 // Constructor initializes class members to default value
    // Pre: Object is created
    // Post: Class members are initialized to default values
    Warehouse::Warehouse()
    {
        deliveryRegister = new Inventory[20];
        orderRegister = new myOrder[20];
        deliveryCount = 0;
        orderCount = 0;
        dIndex = -1;
        oIndex = -1;
        // makeup =2;
        // itemCount = 0;
        // itemCost = 0.0;
    }
    Warehouse::~Warehouse()
    {
        deliveryRegister = new Inventory[20];
        orderRegister = new myOrder[20];
        deliveryCount = 0;
        orderCount = 0;
        dIndex = -1;
        oIndex = -1;
        // makeup=2;
        // itemCount = 0;
        // itemCost = 0.0;
    }

    //Function that stores the delivery details received from the user in the delivery stack
    //Pre: valid delivery cost price per unit and quantity entered by the user
    //Post: stores the cost price, quantity, delivery number in the delivery stack. Increases
    //the index of array and the delivery number by 1. Also, display the changes committed.
    void   Warehouse::setDelivery(double costPrice, int quantity)
    {
        Widgets W;
        W.setCostPrice(costPrice);
        if (dIndex < 0)
        {
            dIndex = 0;
        }

        if (!isDeliveryStackFull())
        {
            deliveryCount++;
            deliveryRegister[dIndex].addQuantity(quantity);
            deliveryRegister[dIndex].addPrice(costPrice);
            deliveryRegister[dIndex].setNumber(deliveryCount);
            dIndex++;

            cout << endl << "Delivery #" << deliveryCount << " of " << quantity << " widgets, has been added to the delivery list" << endl
                << setw(30) << left << "Cost to warehouse: " << setw(30) << costPrice << endl
                << setw(30) << left << "To be sold for: " << setw(30) << W.getSalePrice()<< endl << endl;

        }
        else
        {
            cout << "Delivery list is full. Unable to take any deliveries." << endl << endl;
        }

    }

    //Function that input the delivery details including total widgets and per unit price 
    //from the user
    //Pre: None
    //Post: Total widget quantity and unit price in a particular delivery is passed to setDelivery
    //function to store the details in the stack
    // void   Warehouse::getDelivery()
    // {
    //     cout << endl << "What is the delivery count: ";
    //     cin >> itemCount;

    //    while (cin.fail() || itemCount <= 0)
	  //   {
		//         cin.clear();
		//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         cout << "Enter a positive whole number..." << endl
    //             << "What is the delivery count: ";
    //         cin >> itemCount;
    //     }

    //     cout << "What was the delivery cost to the warehouse: $";

    //     cin >> itemCost;

    //     while (cin.fail() || itemCost <= 0)
    //     {
    //         cin.clear();
		//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         cout << "Enter a positive whole number..." << endl
    //             << "What was the delivery cost: $";
    //         cin >> itemCost;
    //     }

    //     setDelivery(itemCost, itemCount);
    // }

    //Function that checks whether the delivery stack is full or not
    //Pre: None
    //Post: returns a boolean value. If stack is full, value is true and vice versa
    bool Warehouse::isDeliveryStackFull()
    {
        if (dIndex >= 19)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Function that displays the current stock of deliveries available
    //Pre: None
    //Post: Prints the stock table for the user
    void Warehouse::getStockInHand()
    {
        if (dIndex<=0){
          cout << endl <<"There is no pending stock on our hand."<< endl << endl;
        }
        
        else{
            cout << endl << setw(40) << right<< "Stock In Hand" << endl;
            cout << setw(15) << left << "Delivery #" << setw(15) << left << "Quantity" << setw(15) <<
                left << "Unit Price" << setw(20) << left << "Cost to Warehouse" << setw(20) << left << "Cost to Customer" << endl;

              for (int tCount = dIndex; tCount > 0; tCount--)
              {
                  cout << setw(15) << left << deliveryRegister[tCount - 1].getNumber() <<
                      setw(15) << left << deliveryRegister[tCount - 1].getQuantity() << setw(15) <<
                      left << deliveryRegister[tCount - 1].getCost() << setw(20) << left << deliveryRegister[tCount - 1].getCost() * deliveryRegister[tCount - 1].getQuantity() << setw(20) << left << deliveryRegister[tCount - 1].getSalePrice() * deliveryRegister[tCount - 1].getQuantity() << endl;
              }
              cout << endl;
          }
        
        // cout << endl << setw(40) << right<< "Stock In Hand" << endl;
        // cout << setw(15) << left << "Delivery #" << setw(15) << left << "Quantity" << setw(15) <<
        //     left << "Unit Price" << setw(20) << left << "Cost to Warehouse" << setw(20) << left << "Cost to Customer" << endl;

        // for (int tCount = dIndex; tCount > 0; tCount--)
        // {
        //     cout << setw(15) << left << deliveryRegister[tCount - 1].getNumber() <<
        //         setw(15) << left << deliveryRegister[tCount - 1].getQuantity() << setw(15) <<
        //         left << deliveryRegister[tCount - 1].getCost() << setw(20) << left << deliveryRegister[tCount - 1].getCost() * deliveryRegister[tCount - 1].getQuantity() << setw(20) << left << deliveryRegister[tCount - 1].getSalePrice() * deliveryRegister[tCount - 1].getQuantity() << endl;
        // }
        // cout << endl;
    }

    //Function that stores the order details received from the user in the order stack
    //Pre: valid order status and quantity entered by the user
    //Post: stores the status, quantity, order number in the order stack. Increases
    //the index of array and the order number by 1. Also, display the changes committed.
    void   Warehouse::setOrder(char Status, int quantity)
    {

        if (!isOrderStackFull())
        {

            if (oIndex < 0)
            {
                oIndex = 0;
            }
            orderCount++;
            orderRegister[oIndex].setOrderStatus(Status);
            orderRegister[oIndex].addPurchaseQuantity(quantity);
            orderRegister[oIndex].setNumber(orderCount);
            oIndex++;

            cout << endl << "Order #" << orderCount << " of " << quantity << " widgets, has been added to the order list" << endl << endl;

        }
        else
        {
            cout << "Order list is full. Unable to take any orders." << endl << endl;
        }

    }

    //Function that checks whether the order stack is full or not [Max 20 orders can be pending
    // at a time]
    //Pre: None
    //Post: returns a boolean value. If stack is full, value is true and vice versa
    bool   Warehouse::isOrderStackFull()
    {
        if (oIndex >= 19)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Function that input the order details i.e. total widgets from the user
    //Pre: None
    //Post: Total widget quantity is passed to setOrder function to store the details in the stack
    // void Warehouse::getOrder()
    // {
    //     cout << endl << "How many widgets would you like to order: ";
    //     cin >> itemCount;

    //     while (cin.fail() || itemCount <= 0)
	  //     {
		//         cin.clear();
		//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         cout << "Enter a positive whole number..." << endl
    //             << "How many widgets would you like to order: ";
    //         cin >> itemCount;
    //     }

    //     setOrder('B', itemCount);
    // }

    //Function that returns the table of pending orders
    //Pre: None
    //Post: Table with details of the partial and backorders in the order stack
    void Warehouse::getPendingOrders()
    {
        
        if(oIndex<=0) {
          cout << endl <<"there is zero pending order in the Inventory" << endl << endl; 
        }
        else {
          cout << endl << setw(20) << "Pending Order List" << endl;

            for (int tCount = oIndex; tCount > 0; tCount--)
            {
                if (orderRegister[tCount].getOrderStatus() != 'C')
                {
                    cout << setw(30) << left << "Order number" << orderRegister[tCount - 1].getNumber() << endl
                      << setw(30) << left << "Quantity Ordered" << orderRegister[tCount - 1].getPurchaseQuantity() << endl
                      << setw(30) << left << "Quantity Shipped" << orderRegister[tCount - 1].getDeliveredQuantity() << endl
                      << setw(30) << left << "Quantity Remaining" << orderRegister[tCount - 1].getPurchaseQuantity() - orderRegister[tCount - 1].getDeliveredQuantity() << endl
                      << setw(30) << left << "Status[P:Partial|B:Backorder]" << orderRegister[tCount - 1].getOrderStatus() << endl << endl;
                }
            }

        }
        

    }


    //Function that processes an order. It fulfills the orders if the widget deliveries are
    //available or received
    //Pre: None
    //Post: Fulfillment of orders partially or completely. Atleast one order will be processed
    void Warehouse::processOrder()
    {
        if (dIndex <= 0 || oIndex <= 0)
        {
            cout << "Sorry, no order can be delivered right now!" << endl << endl;
        }
        else
        {
            int pendingStock = deliveryRegister[dIndex - 1].getQuantity();
            int pendingDelivery = (orderRegister[oIndex - 1].getPurchaseQuantity() - orderRegister[oIndex - 1].getDeliveredQuantity());

            if (pendingStock > pendingDelivery)
            {
                cout << endl << "Details for the new order processed: " << endl
                    << setw(35) << left << "Order Number " << orderRegister[oIndex - 1].getNumber() << endl
                    << setw(35) << left << "Widgets Ordered " << orderRegister[oIndex - 1].getPurchaseQuantity() << endl
                    << setw(35) << left << "Widgets Previously Delivered " << orderRegister[oIndex - 1].getDeliveredQuantity() << endl
                    << setw(35) << left << "Current Shipment Size" << pendingDelivery << endl;
                    orderRegister[oIndex - 1].addDeliveredQuantity(pendingDelivery);
                cout << setw(35) << left << "Backorder Quantity" << orderRegister[oIndex - 1].getPurchaseQuantity() - orderRegister[oIndex - 1].getDeliveredQuantity() << endl
                    << setw(35) << left << "Per Unit Cost" << deliveryRegister[dIndex - 1].getCost() << endl
                    << setw(35) << left << "Shipment Cost(Warehouse)" << deliveryRegister[dIndex - 1].getCost() * pendingDelivery << endl
                    << setw(35) << left << "Shipment Cost(Customer)" << deliveryRegister[dIndex - 1].getSalePrice() * pendingDelivery << endl
                    << setw(35) << left << "Shipment Profit" << deliveryRegister[dIndex - 1].getCost() * pendingDelivery << endl << endl;
                    orderRegister[oIndex - 1].setOrderStatus('P');
                    deliveryRegister[dIndex - 1].addQuantity(-1 * pendingDelivery);

            }
            else
            {
                cout << endl << "Details for the new order processed: " << endl
                    << setw(35) << left << "Order Number " << orderRegister[oIndex - 1].getNumber() << endl
                    << setw(35) << left << "Widgets Ordered " << orderRegister[oIndex - 1].getPurchaseQuantity() << endl
                    << setw(35) << left << "Widgets Previously Delivered " << orderRegister[oIndex - 1].getDeliveredQuantity() << endl
                    << setw(35) << left << "Current Shipment Size" << pendingStock << endl;
                    orderRegister[oIndex - 1].addDeliveredQuantity(pendingStock);
                cout << setw(35) << left << "Backorder Quantity" << orderRegister[oIndex - 1].getPurchaseQuantity() - orderRegister[oIndex - 1]    .getDeliveredQuantity() << endl
                    << setw(35) << left << "Per Unit Cost" << deliveryRegister[dIndex - 1].getCost() << endl
                    << setw(35) << left << "Shipment Cost(Warehouse)" << deliveryRegister[dIndex - 1].getCost() * pendingStock << endl
                    << setw(35) << left << "Shipment Cost(Customer)" << deliveryRegister[dIndex - 1].getSalePrice() * pendingStock << endl
                    << setw(35) << left << "Shipment Profit" << deliveryRegister[dIndex - 1].getCost() * pendingStock << endl << endl;
                    orderRegister[oIndex - 1].setOrderStatus('P');
                    deliveryRegister[dIndex - 1].addQuantity(-1 * pendingStock);
            }

            if (deliveryRegister[dIndex - 1].getQuantity() <= 0)
            {
                dIndex--;
            }

            if ((orderRegister[oIndex - 1].getPurchaseQuantity() - orderRegister[oIndex - 1].getDeliveredQuantity()) <= 0)
            {
                oIndex--;
            }
            processOrder();
        }


    }
