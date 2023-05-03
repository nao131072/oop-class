/***********************************************************************
 * File: TS0405.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/23
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/23
 * Description: Collatz Conjecture
***********************************************************************/
#include <iostream>
using namespace std;

unsigned long long int CZCJ(unsigned long long int n);

int main()
{
	unsigned long long int a, b;

	//input two
	while (cin >> a >> b)
	{
		//the result of the max length
		unsigned long long int max = 0;
		unsigned long long int small = a, big = b;

		//ensure the small one and the big one that the loop can work
		if (a > b)
		{
			small = b;
			big = a;
		}

		for (int i = small; i <= big; i++)
		{
			unsigned long long int result = CZCJ(i); //THE function
			//check the length and eventually get the biggest result
			if (result > max)
			{
				max = result;
			}
		}

		//output
		cout << a << " " << b << " " << max << endl;
	}
}

unsigned long long int CZCJ(unsigned long long int n)
{
	unsigned long long int count = 1;
	
	//do the calculation according to the file
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = n * 3 + 1;
		}
		count++;
	}
	//return the result count
	return count;
}