#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 105

struct edge {
    int p1;
    int p2;
    int cost;
    edge(int a, int b, int c) {
        p1 = a;
        p2 = b;
        cost = c;
    }

    bool operator<(edge e) const {
        return this->cost < e.cost;
    }
    bool operator>(edge e) const {
        return this->cost > e.cost;
    }
    bool operator==(edge e) const {
        return this->cost == e.cost;
    }
};

int dis[maxN][maxN];
vector<edge>e;
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
        if (p[x] == p[y])
            r[y]++;
    }
}

void Kruskal(vector<edge>&MST, int n) {
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
    int N, Q;
    int tmp, tmp2;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &dis[i][j]);

    vector<edge>MST;
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d%d", &tmp, &tmp2);
        dis[tmp][tmp2] = 0;
    }

    for (int i = 1; i <= N-1; i++)
        for (int j = i+1; j <= N; j++) {
            edge tmpE(i,j,dis[i][j]);
            e.push_back(tmpE);
        }
        

//    for (int i = 0; i < e.size(); i++)
  //      printf("%d\t%d\t%d\n",e[i].p1, e[i].p2, e[i].cost);

    Kruskal(MST, N);

    int result = 0;
    for (int i = 0; i < MST.size(); i++) {
        result += MST[i].cost;
    }
    printf("%d\n", result);
}
