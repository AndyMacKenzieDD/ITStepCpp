#pragma once
#include <iostream>
class Complex
{
	double real;
	double img;
	double getModule() const;
public:
	Complex();
	Complex(const double, const double);
	Complex(const Complex&);
	~Complex() = default;
	Complex& operator=(const Complex&);
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);

	Complex& operator++();
	Complex& operator--();
	Complex operator++(int);
	Complex operator--(int);

	friend bool operator==(const Complex&, const Complex&);
	friend bool operator!=(const Complex&, const Complex&);
	friend bool operator>(const Complex&, const Complex&);
	friend bool operator<(const Complex&, const Complex&);
	friend bool operator>=(const Complex&, const Complex&);
	friend bool operator<=(const Complex&, const Complex&);

	friend Complex operator+(const double, const Complex&);
	friend Complex operator+(const Complex&, const double);
	friend Complex operator-(const double, const Complex&);
	friend Complex operator-(const Complex&, const double);
	friend Complex operator*(const double, const Complex&);
	friend Complex operator*(const Complex&, const double);
	friend Complex operator/(const double, const Complex&);
	friend Complex operator/(const Complex&, const double);
	
	void operator()(double, double);

	friend std::ostream& operator<<(std::ostream&, Complex&);

};

