/***********************************************************************
 * File: Diary.h
 * Author: ³¯©|¿A
 * Create Date: 2023/04/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/30
 * Description: Observation Diary , diary class header file
***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef struct{
	string name;
	string message;
}event;

typedef struct {
	string date;
	vector<event> eventList;
}dayLog;

class Diary
{
	
public:
	static void NewDay(string day);
	static string today;
	static vector<string> days;
	static vector<dayLog> globalLog;
private:
	
};
