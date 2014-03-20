#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define maxN 15
#define maxM 60

struct edge {
    int p1;
    int p2;
    int cost;
    bool operator<(edge e)const{
        return this->cost < e.cost;
    }
    bool operator>(edge e)const{
        return this->cost > e.cost;
    }
    bool operator==(edge e)const{
        return this->cost == e.cost;
    }
};

//edge e[maxM];
vector<edge> e;
bool added[maxM];
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

void Kruskal(vector<edge>&MST, int n) {
    initSet(n);
    for (int i = 0; i < e.size(); i++) {
        int p1 = findSet(e[i].p1);
        int p2 = findSet(e[i].p2);
        if (p1 != p2 && !added[i]) {
            unionSet(p1, p2);
            added[i] = true;
            MST.push_back(e[i]);
        }

        if (MST.size() == n-1)
            break;
    }
}

main()
{
    int n, m;
    vector<edge>MST1, MST2;
    while (scanf("%d%d", &n, &m) == 2 && n) {
        e.clear();
        e.resize(m);
        for (int i = 0; i < m ; i++)
            scanf("%d%d%d", &e[i].p1, &e[i].p2, &e[i].cost);
        memset(added, false, m);

        MST1.clear();
        MST2.clear();
        sort(e.begin(), e.end());
        Kruskal(MST1, n);
        Kruskal(MST2, n);
        if (MST1.size() < n-1 || MST2.size() < n-1)
            printf("No way!\n");
        else {
            int result = 0;
            for (int i = 0; i < MST1.size(); i++)
                result += MST1[i].cost;
            for (int i = 0; i < MST2.size(); i++)
                result += MST2[i].cost;
            printf("%d\n", result);
        }
/*
        for (int i = 0; i < m ; i++)
            printf("%d\t%d\t%d\n", e[i].p1, e[i].p2, e[i].cost);
        printf("\n");
*/

    }
}
