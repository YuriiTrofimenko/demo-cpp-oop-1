#include <exception>
#include <string>
#include <iostream>

class Point2D {
    // объ€вление закрытого статического пол€ класса, без определени€ вне класса - недействительно (компил€ци€ не будет выполнена)
    // назначение пол€ - счЄтчик созданий экземпл€ров класса (объектов)
    static unsigned int instantinationCount;
    // ещЄ одно статическое поле класса - счЄтчик наличных экземпл€ров
    static unsigned int instanceCount;
    // закрытые пол€ дл€ каждого экземпл€ра (объекта) класса - координаты точки на экране и сведени€ о ее цвете
    unsigned int x;
    unsigned int y;
    char* color;
public:
    // объ€влени€ конструкторов класса
    Point2D();
    Point2D(int x, int y, const char* color);
    Point2D(const Point2D& p);
    // объ€вление деструктора класса
    ~Point2D();
    // статическа€ функци€ класса дл€ получени€ значени€ пол€ instantinationCount
    static unsigned int getInstantinationCount()
    {
        return instantinationCount;
    }
    // объ€вление статической функции класса дл€ получени€ значени€ пол€ instanceCount
    static unsigned int getInstanceCount();
    void setX(int x);
    // функци€ получени€ значени€ пол€ объекта x,
    // в заголовке которой при помощи ключевого слова const дано обещание компил€тору,
    // что в еЄ теле не будет кода, способного изменить значение хот€ бы одного пол€ объекта
    unsigned int getX() const {
        return this->x;
    }
    void setY(int y);
    // функци€ получени€ значени€ пол€ объекта y,
    // в заголовке которой при помощи ключевого слова const дано обещание компил€тору,
    // что в еЄ теле не будет кода, способного изменить значение хот€ бы одного пол€ объекта
    unsigned int getY() const {
        return this->y;
    }
    void setColor(const char* color);
    const char* getColor() const {
        return this->color;
    }
    // объ€вление перегрузки оператора + дл€ объектов класса Point2D
    Point2D operator+(Point2D& p);
private:
    // объ€вление закрытой статической функции приращени€ значений счЄтчиков
    static void increaseCounters();
    // объ€вление закрытой функции проверки допустимости устанавливаемого значени€ координаты x или y
    void validate(int value, char fieldName);
};