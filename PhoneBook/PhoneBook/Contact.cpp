#include "Contact.h"

Contact::Contact() : name(""), homePhone(""), mobilePhone("")
{

}
Contact::Contact(std::string newName, std::string newHomePhone, std::string newMobilePhone) : name(newName), homePhone(newHomePhone), mobilePhone(newMobilePhone)
{
}

Contact::~Contact()
{
}

std::string Contact::getName() const
{
	return name;
}
std::string Contact::getHomePhone() const
{
	return homePhone;
}
std::string Contact::getMobilePhone() const
{
	return mobilePhone;
}