#pragma once
#include<iostream>

class Triangle
{
	int choise;
	double side1;
	double side2;
	double side3;

public:
	Triangle();
	~Triangle();
	double getTriangleArea();
	double getTriangleArea(const double height, const double length);
	double getTriangleAreaSides(const double height1, const double height2, const double height3);
	double getTriangleAreaAngle(const double height1, const double height2, const double height3);
};

