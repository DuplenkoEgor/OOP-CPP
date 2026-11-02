#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y, z;
};

struct TetrahedronData {
    Point v[4];
};

class Tetrahedron {
private:
    TetrahedronData object;

public:
    void init(const Point p[4]);
    void input();
    void output();
    char* toPChar();

    void setStruct(const TetrahedronData &d) { object = d; }
    TetrahedronData getStruct() const { return object; }
    void setVertex(int i, const Point &p) { object.v[i] = p; }
    Point getVertex(int i) const { return object.v[i]; }
};

void Tetrahedron::init(const Point p[4]) {
    for (int i = 0; i < 4; i++) {
        object.v[i] = p[i];
    }
}

void Tetrahedron::input() {
    Point p[4];
    for (int i = 0; i < 4; i++) {
        cout << "Vertex " << i + 1 << " (x y z): ";
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    init(p);
}

void Tetrahedron::output() {
    for (int i = 0; i < 4; i++) {
        cout << "(" << object.v[i].x << ", " << object.v[i].y << ", " << object.v[i].z << ")\n";
    }
}

char* Tetrahedron::toPChar() {
    char *s = new char[300];
    sprintf(s, "A(%.2f; %.2f; %.2f) B(%.2f; %.2f; %.2f) C(%.2f; %.2f; %.2f) D(%.2f; %.2f; %.2f)",
            object.v[0].x, object.v[0].y, object.v[0].z,
            object.v[1].x, object.v[1].y, object.v[1].z,
            object.v[2].x, object.v[2].y, object.v[2].z,
            object.v[3].x, object.v[3].y, object.v[3].z);
    return s;
}

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

double surfaceArea(const Tetrahedron &t) {
    Point v0 = t.getVertex(0), v1 = t.getVertex(1);
    Point v2 = t.getVertex(2), v3 = t.getVertex(3);
    return triangleArea(v0, v1, v2)
         + triangleArea(v0, v1, v3)
         + triangleArea(v0, v2, v3)
         + triangleArea(v1, v2, v3);
}

double volume(const Tetrahedron &t) {
    Point v0 = t.getVertex(0), v1 = t.getVertex(1);
    Point v2 = t.getVertex(2), v3 = t.getVertex(3);

    double ax = v1.x - v0.x, ay = v1.y - v0.y, az = v1.z - v0.z;
    double bx = v2.x - v0.x, by = v2.y - v0.y, bz = v2.z - v0.z;
    double cx = v3.x - v0.x, cy = v3.y - v0.y, cz = v3.z - v0.z;

    double det = ax * (by * cz - bz * cy)
               - ay * (bx * cz - bz * cx)
               + az * (bx * cy - by * cx);
    return fabs(det) / 6;
}

bool isRegular(const Tetrahedron &t) {
    Point v0 = t.getVertex(0), v1 = t.getVertex(1);
    Point v2 = t.getVertex(2), v3 = t.getVertex(3);

    double e = dist(v0, v1);
    return fabs(dist(v0, v2) - e) < EPS
        && fabs(dist(v0, v3) - e) < EPS
        && fabs(dist(v1, v2) - e) < EPS
        && fabs(dist(v1, v3) - e) < EPS
        && fabs(dist(v2, v3) - e) < EPS;
}

void shiftX(Tetrahedron &t, double d) {
    for (int i = 0; i < 4; i++) {
        Point p = t.getVertex(i);
        p.x += d;
        t.setVertex(i, p);
    }
}

void shiftY(Tetrahedron &t, double d) {
    for (int i = 0; i < 4; i++) {
        Point p = t.getVertex(i);
        p.y += d;
        t.setVertex(i, p);
    }
}

void shiftZ(Tetrahedron &t, double d) {
    for (int i = 0; i < 4; i++) {
        Point p = t.getVertex(i);
        p.z += d;
        t.setVertex(i, p);
    }
}

int compareVolume(const Tetrahedron &a, const Tetrahedron &b) {
    double va = volume(a);
    double vb = volume(b);
    if (fabs(va - vb) < EPS) return 0;
    if (va < vb) return -1;
    return 1;
}

int main(int argc, char *argv[])
{
    // cout << true;
    Tetrahedron t;
    Point pts[4] = { {0,0,0}, {1,1,0}, {1,0,1}, {0,1,1} };
    // t.input();
    t.init(pts);
    t.output();
    // t.setVertex(2, {5, 5, 5});
    cout << "Surface area: " << surfaceArea(t) << endl;
    cout << "Volume: " << volume(t) << endl;
    cout << "Regular: " << isRegular(t) << endl;

    shiftX(t, 2);
    t.output();

    Tetrahedron t2 = t;
    shiftZ(t2, 5);
    cout << "Compare: " << compareVolume(t2, t) << endl;

    char *s = t.toPChar();
    cout << s << endl;
    delete[] s;

    return 0;
}