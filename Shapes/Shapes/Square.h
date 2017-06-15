#pragma once
#include<iostream>
class Square
{
	int choise;
	double side1;
	double side2;
public:
	Square();
	~Square();
	double getSquareArea();
	double getSquareArea(const double a);
	double getSquareArea(const double a, const double b);
};

