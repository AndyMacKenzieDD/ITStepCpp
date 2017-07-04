#include "Automobile.h"


Automobile::Automobile() : model({"", ""}), yearOfManufacture(0), averageSpeed(0)
{
}

Automobile::Automobile(std::pair <std::string, std::string> m, int y, double s) : model(m), yearOfManufacture(y), averageSpeed(s)
{
}

Automobile::Automobile(std::string mf, std::string ms, int y, double s) : model({ mf, ms }), yearOfManufacture(y), averageSpeed(s)
{
}

Automobile::~Automobile()
{
}

std::pair <std::string, std::string> Automobile::getModel() const
{
	return model;
}

int	Automobile::getYearOfManufacture() const
{
	return yearOfManufacture;
}

double Automobile::getAverageSpeed()
{
	return averageSpeed;
}

double Automobile::computeDistance(const double time) const
{
	return averageSpeed * time;
}

void Automobile::setModel(const std::pair<std::string, std::string> &m)
{
	model = m;
}

void Automobile::setModel(const std::string mfirst, const std::string msecond)
{
	model.first = mfirst;
	model.second = msecond;
}

void Automobile::setYearOfManufacture(int y)
{
	yearOfManufacture = y;
}

void Automobile::setAverageSpeed(double s)
{
	averageSpeed = s;
}

void Automobile::getInfo() const
{
	std::cout << model.first << " " << model.second << std::endl;
	std::cout << yearOfManufacture << " " << averageSpeed << std::endl;
}

std::string Automobile::move() const
{
	return "Automobile";
}