#include <iostream>
#include <iomanip>
#include <cmath>
#include "amount.h"
using namespace std;

int main()
{

    DollarAmount d1{12345};
    DollarAmount d2{1576};

    cout << "After adding d2 (" << d2.toString() << ") into d1 (" << d1.toString() << "), d1 = ";
    d1.add(d2);

    cout << d1.toString() << "\n";

    cout << "After subtracting d2 (" << d2.toString() << ") into d1 (" << d1.toString() << "), d1 = ";
    d1.subtract(d2);

    cout << "After subtracting d1 (" << d1.toString() << ") into d1 (" << d2.toString() << "), d1 = ";
    d1.subtract(d1);

    cout << "Enter integer interest rate and divisor. For example: \n"
         << "for     2%, enter       2  100\n"
         << "for   2.3%, enter      23  1000\n"
         << "for  2.37%, enter     237  10000\n"
         << "for 2.375%, enter    2375  100000\n";
    int rate;
    int divisor;
    cin >> rate >> divisor;
    DollarAmount balance{100000};
    cout << "\nInitial balance: " << balance.toString() << endl;

    // display headers
    cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

    // cout << fixed << setprecision(2);
    // double principal{1000.00};
    // double rate{0.05};
    // cout << "Initial principal: " << principal << endl;
    // cout << "        Interest rate: " << rate << endl;

    // cout << "\n Year" << setw(20) << "Amount on deposit" << endl;
    // for (unsigned int year{1}; year <= 10; year++)
    // {
    //     double amount = principal * pow(1.0 + rate, year);
    //     cout << setw(4) << year << setw(20) << amount << endl;
    // }
}