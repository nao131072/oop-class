/***********************************************************************
 * File: Complex.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/04/28
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/28
 * Description: Complex class file
***********************************************************************/
#include "Complex.h"

Complex::Complex() :
	realValue(0),
	imaginaryValue(0)
{
}

Complex::Complex(double r) :
	realValue(r),
	imaginaryValue(0)
{
}

Complex::Complex(double r, double i) :
	realValue(r),
	imaginaryValue(i)
{
}

// Intent: Get the real value of the complex number
// Pre: A complex number is initialized
// Post: The real value of the complex number is returned
double Complex::real()
{
	return this->realValue;
}

// Intent: Get the imaginary value of the complex number
// Pre: A complex number is initialized
// Post: The imaginary value of the complex number is returned
double Complex::imag()
{
	return this->imaginaryValue;
}

// Intent: Get the norm of the complex number
// Pre: A complex number is initialized
// Post: The norm of the complex number is returned
double Complex::norm()
{
	double norm = sqrt(realValue * realValue + imaginaryValue * imaginaryValue);
	return norm;
}

// Intent: Get the real value of a complex number
// Pre: A complex number is passed as an argument
// Post: The real value of the complex number is returned
double real(Complex c)
{
	return c.realValue;
}

// Intent: Get the imaginary value of a complex number
// Pre: A complex number is passed as an argument
// Post: The imaginary value of the complex number is returned
double imag(Complex c)
{
	return c.imaginaryValue;
}

// Intent: Get the norm of a complex number
// Pre: A complex number is passed as an argument
// Post: The norm of the complex number is returned
double norm(Complex c)
{
	double norm = sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue);
	return norm;
}

// Intent: Add two complex numbers
// Pre: Two complex numbers are initialized
// Post: The sum of the two complex numbers is returned as a new Complex object
Complex Complex::operator+(Complex c)
{
	return Complex(this->realValue + c.realValue, this->imaginaryValue + c.imaginaryValue);
}

// Intent: Subtract two complex numbers
// Pre: Two complex numbers are initialized
// Post: The difference of the two complex numbers is returned as a new Complex object
Complex Complex::operator-(Complex c)
{
	return Complex(this->realValue - c.realValue, this->imaginaryValue - c.imaginaryValue);
}

// Intent: Multiply two complex numbers
// Pre: Two complex numbers are initialized
// Post: The product of the two complex numbers is returned as a new Complex object
Complex Complex::operator*(Complex c)
{
	Complex result;
	double a1 = this->realValue, a2 = this->imaginaryValue;
	double b1 = c.realValue, b2 = c.imaginaryValue;
	double real = a1 * b1 - a2 * b2;
	double imag = a2 * b1 + a1 * b2;
	result.realValue = real;
	result.imaginaryValue = imag;
	return result;
}

// Intent: Overload the division operator for Complex objects
// Pre: Two Complex objects are given
// Post: The quotient of the two Complex objects is returned
Complex Complex::operator/(Complex com)
{
	// Store the real and imaginary values of the current and given Complex objects
	double a = this->realValue, b = this->imaginaryValue;
	double c = com.realValue, d = com.imaginaryValue;
	// Calculate the real and imaginary parts of the quotient
	double real = (a * c + b * d) / (c * c + d * d);
	double imag = (b * c - a * d) / (c * c + d * d);

	// Create a new Complex object with the calculated values and return it
	Complex	result(real, imag);
	return result;
}
// Intent: Overload the addition operator for a double and a Complex object
// Pre: A double and a Complex object are given
// Post: The sum of the double and Complex object is returned
Complex operator+(double d, Complex c)
{
	// Create a new Complex object with the sum of the given double and the real part of the given Complex object,
	// and the imaginary part of the given Complex object
	Complex result(c.realValue + d, c.imaginaryValue);
	return result;
}

// Intent: Overload the subtraction operator for a double and a Complex object
// Pre: A double and a Complex object are given
// Post: The difference between the double and Complex object is returned
Complex operator-(double d, Complex c)
{
	// Create a new Complex object with the difference between the given double and the real part of the given Complex object,
	// and the negative of the imaginary part of the given Complex object
	Complex result(d - c.realValue, 0 - c.imaginaryValue);
	return result;
}

// Intent: Overload the multiplication operator for a double and a Complex object
// Pre: A double and a Complex object are given
// Post: The product of the double and Complex object is returned
Complex operator*(double d, Complex c)
{
	// Create a new Complex object with the product of the given double and the real and imaginary parts of the given Complex object
	Complex result(d * c.realValue, d * c.imaginaryValue);
	return result;
}

// Intent: Overload the division operator for a double and a Complex object
// Pre: A double and a Complex object are given
// Post: The quotient of the double and Complex object is returned
Complex operator/(double dou, Complex com)
{
	Complex result;
	// Store the real and imaginary values of the given Complex object and the given double
	double a = dou, b = 0;
	double c = com.realValue, d = com.imaginaryValue;
	// Calculate the real and imaginary parts of the quotient
	double real = (a * c + b * d) / (c * c + d * d);
	double imag = (b * c - a * d) / (c * c + d * d);

	// Store the calculated values in the new Complex object and return it
	result.realValue = real;
	result.imaginaryValue = imag;
	return result;
}

// Intent: Overload the equality operator for two Complex objects
// Pre: Two Complex objects are given
// Post: Returns true if the two Complex objects have the same real and imaginary parts, false otherwise
bool operator==(Complex c1, Complex c2)
{
	// If the real and imaginary parts of the two Complex objects are equal, return true, otherwise return false
	if (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Intent: Overloading the output stream operator to display a Complex number in a formatted way
// Pre: An output stream object and a constant Complex object reference
// Post: Returns the output stream object after adding the formatted complex number to it
ostream& operator<<(ostream& strm, const Complex& c)
{
	// output the real and imaginary parts of the complex number with the imaginary part represented by "*i"
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm; // return the output stream object
}

// Intent: Overloading the input stream operator to read a Complex number from the input stream
// Pre: An input stream object and a Complex object reference
// Post: Returns the input stream object after reading the Complex number from it and storing it in the Complex object
istream& operator>>(istream& strm, Complex& c)
{
	strm.ignore(5, '='); // ignore the first 5 characters until the '=' sign
	strm >> c.realValue; // read the real part of the Complex number
	strm.ignore(4, '+'); // ignore the next 4 characters until the '+' sign
	char strImag[20]; // create a char array to store the imaginary part as a string
	strm.getline(strImag, 20, '*'); // read the imaginary part as a string until the '*' sign
	c.imaginaryValue = atof(strImag); // convert the imaginary part from string to float and store it in the Complex object
	return strm; // return the input stream object
}