/***********************************************************************
 * File: main.cpp
 * Author: 
 * Create Date: 
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/08
 * Description: namespace Authenticate
***********************************************************************/
#include "user.h"
#include "password.h"
#include <iostream>
using namespace std;
using namespace Authenticate;


int main()
{
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}
