#include <iostream>
#include "Box.h"
using namespace std;

int main() {
    Box b(0, 4, 0, 3, 2, 5);

    cout << "Вершини:\n" << b << "\n";

    cout << "Площа поверхні: " << b.get_area() << "\n";
    cout << "Об'єм: " << b.get_volume() << "\n";
    cout << "Сума ребер: " << b.sum_edges() << "\n";
    cout << "Об'єм описаного циліндра: " << b.get_cylinder_volume() << "\n\n";

    Box c = b;
    Box d;
    d = b;
    cout << "Копія і присвоєння однакові з оригіналом\n\n";

    Box moved(10, 14, 20, 23, 7, 5);
    cout << "b == moved: " << (b == moved) << "\n";
    cout << "b != moved: " << (b != moved) << "\n\n";

    b.vector_shift(10, 20, 5);
    cout << "Після зсуву на (10, 20, 5):\n" << b << "\n";

    ++b;
    cout << "Після ++b:\n" << b << "\n";
    --b;
    cout << "Після --b:\n" << b << "\n";

    Box big(0, 10, 0, 10, 0, 10);
    cout << "Об'єм big більший за b: " << is_first_volume_is_bigger(big, b) << "\n";

    Pram *p = &b;
    p->show_pram();

    return 0;
}