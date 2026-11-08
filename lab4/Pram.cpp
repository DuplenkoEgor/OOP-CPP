#include "Pram.h"
using namespace std;

int Pram::count = 0;

Pram::Pram(){
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = 1;
    this->y2 = 1;
    cout << "Default constructor\n";
    count++;
}

Pram::Pram(int x1, int x2, int y1, int y2) : Pram(){
    if (x1 != x2 && y1 != y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    cout << "Constructor with parameters\n";
}

Pram::Pram(int x, int y) {
    this->x1 = x;
    this->y1= x;
    this->x2 = y;
    this->y2 = y;
    cout << "Constructor with two parameters\n";
}

Pram::Pram(const Pram &other){
    this->x1 = other.x1;
    this->x2 = other.x2;
    this->y1 = other.y1;
    this->y2 = other.y2;
    cout << "Constructor copy\n";
    count++;
}

Pram::~Pram() {
    cout << "Deconstructor\n";
    count--;
}

ostream& operator<<(ostream& out, const Pram& p) {
    out << "A(" << p.x1 << "," << p.y1 << ")" << "B(" << p.x2 << "," << p.y2 << ")\n";
    return out;
}

istream& operator>>(istream& in, Pram& p) {
    int user_x1, user_x2;
    int user_y1, user_y2;
    cout << "Введіть x1, x2, y1, y2: ";
    in >> user_x1 >> user_x2 >> user_y1 >> user_y2;
    p = Pram(user_x1, user_x2, user_y1, user_y2);
    return in;
}

Pram& Pram::operator=(const Pram &other) {
    this->x1 = other.x1;
    this->x2 = other.x2;
    this->y1 = other.y1;
    this->y2 = other.y2;
    return *this;
}



int Pram::operator+(const Pram &p) const {
    return this->get_area() - this->get_area() - this->get_intersection_area(p);
}

int Pram::operator*(const Pram& p) const {
    return this->get_intersection_area(p);
}

int Pram::operator-(const Pram& p) const {
    return this->get_area() -this->get_intersection_area(p);
}

void Pram::print_info() const {
    cout << "A(" << this->x1 << ", " << this->y1 << ")\n";
    cout << "B(" << this->x2 << ", " << this->y2 << ")\n";
    cout << "Area is: " << this->get_area() << "\n";
}

void Pram::show_pram() { // Graphic in lab 5
    int width = std::abs(this->x2 - this->x1);
    int height = std::abs(this->y1 - this->y2);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
  
int Pram::get_count() {
    return count;
}

bool is_first_area_is_bigger(const Pram &p1, const Pram &p2) {
    return p1.get_area() >= p2.get_area(); 
}

void Pram::get_perim_and_area(int &perim, int &area) {
    perim = this->get_perim();
    area = this->get_area();
}

bool get_is_overlap(const Pram &p1, const Pram &p2) {
    return p1.x2 - p1.x1 == p2.x2 - p2.x1 && p1.y1 - p1.y2 == p2.y1 - p2.y2;
}
