/***********************************************************************
 * File: HotDogStand.cpp
 * Author: 
 * Create Date: 
 * Editor: ³¯©|¿A (and chatGPT for comments)
 * Update Date: 2023/03/30
 * Description: Hot dog stand class setting file
***********************************************************************/
#include "HotDogStand.h"
#include <string.h>
#include <iostream>

int HotDogStand::totalSellAmount = 0; // Static member variable to keep track of total number of hot dogs sold by all stands

HotDogStand::HotDogStand() // Default constructor
{
	// Do nothing
}

HotDogStand::HotDogStand(const char* id) // Constructor with stand ID parameter
{
	this->standId = id; // Set the stand ID
	this->hotDogSellAmount = 0; // Initialize the number of hot dogs sold to 0
}

HotDogStand::HotDogStand(const char* id, int amount) // Constructor with stand ID and hot dog sell amount parameters
{
	this->standId = id; // Set the stand ID
	this->hotDogSellAmount = amount; // Set the number of hot dogs sold
	HotDogStand::totalSellAmount += amount; // Add the number of hot dogs sold to the total number of hot dogs sold by all stands
}


HotDogStand::~HotDogStand() // Destructor
{
	// Do nothing
}

void HotDogStand::justSold() // Function to increment the number of hot dogs sold by this stand and all stands
{
	this->hotDogSellAmount++; // Increment the number of hot dogs sold by this stand
	HotDogStand::totalSellAmount++; // Increment the total number of hot dogs sold by all stands
}

void HotDogStand::print() // Function to print the stand ID and number of hot dogs sold by this stand
{
	std::cout << this->standId << " " << this->hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount() // Function to get the number of hot dogs sold by this stand
{
	return this->hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() // Function to get the total number of hot dogs sold by all stands
{
	return HotDogStand::totalSellAmount;
}
