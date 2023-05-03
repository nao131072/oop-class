/***********************************************************************
 * File: Point.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/1
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/1
 * Description: Advanced Class Point, the class setting file
***********************************************************************/
#include "Point.h"

void Point::Set(float horizontal, float vertical)
{
	//set the point
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(float x, float y)
{
	//change x and y with the data input
	Point::horizontal += x;
	Point::vertical += y;
}
void Point::Rotate()
{
	//rotate for 90 degree
	//first, swap the two value
	float temp = Point::vertical;
	Point::vertical = Point::horizontal;
	Point::horizontal = temp;
	//then, set the y minus
	Point::vertical *= -1;
}
void Point::Reflect()
{
	//set the both axis minus
	Point::horizontal *= -1;
	Point::vertical *= -1;
}
