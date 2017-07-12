#include "Student.h"

Student::Student() : name(""), secondName(""), patronymic(""), group(""), course(0), data(new Date), recordBook(nullptr)
{
}

Student::Student(std::string n, std::string sn, std::string p, std::string g, int c, int d, int m, int y) : 
	name(n), secondName(sn), patronymic(p), group(g), course(c), data(new Date(d, m, y)), recordBook(new RecordBook)
{
}

Student::~Student()
{
	delete data;
	delete recordBook;
}

void Student::printInfo() const
{
	std::cout << data->getDay() << " " << data->getMonth() << " " << data->getYear() << std::endl;
	if (recordBook)
	{
		recordBook->printMarks();
	}
}

void Student::setMarks()
{
	recordBook->setMarks();
}

void Student::addMark(std::string subj, int mark)
{
	recordBook->addMark(subj, mark);
}