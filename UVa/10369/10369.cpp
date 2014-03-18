#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define maxSatelliteNum 105
#define maxOutpostNum 505

typedef pair<double,double> point;

struct edge {
    int p1;
    int p2;
    double len;
    edge(int a, int b) {
        p1 = a;
        p2 = b;
    }
    bool operator<(edge e) const{
        return this->len < e.len;
    }
    bool operator>(edge e) const{
        return this->len > e.len;
    }
    bool operator==(edge e) const{
        return this->len == e.len;
    }
};

point outpost[maxOutpostNum];
vector<edge> channel;
int p[maxOutpostNum];
int r[maxOutpostNum];
bool assigned[maxOutpostNum];

void initSet(int n) {
    for (int i = 0; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }
}
int findSet(int x) {
    if (p[x] == x)
        return p[x];
    return p[x] = findSet(p[x]);
}
void unionSet(int x,int y) {
    if (r[x] > r[y])
        p[y] = x;
    else {
        p[x] = y;
        if (r[x] == r[y])
            r[y]++;
    }
}

void Kruskal(vector<edge>& MST, int outpostNum) {
    initSet(outpostNum);
    for (int i = 0; i < channel.size(); i++) {
        int point1 = findSet(channel[i].p1);
        int point2 = findSet(channel[i].p2);

        if (point1 != point2) {
            unionSet(point1, point2);
            MST.push_back(channel[i]);
        }

        if (MST.size() == outpostNum-1)
            break;
    }
}

main()
{
    int caseNum, satelliteNum, outpostNum;
    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d%d", &satelliteNum, &outpostNum);
        for (int i = 0; i < outpostNum; i++) {
            scanf("%lf%lf", &outpost[i].first, &outpost[i].second);
            assigned[i] = false;
        }
        channel.clear();

        channel.reserve(outpostNum * outpostNum);
        for (int i = 0; i < outpostNum-1; i++)
            for (int j = i+1; j < outpostNum; j++) {
                edge tmp(i, j);
                tmp.len = sqrt(pow(outpost[i].first - outpost[j].first, 2) + pow(outpost[i].second - outpost[j].second, 2));
                channel.push_back(tmp);
            }
        sort(channel.begin(), channel.end());

        vector<edge>MST;
        Kruskal(MST, outpostNum);
        printf("%.2lf\n", MST[outpostNum - satelliteNum - 1].len);
    }
}
