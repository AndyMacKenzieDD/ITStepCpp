#pragma once
#include<map>
#include<string>
#include<iostream>

class RecordBook
{
	std::map<std::string, int> marks;
public:
	RecordBook();
	~RecordBook();

	void printMarks() const;
	void setMarks();
	void addMark(std::string, int);

	std::pair<std::string, int> getMin() const;
	std::pair<std::string, int> getMax() const;
	double getAverage() const;
};

