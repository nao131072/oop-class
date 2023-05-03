/***********************************************************************
 * File: Point.h
 * Author: ³¯©|¿A
 * Create Date: 2023/04/1
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/1
 * Description: Advanced Class Point, the header file
***********************************************************************/
class Point
{
private:
	//horizontal is x, and vertical is y
	float vertical;
	float horizontal;

public:
	Point()
	{
		vertical = 0;
		horizontal = 0;
	}

	void Set(float, float);
	void Move(float x, float y);
	void Rotate();
	void Reflect();
	int GetVertical() const { return vertical; }
	int GetHorizontal() const { return horizontal; }
};