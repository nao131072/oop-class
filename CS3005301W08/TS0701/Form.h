/***********************************************************************
 * File: Form.h
 * Author: 
 * Create Date: 
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/14
 * Description: header file of Form class
***********************************************************************/
#include<string>
#include <vector>
using namespace std;
class Form
{
private:
	string inputWord_allUp;
	string fileName;
	string inputWord_allLow;
	vector<string> wordList;
public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
