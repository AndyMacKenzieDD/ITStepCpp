#include<iostream>

template<typename T, typename ... Types>
void myPrintf(const char* str, T head, Types ... tail)
{
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == '%')
		{
			std::cout << head;
			myPrintf(str + i + 1, tail...);
			break;
		}
		std::cout << str[i];
	}
}

template<typename T>
void myPrintf(T head)
{
	std::cout << head << std::endl;
}

int main()
{
	myPrintf("Tel: % - % - %", 279, 13, 54);
	myPrintf("Hello, %!", "world");

	myPrintf("User: %\n Surname: %\n Age: %\n Score: %\n", "MyName", "MySurname", 25, 15.119);

	return 0;
}