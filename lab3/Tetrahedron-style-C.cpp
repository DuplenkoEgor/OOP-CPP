#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point {
    double x, y, z;
};

struct Tetrahedron {
    Point v[4];
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

void init(Tetrahedron &t, const Point p[4]) {
    for (int i = 0; i < 4; i++) {
        t.v[i] = p[i];
    }
}

void input(Tetrahedron &t) {
    Point p[4];
    for (int i = 0; i < 4; i++) {
        cout << "Vertex " << i + 1 << " (x y z): ";
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    init(t, p);
}

void output(const Tetrahedron &t) {
    for (int i = 0; i < 4; i++) {
        cout << "(" << t.v[i].x << ", " << t.v[i].y << ", " << t.v[i].z << ")\n";
    }
}

char* toPChar(const Tetrahedron &t) {
    char *s = new char[300]; // у купі
    sprintf(s, "A(%.2f; %.2f; %.2f) B(%.2f; %.2f; %.2f) C(%.2f; %.2f; %.2f) D(%.2f; %.2f; %.2f)",
            t.v[0].x, t.v[0].y, t.v[0].z,
            t.v[1].x, t.v[1].y, t.v[1].z,
            t.v[2].x, t.v[2].y, t.v[2].z,
            t.v[3].x, t.v[3].y, t.v[3].z);
    return s;
}

double surfaceArea(const Tetrahedron &t) {
    return triangleArea(t.v[0], t.v[1], t.v[2])
         + triangleArea(t.v[0], t.v[1], t.v[3])
         + triangleArea(t.v[0], t.v[2], t.v[3])
         + triangleArea(t.v[1], t.v[2], t.v[3]);
}

double volume(const Tetrahedron &t) {
    double ax = t.v[1].x - t.v[0].x, ay = t.v[1].y - t.v[0].y, az = t.v[1].z - t.v[0].z;
    double bx = t.v[2].x - t.v[0].x, by = t.v[2].y - t.v[0].y, bz = t.v[2].z - t.v[0].z;
    double cx = t.v[3].x - t.v[0].x, cy = t.v[3].y - t.v[0].y, cz = t.v[3].z - t.v[0].z;

    double det = ax * (by * cz - bz * cy)
               - ay * (bx * cz - bz * cx)
               + az * (bx * cy - by * cx);
    return fabs(det) / 6;
}

bool isRegular(const Tetrahedron &t) {
    double e = dist(t.v[0], t.v[1]);
    return fabs(dist(t.v[0], t.v[2]) - e) < EPS
        && fabs(dist(t.v[0], t.v[3]) - e) < EPS
        && fabs(dist(t.v[1], t.v[2]) - e) < EPS
        && fabs(dist(t.v[1], t.v[3]) - e) < EPS
        && fabs(dist(t.v[2], t.v[3]) - e) < EPS;
}

void shiftX(Tetrahedron &t, double d) {
    for (int i = 0; i < 4; i++) {
        t.v[i].x += d;
    }
}

void shiftY(Tetrahedron &t, double d) {
    for (int i = 0; i < 4; i++) {
        t.v[i].y += d;
    }
}

void shiftZ(Tetrahedron &t, double d) {
    for (int i = 0; i < 4; i++) {
        t.v[i].z += d;
    }
}

// -1, 0 або 1
int compareVolume(const Tetrahedron &a, const Tetrahedron &b) {
    double va = volume(a);
    double vb = volume(b);
    if (fabs(va - vb) < EPS) return 0;
    if (va < vb) return -1;
    return 1;
}

int main() {
    Tetrahedron t;
    Point pts[4] = { {0,0,0}, {1,0,0}, {0,1,0}, {0,0,1} };
    init(t, pts);
    output(t);

    cout << "Surface area: " << surfaceArea(t) << endl;
    cout << "Volume: " << volume(t) << endl;
    cout << "Regular: " << isRegular(t) << endl;

    shiftX(t, 2);
    output(t);

    Tetrahedron t2 = t;
    shiftZ(t2, 5);
    cout << "Compare: " << compareVolume(t, t2) << endl;

    char *s = toPChar(t);
    cout << s << endl;
    delete[] s;

    return 0;
}