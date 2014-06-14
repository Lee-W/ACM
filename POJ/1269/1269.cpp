#include <cstdio>
#include <cmath>
#include <climits>

#define pointNum 4
#define lineNum 2
#define INF INT_MAX/10
#define eps 1e-8

struct Point {
    double x, y;
    Point (double x = 0, double y = 0) : x(x), y(y) {};
};

struct Line {   // y = ax + b
    double a, b;

    Line (Point p1, Point p2) {
        if (p1.x - p2.x) {
            a = (p1.y - p2.y) / (p1.x - p2.x);
            b = p1.y - a*p1.x;
        } else {
            a = INF;
            b = -p1.x;
        }
    }

    Point getIntersectionPoint(Line li) {
        double x, y;
        if (this->a == INF) {
            x = -this->b;
            y = li.a * x + li.b;
        } else if (li.a == INF){
            x = -li.b;
            y = this->a * x + this->b;
        } else {
            x = (li.b - this->b) / (this->a - li.a) + eps;
            y = this->a * x + this->b + eps;
        }
        return Point(x, y);
    }
};

Point p[pointNum];

int main()
{
    int caseNum;

    scanf("%d", &caseNum);
    printf("INTERSECTING LINES OUTPUT\n");
    while (caseNum--) {
        for (int i = 0; i < pointNum; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);

        Line line1(p[0], p[1]), line2(p[2], p[3]);

        if (std::abs(line1.a - line2.a) < eps) {
            if (std::abs(line1.b - line2.b) < eps)
                printf("LINE\n");
            else
                printf("NONE\n");
        } else {
            Point intersectionPoint = line1.getIntersectionPoint(line2);
            printf("POINT %.2f %.2f\n", intersectionPoint.x, intersectionPoint.y);
        }
    }
    printf("END OF OUTPUT\n");
}
