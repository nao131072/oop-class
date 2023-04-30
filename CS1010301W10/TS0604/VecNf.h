#pragma once
#include <iostream>
#include <vector>
using namespace std;

class VecNf
{
public:
	VecNf();
	VecNf(float*, int);
	VecNf(const VecNf& rhs);
	int Size() { return this->values.size(); }
	VecNf& operator=(VecNf v);
	double& operator[](int index);
	friend VecNf operator+(VecNf& v1, VecNf& v2);
	friend VecNf operator-(VecNf& v1, VecNf& v2);
	friend double operator*(VecNf& v1, VecNf& v2);
	friend VecNf operator*(double c, VecNf& v);
	friend ostream& operator<<(ostream& strm, VecNf v);
private:
	vector<float> values;
};

