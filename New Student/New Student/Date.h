#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<ctime>
#include<iostream>

class Date
{
	int day;
	int month;
	int year;
	static const std::map<int, int> dates;

	time_t t;
	tm *tk;

public:
	Date();
	Date(int, int = 0, int = 0);
	~Date();

	Date(const Date&);
	Date& operator=(const Date&);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void plusDate(int, int = 0, int = 0);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
};

