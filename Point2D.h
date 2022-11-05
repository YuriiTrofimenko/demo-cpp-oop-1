#include <exception>

class Point2D {
    unsigned int x;// = 0;
    unsigned int y;// = 0;
    char* color;
public:
    Point2D();
    ~Point2D();
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
    void validate(int value);
};