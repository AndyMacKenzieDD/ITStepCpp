#include "Parallelogram.h"
#include <cmath>

Parallelogram::Parallelogram(double a, double b, double c) : size1(a), size2(b), angle(c)
{
}

Parallelogram::~Parallelogram()
{
}

double Parallelogram::getArea()
{
	return size1 * size2 * (sin(angle / 180 * 3.14159));
}

double Parallelogram::getSize1() const
{
	return size1;
}
double Parallelogram::getSize2() const
{
	return size2;
}

double Parallelogram::getAngle() const
{
	return angle;
}
