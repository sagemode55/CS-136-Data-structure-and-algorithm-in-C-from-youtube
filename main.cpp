//
//  main.cpp
//  Sample Sorting Function
//
//  Created by Sitthiphol Yuwanaboon on 12/20/20.
//
#include <iostream>
#include <ncurses.h>
using namespace std;


class stack{
private:
    
    int top;
    int arr[5];

public:
    
    stack(){
        top=-1;
        for(int i= 0; i<5;i++){
            arr[i]=0;
        }
    }
        bool isEmpty(){
            if(top==-1)
                return true;
            else
                return false;
        }

    bool isFull(){
        if(top==4)
            return true;
        else
            return false;
    }
    void push(int val){

        if(isFull()){
            cout << "Stack OVerFlow" << endl;
        }
        else{
            top++;
            arr[top]= val;

        }
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack underFlow" << endl;
            return 0;
            }
        else{
            int popValue =arr[top];
            arr[top]=0;
            top=-1;
            return popValue;
        }
    }
    int count(){


        return(top+1);

    }
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout << "Stack underFlow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos]=val;
        cout <<"value changed at location " << pos << endl;
    }
    void display()
    {
        cout << "All values in the stack are " << endl;

        for (int i =4; i>=0;i--)
        {
            cout << arr[i]<<endl;
        }
    }
};

int main(){


    stack s1;
    int option, position,value;


    do{
        
        cout <<"what operation do you want to perform? Select Option number Enter 0 to Exit" << endl;
        cout<<"1 push "<< endl;
        cout<<"2 pop "<< endl;
        cout<<"3 isEmpty "<< endl;
        cout<<"4 isFull "<< endl;
        cout<<"5 Peek "<< endl;
        cout<<"6 count "<< endl;
        cout<<"7 Change "<< endl;
        cout<<"8 display "<< endl;
        cout<<"9 clear Screen "<<endl <<endl;
        cin >>option;
        
        switch (option) {
            case 0:
                break;

            case 1:
                cout<<"enter an item value to push in the stack"<< endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                
                cout<<"Pop function called Popped Value"<< s1.pop()<<endl;
                break;
            case 3:
               
                if (s1.isEmpty()) {
                    cout<< "Stack is Empty "<< endl;

                }
                else
                    cout <<"Stack is not Empty "<< endl;
                break;
                
            case 4:
                if (s1.isFull()) {
                    cout<< "Stack is Full "<< endl;

                }
                else
                    cout <<"Stack is not full "<< endl;
                break;
                
            case 5:
                cout<<"Enter postion of item you want to peek:  "<< endl;
                cin >> position;
                cout<<"Peek function called "<<position<<" is "<<s1.peek(position)<< endl;

                break;
                
            case 6:
                cout<<"count Function called - number of item in the stack are: "<< s1.count()<<endl;
                break;
                
            case 7:
                cout<<"Chage function called"<<endl;
                cout <<"Enter position of item you want to change : ";
                cin>>position;
                cout << endl;
                cout <<"Enter value that you want to change: ";
                cin >> value;
                s1.change(position, value);
                break;
            case 8:
                cout<<"display function called "<<endl;
                s1.display();
                
                break;
            case 9:
                system("clear");
                
                break;
                
            default:
                cout <<"Enter proper option number: "<< endl;

        }
    }
    while(option!=0);



    return 0;


}































//void merge(int arr[],int l, int m, int r){
//    int i= l;
//    int j= m+1;
//    int k =l;
//    int size = (r-l)+1;
//    int temp[size];
//
//
//    while (i<=m&& j<=r){
//        if (arr[i]<= arr[j]){
//            temp[k] = arr[i];
//            i++;
//            k++;
//        }
//        else{
//            temp[k] = arr[j];
//            j++;
//            k++;
//        }
//    }
//    while(i<=m){
//        temp[k] = arr[i];
//        i++;
//        k++;
//    }
//    while(j<=r){
//        temp[k] = arr[j];
//        j++;
//        k++;
//    }
//    for (int s= l;s<r;s++){
//        arr[s]= temp[s];
//    }
//}
//
//
//
//
//
//void mergesort(int arr[],int l, int r){
//    if (l<r){
//        int m = (l+r)/2;
//        mergesort (arr,l,m);
//        mergesort (arr,m+1,r);
//        merge (arr,l,m,r);
//    }
//}
//
//
//
//
//int main() {
//
//    int size;
//    cout << "enter size of array: " << endl;
//    cin >> size;
//
//    cout << "Size of element is " << size << endl;
//
//    int myarr[size];
//    cout << "enter element of array: " << endl;
//    for (int  i =0; i< size-1; i++){
//        cin >> myarr[i];
//
//    }
//
//    cout << endl;
//
//    // before sourcing
//    for (int  i =0; i<size-1; i++){
//        cout  << myarr[i] <<" ";
//
//    }
//    cout << endl;
//
//    cout << "after sourcing " << endl;
//
//    mergesort(myarr,0,size-1);
//    // after sourcing
//    for (int  i =0; i<size; i++){
//        cout << myarr[i] << " ";
//
//    }
//    cout << endl << endl;
//
//    return 0;
//}
