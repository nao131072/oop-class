#include "Creature.h"

Creature::Creature(string name):
	creatureName(name)
{
	this->createDay = Diary::today;
	cout << "{new creature " << this->creatureName << "}"; //t
}
Creature::Creature(string name, const Creature& base)
{
	this->creatureName = name;
	for (int i = 0; i < base.parts.size(); i++)
	{
		part clonePart(*this, base.parts[i]);
		this->parts.push_back(clonePart);
	}
	this->createDay = Diary::today;
	cout << "{new creature " << this->creatureName <<" from " << base.creatureName<< "}"; //t
}

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

void Creature::PrintStatus()
{
	cout << this->creatureName + "'s status:" << "/";

	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i].count > 0)
		{
			string partName = parts[i].name;
			int partCount = parts[i].count;
			cout << partName << " * " << partCount << "/";
		}
	}
	cout << endl;
}
void Creature::PrintLog()
{
	
	cout << this->creatureName << "'s log:" << "/";
	if (log.size() == 0)
	{
		cout << "/";
		return;
	}
		
	int startIndex = 0;

	if(log[0].first!=this->createDay)
		cout << "Day " << this->createDay << "/";

	for (int i = 0; i < Diary::days.size(); i++)
	{
		if (Diary::days[i] == log[0].first)
		{
			startIndex = i;
			break;
		}
	}

	for (int i = startIndex; i < Diary::days.size(); i++)
	{
		cout << "Day " << Diary::days[i] << "/";
		for (int j = 0; j < this->log.size(); j++)
		{
			if (log[j].first == Diary::days[i])
			{
				cout << log[j].second << "/";
			}
		}
	}
	cout << "/";
}

