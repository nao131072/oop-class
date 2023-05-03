/************************************************************************
File:   Source.cpp

Author:
		Áé½å¼s¡Aea5878158@gmail.com
Modifier:
		¿à¯§¦N¡Acheeryuchi@gmail.com
		³¯«T¦t¡AJYCReports@gmail.com
Comment:
		Use clock to count time (And output) for following input tasks

************************************************************************/

#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	clock_t startT, endT; // Variable to store the start of the gameloop
	startT = clock();
	endT = clock();
	clock_t globalStartT = startT;
	
	// Start the game loop
	/************************************************************************/
	/*Please implement your code here*/

	double deltaTime = 0;
	double secCount = 0;
	while (secCount < 15)
	{
		while (endT - startT < CLOCKS_PER_SEC)
		{
			endT = clock();
		}
		secCount++;
		startT = clock();
		cout <<"Total Time " << secCount;
		cout << " at " << (double)endT / CLOCKS_PER_SEC << endl;
		endT = clock();
	}

	/************************************************************************/

}
