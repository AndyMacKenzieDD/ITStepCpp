#pragma once
#include "Automobile.h"

class Taxi :
	public Automobile
{
	double fare;
	double totalAmount;
	static unsigned int taxiCounter;
public:
	Taxi();
	Taxi(std::pair <std::string, std::string>, int, double, double, double = 0);
	Taxi(std::string, std::string, int, double, double, double = 0);
	Taxi(double, double = 0);
	~Taxi();

	double getFare() const;
	double getTotalAmount() const;
	double getCurrentPayment(const double);

	void setFare(double);
	void getInfo() const;

	static unsigned int getTaxiCounter();
};

