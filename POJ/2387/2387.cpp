#include <cstdio>
#include <climits>

#define maxN 1005
#define maxT 2005

struct edge {
    int start;
    int end;
    int len;
};
    edge e[maxT*2];


int BellmanFord(int n, int t,int source, int end) {
    int dis[maxN];
    for (int i = 1; i <=n; i++)
        dis[i] = INT_MAX/2;
    dis[source] = 0;

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < 2*t; j++)
            if (dis[e[j].start] + e[j].len < dis[e[j].end])
                dis[e[j].end] = dis[e[j].start] + e[j].len;

    return dis[end];
}

main()
{
    int T, N;

    scanf("%d%d", &T, &N);
    for (int i = 0; i < T; i++) {
        scanf("%d%d%d", &e[i].start, &e[i].end, &e[i].len);
        e[i+T].start = e[i].end;
        e[i+T].end = e[i].start;
        e[i+T].len = e[i].len;
    }
    printf("%d\n", BellmanFord(N,T,1,N));
}
