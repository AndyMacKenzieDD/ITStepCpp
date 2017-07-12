#include "Date.h"
 
const std::map<int, int> Date::dates = { { 1, 31 },{ 2, 28 },{ 3, 31 },{ 4, 30 },{ 5, 31 },{ 6, 30 },{ 7, 31 },{ 8, 31 },{ 9, 30 },{ 10, 31 },{ 11, 30 },{ 12, 31 } };

Date::Date() : year(0), month(0), day(0)
{
	time(&t);
	tk = localtime(&t);
	year = tk->tm_year + 1900;
	month = tk->tm_mon + 1;
	day = tk->tm_mday;
}

Date::Date(int d, int m, int y) : year(y), month(m), day(d)
{
	time(&t);
	tk = localtime(&t);
	if(!year) year = tk->tm_year + 1900;
	if(!month) month = tk->tm_mon + 1;
	if(!day) day = tk->tm_mday;
}

Date::~Date()
{
}

Date::Date(const Date& v) : day(v.day), month(v.month), year(v.year)
{
}

Date& Date::operator=(const Date& d)
{
	if (this == &d)
	{
		return *this;
	}

	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::plusDate(int d, int m, int y)
{
	year += y;

	while (m--)
	{
		if (month == 12)
		{
			++year;
			month = 1;
		}
		else
		{
			++month;
		}
	}

	while (d--)
	{
		if (day == dates.find(month)->second)
		{
			if (month == 12)
			{
				++year;
				month = 1;
				day = 1;
			}
			else
			{
				++month;
				day = 1;
			}
		}
		else
		{
			++day;
		}
	}
}

Date& Date::operator++()
{
	if (day == dates.find(month)->second)
	{
		if (month == 12)
		{
			++year;
			month = 1;
			day = 1;
		}
		else
		{
			++month;
			day = 1;
		}
	}
	else
	{
		++day;
	}
	return *this;
}

Date Date::operator++(int)
{
	Date oldValue = *this;
	if (day == dates.find(month)->second)
	{
		if (month == 12)
		{
			++year;
			month = 1;
			day = 1;
		}
		else
		{
			++month;
			day = 1;
		}
	}
	else
	{
		++day;
	}
	return oldValue;
}

Date& Date::operator--()
{
	if (day == 1)
	{
		if (month == 1)
		{
			--year;
			month = 12;
			day = 31;
		}
		else
		{
			--month;
			day = dates.find(month)->second;
		}
	}
	else
	{
		--day;
	}
	return *this;
}

Date Date::operator--(int)
{
	Date oldValue = *this;
	if (day == 1)
	{
		if (month == 1)
		{
			--year;
			month = 12;
			day = 31;
		}
		else
		{
			--month;
			day = dates.find(month)->second;
		}
	}
	else
	{
		--day;
	}
	return oldValue;
}