#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 100005
#define maxM 100005

int parent[maxN*2], size[maxN], sum[maxN];

void initialSet(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = maxN + i;
        parent[maxN+i] = maxN + i;
        size[i] = 1;
        sum[i] = i;
    }
}

int findSet(int x) {
    if (parent[x] == x)
        return parent[x];
    return parent[x] = findSet(parent[x]);
}

void unionSet(int p, int q) {
    parent[q] = parent[p];
    size[p-maxN] += size[q-maxN];
    sum[p-maxN] += sum[q-maxN];
}

void move(int p, int q) {
    int pRoot =findSet(p);
    int qRoot = findSet(q);
    sum[pRoot - maxN] -= p;
    sum[qRoot - maxN] += p;
    size[pRoot - maxN]--;
    size[qRoot - maxN]++;
    parent[p] = parent[q];
}

void display(int p) {
    p = findSet(p);
    printf("%d %d\n", size[p-maxN], sum[p-maxN]);
}

void test(int N) {
    printf("index\tp\tsize\tsum\n");
    for (int i = 1; i <= N; i++)
        printf("%d\t%d\n",i, parent[i]);
    for (int i = 1; i <= N; i++)
        printf("%d\t%d\t%d\t%d\n", i+maxN, parent[i+maxN], size[i], sum[i]);
    printf("\n");
}

main()
{
    int N, M;
    int command, p, q;

    while(scanf("%d%d", &N, &M) == 2) {
        initialSet(N);
        while(M--) {
            scanf("%d", &command);

            if (command == 1) {
                scanf("%d%d", &p, &q);
                p = findSet(p);
                q = findSet(q);
                if (p != q)
                    unionSet(p, q);
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                move(p, q);
            } else if (command == 3) {
                scanf("%d", &p);
                display(p);
            }
        }
    }
}
