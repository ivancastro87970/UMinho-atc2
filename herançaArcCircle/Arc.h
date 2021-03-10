#pragma once
#include "Circle.h"

class Arc : public Circle 
{
    float angle;
    float orientation;
public:
    Arc(float radio, const Point& centre = Point::ORIGIN);
    float rotateThrough(float degrees);
    float changeAngle(float delta_degrees);
    float perimeter() const;
    float area() const;
};