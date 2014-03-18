#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 2005

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

vector<edge> e;
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

void Kruskal(vector<edge>& MST, int n) {
    initSet(n);
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++) {
        int p1 = findSet(e[i].p1);
        int p2 = findSet(e[i].p2);

        if (p1 != p2) {
            unionSet(p1, p2);
            MST.push_back(e[i]);
        }

        if (MST.size() == n-1)
            break;
    }
}

main()
{
    int N, M;
    vector<edge>MST;

    scanf("%d%d", &N, &M);
    e.resize(M);
    for (int i = 0; i < M; i++)
        scanf("%d%d%d", &e[i].p1, &e[i].p2, &e[i].dis);

    Kruskal(MST, N);
    printf("%d\n", MST.back().dis);

}
