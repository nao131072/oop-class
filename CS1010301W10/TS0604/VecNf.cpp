#include "VecNf.h"
using namespace std;
VecNf::VecNf()
{
	this->values.push_back(0);
}
VecNf::VecNf(float* dest, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		this->values.push_back(dest[i]);
	}
}
VecNf::VecNf(const VecNf& rhs)
{
	this->values = rhs.values;
}
VecNf& VecNf::operator=(VecNf v)
{
	cout << "ASSIGNMENT!!!\n";
	this->values = v.values;
	return *this;
}
double& VecNf::operator[](int index)
{
	if (index < this->values.size())
	{
		double result = values[index];
		return result;
	}
}
VecNf operator+(VecNf& v1, VecNf &v2)
{
	VecNf result(v1);
	if (v1.Size() == v2.Size())
	{
		for (int i = 0; i < v2.values.size(); i++)
		{
			result.values[i] += v2.values[i];
		}
	}
	else
	{
		cout << "dimensions inconsistent" << endl;
		VecNf inconsistent;
		return inconsistent;
	}
	return result;
}
VecNf operator-(VecNf& v1, VecNf& v2)
{
	VecNf result(v1);
	if (v1.Size() == v2.Size())
	{
		for (int i = 0; i < v2.values.size(); i++)
		{
			result.values[i] -= v2.values[i];
		}
	}
	else
	{
		cout << "dimensions inconsistent" << endl;
		VecNf inconsistent;
		return inconsistent;
	}
	return result;
}
double operator*(VecNf& v1, VecNf& v2)
{
	if (v1.Size() != v2.Size())
	{
		cout << "dimensions inconsistent" << endl;
		return 0;
	}

	float product = 0;
	for (int i = 0; i < v1.Size(); i++)
	{
		product += v1.values[i] * v2.values[i];
	}
	return product;
}
VecNf operator*(double c, VecNf& v)
{
	VecNf result;
	result.values.clear();
	for (float value : v.values)
	{
		result.values.push_back(value * c);
	}
	return result;
}
ostream& operator<<(ostream& strm, VecNf v)
{
	for (int i = 0; i < v.Size(); i++)
	{
		strm << v.values[i];
	}
	strm << endl;
	return strm;
}
