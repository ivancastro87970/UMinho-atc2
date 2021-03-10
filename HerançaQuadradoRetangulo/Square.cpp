#include "Square.h"
#include <sstream>

Square::Square()
	: Rectangle(1, 1)
{
}

Square::Square(double side)
	: Rectangle(side, side)
{
}

Square::Square(const Square& s)
	: Rectangle(s)
{
}

string Square::toString() const
{
	ostringstream oss;
	oss << "Square: size = " << length;
	return oss.str();
}