#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void getHighScores(vector<int> scores, vector<string> students);

int main()
{
	string filename;
	fstream file;
	cin >> filename;
	file.open(filename,ios::in);

	string student;
	int score;
	vector<string> students;
	vector<int> scores;

	while (!file.eof())
	{
		file >> student;
		file >> score;
		students.push_back(student);
		scores.push_back(score);
	}
	getHighScores(scores, students);
	
}

void getHighScores(vector<int> scores, vector<string> students)
{
	for (int i = 0; i < scores.size() - 1; i++)
	{
		for (int j = 0; j < scores.size() - i - 1; j++)
		{
			if (scores[j] < scores[j + 1])
			{
				int temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
				string tmp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << students[i] << endl;
		cout << scores[i] << endl;
	}
}