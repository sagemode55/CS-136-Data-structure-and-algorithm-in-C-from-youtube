#include <iostream>
using namespace std;


void setInput(int &);
//void outPutDescendingSeries(double n);
double descendingSeries(double,double);
double ascendingSeries(double);

int main()
{
    int choice = 0;
    int n = 0;

    do
    {
        cout << "Menu options\n"
            << "1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).\n"
            << "2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).\n"
            << "3) Quit the program.\n"
            << "Enter a valid input: ";
        cin >> choice;

        switch (choice)
        {
        
        case 1: setInput(n);
            cout << descendingSeries(1,n) << "\n\n";
            break;
        case 2: setInput(n);
            cout  << ascendingSeries(n) << "\n\n";
            break;
        case 3: cout << "\nQuitting program...\n\n";
            break;
        default: cout << "Enter a number listed on the menu.\n\n";
            cin.clear();
            cin.ignore(128, '\n');
        }
    } while (choice !=3);
    system("pause");
    return 0;
}


// Function checks for user input passed by reference with one paramater/

void setInput(int &n)
{
    cout << "\nEnter a whole number >= 1 for n.\n"
         << "n: ";
    cin >> n;

    while (cin.fail() || n < 1)
    {
        cin.clear();
        cin.ignore(128, '\n');
        cout << "Invalid input, enter a whole number >= 1 for n.\n"
             << "n: ";
        cin >> n;
    }
}


double descendingSeries(double i,double n) // return function 
{
    double sum = 0.0;
    if (i == 1)
    {
      cout << "1" << " ";
        sum = 1 / (2*i-1) + descendingSeries(i+1,n);
        
    }
    
   else if (i <= n & i>=1)
    {
    cout <<"+ "<< 1 << "/(" << i-1 << "+"<< i <<")"<<" ";
        sum = 1 / (2*i-1) + descendingSeries(i+1,n);
        
      
    }
     if (i==n){
    cout << "= ";
      sum = 1 / (2*i-1) + descendingSeries(i+1,n);
      }
  return sum;
}
// position of the cout does affect how the output will be ascending or descending order but the sum will be the same.
// The value first as accumalative sum


double ascendingSeries(double n)
{
    double sum = 0.0;
    if (n > 1)
    {
        cout << 1 << "/(" << n << "+"<< n-1 <<")"<<" + ";
        sum = 1 /(2*n-1) + ascendingSeries(n - 1);
    }
    else if (n == 1)
    {
        cout << 1<< " = ";
        sum = 1 /(2*n-1) + ascendingSeries(n-1);
    }
    
    return sum;
}

// / clang++-7 -pthread -std=c++17 -o main main.cpp
//  ./main
// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for n.
// n: 1
// 1 = 1

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for n.
// n: 2
// 1 + 1/(1+2) = 1.33333

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for n.
// n: 10
// 1 + 1/(1+2) + 1/(2+3) + 1/(3+4) + 1/(4+5) + 1/(5+6) + 1/(6+7) + 1/(7+8) + 1/(8+9) + 1/(9+10) = 2.13326

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for n.
// n: 1
// 1 = 1

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 1

// Enter a whole number >= 1 for n.
// n: 20
// 1 + 1/(1+2) + 1/(2+3) + 1/(3+4) + 1/(4+5) + 1/(5+6) + 1/(6+7) + 1/(7+8) + 1/(8+9) + 1/(9+10) + 1/(10+11) + 1/(11+12) + 1/(12+13) + 1/(13+14) + 1/(14+15) + 1/(15+16) + 1/(16+17) + 1/(17+18) + 1/(18+19) + 1/(19+20) = 2.47967

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 2

// Enter a whole number >= 1 for n.
// n: 1
// 1 = 1

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 2

// Enter a whole number >= 1 for n.
// n: 2
// 1/(2+1) + 1 = 1.33333

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 2

// Enter a whole number >= 1 for n.
// n: 10
// 1/(10+9) + 1/(9+8) + 1/(8+7) + 1/(7+6) + 1/(6+5) + 1/(5+4) + 1/(4+3) + 1/(3+2) + 1/(2+1) + 1 = 2.13326

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 2

// Enter a whole number >= 1 for n.
// n: 20
// 1/(20+19) + 1/(19+18) + 1/(18+17) + 1/(17+16) + 1/(16+15) + 1/(15+14) + 1/(14+13) + 1/(13+12) + 1/(12+11) + 1/(11+10) + 1/(10+9) + 1/(9+8) + 1/(8+7) + 1/(7+6) + 1/(6+5) + 1/(5+4) + 1/(4+3) + 1/(3+2) + 1/(2+1) + 1 = 2.47967

// Menu options
// 1) Add all of the number(s) in the descending series (1 + 1/(1+2) + 1/(2+3) + ... + 1/((n-1)+n).
// 2) Add all of the number(s) in the ascending series (1/(n+(n-1)) + ... + 1/(2+1) + 1).
// 3) Quit the program.
// Enter a valid input: 
