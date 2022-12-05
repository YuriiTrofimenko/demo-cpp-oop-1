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

/*
* ����� ������ "������������ ����� �� ���������"
*/
class ImmutablePoint {
    unsigned int x;
    unsigned int y;
public:
    ImmutablePoint(unsigned int x, unsigned int y) : x{ x }, y{ y }
    {
        // this->x = x;
        // this->y = y;
    }
    void print() const {
        cout << "x = " << x << "; y = " << y << endl;
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

    cout << "Point2D instantination count: " << Point2D::getInstantinationCount() << endl;
    cout << "Point2D current instance count: " << Point2D::getInstanceCount() << endl;

    // Point2D* p1Pointer = &p1;
    // p1.x = -100;
    // p1.y = -200;
    // cout << p1.x << "; " << p1.y << endl;
    Point2D p1;
    Point2D p5;
    try {
        
        Point2D p2;
        Point2D p3(300, 400, "red"); // 300, 400, "red" �++ ����������� � �����������

        p1.setX(100);
        p1.setY(200);
        p1.setColor("green");
        // p1.setColor(nullptr); // NULL
        cout << p1.getX() << "; " << p1.getY() << "; " << p1.getColor() << endl;
        cout << p2.getX() << "; " << p2.getY() << "; " << p2.getColor() << endl;
        cout << p3.getX() << "; " << p3.getY() << "; " << p3.getColor() << endl;
        // cout << (* p1Pointer).getX() << "; " << (* p1Pointer).getY() << endl;
        // cout << p1Pointer->getX() << "; " << p1Pointer->getY() << "; " << p1Pointer->getColor() << endl;

        // Point2D p4 = p3;

        /* Point2D p4(p3.getX(), p3.getY(), p3.getColor());
        cout << p4.getX() << "; " << p4.getY() << "; " << p4.getColor() << endl << endl;

        p3.setColor("white");
        cout << p3.getX() << "; " << p3.getY() << "; " << p3.getColor() << endl;
        cout << p4.getX() << "; " << p4.getY() << "; " << p4.getColor() << endl; */

        Point2D p4(p3);
        cout << p4.getX() << "; " << p4.getY() << "; " << p4.getColor() << endl << endl;

        p3.setColor("white");
        cout << p3.getX() << "; " << p3.getY() << "; " << p3.getColor() << endl;
        cout << p4.getX() << "; " << p4.getY() << "; " << p4.getColor() << endl;
        // ���������� �������������� ��������� +
        // (��� ���������� ���������� ����� �������� � ���� Point2D ������ ���� ����������� �����������,
        // ����������� �������� ���� const Point2D& p,
        // ����� ����������� ���� ������� �������������� �������, �� �������� ����������� ����������� ������)
        Point2D p6 = p1 + p2;
        cout << "P6: " << p6.getX() << "; " << p6.getY() << "; " << p6.getColor() << endl;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
    cout << "Point2D instantination count: " << Point2D::getInstantinationCount() << endl;
    cout << "Point2D current instance count: " << Point2D::getInstanceCount() << endl;

    const ImmutablePoint ip1{10, 20};
    ip1.print();

    // cout << "p1's object address: " << &p1 << endl;
    // cout << "p5's object address: " << &p5 << endl;
}
