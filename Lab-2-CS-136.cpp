#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
#define p(x) std::cout << "\n"<< x << std::endl; // For debugging, prints variable name & value

const int MAX_RECORDS = 100;

enum Choices{
  PRINT_ALL=1, 
  PRINT_ERROR=2, 
  PRINT_ALL_ASCENDING=3, 
  PRINT_ACTIVE=4,
  PRINT_DISCONTINUED=5,
  PRINT_RECALLED=6,
  SEARCH_ITEM=7, 
  CHANGE_STATUS=8, 
  PRINT_REPORT=9,
  QUIT=10
};
enum SORT_CHOICES{
  SORTED_BY_ID=1,
  SORTED_BY_NAME=2,
  SORTED_BY_QUANTITY=3, 
  SORTED_BY_PRICE=4 
};

enum status{
  All =0,
	Active = 1, // 1
	Discontinued =2, // 2
	Recall=3 // 3
};
const string strStatus[]= {"All", "Active","Discontinued","Recalled"};
class Record{
private:
	std::string id;
	std::string name;
	int quantity;
	double price;
	status curStatus;
public:
	Record(); // Default Constructor
	Record(std::string id, std::string name, int quantity, double price); // Multiple parameter constructor
	std::string RecordStr(); 
  string RecordStr(int);// Returns Record as string
	void SetRecord(std::string id, std::string name, int quantity, double price);
	void SetId(std::string id);  // Sets given value as Record's ID
	void SetName(std::string name); // Sets given value as Record' Name
	void SetQuantity(int quantity); // Set givn value as Record's Quantity
	void SetPrice(double price);   // Sets given value as Record's Price
	void SetStatus(int status);
	status GetStatus();
	double GetPrice(); // Returns Record's Price
	int GetQuantity(); // Returns Record's Quantity
	std::string GetId(); // Returns Record's ID
	std::string GetName();// Returns Record's Name

	//~Record(){ std::cout<<"\nDeleted: "+this->RecordStr(); }; // Destructor
};


void Menu(Record* recordBookPtr[], Record recordBook[], std::string fileName, int& curCount); // Displays Menu
void GetData(Record* recordBookPtr[], Record recordBook[], std::string fileName, int& curCount); // Grabs data from file and store to database
void WriteError(std::string input); // Writes to ErrorFile
bool IsValidRec(Record& curRecord); // Checks if Record is Valid
void DisplayArray(Record recordBook[], int count); // Display's Record's Array
void sortItems(Record* recordBookPtr[], SORT_CHOICES field, int n);
int SearchRecords(Record recordBook[], int count, std::string searchKey);
void printReport(Record recordBook[], const int count);
std::string CapitalizeStr(std::string lowerCase); // Capitalizes string
void PrintTitle();
void PrintType(status s, Record recordBook[], int& curCount, int n);
void PrintError(std::string fileName);
void PrintAssending(int value_for_assending, Record* recordBookPtr[], int& curCount);
void changeStatus(string word, Record recordBook[], int& curCount, Record* recordBookPtr[]);
void searchItem(string word, Record recordBook[], int& curCount);
void printAll(int& curCount, Record* recordBookPtr[]);
void printSort(Record *ptr[], int n);

//
/* MAIN PROGRAM HURRRR */
//
int main(){

	int recordCount = 0;
	string fileName = "data.txt";
	Record* recordBookPtr[MAX_RECORDS];
	Record recordBook[MAX_RECORDS];
  GetData(recordBookPtr, recordBook, fileName, recordCount);
	Menu(recordBookPtr,recordBook,fileName,recordCount);
  
	//DisplayArray(recordBook, recordCount);
	//int result = SearchRecords(recordBook, recordCount, "WAX");
	//p(recordBook[result].RecordStr());


	return 0;
}

void Menu(Record* recordBookPtr[], Record recordBook[], std::string fileName, int& curCount){
	/*
ï¿½ print all items in the inventory unsorted
ï¿½ print invalid records from an error file
ï¿½ you should allow a user to sort by any field: item ID, item name (one word), quantity on hand, or price.ï¿½
ï¿½ print report - Number of unique item + the total worth all inventory (Qty * price of everytype)
*/
//GetData(recordBookPtr, recordBook, fileName, curCount);

Choices opt; 
int selection=0;
while (selection!=10)
   {
	   std::cout << "\n";
	   std::cout << "***********************************************\n";
       std::cout << "1. Print all items(except errors) in inventory unsorted\n";
       std::cout << "2. Print invalid records\n";
       std::cout << "3. Print all items in the inventory sorted in ascending order\n";
       std::cout << "4. Print all active items\n";
       std::cout << "5. Print all discontinued items\n";
       std::cout << "6. Print all recalled items\n";
       std::cout << "7. Search for an item by ID or name\n";
       std::cout << "8. Change status\n";
       std::cout << "9. Print a report of TotalWorth and Quantity\n";
       std::cout << "10. Quit the program\n";
       
	   std::cin>>selection;
	   opt= Choices(selection);
       int intopt;
	   std::fstream file;
	   std::string word;
       int z = 0;
       switch (selection)
       {
       case PRINT_ALL:
            PrintTitle();
            PrintType(All, recordBook, curCount,1);
           break;
       case PRINT_ERROR:
            PrintError("errorFile.txt");
			break;

       case PRINT_ALL_ASCENDING:
           std::cout << "Select which field to sort by\n";
           std::cout << "1. Id 2. Name 3. Quantity 4. Price\n";
           std::cin >> intopt;
           PrintAssending(intopt, recordBookPtr, curCount);

           break;
       case PRINT_ACTIVE:
            PrintTitle();
            PrintType(Active, recordBook, curCount,2);
            break;
       case PRINT_DISCONTINUED:
            PrintTitle();
            PrintType(Discontinued, recordBook, curCount,2);
            break;
       case PRINT_RECALLED:
            PrintTitle();
            PrintType(Recall, recordBook, curCount,2);
            break;
       case SEARCH_ITEM:
			std::cout << "Enter name or ID of the product to search" << std::endl;
			std::cin >> word;
			searchItem(word, recordBook, curCount);
            break;
       case CHANGE_STATUS:
			std::cout << "Enter name or ID to search and change status" << std::endl;
			std::cin >> word;
			changeStatus(word, recordBook, curCount, recordBookPtr);

           break;
       case PRINT_REPORT:
           	printReport(recordBook, curCount);
           // print report on total quantities and totalworth and unique item in the inventory
           break;
       case QUIT:
       cout << "Quiting program\n";
           break; // quiting program
       default:
	   	   std::cout<<"Invalid Input\n";
           break;
       }

   }

//switch( selection ){

//}
}


// Impelement this to write error message along with Record 

// Writes to Error File
void WriteError(std::string errorStr){
	std::ofstream outFile;

	outFile.open("errorFile.txt", std::ios::out|std::ios::app);

	outFile<<errorStr;

	outFile.close();
}




// ** Get Data **
void GetData(Record* recordBookPtr[], Record recordBook[], std::string fileName, int& curCount){
	bool goodFile = false;


	std::ifstream inFile;
	std::ofstream outFile;

	inFile.open(fileName, std::ios::in);
	outFile.open("errorFile.txt", std::ios::out|std::ios::app);


	//std::cout<<"\n"+fileName;

	if( !inFile ){ // Tries to open file
		std::cout<<"\nError: Could Not Open Input File";
		exit(0);
	}
	if( inFile.peek()==EOF ){// Checking if file is empty
		std::cout<<"\nError: Input File is Empty";
		exit(0);
	}


	std::string id;
	std::string name;
	int quantity;
	double price;


	while( !inFile.eof()&&curCount<MAX_RECORDS ){
		inFile>>id>>name>>quantity>>price;

		Record curRecord = Record(id, name, quantity, price);
		// Build the record here then check for validation
		// We shouldn't test for a bad record without first building the record itself
		if( IsValidRec(curRecord) ){
			// Debugging here
			//std::cout<<"\nTo Array: "<<id<<" "<<name<<" "<<quantity<<" "<<price;

			recordBook[curCount] = curRecord; // Assigning Value to Dynamically Created object
			recordBookPtr[curCount] = &recordBook[curCount]; // Assign Address of object to pointer 
			curCount++;
		} else{
			// Debugging here
			std::cout<<"\nErrorFile: "<<id<<" "<<name<<" "<<quantity<<" "<<price;

			outFile<<id<<" "<<name<<" "<<quantity<<" "<<price<<"\n";
		}
	};

	if( (curCount+1)==MAX_RECORDS ){
		std::cout<<"\nProgram Storage Full. Using values grabbed. . . "<<std::endl;
	}

	outFile.close();
	inFile.close();
}



// Check Record for Validity, Writing to ErrorFile when not true
bool IsValidRec(Record& curRecord){
	bool valid = true;
	std::string errStr;

	if( curRecord.GetPrice()<=0.0 ){
		errStr += "Invalid Price - ID: "+curRecord.GetId()+"\n";
		valid = false;
	}

	if( curRecord.GetQuantity()<=0 ){
		errStr += "Invalid Quantity - ID: "+curRecord.GetId()+"\n";
		valid = false;
	}
  if( curRecord.GetId().length()!= 5 ){
			errStr += "Invalid length - ID: "+curRecord.GetId()+"\n";
			valid = false;
		}
  
  for( unsigned int pos = 0; pos<curRecord.GetId().length(); pos++ ){
    if(!isalnum(curRecord.GetId()[pos])){
			errStr += "Invalid character ID - ID: "+curRecord.GetId()+"\n";
			valid = false;
		}
  }
	for( unsigned int pos = 0; pos<curRecord.GetName().length(); pos++ ){
    if( !(curRecord.GetName()[pos]>='A'&&curRecord.GetName()[pos]<='Z') ){
			errStr += "Invalid Character In Name - ID: "+curRecord.GetId()+"\n";
			valid = false;
		}
	}

	if( !valid ){
		WriteError(errStr);
	}
	return valid;
}

// Record Methods

Record::Record(){ // Record Default Constructor
	this->id = "";
	this->name = "";
	this->quantity = 0;
	this->price = 0.0;
	this->curStatus = Active;
}

// Multiple Parameter Constructor
Record::Record(std::string newId, std::string newName, int newQuantity, double newPrice){
	this->SetRecord(newId, newName, newQuantity, newPrice);
	this->curStatus = Active;
}


// Pre: Object must exist first
// Pos: Display the record
string Record::RecordStr(int status){
  return (this->id+"\t"+this->name+"\t\t\t"+std::to_string(this->quantity)+"\t\t\t"+std::to_string(this->price)+"\t\t\t" +strStatus[status]);
}

std::string Record::RecordStr(){
	 return (this->id+"\t"+this->name+"\t\t\t"+std::to_string(this->quantity)+"\t\t\t"+std::to_string(this->price)+"\t\t\t" +strStatus[curStatus]);
  
  
}


// Pre: Object must exist first
// Pos: Retrieves the Quantity
int Record::GetQuantity(){
	return this->quantity;
}


// Pre: Object must exist first
// Pos: Retrieves the Price
double Record::GetPrice(){
	return this->price;
}


// Pre: Object must exist first
// Pos: Retrieves the Name
std::string Record::GetName(){
	return this->name;
}


// Pre: Object must exist first
// Pos: Retrieves the Name
std::string Record::GetId(){
	return this->id;
}
status Record::GetStatus(){
	return this->curStatus;
}

// Pre: Must have Valid inputs
// Pos: Set input values as Record
void Record::SetRecord(std::string id, std::string name, int quantity, double price){

	this->SetId(id);
	this->SetName(name);
	this->SetQuantity(quantity);
	this->SetPrice(price);
}

// Pre: Object Must be Allocated
// Pos: Sets input value as ID
void Record::SetId(std::string newId){
	int idLength = newId.length();
	std::string checkedStr = "";

	for( int pos = 0; pos<idLength; pos++ ){
		if( (newId[pos]>='A'&&newId[pos]<='Z')||(newId[pos]>='a'&&newId[pos]<='z')||(newId[pos]>='0'&&newId[pos]<='9') ){
			checkedStr += newId[pos];
		} else{
			checkedStr += newId[pos];
		}
	}
	this->id = checkedStr;
}


// Pre: Object Must be Allocated
// Pos: Sets input value as Name
void Record::SetName(std::string name){
	std::string checkedName = "";
	int nameLength = name.length();

	for( int pos = 0; pos<nameLength; pos++ ){
		if( (name[pos]>='A'&&name[pos]<='Z')||name[pos]==' ' ){
			checkedName += name[pos];
		} else if( name[pos]>='a'&&name[pos]<='z' ){
			checkedName += (name[pos]-32);
		} else{
			checkedName += name[pos];
		}
	}
	this->name = checkedName;
}


// Pre: Object Must be Allocated
// Pos: Sets input value as Quantity
void Record::SetQuantity(int newQuantity){
	this->quantity = newQuantity;
}


// Pre: Object Must be Allocated
// Pos: Sets input value as Price
void Record::SetPrice(double newPrice){
	this->price = newPrice;
}
void Record::SetStatus(int status1){
	if(status1 == 1){
		this->curStatus = Active ;}
	else if (status1 == 2){
		this->curStatus = Discontinued ;
	}
	else{
		this->curStatus = Recall ;
	}
}


// Function to display all Records in RecordArray
void DisplayArray(Record recordBook[], int count){
	std::cout<<"\nOutside Loop: ";
	for( int i = 0; i<count; i++ ){
		std::cout<<"\nHere: "<<count<<recordBook[i].RecordStr();
	}
}

int SearchRecords(Record recordBook[], int count, std::string searchKey){

	for( int pos = 0; pos<count; pos++ ){
		if( recordBook[pos].GetName()==searchKey||recordBook[pos].GetId()==searchKey)
			return pos;
	}
	return MAX_RECORDS+1;
}


// Prints a report of Total of unique item and total worth of all invetory
void printReport(Record recordBook[], const int count){
	double totalValue = 0.0;
  double totalQuantities = 0.0;

	for( int i = 0; i<count; i++ ){
    totalQuantities +=(recordBook[i].GetQuantity());
		totalValue += (recordBook[i].GetQuantity()*recordBook[i].GetPrice());
    }
    std::cout<<"Report:\nTotal Number of items: "<<setw(5)<<count<<"\nTotal worth of Inventory: $"
	        <<std::setprecision(2)<<std::fixed<<setw(5)<<totalValue<<std::endl
          << "Total Quantities: " << setw(15)<< totalQuantities << endl;
};
void sortItems(Record *ptr[],  SORT_CHOICES field, int n) // sorting function using bubble sort then swap with if statement
{
	int i, j;
	Record *temp;
	bool toSwap = false;

   // Sort the numbers using pointers
    for (i = 0; i < n-1; i++) {

       for (j = 0; j < n-i-1; j++)
       { 
           switch (field)
           {
           case SORTED_BY_ID:
		   			//std::cout<<ptr[j]->GetId();
                   toSwap =(ptr[j]->GetId() > ptr[j+1]->GetId());
                   // sorting by identification or id
                break;
           case SORTED_BY_NAME:
                   toSwap =(ptr[j]->GetName() > ptr[j+1]->GetName()); // sorting by name
                break;
           case SORTED_BY_QUANTITY:
                   toSwap =(ptr[j]->GetQuantity() > ptr[j+1]->GetQuantity()); // sorting by quantity
                break;
           case SORTED_BY_PRICE:
                   toSwap =(ptr[j]->GetPrice() > ptr[j+1]->GetPrice()); // sorting by price
                break;
           }
           if (toSwap==true){
               temp=ptr[j];
               ptr[j]=ptr[j+1];
               ptr[j+1]=temp;
               toSwap=false;
           }
       }
   }
    
   //printSort(ptr, n);
    // since it is void function we can not use output operator, so we called ascending order of sorting menu.
}
void PrintTitle(){
  cout <<setw(1)<<"ID\t\t"<<"NAME\t\t"<<"QUANTITIES\t\t" <<"PRICE\t\t" <<"\t\tSTATUS"<< endl;
}

void PrintType(status s, Record recordBook[], int& curCount, int n){
    
   
   for (int i = 0; i < curCount; i++){
      if (n==1){
          p(recordBook[i].RecordStr(0));
   }
      else if(recordBook[i].GetStatus() == s){
          p(recordBook[i].RecordStr());
    }
   }
  //  switch(n){
  //    case 1: // printing all
  //         PrintTitle();
  //         for (int i = 0; i < curCount; i++){
  //             p(recordBook[i].RecordStr(0));
  //         }
  //    break;
  //    case 2: // printing status 
  //         for(int i = 0; i < curCount; i++){
  //             if(recordBook[i].GetStatus() == s){
  //                 p(recordBook[i].RecordStr());
  //             }
  //           }
  //    break;
  //  } 
    
}
void PrintError(std::string fileName){
  std::fstream file;
	std::string word;
	file.open(fileName, ios::in | ios::out);
      
	while (std::getline(file,word))
	{
		std::cout << word<<std::endl;
	}
	std::cout << std::endl;
	file.close();
}

void PrintAssending(int value_for_assending, Record* recordBookPtr[], int& curCount){
    SORT_CHOICES sorted_opt;
    sorted_opt= SORT_CHOICES(value_for_assending);

    if (value_for_assending < 1 || value_for_assending > 4)
    {
        std::cout << "Invalid input\n";
    }
    else
    {
        PrintTitle();
        sortItems(recordBookPtr, sorted_opt, curCount);
        printSort(recordBookPtr, curCount);
        //Implement by sort function
    }
}

void changeStatus(string word, Record recordBook[], int& curCount, Record* recordBookPtr[]){
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    int result;
    int z = 0;
    int intopt;
    while (z < curCount)
    {
        result = SearchRecords(recordBook, curCount, word);
        if (result != -1)
           break;
        z++;
    }

    if (result !=-1)
    {
       if(recordBook[result].GetStatus()==Active){
        
       std::cout << "Enter new status  2. Discontinued 3. Recalled 4. Exit/Main\n";
       std::cin >> intopt;
       if (intopt < 1 || intopt > 4)
       // setting the parameter to catch an error then break out of the case to the menu
       {
          std::cout << "Invalid input\n" ;
       }
       else if (intopt==4||intopt==1){
        cout << "GO->Back to Main\n";
         return;
       }
       else
       {
           recordBookPtr[result]->SetStatus(intopt);
          
       }
      }
      else if(recordBook[result].GetStatus()==Discontinued){
        
       std::cout << "Enter new status 1. Active 3. Recalled 4. Exit/Main\n";
       std::cin >> intopt;
       
       if (intopt < 1 || intopt > 4)
       // setting the parameter to catch an error then break out of the case to the menu
       {
          std::cout << "Invalid input\n" ;
       }
       else if (intopt==4||intopt==2){
        cout << "GO->Back to Main\n";
         return;
        }
       else
       {
           recordBookPtr[result]->SetStatus(intopt);
           
       }
      }
       else if(recordBook[result].GetStatus()==Recall){
        
       std::cout << "Enter new status 1. Active 2. Discontinued 3. Exit/Main\n";
       std::cin >> intopt;
       
       if (intopt < 1 || intopt > 3)
       // setting the parameter to catch an error then break out of the case to the menu
       {
          std::cout << "Invalid input\n" ;
       }
       else if (intopt==3){
        cout << "GO->Back to Main\n";
         return;
       }
       else
       {
           recordBookPtr[result]->SetStatus(intopt);
           
       }
      }
    }
  else{
      cout << "item can not be found in inventory\n";
    }
}

void searchItem(string word, Record recordBook[], int& curCount){
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	int result;
	int z = 0;
    while (z < curCount)
    {
        result = SearchRecords(recordBook, curCount, word);
        if (result != -1)
           break;
        z++;
    }
    if(result !=-1){
       p(recordBook[result].RecordStr());}
    else{
        std::cout << "Item was not found in the inventory " << std::endl;
	}
}

// void printAll(int& curCount, Record* recordBookPtr[]){
//     PrintTitle();
//     for (int i = 0; i < curCount; i++)
//     {
//         p(recordBookPtr[i]->RecordStr(0));
//     }
// }

void printSort(Record *ptr[], int n){
    // print the numbers
   for (int i = 0; i < n; i++)
       p(ptr[i]->RecordStr());
}

// ErrorFile: 570CCCC Keyboard 225 78.9522
// ErrorFile: 472DDD Chair 201 399.99
// ErrorFile: 031FFF Mouse 429 59.97
// ErrorFile: 717GG Desk! 250 150.8
// ErrorFile: 552HH Laptop! 211 50.32
// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 1
// ID      NAME        QUANTITIES      PRICE               STATUS

// 330AA   IPHONEX         650         13.550000           Active

// 526BB   TIPHONE         349         90.030000           Active

// 340II   CABLE           200         2.500000            Active

// 938JJ   TABLET          124         1100.090000         Active

// 300KK   MONITOR         105         750.100000          Active

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 2
// Invalid length - ID: 570CCCC
// Invalid length - ID: 472DDD
// Invalid length - ID: 031FFF
// Invalid Character In Name - ID: 717GG
// Invalid Character In Name - ID: 552HH
// 570CCCC Keyboard 225 78.9522
// 472DDD Chair 201 399.99
// 031FFF Mouse 429 59.97
// 717GG Desk! 250 150.8
// 552HH Laptop! 211 50.32
// Invalid length - ID: 570CCCC
// Invalid length - ID: 472DDD
// Invalid length - ID: 031FFF
// Invalid Character In Name - ID: 717GG
// Invalid Character In Name - ID: 552HH
// 570CCCC Keyboard 225 78.9522
// 472DDD Chair 201 399.99
// 031FFF Mouse 429 59.97
// 717GG Desk! 250 150.8
// 552HH Laptop! 211 50.32


// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 3
// Select which field to sort by
// 1. Id 2. Name 3. Quantity 4. Price
// 1
// ID      NAME        QUANTITIES      PRICE               STATUS

// 300KK   MONITOR         105         750.100000          Active

// 330AA   IPHONEX         650         13.550000           Active

// 340II   CABLE           200         2.500000            Active

// 526BB   TIPHONE         349         90.030000           Active

// 938JJ   TABLET          124         1100.090000         Active

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
//  clang++-7 -pthread -std=c++17 -o main main.cpp
//  ./main

// ErrorFile: 570CCCC Keyboard 225 78.9522
// ErrorFile: 472DDD Chair 201 399.99
// ErrorFile: 031FFF Mouse 429 59.97
// ErrorFile: 717GG Desk! 250 150.8
// ErrorFile: 552HH Laptop! 211 50.32
// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 3
// Select which field to sort by
// 1. Id 2. Name 3. Quantity 4. Price
// 1
// ID      NAME        QUANTITIES      PRICE               STATUS

// 300KK   MONITOR         105         750.100000          Active

// 330AA   IPHONEX         650         13.550000           Active

// 340II   CABLE           200         2.500000            Active

// 526BB   TIPHONE         349         90.030000           Active

// 938JJ   TABLET          124         1100.090000         Active

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 3
// Select which field to sort by
// 1. Id 2. Name 3. Quantity 4. Price
// 2
// ID      NAME        QUANTITIES      PRICE               STATUS

// 340II   CABLE           200         2.500000            Active

// 330AA   IPHONEX         650         13.550000           Active

// 300KK   MONITOR         105         750.100000          Active

// 938JJ   TABLET          124         1100.090000         Active

// 526BB   TIPHONE         349         90.030000           Active

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 3
// Select which field to sort by
// 1. Id 2. Name 3. Quantity 4. Price
// 3
// ID      NAME        QUANTITIES      PRICE               STATUS

// 300KK   MONITOR         105         750.100000          Active

// 938JJ   TABLET          124         1100.090000         Active

// 340II   CABLE           200         2.500000            Active

// 526BB   TIPHONE         349         90.030000           Active

// 330AA   IPHONEX         650         13.550000           Active

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 3
// Select which field to sort by
// 1. Id 2. Name 3. Quantity 4. Price
// 4
// ID      NAME        QUANTITIES      PRICE               STATUS

// 340II   CABLE           200         2.500000            Active

// 330AA   IPHONEX         650         13.550000           Active

// 526BB   TIPHONE         349         90.030000           Active

// 300KK   MONITOR         105         750.100000          Active

// 938JJ   TABLET          124         1100.090000         Active

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
// 9
// Report:
// Total Number of items:     5
// Total worth of Inventory: $255899.63
// Total Quantities:         1428.00

// ***********************************************
// 1. Print all items(except errors) in inventory unsorted
// 2. Print invalid records
// 3. Print all items in the inventory sorted in ascending order
// 4. Print all active items
// 5. Print all discontinued items
// 6. Print all recalled items
// 7. Search for an item by ID or name
// 8. Change status
// 9. Print a report of TotalWorth and Quantity
// 10. Quit the program
