#pragma once
#include <vector>
#include <iostream>
#include "Diary.h"
#include <string>
using namespace std;

class Creature
{
	class part
	{
	public:
		part():parent(parent), name(""),count(0){}
		part(Creature& parent, string _name, int _count) :parent(parent), name(_name), count(_count){}
		part(Creature& parent, const part& clone) :parent(parent) {
			this->name = clone.name;
			this->count = clone.count;
		}
		part& operator=(int count)
		{
			cout << "(" << parent.creatureName << "." << this->name << "=" << count << ")"; //t
			int oldCount = this->count;
			this->count = count;
			string action = matchAction(oldCount, this->count);
			string date = Diary::today;
			string message = parent.creatureName + "'s " + this->name + action + to_string(oldCount) + " -> " + to_string(this->count) + ").";
			if (this->count == 0)
				this->name = "";
			if (this->count == oldCount)
				return *this;
			parent.log.push_back(make_pair(Diary::today, message));
			
			return *this;
		}
		part& operator+=(int count)
		{
			cout << "(" << parent.creatureName << "." << this->name << "+=" << count << ")"; //t
			int oldCount = this->count;
			this->count += count;
			string action = matchAction(oldCount, this->count);
			string date = Diary::today;
			string message = parent.creatureName + "'s " + this->name + action + to_string(oldCount) + " -> " + to_string(this->count) + ").";
			if (this->count == 0)
				this->name = "";
			if (this->count == oldCount)
				return *this;
			parent.log.push_back(make_pair(Diary::today, message));
			
			return *this;
		}
		part& operator-=(int count)
		{
			cout << "(" << parent.creatureName << "." << this->name << "-=" << count << ")"; //t
			int oldCount = this->count;
			this->count -= count;
			string action = matchAction(oldCount, this->count);
			string date = Diary::today;
			string message = parent.creatureName + "'s " + this->name + action + to_string(oldCount) + " -> " + to_string(this->count) + ").";
			if (this->count == 0)
				this->name = "";
			if (this->count == oldCount)
				return *this;
			parent.log.push_back(make_pair(Diary::today, message));

			return *this;
		}
		string matchAction(int oldNum, int newNum)
		{
			if (newNum < oldNum) return " decreased (";
			else if (oldNum == 0 && newNum > oldNum) return " appeared (";
			else if (oldNum > 0 && newNum > oldNum) return " increased (";
			else
			{
				return " increased (";
			}
		}

		Creature& parent;
		string name;
		int count;
	};

public:
	Creature(string name);
	Creature(string name, const Creature& base);
	part& operator[](string part);
	void PrintStatus();
	void PrintLog();

private:
	string creatureName;
	vector<part> parts;
	vector<pair<string, string>> log;
	string createDay;
};

