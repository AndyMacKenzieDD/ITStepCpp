#include "Triangle.h"

Triangle::Triangle() : choise(0), side1(0), side2(0), side3(0){}
Triangle::~Triangle(){}

double  Triangle::getTriangleArea()
{
	std::cout << "1. Height, Length" << std::endl;
	std::cout << "2. Only Heights" << std::endl;
	std::cout << "3. Heights and angle" << std::endl;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> side1;
		std::cin >> side2;
		return getTriangleArea(side1, side2);

		break;
	}
	case 2:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> side1;
		std::cin >> side2;
		std::cin >> side3;
		return getTriangleAreaSides(side1, side2, side3);

		break;
	}
	case 3:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> side1;
		std::cin >> side2;
		std::cin >> side3;
		return getTriangleAreaAngle(side1, side2, side3);

		break;
	}
	default:
	{
		std::cout << "Enter correct values" << std::endl;

		break;
	}
	}
}

double Triangle::getTriangleArea(const double height, const double length)
{
	if (height > 0 && length > 0)
	{
		return height * length / 2;
	}
	else
	{
		std::cout << "Error: Incorrect values" << std::endl;
		return 1;
	}
}
double Triangle::getTriangleAreaSides(const double height1, const double height2, const double height3)
{
	if (height1 > 0 && height2 > 0 && height3 > 0)
	{
		double semiper = (height1 + height2 + height3) / 2;
		return sqrt(semiper * (semiper - height1) * (semiper - height2) * (semiper - height3));
		
	}
	else
	{
		std::cout << "Error: Incorrect values" << std::endl;
		exit(1);
	}
}
double Triangle::getTriangleAreaAngle(const double height1, const double height2, const double angle)
{
	if (height1 > 0 && height2 > 0 && angle > 0)
	{
	
		side3 = angle * 3.14 / 180;
		return (height1 * height2 * sin(side3)) / 2;
	}
	else
	{
		std::cout << "Error: Incorrect values" << std::endl;
		exit(1);
	}
}
