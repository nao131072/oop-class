/***********************************************************************
 * File: TS0303.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/16
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/19
 * Description:reformat a double number with the customized format
***********************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	double target = 0;
	int width = 0;
	int precision = 0;
	char filling = ' ';

	while (cin >> target)
	{
		cin >> width;
		cin >> precision;
		cin >> filling;

		// check the target value is positive, 
		if (target >= 0)
		{
			// discard the value after the precision
			target = floor(target * pow(10, precision)) / pow(10, precision);
		}
		else
		{
			//if it's minus, it should be get to the ceil
			target = ceil(target * pow(10, precision)) / pow(10, precision);
		}

		//use this so that the setprecision function will show the zero after the value
		cout.setf(ios::fixed);
		// list out every thing according to the data we get from the start
		cout << setw(width) << setfill(filling) << setprecision(precision) << target << endl;

		//reset the value
		target = 0;
		width = 0;
		precision = 0;
		filling = ' ';
	}
}