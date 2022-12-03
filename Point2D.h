#include <exception>
#include <string>

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
    Point2D(Point2D& p);
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
    // ���������� �������� ����������� ������� ���������� �������� ���������
    static void increaseCounters();
    // ���������� �������� ������� �������� ������������ ���������������� �������� ���������� x ��� y
    void validate(int value, char fieldName);
};