#include <cstdio>
#include <utility>
#include <cmath>
#include <map>
using namespace std;

#define maxPointNum 105
typedef pair<double, double> Point;

struct Edge {
    Point p1;
    Point p2;
    double distance;
    Edge(Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
        distance = sqrt(pow(p1.first-p1.first, 2) + pow(p1.second-p2.second, 2));
    }

    bool operator==(Edge& p) {
        return (this->p1 == p.p1 && this->p2 == p.p2) || (this->p2 == p.p1 && this->p1 == p.p1);
    }
};


main()
{
    int caseNum, pointNum;
    Point points[maxPointNum];


    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d", &pointNum);
        for (int i = 0; i < pointNum; i++) {
            Point p;
            scanf("%lf%lf", &p.first, &p.second);
            points[i] = p;
        }

        for (int i = 0; i < )

    }
}
