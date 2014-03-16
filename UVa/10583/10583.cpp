#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 50005

int parent[maxN], r[maxN], child[maxN];

void initSet(int N) {
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
        r[i] = 0;
        child[i] = 0;
    }
}
int findSet(int x) {
    if (parent[x] == x)
        return parent[x];
    return parent[x] = findSet(parent[x]);
}

void unionSet(int x, int y) {
    if (r[x] > r[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if (r[x] == r[y])
            r[y]++;
    }
}

main()
{
    int N, M;
    int caseCounter = 0;
    int first, second;
    vector<int> setRoot;

    while (scanf("%d%d", &N, &M) == 2 && N || M) {
        caseCounter++;
        setRoot.clear();
        initSet(N);
        while (M--) {
            scanf("%d%d", &first, &second);
            first = findSet(first);
            second = findSet(second);
            if (first != second)
                unionSet(first, second);
        }

        for (int i = 1; i <= N; i++) {
            int root = findSet(parent[i]);
            vector<int>::iterator it = find(setRoot.begin(), setRoot.end(), root);
            if (it == setRoot.end())
                setRoot.push_back(root);
        }

        printf("Case %d: %d\n", caseCounter, (int)setRoot.size());
    }
}
