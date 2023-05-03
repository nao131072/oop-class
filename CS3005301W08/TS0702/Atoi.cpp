/***********************************************************************
 * File: Atoi.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/14
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/14
 * Description: class Atoi setting file
***********************************************************************/
#include "Atoi.h"
#include <iostream>

// Default constructor, initializes beTrans to an empty string
Atoi::Atoi() : beTrans("")
{

}

// Constructor that initializes beTrans to the given string s
Atoi::Atoi(string s) : beTrans(s)
{

}

// Sets the value of beTrans to the given string s
void Atoi::SetString(string s)
{
	this->beTrans = s;
}

// Returns the current value of beTrans
const string Atoi::GetString()
{
	return this->beTrans;
}

// Returns the length of the string in beTrans, excluding a leading negative sign if present
int Atoi::Length()
{
	int i = 0;
	while (this->beTrans[i] != '\0')
	{
		i++;
	}
	if (this->beTrans[0] == '-')
	{
		i--;
	}
	return i;
}

// Returns true if the string in beTrans consists only of digits and a leading negative sign if present, false otherwise
bool Atoi::IsDigital()
{
	bool isDigital = 1;
	for (int i = 0; i < this->beTrans.length(); i++)
	{
		if ((this->beTrans[i] >= '0' && this->beTrans[i] <= '9') || this->beTrans[i] == '-')
		{
			// do nothing
		}
		else
		{
			isDigital *= 0;
			break;
		}
	}
	return isDigital;
}

// Converts the string in beTrans to an integer and returns it
int Atoi::StringToInteger()
{
	int sum = 0;
	if (this->beTrans[0] == '-')
	{
		// if the string starts with a negative sign, skip the first character and subtract each digit from the sum
		for (int i = 1; i < this->beTrans.length(); i++)
		{
			int digit = this->beTrans[i] - '0';
			sum *= 10;
			sum -= digit;
		}
	}
	else
	{
		// if the string does not start with a negative sign, add each digit to the sum
		for (int i = 0; i < this->beTrans.length(); i++)
		{
			int digit = this->beTrans[i] - '0';
			sum *= 10;
			sum += digit;
		}
	}
	return sum;
}
