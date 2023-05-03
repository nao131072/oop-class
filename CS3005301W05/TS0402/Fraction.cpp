/***********************************************************************
 * File: Fraction.cpp
 * Author: Not me
 * Create Date: unknown
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/23
 * Description: the class setting file of a kind of fraction calculting which should be easy enough to be done in only one file
***********************************************************************/
#include "Fraction.h"
#include <math.h>

void Fraction::setNumerator(int nu)
{
	//assign to the class variable
	Fraction::numerator = nu;
}

void Fraction::setDenominator(int de)
{
	//assign to the class variable
	Fraction::denominator = de;
}

void Fraction::getDouble()
{
	double result = 0;
	//calculate the prcision to be 6 after the point
	int logResult;
	//first get the result
	result = double(Fraction::numerator) / double(Fraction::denominator);
	//get the integer part
	int intResult = result;

	//to exclude the possibility of log(0)
	if (intResult == 0)
	{
		logResult = 0;
	}
	//get the whole length of the result
	else
	{
		logResult = log10(intResult) + 1;
	}
	
	//output with length
	cout << setprecision(logResult+6) << result << endl;
}

void Fraction::outputReducedFraction()
{
	//find the start point to calculate the max something something, im sure u know
	int max = numerator;
	//that something would be small one
	if (Fraction::numerator > Fraction::denominator)
	{
		max = Fraction::denominator;
	}
	
	for (int i = max; i > 0; i--)
	{
		//make sure both can be divide clearly
		if (Fraction::denominator % i == 0 && Fraction::numerator % i == 0)
		{
			Fraction::denominator /= i;
			Fraction::numerator /= i;
		}
	}
	//output but if the lower one is 1, not show
	if (Fraction::denominator == 1)
	{
		cout << Fraction::numerator << endl;
	}
	//normal case
	else
	{
		cout << Fraction::numerator << "/" << Fraction::denominator << endl;
	}
	
}



