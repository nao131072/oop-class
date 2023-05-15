/***********************************************************************
 * File: user.h
 * Author: ³¯©|¿A
 * Create Date:2023/05/08
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/08
 * Description: namespace Authenticate password user file
***********************************************************************/
#pragma once
#include <iostream>
using namespace std;

namespace Authenticate
{
    string username = "";

        // Intent: To validate the format of username input
        // Pre: None
        // Post: Returns a boolean value indicating whether the username input is valid
        bool isValid_username(void)
    {
        bool usernameValid = 0;
        if (username.size() == 8)
        {
            for (int i = 0; i < username.size(); i++)
            {
                if (username[i] < 'A' || username[i]>'z')
                {
                    return 0;
                }
            }
            usernameValid = 1;
        }
        return usernameValid;
    }

    // Intent: To get and validate username input from user
    // Pre: None
    // Post: User input a valid username and it's stored in username variable
    void inputUserName()
    {
        do
        {
            cout << "Enter your username (8 letters only)" << endl;
            cin >> username;
        } while (!isValid_username());
    }

    // Intent: To get username
    // Pre: None
    // Post: Returns the value of the username variable
    string getUserName()
    {
        return username;
    }
}