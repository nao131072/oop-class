/***********************************************************************
 * File: source.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/1
 * Editor: ³¯©|¿A (chatGPT for comments)
 * Update Date: 2023/04/1
 * Description: Sudoku Checker
***********************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int sudoku[9][9]; // 2D array for holding the sudoku puzzle

int checkOnetoNine(int target[]); // function prototype for checking if an array of 9 numbers contains all the numbers 1 through 9

int main()
{
	ifstream fin;
	ifstream fout;
	//fin.open("input.txt");
	//fout.open("output.txt");

	while (cin >> sudoku[0][0]) // loop to read in the sudoku puzzle, assumes input is well-formed
	{
		bool valid = 1; // flag to indicate if the puzzle is valid
		for (int i = 1; i < 9; i++)
		{
			scanf_s(", %d", &sudoku[0][i]); // read in the rest of the first row of the puzzle
		}

		for (int i = 1; i < 9; i++)
		{
			cin >> sudoku[i][0]; // read in the first column of each subsequent row
			for (int j = 1; j < 9; j++)
			{
				scanf_s(", %d", &sudoku[i][j]); // read in the rest of each row
			}
		}

		int checkLine[9] = { 0 }; // array to hold a row, column, or box for checking if it contains all the numbers 1 through 9

		for (int i = 0; i < 9; i++) // loop over the rows of the puzzle
		{
			for (int j = 0; j < 9; j++)
			{
				checkLine[j] = sudoku[i][j]; // copy the row into checkLine
			}

			if (checkOnetoNine(checkLine) != 1) // if the row doesn't contain all the numbers 1 through 9
			{
				valid *= 0; // set valid to false
				break; // exit the loop
			}
		}

		for (int i = 0; i < 9; i++) // loop over the columns of the puzzle
		{
			for (int j = 0; j < 9; j++)
			{
				checkLine[j] = sudoku[j][i]; // copy the column into checkLine
			}

			if (checkOnetoNine(checkLine) != 1) // if the column doesn't contain all the numbers 1 through 9
			{
				valid *= 0; // set valid to false
				break; // exit the loop
			}
		}

		for (int i = 0; i < 3; i++) // loop over the 3x3 boxes of the puzzle
		{
			for (int j = 0; j < 3; j++)
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						checkLine[a * 3 + b] = sudoku[i * 3 + a][j * 3 + b]; // copy the box into checkLine
					}
				}
				if (checkOnetoNine(checkLine) != 1) // if the box doesn't contain all the numbers 1 through 9
				{
					valid *= 0; // set valid to false
					break;
				}
			}
		}

		// Print True if the puzzle is valid, otherwise print False
		if (valid)
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
		
	}
	

}

int checkOnetoNine(int target[]) // function to check if all numbers from 1 to 9 are present in an array
{
	int count = 0; // initialize count variable

	for (int i = 1; i <= 9; i++) // loop through numbers 1 to 9
	{
		for (int j = 0; j < 9; j++) // loop through each element in the target array
		{
			if (target[j] == i) // if the current element is equal to the current number being checked
			{
				count++; // increment the count variable
				break; // break out of the inner loop
			}
		}
	}

	if (count == 9) // if all numbers from 1 to 9 were found in the target array
	{
		return 1; // return 1 (true)
	}
	else // otherwise
	{
		return 0; // return 0 (false)
	}
}