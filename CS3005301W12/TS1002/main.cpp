/***********************************************************************
 * File: main.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/13
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/13
 * Description: word Game
***********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct Position{
	int i, j;
};

ifstream fileIn("words.txt");
map<pair<int, int>, int> usedPos;

// Intent: To check if a given position is within the boundaries of a 4x4 grid
// Pre: A Position struct containing the row and column indices of the position
// Post: Returns a boolean value indicating if the position is valid or not
bool isValidPos(Position pos)
{
	if (pos.i < 4 && pos.i >= 0 && pos.j < 4 && pos.j >= 0) // Check if the row and column indices are within 4x4 grid boundaries
	{
		return true; // If position is valid, return true
	}
	else
	{
		return false; // If position is not valid, return false
	}
}

// Intent: To check if the element at the given position matches a specific character
// Pre: A 2D char array, a char to check for, and a Position struct representing the position to check
// Post: Returns true if the element at the given position matches the char and has not been previously checked, false otherwise
bool checkDirection(char elements[][4], char c, Position posCheck)
{
	if (elements[posCheck.i][posCheck.j] == c) // check if the element at posCheck matches c
	{
		if (usedPos.find(pair<int, int>(posCheck.i, posCheck.j)) != usedPos.end()) // check if the position has already been used
		{
			return 0; // if the position has already been used, return false
		}
		else
		{
			usedPos[pair<int, int>(posCheck.i, posCheck.j)] = 1; // add the position to the used positions map
			return 1; // return true if the position matches c and has not been previously used
		}
	}
	else
	{
		return 0; // return false if the element at posCheck does not match c
	}
}

// Intent: To check if a word can be formed in a given 4x4 grid of characters
// Pre: A 4x4 grid of characters, a string word to be checked, an integer index representing the current position of the letter being checked, and a Position struct containing the current position of the letter being checked
// Post: Returns a boolean value indicating if the word can be formed in the grid
bool inChart(char elements[][4], string word, int index, Position posNow)
{
	if (index == word.size())
	{
		return 1; //The word has been completely formed and found in the grid, return true
	}

	Position posCheck;
	bool found = 0;

	posCheck.i = posNow.i + 1;
	posCheck.j = posNow.j;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck); //Check if the next letter in the word can be formed in the grid starting from the current position
		}

	}
	posCheck.i = posNow.i - 1;
	posCheck.j = posNow.j;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}
	posCheck.i = posNow.i;
	posCheck.j = posNow.j + 1;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}
	posCheck.i = posNow.i;
	posCheck.j = posNow.j - 1;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}
	posCheck.i = posNow.i + 1;
	posCheck.j = posNow.j + 1;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}
	posCheck.i = posNow.i - 1;
	posCheck.j = posNow.j - 1;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}
	posCheck.i = posNow.i + 1;
	posCheck.j = posNow.j - 1;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}
	posCheck.i = posNow.i - 1;
	posCheck.j = posNow.j + 1;
	if (isValidPos(posCheck))
	{
		if (checkDirection(elements, word[index], posCheck))
		{
			found = 1;
			return inChart(elements, word, index + 1, posCheck);
		}
	}

	if (found == 0)
	{
		return 0; 
	}
}

// Intent: To find the first position of a word in a 4x4 character matrix
// Pre: A 4x4 character matrix and a string representing a word
// Post: The function returns a Position struct representing the coordinates of the first character 
Position findFirstPos(char elements[][4], string word)
{
	Position result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (elements[i][j] == word[0])
			{
				result.i = i;
				result.j = j;
				return result;
			}
		}
	}
	result.i = -1;
	result.j = -1;
	return result;
}

// Intent: To check words that can be formed using the given characters array
// Pre: An array of characters with dimension 4x4
// Post: Print all valid words that can be formed using the characters array
void checkWords(char elements[][4])
{
	string word;
	while (!fileIn.eof())
	{
		fileIn >> word;
		Position posNOw = findFirstPos(elements, word);
		if (posNOw.i == -1 || posNOw.j == -1) continue;
		usedPos[pair<int,int>(posNOw.i, posNOw.j)] = 1;

		if (inChart(elements, word, 1, posNOw)==1)
		{
			cout << word << endl;
		}
		usedPos.clear();
	}

}


int main()
{
	char elements[4][4];
	char input;
	int i = 0;
	while (cin >> input)
	{
		elements[i / 4][i % 4] = input;
		i++;
		if (i == 16)
		{
			fileIn.close(); //reopen the file
			fileIn.open("words.txt");
			checkWords(elements);
			cout << "\n"; //format
			i = 0; //reset i
		}
	}
}