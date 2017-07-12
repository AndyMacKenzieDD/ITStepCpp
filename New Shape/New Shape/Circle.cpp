#include "Circle.h"

Circle::Circle(const std::pair<double, double> pnt, const double r)
{
	if (pnt.first > 0 && pnt.second > 0 && r > 0)
	{
		radius = r;
		centre.first = pnt.first;
		centre.second = pnt.second;
	}
}

Circle::Circle(const double x, const double y, const double r)
{
	if (x > 0 && y > 0 && r > 0)
	{
		radius = r;
		centre.first = x;
		centre.second = y;
	}
}

Circle::~Circle()
{
}

double Circle::getArea()
{
	return 3.14159 * (radius * radius);
}