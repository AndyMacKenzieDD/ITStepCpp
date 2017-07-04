#include<vector>
#include<iostream>
#include<algorithm>

class isEq
{
	int tmp;
public:
	isEq(int x) : tmp(x) {}
	bool operator()(int x)
	{
		return tmp == x;
	}
};

class multiplesOf
{
	int tmp;
public:
	multiplesOf(int x) : tmp(x) {}
	bool operator()(int x)
	{
		return !(x % tmp);
	}
};

class beginning
{
	int tmp;
public:
	beginning(int x) : tmp(x) {}
	bool operator()(int x)
	{
		while (x >= 10)
		{
			x = x / 10;
		}
		return tmp == x;
	}
};

class sqrtOf
{
	int tmp;
public:
	sqrtOf(int x) : tmp(x) {}
	bool operator()(int x)
	{
		return tmp * tmp == x;
	}
};

int main()
{
	std::vector<int> vec = { 12, 16, 10, 25, 5, 567, 13, 8235, 9 };

	std::vector<int>::iterator it = std::find_if(vec.begin(), vec.end(), isEq(5)); //find_if
	std::cout << *it << std::endl;

	int count = std::count_if(vec.begin(), vec.end(), multiplesOf(4)); //count_if
	std::cout << count << std::endl;

	it = std::remove_if(vec.begin(), vec.end(), beginning(1)); //remove_if
	vec.erase(it, vec.end());

	std::replace_if(vec.begin(), vec.end(), sqrtOf(5), 0); //replace_if

	for (auto it : vec)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	return 0;
}