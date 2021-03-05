#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>

#include "Point.h"

class Circle {
    Point center;
    float radio;
public:
    Circle(float radio, const Point& center = Point::ORIGIN);
    Circle(float radio, float x, float y);
    float perimeter() const;
    float area() const;
    FloatXY move(FloatXY displacement);
    float resize(float zoom);
    bool contains(const Point& p) const;
    float perimetersDistance(const Circle& c) const;
    FloatXY position() const;
    float size() const;
    Quadrant quadrant() const;
    string quadrantStr() const;
};

#endif // CIRCLE_H
