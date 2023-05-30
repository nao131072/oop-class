/***********************************************************************
 * File: School.h
 * Author: ³¯©|¿A
 * Create Date: 2023/05/29
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/29
 * Description: School class header file
***********************************************************************/
#pragma once
#include <iostream>
using namespace std;

class School {
public:
	School(string name, float studentAmount);
	void admissions(int amount);
	virtual void dropouts(int amount);
	void transfer(int amount, School& toSchool);
	friend ostream& operator<<(ostream& SchoolOut, School& sch);
private:

protected:
	string name="";
	int studentAmount=0;
	int studentAmountNextYear = studentAmount;

};

#include "PublicSchool.h"
#include "PrivateSchool.h"

