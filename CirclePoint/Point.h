#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;


struct FloatXY {
    float x;
    float y;
};

enum class Quadrant {
    Q1, Q2, Q3, Q4
};


class Point {
    float x;
    float y;
public:
    static const Point ORIGIN;

    Point(float x, float y);
    FloatXY displacementFrom(const Point& p) const;
    float distanceTo(const Point& p) const;
    FloatXY move(FloatXY displacement);
    Quadrant quadrant() const;
    string quadrantStr() const;
};

#endif // PONTO_H
