/***********************************************************************
 * File: PublicSchool.h
 * Author: ³¯©|¿A
 * Create Date: 2023/05/29
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/29
 * Description: PublicSchool class header file
***********************************************************************/
#pragma once
#include "School.h"


class PublicSchool : public School {
public:
	PublicSchool(string name, float studentAmount);
	void apply_growth();
	void dropouts(int amount);
private:
	float growing_rate = 0.05f;

};
