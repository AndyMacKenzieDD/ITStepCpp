#include "Rectangle.h"

Rectangle::Rectangle(const double a, const double b) : Parallelogram(a, b, 90)
{
}

Rectangle::~Rectangle()
{
}

double Rectangle::getArea()
{
	return getSize1() * getSize2();
}
