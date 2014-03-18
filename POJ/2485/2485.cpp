#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 505


struct edge {
    int p1;
    int p2;
    int len;
    edge(int a, int b, int l) {
        p1 = a;
        p2 = b;
        len = l;
    }
    
    bool operator<(edge e)const {
        return this->len < e.len;
    }
    bool operator>(edge e)const {
        return this->len > e.len;
    }
    bool operator==(edge e)const {
        return this->len == e.len;
    }
};

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

void unionSet(int x,int y) {
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
    sort(e.begin(), e.end());

    for (int i = 0; i < e.size(); i++) {
        int point1 = findSet(e[i].p1);
        int point2 = findSet(e[i].p2);

        if (point1 != point2) {
            unionSet(point1, point2);
            MST.push_back(e[i]);
        }

        if (MST.size() ==  n-1)
            break;
    }
}

main ()
{
    int caseNum, townNum, tmp;
    vector<edge>MST;

    scanf("%d", &caseNum);
    while(caseNum--) {
        e.clear();
        MST.clear();

        scanf("%d", &townNum);
        for (int i = 0; i < townNum; i++)
            for (int j = 0; j < townNum; j++) {
                scanf("%d", &tmp);
                if (j > i) {
                    edge tmpE(i,j,tmp);
                    e.push_back(tmpE);
                }
            }


        Kruskal(MST, townNum);
        printf("%d\n", MST.back().len);
    }
}
