/***********************************************************************
 * File: Document.h
 * Author: ³¯©|¿A
 * Create Date: 2023/05/21
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/21
 * Description: Class_Inheritance Document header
***********************************************************************/
#pragma once
#include <iostream>
using namespace std;

class Document {
	
public:
	Document(string text);
	string getText() const { return text; };
	string text;
	
private:

};