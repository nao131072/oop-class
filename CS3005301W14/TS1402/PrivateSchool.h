/***********************************************************************
 * File: PrivareSchool.h
 * Author: ���|�A
 * Create Date: 2023/05/29
 * Editor: ���|�A
 * Update Date: 2023/05/29
 * Description: PrivareSchool class header file
***********************************************************************/
#pragma once
#include "School.h"

class PrivateSchool : public School {
public:
	PrivateSchool(string name, float studentAmount);
	void dropouts(int amount);
private:
	bool isFirstWave = true;
};
