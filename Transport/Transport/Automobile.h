#pragma once
#include "Transport.h"
#include<iostream>

class Automobile :
	public Transport
{
	std::pair <std::string, std::string> model;
	int	yearOfManufacture;
	double averageSpeed;
public:
	Automobile();
	Automobile(std::pair <std::string, std::string>, int, double);
	Automobile(std::string, std::string, int, double);
	virtual ~Automobile();

	std::pair <std::string, std::string> getModel() const;
	int	getYearOfManufacture() const;
	double getAverageSpeed();
	double computeDistance(const double) const;

	void setModel(const std::pair<std::string, std::string>&);
	void setModel(const std::string, const std::string);
	void setYearOfManufacture(int);
	void setAverageSpeed(double);

	void getInfo() const;

	std::string move() const override;
};

