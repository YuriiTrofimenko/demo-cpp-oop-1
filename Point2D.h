#include <exception>
#include <string>

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
    Point2D(Point2D& p);
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
    unsigned int getX() {
        return this->x;
    }
    void setY(int y);
    unsigned int getY() {
        return this->y;
    }
    void setColor(const char* color);
    const char* getColor() {
        return this->color;
    }
private:
    // объ€вление закрытой статической функции приращени€ значений счЄтчиков
    static void increaseCounters();
    // объ€вление закрытой функции проверки допустимости устанавливаемого значени€ координаты x или y
    void validate(int value, char fieldName);
};