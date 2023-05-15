/***********************************************************************
 * File: main.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/05/08
 * Editor: ³¯©|¿A
 * Update Date: 2023/05/08
 * Description: reverse longest
***********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

map<string, int> words;

int main()
{
	string longest = ""; // initialize variable to store the longest palindrome word found so far
	string current = ""; // initialize variable to store the current word being read from input stream
	string temp = ""; // initialize temporary variable to store the reverse of current word

	while (cin >> current) // read words from input stream until end of stream
	{
		temp = current;
		reverse(temp.begin(), temp.end()); // reverse the current word to check if it is a palindrome
		if (words.find(temp) == words.end()) // if the reverse of current word is not found in the map
		{
			words[current] = 0; // add the current word to the map
		}
		else // if the reverse of current word is found in the map
		{
			if (temp.size() > longest.size()) // check if the length of current word is greater than the length of the previous longest palindrome word found
			{
				longest = current; // update the longest palindrome word found so far
			}
		}
	}
	reverse(longest.begin(), longest.end()); // reverse the longest palindrome word to get the original word
	cout << longest; // output the longest palindrome word
}