//Rectangle.h

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() : x1(1), y1(2), x2(3), y2(1) {
    cout << "[конструктор за замовчуванням]" << endl;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2) {
    bool ok = x1 > 0 && y1 > 0 && x2 > 0 && y2 > 0 && x1 < x2 && y1 > y2;
    if (ok) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    } else {
        cout << "Некоректні координати, встановлено значення за замовчуванням" << endl;
        this->x1 = 1;
        this->x2 = 3;
        this->y1 = 2;
        this->y2 = 1;
    }
    cout << "[конструктор з параметрами]" << endl;
}

Rectangle::Rectangle(int x, int y, int side)
    : Rectangle(x, y, x + side, y - side) {
    cout << "[делегуючий конструктор (квадрат)]" << endl;
}

Rectangle::Rectangle(const Rectangle& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {
    cout << "[конструктор копіювання]" << endl;
}

Rectangle::Rectangle(int x, int y) {
        // : x1(x), y1(y), x2(x), y2(y)  
    this->x1 = x;
    this->y1 = x;
    this->x2 = y;
    this->y2 = y;
    cout << "[Діагональний конструктор]" << endl;
}


Rectangle::~Rectangle() {
    cout << "[деструктор]" << endl;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        x1 = other.x1;
        x2 = other.x2;
        y1 = other.y1;
        y2 = other.y2;
    }
    cout << "[оператор присвоєння]" << endl;
    return *this;
}

ostream& operator<<(ostream& out, const Rectangle& r) {
    out << "A(" << r.x1 << "," << r.y1 << ") B(" << r.x2 << "," << r.y2 << ")";
    return out;
}

istream& operator>>(istream& in, Rectangle& r) {
    int a, b, c, d;
    cout << "Введіть x1 y1 x2 y2: ";
    in >> a >> b >> c >> d;
    r = Rectangle(a, b, c, d);   // перевірка координат вже є в конструкторі
    return in;
}