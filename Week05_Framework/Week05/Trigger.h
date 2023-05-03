#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"


//************************************************************
// Trigger Class
//************************************************************
class Trigger {
	// Implement Trigger Class
	/*Please implement your code here*/
private:
	int score;
	int x, y;
	char icon = 'T';

public:
	Trigger(int x, int y, int score)
	{
		this->x = x;
		this->y = y;
		this->score = score;
	}

	Position getPos()
	{
		Position triggerPos;
		triggerPos.x = this->x;
		triggerPos.y = this->y;
		return triggerPos;
	}

	char getIcon()
	{
		return this->icon;
	}

	int getExpAmount()
	{
		return this->score;
	}

	void update(Hero& hero)
	{
		Position heroPos = hero.getPos();
		int heroX = heroPos.x;
		int heroY = heroPos.y;
		if (heroX == this->x && heroY == this->y)
		{
			hero.gainEXP(this->score);
		}
	}

	/************************************************************************/
};

