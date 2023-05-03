/***********************************************************************
 * File: TS0403.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/23
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/23
 * Description: Greatest Common Divisor
***********************************************************************/
#include <iostream>
using namespace std;

int GCD(unsigned long long int a, unsigned long long int b);

int main()
{
    unsigned long long int a, b;
    //input two numbers
    while (cin >> a >> b)
    {
        //output
        cout << GCD(a, b) << endl;
    }
}

//use Euclidean algorithm
int GCD(unsigned long long int a, unsigned long long int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}