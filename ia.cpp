#include <iostream>
using namespace std;

// Структура Point
struct Point {
    double x, y;
};

// Класс Point
class PointClass {
private:
    Point p;

public:
    // Конструктор
    PointClass(double x = 0, double y = 0) : p{x, y} {}

    // Методы для доступа к данным
    double getX() const { return p.x; }
    double getY() const { return p.y; }

    // Методы для установки значений
    void setX(double x) { p.x = x; }
    void setY(double y) { p.y = y; }

    // Метод для вывода координат
    void print() const {
        cout << "Point (" << p.x << ", " << p.y << ")" << endl;
    }

    // Функция инициализации
    void init(double x, double y) {
        p.x = x;
        p.y = y;
    }

    // Функция ввода
    void input() {
        cout << "Enter x: ";
        cin >> p.x;
        cout << "Enter y: ";
        cin >> p.y;
    }

    // Функция вывода
    void output() const {
        cout << "Point (" << p.x << ", " << p.y << ")" << endl;
    }
};

int main() {
    PointClass p;
    p.input();
    p.output();

    return 0;
}
