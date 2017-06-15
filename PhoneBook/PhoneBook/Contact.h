#pragma once
#include <string>
class Contact
{
	std::string name;
	std::string homePhone;
	std::string mobilePhone;
public:
	Contact();
	Contact(std::string, std::string, std::string);
	~Contact();
	std::string getName() const;
	std::string getHomePhone() const;
	std::string getMobilePhone() const;

};

