/************************************************************************
File:   Source.cpp

Author:
		���s�Aea5878158@gmail.com
Modifier:
		�௧�N�Acheeryuchi@gmail.com
		���T�t�AJYCReports@gmail.com
		���ſ��Atbcey74123@gmail.com
Comment:
		�򥻿�J��V���ʥ\��Aw s a d ���ʸ}��W�U���k�A�ťէ��ܸ}�⯸�ߤ��a�O�r���A
		ESC�O���}�e���C�P�ɧ�s�Ϫ��W����T�C

************************************************************************/
#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function

//************************************************************
// The location in the board
//************************************************************
struct Position {
	int x; // X, y Coordinate
	int y;
};

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero {
private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'H';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Incrementally move the elements 
	void move(int deltaX, int deltaY) {
		// Implement Hero controls
		/*Please implement your code here*/
		Position posNow;
		posNow.x = this->sPos.x;
		posNow.y = this->sPos.y;
		posNow.x += deltaX;
		posNow.y += deltaY;

		if (isPositionValid(posNow))
		{
			this->setPos(posNow);
		}
		/************************************************************************/
	}
};

// clip algroithm
float clip(float n, float minimun, float maximum);

class Creature {

	// Implement Creature Class
	/*Please implement your code here*/
	private:
		Position creaturePosition; //creature position
		char creatureIcon = '@';  //creature Icon
		const int inRange_distance = 2;

	public:
		// Default constructor
		Creature()
		{
			this->creaturePosition.x = 0;
			this->creaturePosition.y = 0;
			this->creatureIcon = '@';
		};
		// Set position
		void setPos(Position pos) { this->creaturePosition = pos; }
		void setPos(int x, int y) {
			this->creaturePosition.x = x;
			this->creaturePosition.y = y;
		}

		// Set icon
		void setIcon(char& icon) { this->creatureIcon = icon; }

		// Get position
		Position getPos(void) { return this->creaturePosition; }

		// Get Icon
		char getIcon(void) { return this->creatureIcon; }

		// Incrementally move the elements 
		void move(int deltaX, int deltaY) 
		{
			Position posNow;
			posNow.x = this->creaturePosition.x;
			posNow.y = this->creaturePosition.y;
			posNow.x += deltaX;
			posNow.y += deltaY;

			if (isPositionValid(posNow))
			{
				this->setPos(posNow);
			}
		}

		void update(Position heroPosition)
		{
			int heroPosX = heroPosition.x;
			int heroPosY = heroPosition.y;
			
			if (inRange(heroPosition))
			{
				std::cout << "Creature saw Hero" << std::endl;
				int priorityX = 0;
				int priorityY = 1;

				if (abs(this->creaturePosition.x - heroPosX) > abs(this->creaturePosition.y - heroPosY))
				{
					priorityX = 1;
					priorityY = 0;
				}

				if (priorityX == 1 && heroPosX < this->creaturePosition.x)
				{
					priorityX *= -1;
				}
				else if (priorityY == 1 && heroPosY < this->creaturePosition.y)
				{
					priorityY *= -1;
				}
				this->move(priorityX, priorityY);
			}
			else
			{
				int randX = rand() % 2;
				int randY = 0;
				
				if (randX == 0)
				{
					randY = 1;
				}
				
				for (int i = 0; i < rand() % 2; i++)
				{
					randX *= -1;
					randY *= -1;
				}

				this->move(randX, randY);
			}
		}

		bool inRange(Position targetPos)
		{
			int xNow = this->creaturePosition.x;
			int yNow = this->creaturePosition.y;

			if (targetPos.x >= xNow - inRange_distance && targetPos.x <= xNow + inRange_distance)
			{
				if (targetPos.y >= yNow - inRange_distance && targetPos.y <= yNow + inRange_distance)
				{
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		
	/************************************************************************/
};

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// �Ψ��x�s�������
char gBoard[GHEIGHT][GWIDTH];

// �w�q���ؿ�J���O�P�����}�Cindex
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

Hero gHero;
Creature gCreature;

// function declare
// ������J���A
void keyUpdate(bool key[]);
// �P�_��m�O�_����
bool isPositionValid(Position& loc);
// ��l�ƪ���
void setupBoard();
// ��X����
void draw(void);
// ��X������T
void drawInfo(void);

// �{���D�X�ʨ禡
void update(bool key[]);

int main(int argc, char** argv)
{
	srand(time(NULL));

	// �ΨӺ޲z��L��J���A���}�C
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	// Set the position of Hero
	gHero.setPos(2, 2);

	gCreature.setPos(5, 6);

	// Draw the board and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC]) {
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * ������J���A
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * �P�_��m�O�_����
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	if (pos.x == gHero.getPos().x && pos.y == gHero.getPos().y)
		return false;

	if (pos.x == gCreature.getPos().x && pos.y == gCreature.getPos().y)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			if (i == 0 || i == GHEIGHT - 1) {
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1) {
				gBoard[i][j] = GWALL;
			}
			else {
				gBoard[i][j] = GNOTHING;
			}
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	// Print Outputs
	/*Please implement your code here*/

	/************************************************************************/

	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Press ESC key to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// �M������
	system("CLS");

	// �O�_��input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		gHero.move(1, 0);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	//Calculate and Initiate Move
	gCreature.update(gHero.getPos());
	draw();
	drawInfo();
}
