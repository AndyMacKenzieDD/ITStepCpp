#pragma once
#include "Date.h"
#include "RecordBook.h"
#include<string>

class Student
{
	std::string name;
	std::string secondName;
	std::string patronymic;
	std::string group;
	int course;
	Date* data;
	RecordBook* recordBook;
public:
	Student();
	Student(std::string, std::string, std::string, std::string, int, int, int, int);
	~Student();

	void printInfo() const;
	void setMarks();
	void addMark(std::string, int);
};

