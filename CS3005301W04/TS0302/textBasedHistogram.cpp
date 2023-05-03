/***********************************************************************
 * File: textBasedHistogram.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/17
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/19
 * Description:Calculate each amount of the grades from the file, and output it to another file.
***********************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string filename = "grade.txt";
	string outFilename = "grades.Output";
	//create fstream to read file
	fstream file;
	fstream fileOut;

	//open the two file, one for in, one for out
	file.open(filename, ios::in);
	fileOut.open(outFilename, ios::out);

	//set a constant length grade array since there's only 6 kinds of grades
	int grades[6] = { 0, 0, 0, 0, 0 };
	//the input grade
	int inputGrade;

	//read the file
	while (file >> inputGrade) //read until file end
	{
		for (int i=0;i<6;i++)
		{
			//find how much is the input grade and plus one to the index
			if (inputGrade == i)
			{
				grades[i]++;
			}
		}
	}

	//output section
	for (int i = 0; i < 6; i++)
	{
		fileOut << grades[i] << " grade(s) of " << i << endl;
	}
}