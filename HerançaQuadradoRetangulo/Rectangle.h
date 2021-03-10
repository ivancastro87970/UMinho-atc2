#pragma once
#include <string>

using namespace std;

class Rectangle
{
protected:
	double length;
	double width;

public:
	Rectangle();
	Rectangle(double length, double width);
	Rectangle(const Rectangle& r);

	double area() const;
	double perimeter() const;

	string toString() const;
}