#include "Taxi.h"

unsigned int Taxi::taxiCounter = 0;

Taxi::Taxi() : Automobile({ "", "" }, 0, 0), fare(0), totalAmount(0)
{
	++taxiCounter;
}

Taxi::Taxi(std::pair <std::string, std::string> m, int y, double s, double f, double a) : Automobile(m, y, s), fare(f), totalAmount(a)
{
	++taxiCounter;
}

Taxi::Taxi(std::string mf, std::string ms, int y, double s, double f, double a) : Automobile({mf, ms}, y, s), fare(f), totalAmount(a)
{
	++taxiCounter;
}

Taxi::Taxi(double f, double a) : fare(f), totalAmount(a)
{
	++taxiCounter;
}

Taxi::~Taxi()
{
}

double Taxi::getFare() const
{
	return fare;
}

double Taxi::getTotalAmount() const
{
	return totalAmount;
}

double Taxi::getCurrentPayment(const double time)
{
	double res = time * computeDistance(time);
	totalAmount += res;
	return res;
}

void Taxi::setFare(const double f)
{
	fare = f;
}

void Taxi::getInfo() const
{
	Automobile::getInfo();
	std::cout << fare << std::endl;
}

unsigned int Taxi::getTaxiCounter()
{
	return taxiCounter;
}