/***********************************************************************
 * File: Month.h
 * Author: 
 * Create Date:
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/30
 * Description: Design Month Class, header file for initializing the class
***********************************************************************/
#pragma once
#include <iostream>
using namespace std;
class Month
{
public:
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);
	~Month();

	void inputInt();
	void inputStr();
	int checkStr(string three);
	void outputInt();
	void outputStr();
	Month nextMonth();
private:
	int month;
	string MonthNames[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
};

