#include "Area.h"

int Area::choise = 0;
int Area::counter = 0;
double Area::side1 = 0; 
double Area::side2 = 0;
double Area::angle = 0;
double Area::height = 0;
double Area::diagonal1 = 0;
double Area::diagonal2 = 0;

double Area::getRectangleArea()
{
	std::cout << "1. Square" << std::endl;
	std::cout << "2. Rectangle" << std::endl;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		std::cout << "Input value: ";
		std::cin >> side1;
		if(checkCorrect(side1)) return getRectangleArea(side1);
		
		
		break;
	}
	case 2:
	{
		std::cout << "Input values: ";
		std::cin >> side1;
		std::cin >> side2;
		if (checkCorrect(side1, side2)) return getRectangleArea(side1, side2);

		break;
	}
	default:
	{
		if (checkCorrect(0))
		break;
	}
	}
	return 0;
}
double Area::getRectangleArea(const double side)//It would be possible to not transfer anything in function at all, as I have a statics fields
{
	counter++;
	return side * side;
	
} 
double Area::getRectangleArea(const double side1, const double side2)
{
	counter++;
	return side1 * side2;
}

double Area::getParallelogramArea()
{
	std::cout << "1. Side and height" << std::endl;
	std::cout << "2. Sides and the angle" << std::endl;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		std::cout << "Input values";
		std::cin >> side1;
		std::cin >> height;
		counter++;
		if (checkCorrect(side1, height)) return getParallelogramArea(side1, height);
		
		break;
	}
	case 2:
	{
		std::cout << "Input values";
		std::cin >> side1;
		std::cin >> side2;
		std::cin >> angle;
		if (checkCorrect(side1, side2, angle)) return getParallelogramArea(side1, side2, angle);
		
		break;
	}
	default:
	{
		if (checkCorrect(0))
		break;
	}
	}
}
double Area::getParallelogramArea(const double side, const double height)
{
	counter++;
	return side * height;
}
double Area::getParallelogramArea(const double side1, const double side2, double angle)
{
	counter++;
	angle = angle * 3.14 / 180;
	return side1 * side2 * sin(angle);
}

double Area::getRhombusArea()
{
	std::cout << "1. Side and angle" << std::endl;
	std::cout << "2. Diagonals" << std::endl;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> side1;
		std::cin >> angle;
		if (checkCorrect(side1, angle)) return getRhombusAreaSideAngle(side1, angle);

		break;
	}
	case 2:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> diagonal1;
		std::cin >> diagonal2;
		counter++;
		if (checkCorrect(diagonal1, diagonal2)) return getRhombusAreaDiagonals(diagonal1, diagonal2);
		
		break;
	}
	default:
	{
		if (checkCorrect(0))
		break;
	}
	}
}
double Area::getRhombusAreaSideAngle(const double side1, double angle)// I know that such methods already exist. But the names are not so =)
{
	counter++;
	angle = angle * 3.14 / 180;
	return side1 * side1 * sin(angle);
} 
double Area::getRhombusAreaDiagonals(const double diagonal1, const double diagonal2)
{
	counter++;
	return diagonal1 * diagonal2 / 2;
}

int Area::getCouter()
{
	return counter;
}

bool Area::checkCorrect(const double a, const double b, const double c)
{
	if (a > 0 && b > 0 && c > 0) return 1;
	else
	{
		std::cout << "Error: Incorrect value" << std::endl;
		return 0;
	}
}