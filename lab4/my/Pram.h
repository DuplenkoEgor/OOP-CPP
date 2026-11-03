#ifndef Pram_h
#define Pram_h
#include <iostream>

struct Pram_metric
{
    int area;
    int perim;
};


class Pram {
private:
    int x1;
    int x2;
    int y1;
    int y2;
    static int count;

public:
    Pram();
    Pram(int x1, int x2, int y1, int y2);
    Pram(const Pram &other);
    ~Pram();
    
    friend std::ostream& operator<<(std::ostream &out, const Pram &p);
    friend std::istream& operator>>(std::istream &in, Pram &p);
    Pram &operator=(const Pram &other);

    void print_info() const;
    void show_pram();
    int get_area() const;
    int get_perim() const;
    static int get_count();
    friend bool get_is_overlap(const Pram &p1, const Pram &p2);
    friend bool is_first_area_is_bigger(const Pram &p1, const Pram &p2);
};

#endif