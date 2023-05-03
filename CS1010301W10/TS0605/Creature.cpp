/***********************************************************************
 * File: Creature.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/30
 * Description: Observation Diary , creature class implement
***********************************************************************/
#include "Creature.h"

// Intent: To create a new Creature object with a given name
// Pre: A string representing the name of the creature
// Post: A new Creature object is created with the given name, and the creation date is recorded in the global log
Creature::Creature(string name) :
	creatureName(name)
{
	this->createDay = Diary::globalLog.size() - 1;
	//cout << "{new creature " << this->creatureName << "}"; //t
}

// Intent: To create a new Creature object with a given name, based on an existing Creature object
// Pre: A string representing the name of the new creature, and an existing Creature object to be cloned
// Post: A new Creature object is created with the given name, and its body parts are cloned from the existing Creature object. The creation date is recorded in the global log
Creature::Creature(string name, const Creature& base)
{
	this->creatureName = name;
	for (int i = 0; i < base.parts.size(); i++)
	{
		part clonePart(*this, base.parts[i]);
		this->parts.push_back(clonePart);
	}
	this->createDay = Diary::globalLog.size() - 1;
	//cout << "{new creature " << this->creatureName <<" from " << base.creatureName<< "}"; //t
}

// Intent: To access a specific body part of a Creature object using its name
// Pre: A string representing the name of the body part
// Post: The body part object with the given name is returned. If the body part doesn't exist, a new one is created with a count of 0 and returned.
Creature::part& Creature::operator[](string part)
{
	bool exist = 0;
	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i].name == part)
		{
			exist = 1;
			return parts[i];
		}
	}

	if (!exist)
	{
		Creature::part newPart(*this, part, 0);
		this->parts.push_back(newPart);
		return this->parts[parts.size() - 1];
	}
	else
	{
		return this->parts[parts.size() - 1];
	}
}


//Intent: To print the status of a creature
//Pre: None
//Post: The function prints the status of the creature including its name and the count of each body part it has

void Creature::PrintStatus()
{
	cout << this->creatureName + "'s status:" << endl; // print the creature name

	// sort the parts of the creature in alphabetical order
	if (parts.size() > 1)
	{
		for (int i = 0; i < parts.size() - 1; i++) {
			for (int j = 0; j < parts.size() - i - 1; j++) {
				if (parts[j].name > parts[j + 1].name) {
					string nameT = parts[j].name;
					int countT = parts[j].count;
					parts[j].name = parts[j + 1].name;
					parts[j].count = parts[j + 1].count;
					parts[j + 1].name = nameT;
					parts[j + 1].count = countT;
				}
			}
		}
	}

	// print each body part and its count
	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i].count > 0)
		{
			string partName = parts[i].name;
			int partCount = parts[i].count;
			cout << partName << " * " << partCount << endl;
		}
	}

	cout << endl; // add a new line after printing the status
}


// Intent: To print the log of a creature
// Pre: None
// Post: The function prints the log of the creature
void Creature::PrintLog()
{
	cout << this->creatureName << "'s log:" << endl; // Print the creature's name and the word "log" in the console
	int startIndex = this->createDay; // The index of the day when the creature was created
	for (int i = startIndex; i < Diary::globalLog.size(); i++) // Loop through the global log starting from the createDay of the creature
	{
		cout << "Day " << Diary::globalLog[i].date << endl; // Print the current day in the console

		for (int j = 0; j < Diary::globalLog[i].eventList.size(); j++) // Loop through the event list of the current day
		{
			if (Diary::globalLog[i].eventList[j].name == this->creatureName) // If the name of the current event matches the creature's name
			{
				cout << Diary::globalLog[i].eventList[j].message << endl; // Print the message of the current event in the console
			}
		}
	}
	cout << endl; // Print a blank line in the console
}


