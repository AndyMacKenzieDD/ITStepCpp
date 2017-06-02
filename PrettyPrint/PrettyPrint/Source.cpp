#include "PrettyPrint.h"


void test()
{
	PrettyPrint pp;
	std::cout << pp.concatenate("Hello", "World") << std::endl;
	std::cout << pp.reverseString("My Name Is Andy") << std::endl;
	std::cout << pp.replace("Моё имя Андрей") << std::endl;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	test();
	return 0;
}