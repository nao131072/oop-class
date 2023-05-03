/***********************************************************************
 * File: Month.cpp
 * Author: 
 * Create Date:
 * Editor: ³¯©|¿A (and chatGPT for comments)
 * Update Date: 2023/03/30
 * Description: Design Month Class, class setting file
***********************************************************************/
#include "Month.h"
#include <string.h>
#include <iostream>

using namespace std;

// Default constructor
Month::Month()
{
	this->month = 1;
}

// Constructor that accepts a three-letter month 
Month::Month(char first, char second, char third)
{
	
	string three = "   ";
	three[0] = first;
	three[1] = second;
	three[2] = third;

	// Check if the string matches one of the valid month
	int resultMonth = Month::checkStr(three);
	if (resultMonth == 0)
	{
		// If not valid,  January
		this->month = 1;
	}
	else
	{
		// If valid, set the month to the corresponding number
		this->month = resultMonth;
	}
}

// Constructor that accepts a numeric month value
Month::Month(int monthInt)
{
	// Check if the month value is in the valid range of 1 to 12
	if (monthInt < 1 || monthInt>12)
	{
		// If the value is not valid, set the month to January
		this->month = 1;
	}
	else
	{
		// If the value is valid, set the month to the corresponding value
		this->month = monthInt;
	}
}

Month::~Month()
{
}

// Read a numeric month value from standard input and set the month
void Month::inputInt()
{
	int input;
	std::cin >> input;
	if (input < 1 || input >12)
	{
		this->month = 1;
	}
	else
	{
		this->month = input;
	}
}

// Read a three-letter month abbreviation from standard input and set the month
void Month::inputStr()
{
	// Construct a string from the input characters
	string three = "   ";
	cin >> three[0] >> three[1] >> three[2];

	// Check if the string matches one of the valid month abbreviations
	int resultMonth = Month::checkStr(three);
	if (resultMonth == 0)
	{
		// If the string is not valid, set the month to January
		this->month = 1;
	}
	else
	{
		// If the string is valid, set the month to the corresponding number
		this->month = resultMonth;
	}

}

// Check if a three-letter string matches a valid month abbreviation and return the corresponding number
int Month::checkStr(string three)
{
	for (int i = 0; i < 12; i++)
	{
		if (three == this->MonthNames[i])
		{
			// If the string matches a valid abbreviation, return the corresponding number
			return i + 1;
			break;
		}
	}
	// If the string does not match a valid abbreviation, return 0
	return 0;
}

// Print the month number to standard output
void Month::outputInt()
{
	cout << this->month;
}

// Print the three-letter month abbreviation to standard output
void Month::outputStr()
{
	cout << this->MonthNames[this->month - 1];
}

// Return a new Month object representing the next month after this one
Month Month::nextMonth()
{
	Month newMonth(this->month + 1);
	return newMonth;
}
