#include <iostream>
using namespace std;

// Класс Point
class Point {
private:
    double x, y;

public:
    // Конструктор
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Методы для доступа к данным
    double getX() const { return x; }
    double getY() const { return y; }

    // Методы для установки значений
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    // Метод для вывода координат
    void print() const {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }

    // Функция инициализации
    void init(double x, double y) {
        this->x = x;
        this->y = y;
    }

    // Функция ввода
    void input() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    // Функция вывода
    void output() const {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p;
    p.input();
    p.output();

    return 0;
}
