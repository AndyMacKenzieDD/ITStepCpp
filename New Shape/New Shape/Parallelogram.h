#pragma once
#include "Shape.h"

class Parallelogram :
	public Shape
{
	double size1;
	double size2;
	double angle;
public:
	Parallelogram(const double, const double, const double);
	virtual ~Parallelogram();

	virtual double getArea() override;
	virtual double getSize1() const;
	virtual double getSize2() const;

	double getAngle() const;
};

