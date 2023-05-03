/***********************************************************************
 * File: BankAccount.h
 * Author: ³¯©|¿A
 * Create Date: 2023/03/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/30
 * Description: header file for bankAccount
***********************************************************************/
#pragma once
using namespace std;

class BankAccount {
private:
	int balance;
	static int total;
public:
	BankAccount();
	BankAccount(int input);
	void withdraw(int output);
	void save(int input);
	int getBalance();
	static int getAllMoneyInBank();
};
