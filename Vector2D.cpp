//
// Created by justi on 11/4/2019.
//

#include "Vector2D.h"
#include <iostream>

using namespace std;

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

Vector2D operator*(const Vector2D& v1, const double d)
{
    Vector2D pt;
    pt.x = v1.x * d;
    pt.y = v1.y * d;
    return pt;
}

Vector2D operator/(const Vector2D& v1, const double d)
{
    Vector2D pt;
    pt.x = v1.x / d;
    pt.y = v1.y / d;
    return pt;
}

ostream& operator<<(ostream& os, Vector2D v1)
{
    os << "<" << v1.x << ", " << v1.y << ">";
    return os;
}