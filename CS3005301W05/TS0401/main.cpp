/***********************************************************************
 * File: main.cpp
 * Author: not me
 * Create Date: unknown
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/23
 * Description: Use class structure to calculate a point on a x-y axis
***********************************************************************/
#include <iostream>
#include "Point.h"
using namespace std;

int main(void) {
	Point point;

	point.Set(0, 5);
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	point.Move(1, 2);
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	for (int i = 0; i < 4; i++) {
		point.Rotate();
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	}

	return 0;
}