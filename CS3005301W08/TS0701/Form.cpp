/***********************************************************************
 * File: Form.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/14
 * Editor: ³¯©|¿A (chatGPT for comments)
 * Update Date: 2023/04/14
 * Description: function setting file of Form
***********************************************************************/
#include"Form.h"
#include <fstream>
#include <iostream>
#include <cstring>

// This function sets the input word in both uppercase and lowercase forms
void Form::SetInputWord(string inputWord)
{
	this->inputWord_allUp = inputWord; // input word in all uppercase letters
	this->inputWord_allLow = inputWord; // input word in all lowercase letters
}

// This function converts the input word to uppercase and lowercase versions
void Form::ProcessInputWord()
{
	for (int i = 0; i < inputWord_allUp.length(); i++)
	{
		// if the character is a lowercase letter, convert it to uppercase
		if (inputWord_allUp[i] >= 'a' && inputWord_allUp[i] <= 'z')
		{
			inputWord_allUp[i] -= 32;
		}

		// if the character is an uppercase letter, convert it to lowercase
		if (inputWord_allLow[i] >= 'A' && inputWord_allLow[i] <= 'Z')
		{
			inputWord_allLow[i] += 32;
		}
	}
}

// This function sets the name of the file to load the compare word from
void Form::SetFileName(string fileName)
{
	this->fileName = fileName; // set the file name to load the compare word from
}

// This function loads the compare word from the file and searches for matching words
void Form::Load_CompareWord()
{
	ifstream fileInput(this->fileName); // open the input file
	string word;
	while (fileInput >> word) // read words from the input file
	{
		string temp = this->inputWord_allLow; // make a copy of the input word in lowercase
		bool isInside = 1; // initialize a flag to indicate if the word is found in the input word
		for (int i = 0; i < word.length(); i++) // loop through each character in the current word
		{
			int index = temp.find(word[i]); // find the index of the current character in the copy of the input word
			if (index != string::npos) // if the character is found in the input word
			{
				temp[index] = 'A' - 1; // replace the character in the copy of the input word with a non-alphabetic character
				isInside *= 1; // set the flag to indicate that the character is found in the input word
				continue;
			}
			else // if the character is not found in the input word
			{
				isInside *= 0; // set the flag to indicate that the word is not found in the input word
				break;
			}
		}
		if (isInside) // if the word is found in the input word
		{
			this->wordList.push_back(word); // add the word to the list of found words
		}
	}
}

// This function prints the list of found words
void Form::PrintFoundWords()
{
	for (string word : this->wordList) // loop through each word in the list of found words
	{
		cout << word << endl; // print the word to the console
	}
}
