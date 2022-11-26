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

        // приведение типа переменной value к строке
        string valueString = to_string(value);
        // шаблон сообщения об ошибке с пустой позицией под индексом 19 для "вклеивания" имени поля,
        // попытка проинициализировать которое провалилась (x или y)
        const char* message = "value of the field   must be greather or equals 0, not ";
        // всегда заранее известная длина шаблона
        const int messageTemplateLength = strlen(message);
        // явное приведение типа строки valueString к const char*
        // и вычисление длины этой строки
        int valueStringLength = strlen(valueString.c_str());
        // char m[50];
        // вычисление суммарной длины строки сообщения об ошибке,
        // где 1 - увеличение длины массива, чтобы затем в последнюю дополнительную позицию
        // записать символ окончания строки \0
        int messageLength = messageTemplateLength + valueStringLength + 1;
        // создание массива, в который будут записаны все символы сообщения об ошибке
        // (память для него выделяем динамически, с помощью слова new, потому что длину этого массива можно узнать
        // только во время выполнения программы, когда произойдёт ошибка валидации значения value)
        char* m = new char[messageLength];
        // запись в выходную строку всех символов шаблона
        for (int i = 0; i < messageTemplateLength; i++)
        {
            m[i] = message[i];
        }
        // подстановка в шаблон имени поля, значение для которого не прошло валидацию
        m[19] = fieldName;
        // добавление в конец массива сообщения об ошибке символов из строки,
        // отображающей значение, не прошедшее проверку
        for (int i = messageTemplateLength; i < messageLength - 1; i++)
        {
            m[i] = valueString[i - messageTemplateLength];
        }
        // записать символ окончания строки \0
        m[messageLength - 1] = '\0';
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