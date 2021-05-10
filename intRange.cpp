#include "intRange.h"

intRange::intRange()
{
	first = 0;
	second = 0;
}
intRange::intRange(int first = 0, int second = 0) throw(Exception, invalid_argument)
{
	if (first > second)
		throw Exception("Exception - Error!(first < second)");
	if (first == second)
		throw invalid_argument("Built in exception - Error!(first = second)");
	this->first = first;
	this->second = second;
}
intRange::intRange(const intRange& c)
{
	first = c.first;
	second = c.second;
}

void intRange::SetFirst(int first)
{
	this->first = first;
}
void intRange::SetSecond(int second)
{
	this->second = second;
}

int intRange::GetFirst() const { return first; }
int intRange::GetSecond() const { return second; }

intRange& intRange::operator = (const intRange& c)
{
	first = c.first;
	second = c.second;

	return *this;
}
istream& operator >> (istream& in, intRange& c) throw(const char*, bad_exception&)
{
	cout << "Enter a First number in range: "; in >> c.first;
	cout << "Enter a Second number in range: "; in >> c.second;
	cout << endl;

	if (c.first > c.second)
		throw "Error!(first > second)";
	if (c.first == c.second)
		throw bad_exception();
	return in;
}
ostream& operator << (ostream& out, const intRange& c)
{
	out << string(c);
	return out;
}
intRange::operator string() const
{
	stringstream ss;
	ss << "First number in range is equal to " << first << endl;
	ss << "Second number in range is equal to " << second << endl;

	return ss.str();

}

intRange& intRange::operator ++()
{
	first++;
	return *this;
}
intRange& intRange::operator --()
{
	first--;
	return *this;
}
intRange intRange::operator ++ (int)
{
	intRange t(*this);
	second++;
	return t;
}
intRange intRange::operator -- (int)
{
	intRange t(*this);
	second--;
	return t;
}

bool operator > (const intRange a, const int number)
{
	if (a.GetSecond() > number)
		return 1;
	else
		return 0;
}
bool operator < (const intRange a, const int number)
{
	if (a.GetFirst() <= number)
		return 1;
	else
		return 0;
}

bool intRange::rangeCheck(const intRange a, const int number)
{
	return a < number&& a > number;
}
void intRange::rangeCheckResult(const bool result)
{
	if (result == 1)
		cout << "Yes, the number is within the specified range" << endl;
	else
		cout << "No, the number is not within the specified range" << endl;
}
