/***********************************************************************
 * File: PrimeNumber.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/28
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/28
 * Description: Prime Number class setting file
***********************************************************************/
#include "PrimeNumber.h"

// Constructor to initialize PrimeNumber object with a value of 1
// Pre: None
// Post: PrimeNumber object is initialized with a value of 1
PrimeNumber::PrimeNumber() :value(1)
{

}

// Constructor to initialize PrimeNumber object with a given value
// Pre: An integer value
// Post: PrimeNumber object is initialized with the given value
PrimeNumber::PrimeNumber(int _value) :value(_value)
{

}

// Function to get the value of PrimeNumber object
// Pre: None
// Post: The value of PrimeNumber object is returned
int PrimeNumber::get()
{
	return this->value;
}

// Overloaded pre-increment operator to increment the value of PrimeNumber object to the next prime number
// Pre: None
// Post: The value of PrimeNumber object is incremented to the next prime number and the updated object is returned
PrimeNumber& PrimeNumber::operator++()
{
	while (1)
	{
		this->value++;
		if (isPrime(this->value))
		{
			return *this;
		}
	}
}

// Overloaded post-increment operator to increment the value of PrimeNumber object to the next prime number
// Pre: None
// Post: The value of PrimeNumber object is incremented to the next prime number and the previous object is returned
PrimeNumber PrimeNumber::operator++(int)
{
	PrimeNumber result(this->value);
	while (1)
	{
		this->value++;
		if (isPrime(this->value))
		{
			return result;
		}
	}
}

// Overloaded pre-decrement operator to decrement the value of PrimeNumber object to the previous prime number
// Pre: None
// Post: The value of PrimeNumber object is decremented to the previous prime number and the updated object is returned
PrimeNumber& PrimeNumber::operator--()
{
	if (this->value == 2)
	{
		this->value = 1;
		return *this;
	}
	while (1)
	{
		this->value--;
		if (isPrime(this->value))
		{
			return *this;
		}
	}
}

// Overloaded post-decrement operator to decrement the value of PrimeNumber object to the previous prime number
// Pre: None
// Post: The value of PrimeNumber object is decremented to the previous prime number and the previous object is returned
PrimeNumber PrimeNumber::operator--(int)
{
	PrimeNumber result(this->value);
	if (this->value == 2)
	{
		result.value = 1;
		return result;
	}
	while (1)
	{
		this->value--;
		if (isPrime(this->value))
		{
			return result;
		}
	}
}
// Intent: To assign a PrimeNumber to another PrimeNumber
// Pre: A PrimeNumber object
// Post: The value of the right-hand side PrimeNumber is assigned to the left-hand side PrimeNumber
void PrimeNumber::operator=(PrimeNumber n)
{
	this->value = n.get(); //assign the value of the right-hand side PrimeNumber to the left-hand side PrimeNumber
}

// Intent: To check if a number is prime
// Pre: An integer number greater than or equal to 2
// Post: The function returns true if the number is prime, false otherwise
bool PrimeNumber::isPrime(int n)
{
	for (int i = n - 1; i >= 2; i--)
	{
		if (n % i == 0)
		{
			return 0; //the number is not prime
			break;
		}
	}
	return 1; //the number is prime
}