#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 1005
#define maxM 25005

struct edge {
    int p1;
    int p2;
    int weight;
    bool operator<(edge e) const {
        return this->weight < e.weight;
    }
    bool operator>(edge e) const {
        return this->weight > e.weight;
    }
    bool operator==(edge e) const {
        return this->weight == e.weight;
    }
};

edge e[maxM];

int p[maxN];
int r[maxN];

void initSet(int n) {
    for (int i = 0; i < n; i++) {
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

main()
{
    int n, m;
    vector<edge>result;
    while (scanf("%d%d", &n, &m) == 2 && n) {
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &e[i].p1, &e[i].p2, &e[i].weight);
        sort(e, e+m);
        initSet(n);

        result.clear();
        for (int i = 0; i < m; i++) {
            int p1 = findSet(e[i].p1);
            int p2 = findSet(e[i].p2);

            if (p1 != p2) {
                unionSet(p1, p2);
            } else
                result.push_back(e[i]);
        }

        sort(result.begin(), result.end());
        if (result.size()) {
            for (int i = 0; i < result.size()-1; i++)
                printf("%d ", result[i].weight);
            printf("%d\n",result.back().weight);
        } else
            printf("forest\n");
    }

}
