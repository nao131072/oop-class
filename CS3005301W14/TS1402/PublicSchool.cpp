/***********************************************************************
 * File: PublicSchool.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/29
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/29
 * Description: Publicschool class cpp file
***********************************************************************/
#include "PublicSchool.h"

//Intent: public school constructor
//Pre: string school name, float student amount
//Post: none
PublicSchool::PublicSchool(string name, float studentAmount)
	:School(name, studentAmount)
{
	this->name = name;
	this->studentAmount = studentAmount;
	this->studentAmountNextYear = studentAmount;
}

//Intent: apply growth to student amount
//Pre: none
//post: none
void PublicSchool::apply_growth()
{
	studentAmountNextYear += studentAmountNextYear * growing_rate;
}

//Intent: deduct the amount of student from the school
//Pre: int student amount
//post: none
void PublicSchool::dropouts(int amount)
{
	if (amount > studentAmount) return;
	if (amount < 0) return;

	studentAmount -= amount;

	if (amount >= 100)
	{
		studentAmountNextYear -= studentAmountNextYear * 0.05f;
		studentAmountNextYear = floor(studentAmountNextYear);
	}
}


