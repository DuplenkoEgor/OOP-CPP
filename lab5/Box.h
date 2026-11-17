#ifndef Box_h
#define Box_h
#include "Pram.h"

class Box : public Pram {
    protected:
        int height;
        int base_z;
    public:
        Box();
        Box(int base_z, int height);
        Box(int x1, int x2, int y1, int y2, int base_z, int height);
        Box(const Box &other);
        ~Box();

        Box &operator=(const Box &other);
        bool operator==(const Box &other);
        bool operator!=(const Box &other);
        friend std::ostream& operator<<(std::ostream &out, const Box &p);
        Box& operator++();
        Box operator++(int);
        Box& operator--();
        Box operator--(int);
        void show_pram() override;
        int get_area() const;
        int get_volume() const;
        int sum_edges() const;
        double get_cylinder_volume() const;
        void vector_shift(int v_x, int v_y, int v_z);
        friend bool is_first_volume_is_bigger(const Box &b1, const Box &b2);
};

#endif