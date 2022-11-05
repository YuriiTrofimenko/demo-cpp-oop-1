#include <iostream>
#include <string>
#include "Point2D.h"
using namespace std;

/* TODO: добавить в класс методы получени€ и установки значени€ пол€ name,
ограничьте возможность записи в поле name (ограничени€ придумать самосто€тельно) */

/* struct Point2D {
    unsigned int x;
    unsigned int y;
}; */

class Department {
    // private:
        // class members / члены класса
    int id; // class fields / пол€ класса
    string name;
public:
    void setId(int id) // class method / метод класса
    {
        if (id <= 0 || id >= 1000000)
        {
            throw exception("Validation error: id must be greather than 0 and less than 1000000");
        }
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
};

int main()
{
    // создан объект / object (экземпл€р / instance) типа Department,
    // и записан в переменную d1
    Department d1;
    // на объекте типа Department, хран€щемс€ в переменной d1,
    // вызван метод установки значени€ в поле id
    // d1.setId(-100);
    // d1.setId(100);
    
    /* int id;
    cout << "Input id (greather than 0 and less than 1000000): " << endl;
    cin >> id;
    try {
        d1.setId(id);
        cout << d1.getId() << endl;
    }
    catch (exception ex) {
        cerr << ex.what() << endl;
    } */

    /* int x = 100;
    int y = 200;
    int z = 250; */

    Point2D p1;
    // p1.x = -100;
    // p1.y = -200;
    // cout << p1.x << "; " << p1.y << endl;
    try {
        p1.setX(100);
        p1.setY(-200);
        cout << p1.getX() << "; " << p1.getY() << endl;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
}
