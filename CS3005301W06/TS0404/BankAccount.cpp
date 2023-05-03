/***********************************************************************
 * File: BankAccount.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/30
 * Description: class setting file for BankAccount
***********************************************************************/
#include "BankAccount.h"

int BankAccount::total = 0; // Static member variable to keep track of total money in bank

BankAccount::BankAccount() // Default constructor
{
	balance = 0; // Set initial balance to zero
	total += balance; // Add initial balance to total money in bank
}

BankAccount::BankAccount(int input) // Parameterized constructor
{
	balance = input; // Set initial balance to user input
	total += balance; // Add initial balance to total money in bank
}

void BankAccount::withdraw(int input) // Function to withdraw money
{
	balance -= input; // Subtract withdrawn amount from balance
	total -= input; // Subtract withdrawn amount from total money in bank
}

void BankAccount::save(int input) // Function to save money
{
	balance += input; // Add saved amount to balance
	total += input; // Add saved amount to total money in bank
}

int BankAccount::getBalance() // Function to get current balance
{
	return balance; // Return current balance
}

int BankAccount::getAllMoneyInBank() // Function to get total money in bank
{
	return total; // Return total money in bank
}
