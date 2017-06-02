#pragma once
#include<string>
#include<iostream>

class PrettyPrint
{
public:
	PrettyPrint();
	static std::string concatenate(const std::string&, const std::string&);
	static std::string reverseString(const std::string&);
	static std::string replace(const std::string&);
};

