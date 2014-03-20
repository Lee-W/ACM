#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define maxN 755
#define maxM 1005

typedef pair<int,int> point;
struct edge {
    int p1;
    int p2;
    double dis;
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

point towns[maxN];
edge e[maxN*maxN];
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

void Kruskal(edge MST[maxN], int n, int eNum, int builtNum) {
    initSet(n);
    int MSTCounter = builtNum;
    for (int i = 0; i < eNum; i++) {
        int p1 = findSet(e[i].p1);
        int p2 = findSet(e[i].p2);

        if (p1 != p2) {
            unionSet(p1, p2);
            MST[MSTCounter++] = e[i];
        }
        if (MSTCounter == n-1)
            break;
    }
}

main()
{
    int n, m;
    edge MST[maxN];
    int MSTCounter = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &towns[i].first, &towns[i].second);

    int p1, p2;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &p1, &p2);
        p1 = findSet(p1);
        p2 = findSet(p2);

        if (p1 != p2) {
            unionSet(p1, p2);
            MST[MSTCounter++] = e[i];
        }
    }

    //count dis for each edge
    int k = 0;
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <=n; j++) {
            e[k].p1 = i;
            e[k].p2 = j;
            e[k].dis = sqrt(pow(towns[i].first - towns[j].first, 2) + pow(towns[i].second - towns[j].second, 2));
            k++;
        }

    sort(e, e+k);
    Kruskal(MST, n, k, m);
    for (int i = m; i < n-1; i++)
        printf("%d %d\n", MST[i].p1, MST[i].p2);

}
