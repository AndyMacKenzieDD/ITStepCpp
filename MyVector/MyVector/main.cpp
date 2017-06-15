#include "MyVector.h"
#include <iostream>

void test()
{
	int *arr = new int[33];
	for(int i = 0; i < 33; ++i)
	{
		arr[i] = i;
	}

	MyVector<int>a(arr, 33);
	std::cout << a.get_capacity() << std::endl;

	MyVector<int> b = std::move(a);
	b.print();
	std::cout << b.get_max() << std::endl;
	std::cout << b.get_min() << std::endl;
	MyVector<int> c;
	c = std::move(b);
	c.print();
	b.print();
	std::cout << std::boolalpha << (c != b) << std::endl;
	std::cout << c[2] << std::endl;
	//c.clear();
	c.print();
	c.reserve(10);
	c.print();
	//std::cout << c[11] << std::endl;

	int arr1[4] = { 1, 2, 4 };
	int arr2[3] = { 1, 2, 4 };
	MyVector<int> first(arr1, 3);
	MyVector<int> second(arr2, 3);
	std::cout << std::boolalpha << (first <= second) << std::endl;
	
	first.clear();
	for (int i = 0; i < 40; ++i)
	{
		first.insert(i, 0);
	}
	
	first.print();
	first.insert(99, 10);
	first.print();
	first.resize(10);
	first.resize(20, 50);
	first.print();

}

int main(int argc, char* argv[])
{
	test();


	return 0;
}
