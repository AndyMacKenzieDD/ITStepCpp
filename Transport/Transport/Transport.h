#pragma once
#include<string>

class Transport
{
public:
	Transport();
	virtual ~Transport();
	virtual std::string move() const = 0;
};

