#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(const double a, const double b, const double c)
{
	if (checkExist(a, b, c))
	{
		size1 = a;
		size2 = b;
		size3 = c;

		angle1 = acos(((size1 * size1) + (size2 * size2) - (size3 * size3)) / (2 * size1 * size2)) * 180.0 / 3.141592;
		angle2 = acos(((size2 * size2) + (size3 * size3) - (size1 * size1)) / (2 * size2 * size3)) * 180.0 / 3.141592;
		angle3 = acos(((size3 * size3) + (size1 * size1) - (size2 * size2)) / (2 * size3 * size1)) * 180.0 / 3.141592;
	}
}

Triangle::Triangle(const std::pair<double, double> ab, const double c)
{
	size1 = ab.first;
	size2 = ab.second;
	angle1 = c;
	size3 = sqrt((size1 * size1) + (size2 * size2) - (2 * size1 * size2 * (cos(angle1 * 3.141592 / 180))));

	if (checkExist(size1, size2, size3))
	{
		angle2 = acos(((size2 * size2) + (size3 * size3) - (size1 * size1)) / (2 * size2 * size3)) * 180.0 / 3.141592;
		angle3 = acos(((size3 * size3) + (size1 * size1) - (size2 * size2)) / (2 * size3 * size1)) * 180.0 / 3.141592;
	}
	else
	{
		size1 = 0;
		size2 = 0;
		size3 = 0;
		angle1 = 0;
	}
}

Triangle::Triangle(const double a, const std::pair<double, double> bc)
{
	size1 = a;
	angle1 = bc.first;
	angle2 = bc.second;
	angle3 = 180 - angle1 - angle2;

	size2 = size1 * (sin(angle1) / sin(angle3));
	size3 = size1 * (sin(angle2) / sin(angle3));

	if (!checkExist(size1, size2, size3))
	{
		size1 = 0;
		size2 = 0;
		size3 = 0;
		angle1 = 0;
		angle2 = 0;
		angle3 = 0;
	}
}

Triangle::~Triangle()
{
}

bool Triangle::checkExist(const double a, const double b, const double c) const
{
	if (a <= 0 || b <= 0 || c <= 0 || a + b < c || a + c < b || b + a < c || b + c < a || c + a < b || c + b < a)
	{
		return false;
	}
	return true;
}

void Triangle::print() const
{
	std::cout << size1 << " " << size2 << " " << size3 << " " << angle1 << " " << angle2 << " " << angle3 << std::endl;
}

double Triangle::getArea()
{
	double p = (size1 + size2 + size3) / 2;
	return sqrt(p * (p - size1) * (p - size2) * (p - size3));
}