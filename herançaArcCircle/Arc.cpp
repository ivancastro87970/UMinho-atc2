#include "Arc.h"

Arc::Arc(float radio, const Point& centre)
    : Circle(radio, centre), angle(180), orientation(0)
{ 
}

float Arc::rotateThrough(float degrees) 
{
    orientation += degrees;
    if (orientation > 360)
        orientation -= 360;
    else if (orientation < -360)
        orientation += 360;
    return orientation;
}

float Arc::changeAngle(float delta_degrees) 
{
    float new_angle = angle + delta_degrees;
    if (new_angle > 5 && new_angle < 360) 
    {// ensure a minimum of 5 degrees and maximum of 360
        angle = new_angle;
    }
    return angle;
}

float Arc::perimeter() const 
{
    return 2 * 3.14 * angle / 360 * Circle::size();
}

float Arc::area() const 
{
    float radio = Circle::size();
    return 3.14 * angle / 360 * radio * radio;
}