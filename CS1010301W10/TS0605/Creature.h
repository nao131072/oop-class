/***********************************************************************
 * File: Creature.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/30
 * Description: Observation Diary , creature class, and a part class
***********************************************************************/
#pragma once
#include <vector>
#include <iostream>
#include "Diary.h"
#include <string>
#include <algorithm>
using namespace std;

class Creature
{
	class part
	{
	public:
		// Intent: To create a part object
		// Pre: None
		// Post: A part object is created with default values for parent, name, and count
		part() :parent(parent), name(""), count(0) {}

		// Intent: To create a part object with given values for parent, name, and count
		// Pre: A Creature object exists, a string value for name, and an integer value for count
		// Post: A part object is created with the given values for parent, name, and count
		part(Creature& parent, string _name, int _count) :parent(parent), name(_name), count(_count) {}

		// Intent: To create a part object by copying another part object
		// Pre: A Creature object exists, and a const part object is passed in as a parameter
		// Post: A new part object is created that is a copy of the passed in part object
		part(Creature& parent, const part& clone) :parent(parent) {
			this->name = clone.name;
			this->count = clone.count;
		}

		// Intent: To assign a new count to a creature part and log the change in a diary
		// Pre: An integer count to assign
		// Post: The part's count is updated, and the change is logged in a diary
		part& operator=(int count)
		{
			//cout << "(" << parent.creatureName << "." << this->name << "=" << count << ")"; //t
			int oldCount = this->count;
			this->count = count;
			string action = matchAction(oldCount, this->count);
			if (action == "") return *this;
			string date = Diary::today;
			string message = parent.creatureName + "'s " + this->name + action + to_string(oldCount) + " -> " + to_string(this->count) + ").";

			if (this->count == oldCount)
				return *this;
			event newEvent;
			newEvent.name = parent.creatureName;
			newEvent.message = message;
			Diary::globalLog[Diary::globalLog.size() - 1].eventList.push_back(newEvent);
			return *this;
		}

		// Intent: To update the count of a body part and add an event to the creature's diary
		// Pre: An integer value to add to the body part's count
		// Post: The body part's count is updated by the input value and an event is added to the creature's diary
		part& operator+=(int count)
		{
			//cout << "(" << parent.creatureName << "." << this->name << "+=" << count << ")"; // Debugging line
			int oldCount = this->count;
			this->count += count;
			string action = matchAction(oldCount, this->count); // Get the string representation of the change in count
			if (action == "") return *this; // If no change in count, return without adding an event to the diary
			string date = Diary::today; // Get the current date
			string message = parent.creatureName + "'s " + this->name + action + to_string(oldCount) + " -> " + to_string(this->count) + ")."; // Create the message to add to the diary
			if (this->count == oldCount) return *this; // If no change in count, return without adding an event to the diary
			event newEvent; // Create a new event for the diary
			newEvent.name = parent.creatureName;
			newEvent.message = message;
			Diary::globalLog[Diary::globalLog.size() - 1].eventList.push_back(newEvent); // Add the new event to the creature's diary
			return *this; // Return the updated body part
		}
		// Intent: To subtract a value from a part count
		// Pre: An integer value to subtract from the current count
		// Post: The function returns a reference to the modified part object with updated count and adds a corresponding event to the global log
		part& operator-=(int count)
		{
			int oldCount = this->count;
			this->count -= count; //subtract count from current count
			string action = matchAction(oldCount, this->count); //match the count change action
			if (action == "") return *this; //no change in count, return the current object

			//prepare the event details
			string date = Diary::today;
			string message = parent.creatureName + "'s " + this->name + action + to_string(oldCount) + " -> " + to_string(this->count) + ").";

			//add the event to the global log
			if (this->count != oldCount)
			{
				event newEvent;
				newEvent.name = parent.creatureName;
				newEvent.message = message;
				Diary::globalLog[Diary::globalLog.size() - 1].eventList.push_back(newEvent);
			}
			return *this;
		}
		// Intent: To match the action to be performed based on the change of the numbers
		// Pre: Two integer numbers - oldNum and newNum
		// Post: The function returns a string that describes the action to be performed based on the change of the numbers
		string matchAction(int oldNum, int newNum)
		{
			if (newNum > oldNum)
			{
				if (oldNum == 0)
				{
					return " appeared ("; // creature appeared if it was not present before
				}
				else
				{
					return " increased ("; // creature count increased
				}
			}
			else if (newNum < oldNum)
			{
				return " decreased ("; // creature count decreased
			}
			else
			{
				return ""; // no change in creature count
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
	int createDay;
};

