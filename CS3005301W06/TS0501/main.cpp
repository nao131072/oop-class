/***********************************************************************
 * File: main.cpp
 * Author: 
 * Create Date:
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/30
 * Description: Hot dog stand main file
***********************************************************************/
#include <iostream>
#include "HotDogStand.h"
using namespace std;

int main() {
	HotDogStand stand1("Stand1", 0);
	HotDogStand stand2("Stand2", 100);
	HotDogStand stand3("Stand3");
	stand1.justSold();
	stand2.justSold();
	stand3.justSold();
	stand1.print();
	stand2.print();
	stand3.print();
	std::cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;
	return 0;

}