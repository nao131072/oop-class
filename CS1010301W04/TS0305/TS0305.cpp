/***********************************************************************
 * File: TS0305.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/17
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/19
 * Description: Use a freaking simple custumized canvas to show every goddamn requests from the test data. dont even know if it will work, but Probably not if it is done by only myself.
***********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//seperate each funtion one by one
void appear(bool);
bool drawLine();
bool drawSquare();
//the Triangle Drawing main funtion
bool drawTriangle();
//the customizable draw line funtion
bool drawLine_custom(int x1, int y1, int x2, int y2);

//global variable canvas->to draw the pics
vector<vector<int>> canvas;
//the Width of the canvas
int canvasWidth = 0;
//the Height of the canvas
int canvasHeight = 0;

int main()
{
	//scan
	while (cin >> canvasWidth >> canvasHeight)
	{
		//reset the canvas
		canvas.clear();
		//temp row to make the array two dimension
		vector<int> row;
		for (int i = 0; i < canvasHeight; i++)
		{
			for (int j = 0; j < canvasWidth; j++)
			{
				//initialize every element to 0
				row.push_back(0);
			}
			canvas.push_back(row);
			//reset the row for the next round
			row.clear();
		}

		//choose which pictures to be drew
		string drawType;
		while (cin >> drawType)
		{
			if (drawType == "S")
			{
				appear(drawSquare()); //functions inside appear() all contains a return bool value 'canShow' 
			}
			else if (drawType == "T")
			{
				appear(drawTriangle());
			}
			else if (drawType == "L")
			{
				appear(drawLine());
			}
			else if (drawType == "EXIT")
			{
				break;
				//break the while loop
			}
		}
	}
}

//appear the canvas pon screen
//canShow is 1 if the inputs are not out of range
void appear(bool canShow)
{
	if (canShow)
	{
		for (int i = 0; i < canvasHeight; i++)
		{
			for (int j = 0; j < canvasWidth; j++)
			{
				if (canvas[i][j] == 0)
				{
					cout << '*';
				}
				else
				{
					cout << 'X';
				}
			}
			cout << endl;
		}
	}
	else 
	{
		cout << "Out of range." << endl;
	}
	cout << endl;
}

bool drawSquare()
{
	int x, y, length;
	cin >> length >> x >> y;
	if (x + length <= canvasWidth && y + length <= canvasHeight)
	{
		//double loop to make a filled square
		for (int i = 0; i < length; i++)
		{
			for (int j= 0; j < length; j++)
			{
				canvas[y + i][x + j] = 1;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

bool checkLine(int x1, int y1, int x2, int y2)
{
	//check if the line points are all in the canvas range
	//first check positive part
	if (x1 < canvasWidth && x2 < canvasWidth && y1 < canvasHeight && y2 < canvasHeight)
	{
		//then check minus part
		if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0)
		{
			//return to appear canShow
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

bool drawLine()
{
	//input the two point
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	//draw the line with the data and get result(1or0)
	return drawLine_custom(x1, y1, x2, y2);
}

bool drawLine_custom(int x1, int y1, int x2, int y2)
{
	// use the formula y=m(x-a)+b
	// first need to exclude the possibility of vertical line in case the m to be infinity
	if (x1 != x2 && checkLine(x1, y1, x2, y2))
	{
		float m = (y2 - y1) / (x2 - x1);
		//check the points' value, and make sure we have the right hand side correctly, so that the loop will work
		int leftx, lefty, rightx, righty;
		
		if (x1 < x2)
		{
			leftx = x1;
			lefty = y1;
			rightx = x2;
			righty = y2;
		}
		else
		{
			leftx = x2;
			lefty = y2;
			rightx = x1;
			righty = y1;
		}

		//start draw the line
		int x = leftx;
		for (int i = x; i <= rightx; i++)
		{
			int y;
			//use the formula
			y = m * (i - x1) + y1;
			canvas[y][i] = 1;
		}
		//return 1 to reqresent the requested values are not out of range
		return 1;
	}
	//vertical line
	else if (x1 == x2 && checkLine(x1, y1, x2, y2))
	{
		//samely, check which y is bigger so that the loop will work
		if (y1 > y2)
		{
			swap(y1, y2);
		}
		//draw the vertical line
		for (int i = y1; i <= y2; i++)
		{
			canvas[i][x1] = 1;
		}
		return 1;
	}
	else if (!checkLine(x1, y1, x2, y2))
	{
		//didnt pass the checkLine, means out of range
		return 0;
	}
}

bool drawTriangle()
{
	int length, x, y;
	string direction;
	//inputs according to the document
	cin >> length >> x >> y >> direction;
	
	//initialize the x,y of the1 two points in the triangle except from the input one (x, y)
	int xa = -1, ya = -1, xb = -1, yb = -1;
	
	//check direction
	if (direction == "RD")
	{
		//calculate the points according to the direction
		xa = x + length - 1; //minus one because the dot will also be counted as one length
		ya = y;
		xb = x;
		yb = y + length - 1;
	}
	else if (direction == "RU")
	{
		xa = x + length - 1;
		ya = y;
		xb = x;
		yb = y - length + 1; //plus one because the dot will also be counted as one length
	}
	else if (direction == "LD")
	{
		xa = x - length + 1;
		ya = y;
		xb = x;
		yb = y + length - 1;
	}
	else if (direction == "LU")
	{
		xa = x - length + 1;
		ya = y;
		xb = x;
		yb = y - length + 1;
	}

	//now we have two dots, we can draw now
	if (xa >= 0 && ya >= 0 && xb >= 0 && yb >= 0) //check if all the dots are detected
	{
		// if two lines are all in the range, so would be the three dots
		if (checkLine(xa, ya, xb, yb) && checkLine(x, y, xa, ya))
		{
			bool result = 1;
			result *= drawLine_custom(xa, ya, xb, yb); //however, check one more time 
			result *= drawLine_custom(x, y, xa, ya);
			result *= drawLine_custom(x, y, xb, yb);
			//multiply the to check all of them are good
			return result;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}