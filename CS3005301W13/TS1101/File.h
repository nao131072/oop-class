/***********************************************************************
 * File: File.h
 * Author: ³¯©|¿A
 * Create Date: 2023/05/21
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/21
 * Description: Class_Inheritance File header
***********************************************************************/
#pragma once
#include "Document.h"
#include <iostream>
#include <fstream>
using namespace std;

class File : public Document 
{
public:
	File(string text, string filePath);
	void setPathname(string filePath);
	string getPathname() { return filePath; };
	void operator=(File& file);
private:
	ofstream fileOut;
	string filePath;
};