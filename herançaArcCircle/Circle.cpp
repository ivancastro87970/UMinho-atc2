#include "Circle.h"

#include <cmath>
#include <limits>

const float PI = acosf(-1);


Circle::Circle(float radio, const Point& center)
    : center(center) 
{
    this->radio = radio;
}

Circle::Circle(float radio, float x, float y)
//    : Circle(radio, Point(x, y))
//{ }
// ou
    : center(Point(x, y)) 
{
    this->radio = radio;
}

float Circle::perimeter() const 
{
    return 2 * PI * radio;
}

float Circle::area() const 
{
    return PI * powf(radio, 2);
}

FloatXY Circle::move(FloatXY displacement) 
{
    return center.move(displacement);
}

float Circle::resize(float zoom) 
{
    float new_radio = radio * zoom;
    if (new_radio > 0) 
    {
        radio = new_radio;
        return radio;
    }
    return 0;
}

bool Circle::contains(const Point& p) const 
{
    if (center.distanceTo(p) > radio)
        return false;
    return true;
}

float Circle::perimetersDistance(const Circle& c) const 
{
    float cd = center.distanceTo(c.center);
    if (cd > this->radio + c.radio)
        return cd - this->radio - c.radio;
    return std::numeric_limits<float>::lowest();
}

FloatXY Circle::position() const 
{
    return center.displacementFrom(Point::ORIGIN);
}

float Circle::size() const 
{
    return radio;
}

Quadrant Circle::quadrant() const 
{
    return center.quadrant();
}

string Circle::quadrantStr() const 
{
    return center.quadrantStr();
}