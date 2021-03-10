#pragma once
#include <string>
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle
{
public:
	Square();
	Square(double side);
	Square(const Square& r);

	string toString() const;
};