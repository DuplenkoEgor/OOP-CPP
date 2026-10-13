#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y, z;
};

class Tetrahedron {
private:
    Point v[4];

public:
    // Конструктор
    Tetrahedron() {}

    // Методы для доступа к данным
    Point getVertex(int i) const { return v[i]; }
    void setVertex(int i, const Point &p) { v[i] = p; }

    // Методы для инициализации
    void init(const Point p[4]) {
        for (int i = 0; i < 4; i++) {
            v[i] = p[i];
        }
    }

    // Методы для ввода
    void input() {
        Point p[4];
        for (int i = 0; i < 4; i++) {
            cout << "Vertex " << i + 1 << " (x y z): ";
            cin >> p[i].x >> p[i].y >> p[i].z;
        }

        init(p);
    }

    // Методы для вывода
    void output() const {
        for (int i = 0; i < 4; i++) {
            cout << "(" << v[i].x << ", " << v[i].y << ", " << v[i].z << ")\n";
        }
    }

    // Методы для вычисления площади поверхности
    double surfaceArea() const {
        return triangleArea(v[0], v[1], v[2])
             + triangleArea(v[0], v[1], v[3])
             + triangleArea(v[0], v[2], v[3])
             + triangleArea(v[1], v[2], v[3]);
    }

    // Методы для вычисления объема
    double volume() const {
        double ax = v[1].x - v[0].x, ay = v[1].y - v[0].y, az = v[1].z - v[0].z;
        double bx = v[2].x - v[0].x, by = v[2].y - v[0].y, bz = v[2].z - v[0].z;
        double cx = v[3].x - v[0].x, cy = v[3].y - v[0].y, cz = v[3].z - v[0].z;

        double det = ax * (by * cz - bz * cy)
                   - ay * (bx * cz - bz * cx)
                   + az * (bx * cy - by * cx);
        return fabs(det) / 6;
    }

    // Методы для проверки на правильность
    bool isRegular() const {
        double e = dist(v[0], v[1]);
        return fabs(dist(v[0], v[2]) - e) < EPS
            && fabs(dist(v[0], v[3]) - e) < EPS
            && fabs(dist(v[1], v[2]) - e) < EPS
            && fabs(dist(v[1], v[3]) - e) < EPS
            && fabs(dist(v[2], v[3]) - e) < EPS;
    }

    // Методы для сдвига координат
    void shiftX(double d) {
        for (int i = 0; i < 4; i++) {
            v[i].x += d;
        }
    }

    void shiftY(double d) {
        for (int i = 0; i < 4; i++) {
            v[i].y += d;
        }
    }

    void shiftZ(double d) {
        for (int i = 0; i < 4; i++) {
            v[i].z += d;
        }
    }

    // Методы для сравнения объемов
    int compareVolume(const Tetrahedron &t) const {
        double va = volume();
        double vb = t.volume();
        if (fabs(va - vb) < EPS) return 0;
        if (va < vb) return -1;
        return 1;
    }

    // Методы для преобразования в строку
    char* toPChar() const {
        char *s = new char[300]; // у купі
        sprintf(s, "A(%.2f; %.2f; %.2f) B(%.2f; %.2f; %.2f) C(%.2f; %.2f; %.2f) D(%.2f; %.2f; %.2f)",
                v[0].x, v[0].y, v[0].z,
                v[1].x, v[1].y, v[1].z,
                v[2].x, v[2].y, v[2].z,
                v[3].x, v[3].y, v[3].z);
        return s;
    }
};

const double EPS = 1e-9;

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double triangleArea(const Point &a, const Point &b, const Point &c) {
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ca = dist(c, a);
    double p = (ab + bc + ca) / 2;
    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

int main() {
    Tetrahedron t;
    Point pts[4] = { {0,0,0}, {1,0,0}, {0,1,0}, {0,0,1} };
    t.init(pts);
    t.output();

    cout << "Surface area: " << t.surfaceArea() << endl;
    cout << "Volume: " << t.volume() << endl;
    cout << "Regular: " << t.isRegular() << endl;

    t.shiftX(2);
    t.output();

    Tetrahedron t2 = t;
    t2.shiftZ(5);
    cout << "Compare: " << t2.compareVolume(t) << endl;

    char *s = t.toPChar();
    cout << s << endl;
    delete[] s;

    return 0;
}
