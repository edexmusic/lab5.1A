#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Exception.h"

using namespace std;

class intRange
{
	int first, second;
public:
	intRange();
	intRange(int, int);
	intRange(const intRange&);

	void SetFirst(int);
	void SetSecond(int);

	int GetFirst() const;
	int GetSecond() const;

	intRange& operator = (const intRange&);
	friend istream& operator >> (istream&, intRange&) throw(const char*, bad_exception&);
	friend ostream& operator << (ostream&, const intRange&);
	operator string() const;

	intRange& operator ++ ();
	intRange& operator -- ();
	intRange operator ++ (int);
	intRange operator -- (int);

	friend bool operator > (const intRange a, const int number);
	friend bool operator < (const intRange a, const int number);

	bool rangeCheck(const intRange a, const int number);
	void rangeCheckResult(const bool result);
};
