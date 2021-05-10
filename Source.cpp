#include <iostream>
#include "intRange.h"
#include "Exception.h";
#include <exception>;
#include <stdexcept>;

int main()
{
	double number;
	intRange a;

	bool initResult;

	do
	{
		try
		{
			initResult = true;
			cin >> a;
		}
		catch (const char* str)
		{
			initResult = false;
			cerr << str << endl;
		}
		catch (bad_exception& e)
		{
			initResult = false;
			cerr << e.what() << endl;
		}
		catch (invalid_argument e)
		{
			initResult = false;
			cerr << e.what() << endl;
		}
	} while (!initResult);

	cout << "Enter a number to check for entry in the specified range: "; cin >> number;
	a.rangeCheckResult(a.rangeCheck(a, number));

	++a; cout << a;
	--a; cout << a;

	a++; cout << a;
	a--; cout << a;


	return 0;
}