#include "Square.h"

Square::Square() : side1(0), side2(0), choise(0)
{
}

Square::~Square()
{
}

double  Square::getSquareArea()
{
	std::cout << "1. One length" << std::endl;
	std::cout << "2. Two lengths" << std::endl;
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> side1;
		if (side1 > 0)
		{
			return getSquareArea(side1);
		}
		else
		{
			std::cout << "Error: Incorrect values" << std::endl;
			exit(1);
		}
		

		break;
	}
	case 2:
	{
		std::cout << "Input values" << std::endl;
		std::cin >> side1;
		std::cin >> side2;
		if (side1 > 0 && side2 > 0)
		{
			if (side1 == side2)
			{
				return getSquareArea(side1);
			}
			else return getSquareArea(side1, side2);
		}
		else
		{
			std::cout << "Error: Incorrect values" << std::endl;
			return 1;
		}

		break;
	}
	default:
	{
		std::cout << "Enter correct values" << std::endl;
		break;

	}
	}
}
double  Square::getSquareArea(const double a)
{
	return a * a;
}
double  Square::getSquareArea(const double a, const double b)
{
	return a * b;
}