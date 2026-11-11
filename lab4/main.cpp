#include <iostream>
#include "Pram.h"
using namespace std;

int main() {
    Pram a(0, 0, 4, 4);
    Pram b(2, 1, 6, 3);

    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;

    return 0;
}