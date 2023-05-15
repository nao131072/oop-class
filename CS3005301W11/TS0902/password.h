/***********************************************************************
 * File: password.h
 * Author: ³¯©|¿A
 * Create Date:2023/05/08
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/08
 * Description: namespace Authenticate password header file
***********************************************************************/
#pragma once
#include <iostream>
using namespace std;

namespace Authenticate
{
	string password = "";

	// Intent: To validate the user's password
	// Pre: None
	// Post: The function returns true if the password is valid, false otherwise
	bool isValid_password(void)
	{
		bool passwordValid = 0;

		if (password.size() >= 8) // check if the password has at least 8 characters
		{
			bool haveNum = 0;
			for (int i = 0; i < password.size(); i++)
			{
				if (password[i] <= '9' && password[i] >= '0') // check if the password contains at least one non-letter character
				{
					haveNum = 1;
					break;
				}
			}
			if (haveNum == 1) // if the password has at least 8 characters and at least one non-letter character, set passwordValid to true
			{
				passwordValid = 1;
			}
		}
		return passwordValid;
	}

	// Intent: To prompt the user to input their password and validate it
	// Pre: None
	// Post: The user's password is validated and stored in the password variable
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid_password()); // repeat until the password is valid
	}

	// Intent: To return the user's password
	// Pre: None
	// Post: The function returns the user's password
	string getPassword()
	{
		return password;
	}

}
