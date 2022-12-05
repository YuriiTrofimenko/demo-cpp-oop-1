#include <exception>
#include <string>
#include <iostream>

class Point2D {
    // ���������� ��������� ������������ ���� ������, ��� ����������� ��� ������ - ��������������� (���������� �� ����� ���������)
    // ���������� ���� - ������� �������� ����������� ������ (��������)
    static unsigned int instantinationCount;
    // ��� ���� ����������� ���� ������ - ������� �������� �����������
    static unsigned int instanceCount;
    // �������� ���� ��� ������� ���������� (�������) ������ - ���������� ����� �� ������ � �������� � �� �����
    unsigned int x;
    unsigned int y;
    char* color;
public:
    // ���������� ������������� ������
    Point2D();
    Point2D(int x, int y, const char* color);
    Point2D(const Point2D& p);
    // ���������� ����������� ������
    ~Point2D();
    // ����������� ������� ������ ��� ��������� �������� ���� instantinationCount
    static unsigned int getInstantinationCount()
    {
        return instantinationCount;
    }
    // ���������� ����������� ������� ������ ��� ��������� �������� ���� instanceCount
    static unsigned int getInstanceCount();
    void setX(int x);
    // ������� ��������� �������� ���� ������� x,
    // � ��������� ������� ��� ������ ��������� ����� const ���� �������� �����������,
    // ��� � � ���� �� ����� ����, ���������� �������� �������� ���� �� ������ ���� �������
    unsigned int getX() const {
        return this->x;
    }
    void setY(int y);
    // ������� ��������� �������� ���� ������� y,
    // � ��������� ������� ��� ������ ��������� ����� const ���� �������� �����������,
    // ��� � � ���� �� ����� ����, ���������� �������� �������� ���� �� ������ ���� �������
    unsigned int getY() const {
        return this->y;
    }
    void setColor(const char* color);
    const char* getColor() const {
        return this->color;
    }
    // ���������� ���������� ��������� + ��� �������� ������ Point2D
    Point2D operator+(Point2D& p);
private:
    // ���������� �������� ����������� ������� ���������� �������� ���������
    static void increaseCounters();
    // ���������� �������� ������� �������� ������������ ���������������� �������� ���������� x ��� y
    void validate(int value, char fieldName);
};