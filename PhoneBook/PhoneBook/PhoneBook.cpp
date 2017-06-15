#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook() :name(""), homePhone(""), mobilePhone(""), size(0)
{

}

void  PhoneBook::addContact()
{
	contactArr[size] = Contact();
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter homePhone: ";
	std::cin >> homePhone;
	std::cout << "Enter mobilePhone: ";
	std::cin >> mobilePhone;
	if (size == 99)
	{
		std::cout << "Phone book is overflow" << std::endl;
		exit(1);
	}
	contactArr[size] = Contact(name, homePhone, mobilePhone);
	size++;
}

void PhoneBook::addContact(const std::string name, const std::string homePhone, const std::string mobilePhone)
{
	if (size == 99)
	{
		std::cout << "Phone book is overflow" << std::endl;
		exit(1);
	}
	contactArr[size] = Contact(name, homePhone, mobilePhone);
	size++;
}

void  PhoneBook::showContact()
{
	std::cout << "Enter name: ";
	std::cin >> name;
	showContact(name);
}

void PhoneBook::showContact(const std::string newName)
{
	
	bool isFind = 0;
	for (int i = 0; i < size; i++)
	{
		if (contactArr[i].getName() == newName)
		{
			isFind = 1;
			std::cout << contactArr[i].getName() << " " << contactArr[i].getHomePhone() << " " << contactArr[i].getMobilePhone() << std::endl;
		}
	}
	if (!isFind)
	{
		std::cout << "Contact not found" << std::endl;
	}
}

void PhoneBook::showAll() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << contactArr[i].getName() << " " << contactArr[i].getHomePhone() << " " << contactArr[i].getMobilePhone() << std::endl;
	}
}

void PhoneBook::deleteContact()
{
	std::cout << "Enter name: ";
	std::cin >> name;
	deleteContact(name);
}


void PhoneBook::deleteContact(const std::string newName)
{
	bool isFind = 0;
	for (int i = 0; i < size; i++)
	{
		if (contactArr[i].getName() == newName)
		{
			isFind = 1;
			size--;
		}
		if (isFind)
		{
			contactArr[i] = contactArr[i + 1];
		}
	}
	if (!isFind)
	{
		std::cout << "Contact not found" << std::endl;
	}
}