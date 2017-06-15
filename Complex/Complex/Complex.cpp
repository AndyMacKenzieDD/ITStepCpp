#include "Complex.h"
#include <cmath>

Complex::Complex() : real(0), img(0)
{
}

Complex::Complex(const Complex& obj) : real(obj.real), img(obj.img)
{
}

Complex::Complex(const double r, const double i) : real(r), img(i)
{
}

Complex& Complex::operator=(const Complex& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	real = obj.real;
	img = obj.img;

	return *this;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex((c1.real + c2.real), (c1.img + c2.img));
}

Complex operator-(const Complex& c1, const Complex& c2)
{
	return Complex((c1.real - c2.real), (c1.img - c2.img));
}

Complex operator*(const Complex& c1, const Complex& c2)
{
	return Complex((c1.real * c2.real - c1.img * c2.img), (c1.real * c2.img + c1.img * c2.real));
}

Complex operator/(const Complex& c1, const Complex& c2)
{
	return Complex((c1.real * c2.real + c1.img * c2.img) / (c2.real * c2.real + c2.img * c2.img), (c2.real * c1.img - c2.img * c1.real) / (c2.real * c2.real + c2.img *  c2.img));
}

std::ostream& operator<<(std::ostream& os, Complex& obj)
{
	if (obj.img >= 0)
	{
		os << obj.real << "+" << obj.img << "i" << std::endl;
	}
	else
	{
		os << obj.real << obj.img << "i" << std::endl;
	}
	return os;
}

Complex& Complex::operator+=(const Complex& c)
{
	real += c.real;
	img += c.img;
	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	real -= c.real;
	img -= c.img;
	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	double tmp = real;
	real = real * c.real - img * c.img;
	img = tmp * c.img + img * c.real;
	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	double tmp = real;
	real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
	img = (c.real * img - c.img * tmp) / (c.real * c.real + c.img *  c.img);
	return *this;
}

Complex& Complex::operator++()
{
	++real;
	return *this;
}

Complex& Complex::operator--()
{
	--real;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex tmp = *this;
	++real;
	return tmp;
}
Complex Complex::operator--(int)
{
	Complex tmp = *this;
	--real;
	return tmp;
}

void Complex::operator()(double r, double i)
{
	real = r;
	img = i;
}

double Complex::getModule() const
{
	return sqrt(pow(real, 2) + pow(img, 2));
}

bool operator==(const Complex& c1, const Complex& c2)
{
	return c1.getModule() == c2.getModule();
}
bool operator!=(const Complex& c1, const Complex& c2)
{
	return c1.getModule() != c2.getModule();
}
bool operator>(const Complex& c1, const Complex& c2)
{
	return c1.getModule() > c2.getModule();
}
bool operator<(const Complex& c1, const Complex& c2)
{
	return c1.getModule() < c2.getModule();
}
bool operator>=(const Complex& c1, const Complex& c2)
{
	return c1.getModule() >= c2.getModule();
}
bool operator<=(const Complex& c1, const Complex& c2)
{
	return c1.getModule() <= c2.getModule();
}

Complex operator+(const double val, const Complex& c)
{
	return Complex((val + c.real), c.img);
}
Complex operator+(const Complex& c, const double val)
{
	return Complex((val + c.real), c.img);
}
Complex operator-(const double val, const Complex& c)
{
	return Complex((val - c.real), c.img);
}
Complex operator-(const Complex& c, const double val)
{
	return Complex((c.real - val), c.img);
}
Complex operator*(const double val, const Complex& c)
{
	return Complex((c.real * val), c.img);
}
Complex operator*(const Complex& c, const double val)
{
	return Complex((c.real * val), c.img);
}
Complex operator/(const double val, const Complex& c)
{
	return Complex((val / c.real), c.img);
}
Complex operator/(const Complex& c, const double val)
{
	return Complex((c.real / val), c.img);
}