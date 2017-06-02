#include "PrettyPrint.h"

PrettyPrint::PrettyPrint()
{

}

std::string PrettyPrint::concatenate(const std::string& firstString, const std::string& secondString)
{
	return firstString + "." + secondString;
}

std::string PrettyPrint::reverseString(const std::string& str)
{
	std::string newString = "";
	for (int i = str.size() - 1; i >= 0; --i) 
	{
		newString += str[i]; 
	}
	return newString;
}

std::string PrettyPrint::replace(const std::string& str)
{
	std::string newStr = str;
	for (std::string::iterator it = newStr.begin(); it != newStr.end(); ++it)
	{
		if (*it == 'a')
		{
			*it = 'o';
		}
		else if (*it == 'A')
		{
			*it = 'O';
		}
		else if (*it == 'à')
		{
			*it = 'î';
		}
		else if (*it == 'À')
		{
			*it = 'Î';
		}
		
	}
	return newStr;
}
