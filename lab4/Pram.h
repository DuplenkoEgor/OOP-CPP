#ifndef Pram_h
#define Pram_h
#include <iostream>

class Pram {
private:
    int x1;
    int x2;
    int y1;
    int y2;
    static int count;

    int get_area() const {
        return std::abs(x2 - x1) * std::abs(y1 - y2);
    }

    int get_perim() const {
        return 2 * (std::abs(x2 - x1) + std::abs(y1 - y2));
    }

    int get_intersection_area(const Pram &p) const;

public:
    Pram();
    Pram(int x1, int x2, int y1, int y2);
    Pram(const Pram &other);
    Pram(int x, int y);
    ~Pram();
    
    friend std::ostream& operator<<(std::ostream &out, const Pram &p);
    friend std::istream& operator>>(std::istream &in, Pram &p);
    Pram &operator=(const Pram &other);
    int operator+(const Pram& p2) const;
    int operator-(const Pram& p2) const;
    int operator*(const Pram& p2) const;
    
    void print_info() const;
    void show_pram();
    void get_perim_and_area(int &perim, int &area);
    static int get_count();
    friend bool get_is_overlap(const Pram &p1, const Pram &p2);
    friend bool is_first_area_is_bigger(const Pram &p1, const Pram &p2);
};

#endif