//Main

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
    Rectangle r1;
    Rectangle r2(2, 8, 7, 3);
    Rectangle r3(r2);
    Rectangle sq(1, 5, 4);
    Rectangle bad(5, 1, 2, 9);

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;
    cout << "sq = " << sq << endl;

    r1 = r2;
    cout << "r1 = " << r1 << endl;

    Rectangle r4;
    // cin >> r4;
    cout << "r4 = " << r4 << endl;


    Rectangle rDiago(10, 20);
    cout << rDiago << endl;    

    return 0; 
}
