/***********************************************************************
 * File: Diary.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/30
 * Description: Observation Diary , diary class implement
***********************************************************************/
#include "Diary.h"

string Diary::today = "0";
vector<string> Diary::days;
vector<dayLog> Diary::globalLog;

// Intent: To create a new day in the diary
// Pre: A string representing the day
// Post: The function adds the day to the diary's list of days and creates a new dayLog object for that day
void Diary::NewDay(string day)
{
	Diary::today = day; // set the current day to the given day
	Diary::days.push_back(day); // add the given day to the list of days
	dayLog newLog; // create a new dayLog object
	newLog.date = day; // set the date of the dayLog object to the given day
	Diary::globalLog.push_back(newLog); // add the dayLog object to the diary's global log
}