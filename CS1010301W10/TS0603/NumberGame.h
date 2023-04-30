#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class NumberGame {
private:
	long long int A = 0;
	vector<int> splitA;
	string fileName = "";
	vector<int> valids;
	vector<int> nums;
	long long int biggestAvailable = 1;

public:
	void SetInput(long long int);
	void ProcessInput();
	void SetFileName(string filename);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
	bool isValid(int, vector<int>&);
	bool isBigger(int);
};