#include "Point2D.h"
using namespace std;

void Point2D::validate(int value)
{
    if (value < 0)
    {
        throw exception("value must be greather or equals 0");
    }
}

void Point2D::setX(int x) {
    validate(x);
    this->x = x;
}

void Point2D::setY(int y) {
    validate(y);
    this->y = y;
}