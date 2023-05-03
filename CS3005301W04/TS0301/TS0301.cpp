/***********************************************************************
 * File: TS0301.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/17
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/19
 * Description: Count the times that each number appears
***********************************************************************/

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//the array to store input numbers
	vector<int> numbers;
	//store the now inputting input
	int input;

	//get input with cin and put them into the vector array
	while (cin >> input)
	{
		numbers.push_back(input);
	}

	//bubble sort the array
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = 0; j < numbers.size() - i - 1; j++)
		{
			if (numbers[j] < numbers[j + 1])
			{
				int temp;
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
	//print out format
	cout << "N	count" << endl;
	
	//I'm going to count the number with the number, since the numbers are sorted,
	//It will be possible to just count the same numbers one by one,
	//Until the number we are counting become different, 
	//And then reset the number counted to 1 time, loop the above 

	//initialize the number to the first one 
	int numNow=numbers[0];
	//initialize the times to the 1st time
	int numberCount = 1;

	//go through the whole array
	for (int i = 1; i < numbers.size(); i++)
	{
		//no change -> count + 1
		if (numbers[i] == numNow)
		{
			numberCount++;
		}

		//changed -> print out the previous result so we can use the variables
		//and change the number counted to the current number, reset the count
		else 
		{
			cout << numNow << '\t' << numberCount << endl;
			numNow = numbers[i];
			numberCount = 1;
		}
	}

	//print out the last number and its count
	cout << numNow << '\t' << numberCount;
}
