/************************************************************************
File:   Source.cpp

Author:
		Áé½å¼s¡Aea5878158@gmail.com
Modifier:
		¿à¯§¦N¡Acheeryuchi@gmail.com
		ÅU°ßÄ£¡Aguweiyao867@gmail.com
		³¯«T¦t¡AJYCReports@gmail.com
		ªô¹Å¿³¡Atbcey74123@gmail.com
Comment:
		Draw and print out the canvas.


 * Editor: ³¯©|¿A
 * Update Date: 2023/03/19
 * Description: Draw and print out the canvas.

************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

void drawBoard(); //Function to draw board
void makeBoard(); //Function to make board
void modifyBoard();	//Function to modify board

const int DUNGEN_ROW = 10, DUNGEN_COL = 20;
char dungenMap[DUNGEN_ROW][DUNGEN_COL];

int main(int argc, char** argv)
{
	makeBoard();
	drawBoard();
	modifyBoard();
	drawBoard();
}

void drawBoard()
//==================================================================
{
	// Draw out the whole board
	/************************************************************************/
	/*Please implement your code here*/
	//draw the map with a double loop
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		for (int j = 0; j < DUNGEN_COL; j++)
		{
				cout << dungenMap[i][j];
		}
		cout << endl;
	}
	/************************************************************************/
}

void makeBoard()
//==================================================================
{
	// Enter symbol for wall and blank then create array
	/************************************************************************/
	/*Please implement your code here*/
	char wallSymbol;
	char blankSymbol;

	cout << "Enter symbol for wall: ";
	cin >> wallSymbol;
	cout << "Enter symbol for blank: ";
	cin >> blankSymbol;

	//first fill the whole map with the blank symbol
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		for (int j = 0; j < DUNGEN_COL; j++)
		{
			dungenMap[i][j] = blankSymbol;
		}
	}

	//and then, draw the up and button walls
	for (int i = 0; i < DUNGEN_COL; i++)
	{
		dungenMap[0][i] = wallSymbol;
		dungenMap[DUNGEN_ROW - 1][i] = wallSymbol;
	}

	//draw the left and right walls
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		dungenMap[i][0] = wallSymbol;
		dungenMap[i][DUNGEN_COL - 1] = wallSymbol;
	}
	/************************************************************************/
}

void modifyBoard()
//==================================================================
{
	// Function for modifying board given position and char to change
	/************************************************************************/
	/*Please implement your code here*/
	char modifySymbol;
	int modifyX, modifyY;

	//input the symbol, x, and y
	cout << "Enter symbol for modifying position: ";
	cin >> modifySymbol;
	cout << "Enter X of modifying position: ";
	cin >> modifyX;
	cout << "Enter Y of modifying position: ";
	cin >> modifyY;

	//if in the range of 10, 20, which is the range of the whole map, execute the change
	if (modifyX >= 0 && modifyX <  DUNGEN_COL && modifyY >= 0 && modifyY < DUNGEN_ROW)
	{
		dungenMap[modifyY][modifyX] = modifySymbol;
	}
	//otherwise, the x, y is invalid
	else
	{
		cout << "Invalid input.\n";
	}

	/************************************************************************/
}