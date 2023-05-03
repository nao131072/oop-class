#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial()
{
	this->size = 0;
	this->param = { 0 };
}

Polynomial::Polynomial(double param[], int size)
{
	int realSize = size;
	for (int i = size - 1; i >= 0; i--)
	{
		if (param[i] == 0)
		{
			realSize--;
		}
		else
		{
			break;
		}
	}
	this->param = new double[realSize];
	
	for (int i = 0; i < realSize; i++)
	{
		this->param[i] = param[i];
	}
	this->size = realSize;
}


Polynomial::Polynomial(const Polynomial& poly)
{
	this->size = poly.mySize();
	this->param = new double[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->param[i] = poly.param[i];
	}
}


void Polynomial::operator = (const Polynomial& poly)
{
	this->size = poly.mySize();
	this->param = new double[poly.size];
	
	for (int i = 0; i < poly.size; i++)
	{
		this->param[i] = poly.param[i];
	}
}

double Polynomial::operator [] (int index)
{
	if (index < this->mySize())
	{
		return this->param[index];
	}
	else return 0;
}

Polynomial operator + (const Polynomial& poly1, const Polynomial& poly2)
{
	int resultSize = 1;
	Polynomial result;


	if (result.mySize() > poly2.mySize())
	{
		result = poly1;
		for (int i = 0; i < poly2.mySize(); i++)
		{
			result.param[i] += poly2.param[i];
		}
	}
	else
	{
		result = poly2;
		for (int i = 0; i < poly1.mySize(); i++)
		{
			result.param[i] += poly1.param[i];
		}
	}

	return result;
}

Polynomial operator + (const Polynomial& poly, const double& c)
{
	Polynomial result(poly);
	result.param[0] += c;
	return result;
}

Polynomial operator + (const double& c, const Polynomial& poly)
{
	Polynomial result(poly);
	result.param[0] += c;
	return result;
}

Polynomial operator - (const Polynomial& poly1, const Polynomial& poly2)
{
	int resultSize = 1;
	double* resultParam = { 0 };
	
	if (poly1.mySize() > poly2.mySize())
	{
		Polynomial result(poly1);
		for (int i = 0; i < poly2.mySize(); i++)
		{
			poly1.param[i] -= poly2.param[i];
		}
		return result;
	}
	else if(poly1.mySize() == poly2.mySize())
	{
		Polynomial result(poly1);
		for (int i = 0; i < poly2.mySize(); i++)
		{
			result.param[i] -= poly2.param[i];
		}
		int resultSize = result.mySize();
		for (int i = result.mySize() - 1; i >= 0; i--)
		{
			if (result.param[i] == 0)
			{
				resultSize--;
			}
		}
		Polynomial finalResult;
		finalResult.size = resultSize;
		finalResult.param = new double[resultSize];
		for (int i = 0; i < resultSize; i++)
		{
			finalResult.param[i] = result.param[i];
		}
		return finalResult;
	}
	else
	{
		Polynomial result(poly2);
		for (int i = 0; i < result.mySize(); i++)
		{
			result.param[i] *= -1;
		}
		for (int i = 0; i < poly1.mySize(); i++)
		{
			result.param[i] += poly1.param[i];
		}
		return result;
	}
}

Polynomial operator - (const Polynomial& poly, const double& c)
{
	Polynomial result(poly);
	result.param[0] -= c;
	return result;
}

Polynomial operator - (const double& c, const Polynomial& poly)
{
	Polynomial result(poly);
	for (int i = 0; i < result.mySize(); i++)
	{
		result.param[i] *= -1;
	}
	result.param[0] += c;
	return result;
}

Polynomial operator * (const Polynomial& poly1, const Polynomial& poly2)
{
	int resultSize = 0;
	double* resultParam = { 0 };
	if (poly1.mySize() == 1 && poly2.mySize() == 1)
	{
		resultSize = 1;
		double answer[1] = { poly1.param[0] * poly2.param[0] };
		Polynomial result(answer, resultSize);
		return result;
	}
	else
	{
		resultSize = poly1.mySize() + poly2.mySize() - 1;
	}
	
	resultParam = new double[resultSize];
	for (int i = 0; i < resultSize; i++)
	{
		resultParam[i] = 0;
	}

	for (int i = 0; i < poly1.mySize(); i++)
	{
		for (int j = 0; j < poly2.mySize(); j++)
		{
			resultParam[i + j] += poly1.param[i] * poly2.param[j];
		}
	}

	Polynomial result(resultParam, resultSize);
	return result;
}

Polynomial operator * (const Polynomial& poly, const double& c)
{
	if (c == 0)
	{
		Polynomial result;
		return result;
	}

	Polynomial result(poly);
	for (int i = 0; i < result.mySize(); i++)
	{
		result.param[i] *= c;
	}
	return result;
}

Polynomial operator * (const double& c, const Polynomial& poly)
{
	if (c == 0)
	{
		Polynomial result;
		return result;
	}

	Polynomial result(poly);
	for (int i = 0; i < result.mySize(); i++)
	{
		result.param[i] *= c;
	}
	return result;
}

double evaluate(const Polynomial& poly, const double& var)
{
	int size = poly.mySize();
	double result = 0;
	double x = 1;
	for (int i = 0; i < size; i++)
	{
		x = 1;
		for (int j = 0; j < i; j++)
		{
			x *= var;
		}
		result += poly.param[i] * x;
	}
	return result;
}

int Polynomial::mySize() const
{
	return this->size;
}