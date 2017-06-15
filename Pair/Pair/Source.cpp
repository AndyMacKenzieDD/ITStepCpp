#include<iostream>
#include<string>
#include "Pair.h"

int main()
{
	Pair<int, double> a(5, 5.2);
	std::cout << a.first() << std::endl;
	std::cout << a.second() << std::endl;

	Pair<int, std::string>b = Pair<int, std::string>::make_pair(6, ":Helo:");
	std::cout << b.first() << std::endl;
	std::cout << b.second() << std::endl;

	Pair<bool, bool> c(true, false);
	std::cout << std::boolalpha << c.first() << std::endl;
	std::cout << std::boolalpha << c.second() << std::endl;

	Pair<bool, bool>d = Pair<bool, bool>::make_pair(false, true);
	std::cout << std::boolalpha << d.first() << std::endl;
	std::cout << std::boolalpha << d.second() << std::endl;


}