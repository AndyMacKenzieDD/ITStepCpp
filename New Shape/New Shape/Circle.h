#pragma once
#include "Shape.h"
#include <utility>

class Circle :
	public Shape
{
	double radius;
	std::pair<double, double> centre;
public:
	Circle(const std::pair<double, double>, const double);
	Circle(const double, const double, const double);
	~Circle();

	double getArea() override;
};

