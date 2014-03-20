#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define maxN 1005
#define maxM 15005

struct edge {
    int p1;
    int p2;
    int dis;
    bool operator<(edge e) const {
        return this->dis < e.dis;
    }
    bool operator>(edge e) const {
        return this->dis > e.dis;
    }
    bool operator==(edge e) const {
        return this->dis == e.dis;
    }
};

edge e[maxM];
int p[maxN], r[maxN];

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

void unionSet(int x, int y) {
    if (r[x] > r[y])
        p[y] = x;
    else {
        p[x] = y;
        if (r[x] == r[y])
            r[y]++;
    }
}

void Kruskal(vector<edge>&MST, int n, int m) {
    initSet(n);
    sort(e, e+m);
    for (int i = 0; i < m; i++) {
        int p1 = findSet(e[i].p1);
        int p2 = findSet(e[i].p2);

        if (p1 != p2) {
            unionSet(p1 , p2);
            MST.push_back(e[i]);
        }
    }
}

main()
{
    int n, m;
    vector<edge>MST;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].p1, &e[i].p2, &e[i].dis);
    Kruskal(MST,n,m);

    printf("%d\n", MST.back().dis);
    printf("%d\n", (int)MST.size());
    for (int i = 0; i < MST.size(); i++)
        printf("%d\t%d\n", MST[i].p1, MST[i].p2);
}
