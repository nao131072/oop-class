/***********************************************************************
 * File: School.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/29
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/29
 * Description: School class cpp file
***********************************************************************/
#include "School.h"

//Intent: school constructor
//Pre: string school name, float student amount
//Post: none
School::School(string name, float studentAmount)
{
	this->name = name;
	this->studentAmount = studentAmount;
	this->studentAmountNextYear = studentAmount;
}

//Intent: add student to student amount
//Pre: int student amount
//post: none
void School::admissions(int amount)
{
	if (amount > 0)
	{
		studentAmount += amount;
	}
}

//Intent: remove student from student amount
//Pre: int student amount
//post: none
void School::dropouts(int amount)
{
	if (amount > 0 && amount <= studentAmount)
	{
		studentAmount -= amount;
	}
}

//Intent: transfer student from one school to another
//Pre: int student amount, another school
//post: none
void School::transfer(int amount, School& toSchool)
{
	if (amount < this->studentAmount) {
		this->dropouts(amount);
		toSchool.admissions(amount);
	}
}

//Intent: output school info
//Pre: ostream, the school to output
//post: ostream with school info
ostream& operator<<(ostream& SchoolOut, School& sch)
{
	SchoolOut << sch.name << '\t' << sch.studentAmount << '\t' << sch.studentAmountNextYear;
	return SchoolOut;
}
