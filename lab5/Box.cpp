#include "Box.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <algorithm>

Box::Box() : Pram() {
    this->base_z = 0;
    this->height = 1;
}

Box::Box(int base_z, int height) : Pram() {
    this->base_z = base_z;
    this->height = height;
}

Box::Box(int x1, int x2, int y1, int y2, int base_z, int height) : Pram(x1, x2, y1, y2){
    this->base_z = base_z;
    this->height = height;
}

Box::Box(const Box &other) : Pram(other) {
    this->base_z = other.base_z;
    this->height = other.height;
}

Box::~Box() {}

Box& Box::operator=(const Box &other) {
    Pram::operator=(other);
    this->base_z = other.base_z;
    this->height = other.height;
    return *this;
}

bool Box::operator==(const Box &other) {
    return get_width() == other.get_width() && get_depth() == other.get_depth() && height == other.height;
}

bool Box::operator!=(const Box &other) {
    return !((*this) == other);
}

std::ostream& operator<<(std::ostream &out, const Box &b) {
    int z1 = b.base_z;
    int z2 = b.base_z + b.height;

    out << "A(" << b.x1 << ", " << b.y1 << ", " << z1 << ")\n";
    out << "B(" << b.x2 << ", " << b.y1 << ", " << z1 << ")\n";
    out << "C(" << b.x2 << ", " << b.y2 << ", " << z1 << ")\n";
    out << "D(" << b.x1 << ", " << b.y2 << ", " << z1 << ")\n";

    out << "A1(" << b.x1 << ", " << b.y1 << ", " << z2 << ")\n";
    out << "B1(" << b.x2 << ", " << b.y1 << ", " << z2 << ")\n";
    out << "C1(" << b.x2 << ", " << b.y2 << ", " << z2 << ")\n";
    out << "D1(" << b.x1 << ", " << b.y2 << ", " << z2 << ")\n";

    return out;
}

Box& Box::operator++() {      
    vector_shift(1, 1, 1);
    return *this;
}

Box Box::operator++(int) {          
    Box old(*this);                 
    vector_shift(1, 1, 1);
    return old;
}

Box& Box::operator--() {            
    vector_shift(-1, -1, -1);
    return *this;
}

Box Box::operator--(int) {         
    Box old(*this);
    vector_shift(-1, -1, -1);
    return old;
}

int Box::get_area() const {
    return 2 * Pram::get_area() + Pram::get_perim() * height;
}

int Box::get_volume() const {
    return Pram::get_area() * this->height;
}

int Box::sum_edges() const {
    return (get_depth() + get_width() + this->height) * 4;
}

double Box::get_cylinder_volume() const {
    double r = (sqrt(get_width() * get_width() + get_depth() * get_depth())) / 2;
    return M_PI * r * r * this->height;
}

bool is_first_volume_is_bigger(const Box &b1, const Box &b2) {
    return b1.get_volume() >= b2.get_volume();
}

void Box::vector_shift(int v_x, int v_y, int v_z) {
    this->x1 += v_x;
    this->x2 += v_x;
    this->y1 += v_y;
    this->y2 += v_y;
    this->base_z += v_z;
}

void Box::show_pram() {
    const float S = 20.f;  

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Top view");

    sf::RectangleShape rect({get_width() * S, get_depth() * S});
    rect.setPosition({std::min(x1, x2) * S + 100.f,
                      std::min(y1, y2) * S + 100.f});
    rect.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(rect);
        window.display();
    }
}