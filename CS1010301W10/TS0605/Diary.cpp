#include "Diary.h"

string Diary::today = "0";
vector<string> Diary::days;

void Diary::NewDay(string day)
{
	Diary::today = day;
	Diary::days.push_back(day);
	cout << "[DAY CHANGE " + day + " ]"; //t
}