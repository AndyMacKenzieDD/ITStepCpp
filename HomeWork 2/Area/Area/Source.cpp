#include "Area.h"

void test(double a, double b, bool c)
{
	//Area sq;

	//std::cout << sq.getRectangleArea() << std::endl;
	//std::cout << sq.getParallelogramArea() << std::endl;
	std::cout << Area::getCouter() << std::endl;
	std::cout << Area::getRectangleArea(a) << std::endl;
	std::cout << Area::getRectangleArea(a, b) << std::endl;
	std::cout << Area::getParallelogramArea(a, b) << std::endl;
	std::cout << Area::getParallelogramArea(a, b, b) << std::endl;
	std::cout << Area::getCouter() << std::endl;
}

int main()
{
	test(10, 20, 1);

	return 0;
}
