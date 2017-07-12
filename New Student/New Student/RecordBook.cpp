#include "RecordBook.h"

RecordBook::RecordBook() : marks({ {"Algebra", 0},{ "Biology", 0 },{ "Chemistry", 0 },{ "Computer science", 0 },{ "Geography", 0 },{ "Geometry", 0 },{ "History", 0 },{ "Literature", 0 },{ "Mathematics", 0 },{ "Physics", 0 }, })
{
}

RecordBook::~RecordBook()
{
}

void RecordBook::printMarks() const
{
	for (auto it : marks)
	{
		std::cout << it.first << " " << it.second << std::endl;
	}
}

void RecordBook::setMarks()
{
	for (auto &it : marks)
	{
		std::cout << it.first << " ";
		std::cin >> it.second;
	}
}

void RecordBook::addMark(std::string subj, int mark)
{
	marks.insert({subj, mark});
}

std::pair<std::string, int> RecordBook::getMin() const
{
	int tmpM = marks.begin()->second;
	std::string tmpS;
	for (auto &it : marks)
	{
		if (it.second < tmpM)
		{
			tmpM = it.second;
			tmpS = it.first;
		}
	}
	return{ tmpS, tmpM };
}

std::pair<std::string, int> RecordBook::getMax() const
{
	int tmpM = marks.begin()->second;
	std::string tmpS;
	for (auto &it : marks)
	{
		if (it.second > tmpM)
		{
			tmpM = it.second;
			tmpS = it.first;
		}
	}
	return{ tmpS, tmpM };
}

double RecordBook::getAverage() const
{
	double size = marks.size();
	double sum = 0;

	for (auto &it : marks)
	{
		sum += it.second;
	}

	return sum / size;
}