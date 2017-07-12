#include "Square.h"

Square::Square(const double a) : Rectangle(a, a)
{
}

Square::~Square()
{
}

double Square::getArea()
{
	return getSize1() * getSize1();
}
