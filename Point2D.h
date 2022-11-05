#include <exception>

class Point2D {
    unsigned int x;
    unsigned int y;
public:
    void setX(int x);
    unsigned int getX() {
        return this->x;
    }
    void setY(int y);
    unsigned int getY() {
        return this->y;
    }
private:
    void validate(int value);
};