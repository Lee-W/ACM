#include <cstdio>
#include <climits>

#define INF INT_MAX/5
#define maxN 1005
#define maxM 2005

struct wormhole {
    int start;
    int end;
    int time;
};

wormhole w[maxM];

bool BellmanFord(int n, int m) {
    int dis[n];
    for (int i = 0; i < n; i++)
        dis[n] = INF;
    dis[0] = 0;

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m; j++)
            if (dis[w[j].start] + w[j].time < dis[w[j].end])
                dis[w[j].end] = dis[w[j].start] + w[j].time;

    for (int j = 0; j < m; j++)
        if (dis[w[j].start] + w[j].time < dis[w[j].end])
            return false;
    return true;
}

main()
{
    int c, n, m;
    scanf("%d", &c);
    while(c--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &w[i].start, &w[i].end, &w[i].time);
        printf(BellmanFord(n, m)?"not possible\n":"possible\n");
    }
}
