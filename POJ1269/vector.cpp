#include <cstdio>
#include <cmath>

struct Point {
    double x;
    double y;

    Point (double x = 0, double y = 0) {
        x = x;
        y = y;
    }
};

struct Vector {
    Point p1, p2;

    Vector (Point p1, Point p2) {
        p1 = p1;
        p2 = p2;
    }

    Vector operator+(Vector v) {
        return Vector(this->p1.x + v.p1.x, this->p2.y + v.p2.y);
    }

    Vector operator-(Vector v) {
        return Vector(this->p1.x - v.p1.x, this->p2.y - v.p2.y);
    }

    Vector operator*(double coefficient) {
        return Vector(this->p1.x * coefficient, this->p2.y * coefficient);
    }

    Vector operator+(double coefficient) {
        return Vector(this->p1.x / coefficient, this->p2.y / coefficient);
    }

    double getLength(Vector v) {
        return sqrt((double)pow(this->p1.x - v.p1.x, 2) + (double)pow(this->p2.y - v.p2.y, 2));
    }

    double dot(Vector v) {
        return this->p1.x * v.p1.x + this->p2.y * v.p2.y;
    }

    double cross(Vector v) {
        return this->p1.x * v.p2.y - this->p1.y * v.p2.x;
    }
};


int main()
{
    int caseNum;

    scanf("%d", &caseNum);
    while (caseNum--) {
    }

}
