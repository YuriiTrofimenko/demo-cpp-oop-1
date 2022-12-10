#include "Point2D.h"

using namespace std;

// определение закрытого статического поля класса с явной инициализацией,
// без определения вне класса - недействительно (компиляция не будет выполнена)
unsigned int Point2D::instantinationCount = 0;
unsigned int Point2D::instanceCount = 0;

// определение статической функции класса для получения значения поля instanceCount
unsigned int Point2D::getInstanceCount() {
    return instanceCount;
}

// определение перегрузки оператора + для объектов класса Point2D
Point2D Point2D::operator+(Point2D& p)
{
    // Point2D result(this->getX() + p.getX(), this->getY() + p.getY(), this->getColor());
    // return result;
    return move(Point2D(this->getX() + p.getX(), this->getY() + p.getY(), this->getColor()));
}

/* Point2D Point2D::operator=(Point2D&& p)
{
    p.killColor();
    return *this;
} */

// определение (реализация) закрытой статической функции приращения значений счётчиков
void Point2D::increaseCounters()
{
    instantinationCount++;
    instanceCount++;
}

Point2D::Point2D() : Point2D(0, 0, "black") {
    // при появлении в памяти каждого нового объекта типа Point2D
    // счётчики случаев создания экземпляров и текущего числа экземпляров увеличивают свои значения на единицу
    /* increaseCounters();
    this->setX(0);
    this->setY(0);
    this->color = new char[25];
    this->setColor("black"); */
}

// реализация конструктора со всеми параметрами
Point2D::Point2D(int x, int y, const char* color) {
    increaseCounters();
    this->setX(x);
    this->setY(y);
    this->color = new char[25];
    this->setColor(color);
}

/* Point2D::Point2D(const Point2D& p)
{
    cout << "Copy constructor was called for new object with address: " << this << endl;
    increaseCounters();
    this->setX(p.getX());
    this->setY(p.getY());
    this->color = new char[25];
    this->setColor(p.getColor());
} */

Point2D::Point2D(Point2D&& p) : x{ p.getX() }, y{ p.getY() }
{
    cout << "Move constructor was called for new object with address: " << this << endl;
    this->color = new char[25];
    this->setColor(p.getColor());
    p.killColor();
}

Point2D::~Point2D() {
    // при удалении из памяти каждого объекта типа Point2D счётчик экземпляров уменьшает своё значение на единицу
    instanceCount--;
    delete[] color;
    cout << "deleted object's address: " << this << endl;
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
    /* delete[] color;
    int length = strlen(newColor);
    color = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        color[i] = newColor[i];
    } */
    for (int i = 0; i <= strlen(color); i++)
    {
        color[i] = newColor[i];
    }
}