#include <iostream>
#include "Pram.h"
using namespace std;

int main() {
    Pram a;
    Pram b(2, 8, 6, 3);
    Pram c(b);
    a = b;

    Pram d;
    cin >> d;                    
    cout << d << endl;           

    b.print_info();
    cout << "Площа: " << b.get_area() << endl;
    cout << "Периметр: " << b.get_perim() << endl;
    b.show_pram();

    cout << "Площа більша: " << is_first_area_is_bigger(b, a) << endl;
    cout << "Збігаються при перенесенні: " << get_is_overlap(b, c) << endl;
    cout << "Кількість об'єктів: " << Pram::get_count() << endl;

    return 0;
}