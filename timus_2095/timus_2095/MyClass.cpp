#include "MyClass.h"
#include <exception>

int MyClass(long long a, long long b)
{
	auto f = [](int n)
	{
		for (int i = 2; n >= i; n -= n / i++);
		return n;
	};

	return (f(b) - f(a - 1));
}

bool checkFirstDay(long long a)
{
	if (a < 1 || a > 1000000000)
		return false;

	return true;
}

bool checkSecondDay(long long a)
{
	if (a < 1 || a > 1000000000)
		return false;
	
	return true;
}

bool firstDayDouble(double a, long long b)
{
	return false;
}

bool secondDayDouble(long long a, double b)
{
	return false;
}

bool moreThanTwoArgs(long long a, long long b, ...)
{
	return false;
}

bool inputNegative(long long a, long long b)
{
	if(a < 0 || b < 0)
		return false;

	return true;
}

bool secondDayIsGreater(long long a, long long b)
{
	if(b > a)
		return false;

	return true;
}

bool noArguments()
{
	return false;
}