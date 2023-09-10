#include <iostream>
#include <iomanip>
#include "maximum.h"
using namespace std;
double getAvg(int total, int count);
unsigned long factorial(unsigned long);
unsigned long fibonacci(unsigned long);

unsigned long fib(unsigned long number)
{
    unsigned long temp, former = 1, i, latter = 1, current;
    for (i = 3; i <= number; ++i)
    {
        current = latter + former;
        former = latter;
        latter = current;
    }
    return current;
}
int main()
{
    // int total = 0, counter = 0, next = 0, size = 3;
    // while (counter < size)
    // {
    //     cout << "Enter a value: ";
    //     cin >> next;
    //     total += next;
    //     counter++;
    // };

    // cout << total << "count: " << counter << "size: " << size << endl;
    // double result = getAvg(total, size);

    // cout << "Average value is: " << result << endl;

    // cout << "Input three integers: ";
    // int int1, int2, int3;
    // cin >> int1 >> int2 >> int3;
    // cout << "The maximum value is: " << maximum(int1, int2, int3) << endl;

    // for (unsigned int counter{0}; counter <= 10; ++counter)
    // {
    //     cout << setw(2) << counter << "! = " << factorial(counter) << endl;
    // };

    for (unsigned int counter{0}; counter <= 10; ++counter)
    {
        cout << "fibonacci (" << counter << ")= " << fibonacci(counter) << endl;
    };

    // iterative fibonacci function

    // for (unsigned int counter{0}; counter <= 10; ++counter)
    // {
    //     cout << "fibonacci (" << counter << ")= " << fib(counter) << endl;
    // };
    cout << fib(10) << endl;
    // cout << "fib: " << fibonacci(4) << endl;
    return 0;
};

unsigned long fibonacci(unsigned long number)
{
    if ((0 == number) | (1 == number))
        return number;
    return fibonacci(number - 1) + fibonacci(number - 2);
};

// unsigned long factorial(unsigned long number)
// {
//     if (number <= 1)
//         return 1;
//     return number * factorial(number - 1);
// };
// double getAvg(int total, int count)
// {
//     return (double)total / count;
// };