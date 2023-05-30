/***********************************************************************
 * File: PrivateSchool.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/29
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/29
 * Description: PrivateSchool class cpp file
***********************************************************************/
#include "PrivateSchool.h"

//Intent: private school constructor
//Pre: string school name, float student amount
//Post: none
PrivateSchool::PrivateSchool(string name, float studentAmount)
	:School(name, studentAmount)
{
	isFirstWave = true;
}

//Intent: apply dropouts to student amount
//Pre: int student amount
//post: none
void PrivateSchool::dropouts(int amount)
{
	if (amount > this->studentAmount) return;
	if (amount < 0) return;

	
	this->studentAmount -= amount;

	if (amount > 100 || !isFirstWave)
	{
		studentAmountNextYear -= 100;
	}

	isFirstWave = false;
}
