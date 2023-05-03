/***********************************************************************
 * File: fraction.h
 * Author: Not me
 * Create Date: unknown
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/23
 * Description: the header file that include the class we are going to use
***********************************************************************/
#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include <iomanip>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	void setNumerator(int nu);
	void setDenominator(int de);
	void getDouble();
	void outputReducedFraction();

};

#endif //Fraction_H