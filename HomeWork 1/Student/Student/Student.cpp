#include "Student.h"

Student::Student(const std::string newFisrstName, const std::string newSecondName, const std::string newPatronymic, const std::string newCity, const std::string newUniversity, const int newYearOfBirth, const std::string newPhone, const std::string newGroupNumber) :
	 city(newCity), university(newUniversity), yearOfBirth(newYearOfBirth), phone(newPhone), groupNumber(newGroupNumber) 
{
	fullName.firstName = newFisrstName;
	fullName.secondName = newSecondName;
	fullName.patronymic = newPatronymic;
}

StudentName Student::getName() const
{
	return fullName;
}
std::string Student::getCity() const
{
	return city;
}
std::string Student::getUniversity() const
{
	return university;
}
const int Student::getYearOfBirth() const
{
	return yearOfBirth;
}
std::string Student::getPhone() const
{
	return phone;
}
std::string Student::getGroupNumber() const
{
	return groupNumber;
}
void Student::printStudentInfo() const
{
	std::cout << "Name: ";
	std::cout << fullName.secondName << " " << fullName.firstName << " " << fullName.patronymic<< std::endl;
	std::cout << "Year of birth: ";	std::cout << yearOfBirth << std::endl;
	std::cout << "Phone: ";
	std::cout << phone << std::endl;
	std::cout << "City: ";
	std::cout << city << std::endl;
	std::cout << "University: ";
	std::cout << university << std::endl;
	std::cout << "Group number: ";
	std::cout << groupNumber << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}


void Student::setName(const std::string newFirstName, const std::string newSecondName, const std::string newPatronymic)
{
	fullName.firstName = newFirstName;
	fullName.secondName = newSecondName;
	fullName.patronymic = newPatronymic;
}
void Student::setCity(const std::string newCity)
{
	city = newCity;
}
void Student::setUniversity(const std::string newUniversity)
{
	university = newUniversity;
}
void Student::setPhone(const std::string newPhone)
{
	phone = newPhone;
}
void Student::setGroupNumber(const std::string newGroup)
{
	groupNumber = newGroup;
}
void Student::setInfo()
{
	std::cout << "First name: ";
	std::cin >> fullName.firstName;
	std::cout << "Second name: ";
	std::cin >> fullName.secondName;
	std::cout << "patronymic: ";
	std::cin >> fullName.patronymic;
	std::cout << "Year of birth: ";
	std::cout << "Phone: ";
	std::cin >> phone;
	std::cout << "City: ";
	std::cin >> city;
	std::cout << "University: ";
	std::cin >> university;
	std::cout << "Group number: ";
	std::cin >> groupNumber;
}