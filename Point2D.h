//
// Created by justi on 11/4/2019.
//

#ifndef PA3_POINT2D_H
#define PA3_POINT2D_H
#include "Vector2D.h"
#include <iostream>
class Point2D {
public:
    double x, y;
    Point2D();
    Point2D(double x, double y);
};

double GetDistanceBetween(Point2D p1, Point2D p2);

Point2D operator+(Point2D p1, Vector2D v1);

Vector2D operator-(Point2D p1, Point2D p2);

std::ostream& operator<<(std::ostream& os, Point2D pt);


#endif //PA3_POINT2D_H
