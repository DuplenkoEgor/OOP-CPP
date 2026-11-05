#include <iostream>
#include "Pram.h"
using namespace std;

int main() {
    Pram a(0, 4, 0, 7);
    int area_a;
    int perim_a;
    a.get_perim_and_area(area_a, perim_a);
    cout << area_a << " " << perim_a << "\n";
    return 0;
}