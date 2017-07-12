#pragma once
#include "Shape.h"
#include <algorithm>

class Triangle :
	public Shape
{
	double size1 = 0;
	double size2 = 0;
	double size3 = 0;

	double angle1 = 0;
	double angle2 = 0;
	double angle3 = 0;

	bool checkExist(const double, const double, const double) const;
	
public:
	Triangle(const double, const double, const double);
	Triangle(const std::pair<double, double>, const double);
	Triangle(const double, const std::pair<double, double>);
	virtual ~Triangle();

	void print() const;
	double getArea() override;
};

