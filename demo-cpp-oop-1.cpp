#include <iostream>
#include <string>
#include "Point2D.h"
using namespace std;

/* TODO: �������� � ����� ������ ��������� � ��������� �������� ���� name,
���������� ����������� ������ � ���� name (����������� ��������� ��������������) */

/* struct Point2D {
    unsigned int x;
    unsigned int y;
}; */

class Department {
    // private:
        // class members / ����� ������
    int id; // class fields / ���� ������
    string name;
public:
    void setId(int id) // class method / ����� ������
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
    // ������ ������ / object (��������� / instance) ���� Department,
    // � ������� � ���������� d1
    Department d1;
    // �� ������� ���� Department, ���������� � ���������� d1,
    // ������ ����� ��������� �������� � ���� id
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
