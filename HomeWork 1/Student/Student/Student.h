#pragma once
#include<string>
#include<iostream>

struct StudentName
{
	std::string firstName;
	std::string secondName;
	std::string patronymic;

};

class Student
{
	StudentName fullName;
	std::string city;
	std::string university;
	const unsigned int yearOfBirth;
	std::string phone;
	std::string groupNumber;

public:
	Student(std::string, std::string, std::string, std::string, std::string, const int, std::string, std::string);
	StudentName getName() const;
	std::string getCity() const;
	std::string getUniversity() const;
	const int getYearOfBirth() const;
	std::string getPhone() const;
	std::string getGroupNumber() const;
	void printStudentInfo() const;

	void setName(const std::string, const std::string, const std::string);
	void setCity(const std::string);
	void setUniversity(const std::string);
	void setPhone(const std::string);
	void setGroupNumber(const std::string);
	void setInfo();


};

