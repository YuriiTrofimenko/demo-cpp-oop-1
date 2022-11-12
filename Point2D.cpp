#include "Point2D.h"

using namespace std;

// реализация конструктора без параметров
Point2D::Point2D() {
    this->setX(0);
    this->setY(0);
    this->setColor("black");
}

// реализация конструктора со всеми параметрами
Point2D::Point2D(int x, int y, const char* color) {
    this->setX(x);
    this->setY(y);
    this->setColor(color);
}

Point2D::~Point2D() {
    delete[] color;
}

void Point2D::validate(int value, char fieldName)
{
    if (value < 0)
    {
        // throw exception("value of the field "s + fieldName + " must be greather or equals 0"s);
        // TODO в конец строки сообщения об ошибке вставлять значение value, не прошедшее валидацию
        // подсказка: длину строки можно измерить алгоритмом или готовой функцией, и задать такую размерность массиву m;
        // чтобы иметь возможность задать неизвестную заранее длину при создании массива m, создайте его динамическим
        const char* message = "value of the field   must be greather or equals 0, not ";
        char m[50];
        for (int i = 0; i < 50; i++)
        {
            m[i] = message[i];
        }
        m[19] = fieldName;
        throw exception(m);
    }
}

void Point2D::setX(int x) {
    validate(x, 'x');
    this->x = x;
}

void Point2D::setY(int y) {
    validate(y, 'y');
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