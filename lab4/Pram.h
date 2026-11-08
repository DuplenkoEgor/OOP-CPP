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

    int get_intersection_area(const Pram &p) const {
        int Xmax;
        int Xmin;
        int Ymax;
        int Ymin;
        int IntersectionWidth;
        int IntersectionHeight;

        if (this->x1 > p.x1) {Xmax = this->x1;}
        else {Xmax = p.x1;}
        if (this->x2 < p.x2) {Xmin = this->x2;}
        else {Xmin = p.x2;}
        if (this->y1 > p.y1) {Ymax = this->y1;}
        else {Ymax = p.y1;}
        if (this->y2 < p.y2) {Ymin = this->y2;}
        else {Ymin = p.y2;}
        IntersectionWidth = Xmin - Xmax;
        IntersectionHeight = Ymin - Ymax;

        if (IntersectionWidth < 0) { IntersectionWidth = 0; }
        if (IntersectionHeight < 0) { IntersectionHeight = 0; }
        return IntersectionHeight * IntersectionWidth;
    }

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