#include "Triangle.h"
#include "Square.h"

void test()
{
	Triangle myTriangle;
	std::cout << myTriangle.getTriangleArea(10,20) << std::endl;
	std::cout << myTriangle.getTriangleAreaSides(10,10,10) << std::endl;
	std::cout << myTriangle.getTriangleAreaAngle(20, 20, 90) << std::endl;
	std::cout << myTriangle.getTriangleArea() << std::endl;

	Square mySquare;
	std::cout << mySquare.getSquareArea(10, 20) << std::endl;
	std::cout << mySquare.getSquareArea(10) << std::endl;
	std::cout << mySquare.getSquareArea() << std::endl;
}

int main()
{
	test();

	return 0;
}