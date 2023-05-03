/************************************************************************
File:   Source.cpp

Author:
		Áé½å¼s¡Aea5878158@gmail.com
Modifier:
		¿à¯§¦N¡Acheeryuchi@gmail.com
		³¯«T¦t¡AJYCReports@gmail.com
Comment:
		Output W,A,S,D after input, ESC to stop process.

************************************************************************/
#include <iostream>	// For print out information
#include <conio.h>	// For getch() function
using namespace std;

// Define inputs and its index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

// Detect state of input
void keyUpdate(bool key[]);

int main()
{
	//Initialize state of key
	bool gKeyState[ValidInput::INVALID];
	
	// Obtain and update the input using a loop
	/************************************************************************/
	/*Please implement your code here*/
	keyUpdate(gKeyState);
	
	
	/************************************************************************/
}

//******************************************************************
//
// * °»´ú¿é¤Jª¬ºA
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();

	// Implement a switch for output calls
	/************************************************************************/
	/*Please implement your code here*/
	while (!key[ValidInput::EESC])
	{
		switch (input)
		{
		case 'W':
		case 'w':
			key[ValidInput::EW] = true;
			break;
		case 'S':
		case 's':
			key[ValidInput::ES] = true;
			break;
		case 'A':
		case 'a':
			key[ValidInput::EA] = true;
			break;
		case 'D':
		case 'd':
			key[ValidInput::ED] = true;
			break;
		case ' ':
			key[ValidInput::ESPACE] = true;
			break;
		case 27:
			cout << "Key ESC is Pressed. End Program\n";
			exit(0);
			break;
		}

		if (key[ValidInput::EW])
		{
			cout << "W\n";
		}
		if (key[ValidInput::EA])
		{
			cout << "A\n";
		}
		if (key[ValidInput::ES])
		{
			cout << "S\n";
		}
		if (key[ValidInput::ED])
		{
			cout << "D\n";
		}
		if (key[ValidInput::ESPACE])
		{
			cout << "SPACE\n";
		}
		for (int i = 0; i < ValidInput::INVALID; i++) {
			key[i] = false;
		}
		input = _getch();
	}
	
	/************************************************************************/
}
