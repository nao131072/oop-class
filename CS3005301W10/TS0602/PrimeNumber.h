/***********************************************************************
 * File: PrimeNumber.h
 * Author: ³¯©|¿A
 * Create Date: 2023/04/28
 * Editor: ³¯©|¿A
 * Update Date: 2023/04/28
 * Description: Prime Number header file
***********************************************************************/
class PrimeNumber {
public:
	int value;
	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber & operator++();
	PrimeNumber operator++(int);
	PrimeNumber & operator--();
	PrimeNumber operator--(int);
	void operator=(PrimeNumber n);
	bool isPrime(int n);
};