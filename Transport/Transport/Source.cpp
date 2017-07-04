#include<iostream>
#include "Automobile.h"
#include "Taxi.h"

int main()
{
	Automobile car({"Volkswagen", "Golf"}, 1994, 110);

	std::cout << car.getModel().first << std::endl;
	std::cout << car.getModel().second << std::endl;
	std::cout << car.getYearOfManufacture() << std::endl;
	std::cout << car.getAverageSpeed() << std::endl;
	std::cout << car.move() << std::endl;
	std::cout << car.computeDistance(0.5) << std::endl;
	car.getInfo();
	std::cout << std::endl;

	Taxi taxi({ "Mazda", "RX-8" }, 2004, 160, 5);

	std::cout << taxi.getModel().first << std::endl;
	std::cout << taxi.getModel().second << std::endl;
	std::cout << taxi.getYearOfManufacture() << std::endl;
	std::cout << taxi.getAverageSpeed() << std::endl;
	std::cout << taxi.move() << std::endl;
	std::cout << taxi.computeDistance(0.5) << std::endl;
	std::cout << taxi.getFare() << std::endl;
	std::cout << taxi.getCurrentPayment(1) << std::endl;
	std::cout << taxi.getCurrentPayment(0.6) << std::endl;
	std::cout << taxi.getTotalAmount() << std::endl;
	std::cout << Taxi::getTaxiCounter() << std::endl;
	taxi.getInfo();
	std::cout << std::endl;

	return 0;
}