#pragma once
#include<iostream>
class Area
{
	static int counter; //It would be possible not to make as many variables. I did it so that I would not be confused in the title and that wherever we are
	static int choise;
	static double side1;
	static double side2;
	static double height;
	static double angle;
	static double diagonal1;
	static double diagonal2;
	static bool checkCorrect(const double, const double = 0, const double = 0); //All checks for correct input made in one private method
public:
	Area() {};
	~Area() {};
	static double getRectangleArea();
	static double getRectangleArea(const double);
	static double getRectangleArea(const double, const double);

	static double getParallelogramArea();
	static double getParallelogramArea(const double, const double);
	static double getParallelogramArea(const double, const double, double);

	static double getRhombusArea();
	static double getRhombusAreaSideAngle(const double, double); //Название: На что хватило фантазии =_=
	static double getRhombusAreaDiagonals(const double, const double);

	static int getCouter();

	
};
