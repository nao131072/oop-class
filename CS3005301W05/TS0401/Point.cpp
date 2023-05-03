/***********************************************************************
 * File: Point.cpp
 * Author: not me
 * Create Date: unknown
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/23
 * Description: the class functions setting
***********************************************************************/
#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	//set the point
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	//change x and y with the data input
	Point::vertical += x;
	Point::horizontal += y;
}
void Point::Rotate()
{
	//rotate for 90 degree
	//first, swap the two value
	int temp = Point::vertical;
	Point::vertical = Point::horizontal;
	Point::horizontal = temp;
	//then, set the y minus
	Point::horizontal *= -1;
}
