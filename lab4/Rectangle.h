//Rectangle.h

#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>

class Rectangle {
private:
    int x1, y1;
    int x2, y2;
    
public:
    Rectangle();
    Rectangle(int x, int y);
    Rectangle(int x1, int y1, int x2, int y2);
    Rectangle(int x, int y, int side);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    Rectangle& operator=(const Rectangle& other);

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
    friend std::istream& operator>>(std::istream& in, Rectangle& r); 
};

#endif