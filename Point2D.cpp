#include "Point2D.h"
#include <string.h>
using namespace std;

Point2D::Point2D() {
    this->setX(0);
    this->setY(0);
    this->setColor("black");
}

Point2D::~Point2D() {
    delete[] color;
}

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

void Point2D::setColor(const char* newColor) {
    if (newColor == nullptr)
    {
        throw exception("null pointer exception");
    }
    delete[] color;
    int length = strlen(newColor);
    color = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        color[i] = newColor[i];
    }
}