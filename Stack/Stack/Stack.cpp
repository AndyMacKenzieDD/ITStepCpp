#include<iostream>
#include "Stack.h"

int main()
{
	Stack<int> a;
	std::cout << std::boolalpha << a.empty() << std::endl;
	std::cout << std::boolalpha << a.size() << std::endl;
	a.push(10);
	std::cout << std::boolalpha << a.empty() << std::endl;
	std::cout << std::boolalpha << a.size() << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		a.push(i);
	}

	Stack<int> b = a;
	Stack<int> c = std::move(b);

	//std::cout << b.pop() << std::endl;

	std::cout << std::boolalpha << (a == c) << std::endl;
	a.pop();
	std::cout << std::boolalpha << (a == c) << std::endl;

	a.print();
	c.print();

	for (int i = 0; i < 11; ++i)
	{
		a.pop();
	}
	a.print();
}