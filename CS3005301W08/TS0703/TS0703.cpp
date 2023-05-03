#include <iostream>
#include <vector>
using namespace std;

string symbols = "_||_||_";
int numbersBinary[10][7] = {
	{ 1,1,1,1,1,1,0 },
	{ 0,1,1,0,0,0,0 },
	{ 1,1,0,1,1,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 0,1,1,0,0,1,1 },
	{ 1,0,1,1,0,1,1 },
	{ 1,0,1,1,1,1,1 },
	{ 1,1,1,0,0,0,0 },
	{ 1,1,1,1,1,1,1 },
	{ 1,1,1,1,0,1,1 } };

void printResult(vector<string>& sevens)
{
	for (string seven : sevens)
	{
		cout << " ";
		cout << seven[0];
		cout << " ";
	}
	cout << endl;
	for (string seven : sevens)
	{
		cout << seven[5];
		cout << seven[6];
		cout << seven[1];
	}
	cout << endl;
	for (string seven : sevens)
	{
		cout << seven[4];
		cout << seven[3];
		cout << seven[2];
	}
	cout << endl;
}

int main()
{
	string inputNumbers;
	while (cin >> inputNumbers)
	{
		vector<string> sevens;
		for (int i = 0; i < inputNumbers.length(); i++)
		{
			if (inputNumbers[i] >= '0' && inputNumbers[i] <= '9')
			{
				string strEach = "       ";
				int realNumber = inputNumbers[i] - '0';

				for (int j = 0; j < 7; j++)
				{
					if (numbersBinary[realNumber][j] == 1)
					{
						strEach[j] = symbols[j];
					}
				}
				sevens.push_back(strEach);
			}
		}
		if (!sevens.empty())
		{
			printResult(sevens);
		}
	}
}
