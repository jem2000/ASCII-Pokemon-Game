//
// Created by justi on 11/4/2019.
//

#include "Point2D.h"
#include <cmath>
#include "Vector2D.h"

using namespace std;

Point2D::Point2D()
{
    x = 0;
    y = 0;
}


Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double distance;
    distance = sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y,2));
    return distance;
}

Point2D operator+(const Point2D p1, const Vector2D v1)
{
    Point2D pt;
    pt.x = p1.x + v1.x;
    pt.y = p1.y + v1.y;
    return pt;
}

Vector2D operator-(const Point2D p1, const Point2D p2)
{
    Vector2D vec;
    vec.x = p1.x - p2.x;
    vec.y = p1.y - p2.y;
    return vec;
}

ostream& operator<<(ostream& os, const Point2D pt)
{
    os << pt.x << ", " << pt.y;
}


