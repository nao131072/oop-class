#include "NumberGame.h"

void NumberGame::SetInput(long long int a)
{
	this->A = a;
}
void NumberGame::ProcessInput()
{
	long long int temp = this->A;
	while (temp > 0)
	{
		this->splitA.push_back(temp % 10);
		temp /= 10;
	}
	for (int i : this->splitA)
	{
		if (i > 0)
			this->biggestAvailable *= i;
	}
}
void NumberGame::SetFileName(string filename)
{
	this->fileName = filename;
}
void NumberGame::LoadNumberList()
{
	ifstream fileIn(fileName);
	
	if (!fileIn.is_open())
	{
		return;
	}

	int n;
	while (!fileIn.eof())
	{
		fileIn >> n;
		
		if (!isBigger(n))
			continue;

		if (n > this->biggestAvailable)
			continue;

		if (isValid(n, this->splitA))
		{
			this->valids.push_back(n);
		}
	}

}
void NumberGame::PrintAllValid()
{
	for (int i : this->valids)
	{
		std::cout << i << std::endl;
	}
}
void NumberGame::Reset()
{
	this->fileName = "";
	this->A = 0;
	this->nums.clear();
	this->valids.clear();
	this->splitA.clear();
	this->biggestAvailable = 1;
}
bool NumberGame::isValid(int n, vector<int>& elements)
{
	if (n == 1)
	{
		return true;
	}
	vector<int> dup = elements;
	for (int i = 0; i < dup.size(); i++)
	{
		if (n % dup[i] == 0 && dup[i] != 1)
		{
			int factor = n / dup[i];
			dup.erase(dup.begin() + i);
			
			if (isValid(factor, dup))
			{
				return true;
			}
		}
	}
	return false;
}

bool NumberGame::isBigger(int n)
{
	bool isBigger = 0;
	for (int i : this->splitA)
	{
		if (n >= i)
		{
			isBigger = 1;
		}
	}
	return isBigger;
}