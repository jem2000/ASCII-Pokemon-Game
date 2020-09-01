//
// Created by justi on 11/4/2019.
//

#ifndef PA3_VECTOR2D_H
#define PA3_VECTOR2D_H


#include <ostream>

class Vector2D {
public:
    double x, y;
    Vector2D();
    Vector2D(double x, double y);
};


Vector2D operator*(const Vector2D& v1, const double d);

Vector2D operator/(const Vector2D& v1, const double d);

std::ostream& operator<<(std::ostream& os, const Vector2D v1);

#endif //PA3_VECTOR2D_H
