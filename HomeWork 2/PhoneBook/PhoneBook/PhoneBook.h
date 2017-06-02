#pragma once
#include "Contact.h"
#include <array>

class PhoneBook
{
	std::string name;
	std::string homePhone;
	std::string mobilePhone;
	std::array<Contact, 101> contactArr; //на паре обьясню почему 101
	int size;
public:
	PhoneBook();
	void addContact(); //Every method is overloaded. What for? Cz I can
	void addContact(const std::string, const std::string, const std::string);
	void showContact();
	void showContact(const std::string);
	void showAll() const;
	void deleteContact();
	void deleteContact(const std::string);
};
