/***********************************************************************
 * File: main.cpp
 * Author:
 * Create Date:
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/14
 * Description: atoi class header
***********************************************************************/
#include <string>
using namespace std;

class Atoi {

private:
	string beTrans;
	
public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();
};