/***********************************************************************
 * File: HotDogStand.h
 * Author:
 * Create Date:
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/30
 * Description: Hot dog stand class header file
***********************************************************************/
#pragma once
class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	const char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

