#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle()
	: length(1), width(2)
{
}

Rectangle::Rectangle(double length, double width)
	: length(length), width(width)
{
}

Rectangle::Rectangle(const Rectangle& r)
	: length(r.length), width(r.width)
{
}

double Rectangle::area() const
{
	return length * width;
}

double Rectangle::perimeter() const
{
	return 2 * length + 2 * width;
}

string Rectangle::toString() const
{
	ostringstream oss;
	oss << "Rectangle: length = " << length << ", width = " << width;
	return oss.str();
}