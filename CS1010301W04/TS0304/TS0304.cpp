/***********************************************************************
 * File: TS0304.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/19
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/19
 * Description: Calculate the biggest integer that a CPU might process in the specific year
***********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int standardYear = 1900;
    int standardCpu = 4;
    int yearInput = 0;
    int yearGap = 0;
    int i = 2;
    long int cpuAmount = 0;
    double logMaxInt = 0;

    //use log2 to shorten the integer we are calculating
    while (cin >> yearInput)
    {
        //initialize the values
        i = 2;
        logMaxInt = log2(1);
        //find out the year gap with the standard Year 1900
        yearGap = (yearInput - standardYear) / 10;
        //get the amount of the CPU that year
        cpuAmount = standardCpu * pow(2, yearGap);

        while (logMaxInt <= cpuAmount)
        {
            logMaxInt = logMaxInt + log2(i); //logA + logB = logAB
            i++;
        }
        cout << i - 2 << endl;
    }
}



