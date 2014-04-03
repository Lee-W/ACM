#include <cstdio>
#include <climits>

#define maxN 505
#define maxM 2505
#define maxW 205

struct edge {
    int start;
    int end;
    int len;
    edge() {
    }
    edge init(int s, int e, int l) {
        start = s;
        end = e;
        len = l;
    }
};

edge path[maxM*2];
edge wormhole[maxW];
int dis[maxN];

void relax(int start, int end, int len) {
    if (dis[start] + len < dis[end])
        dis[end] = dis[start] + len;
}

bool BellmanFord(int n, int m, int w, int source) {
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX/2;
    dis[source] = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m*2; j++)
            relax(path[j].start, path[j].end, path[j].len);

        for (int j = 0; j < w; j++)
            relax(wormhole[j].start, wormhole[j].end, wormhole[j].len);
    }

    for (int j = 0; j < m*2; j++)
        if (dis[path[j].start] + path[j].len < dis[path[j].end])
            return true;
    for (int j = 0; j < w; j++)
        if (dis[wormhole[j].start] + wormhole[j].len < dis[wormhole[j].end])
            return true;
    return false;
}

main()
{
    int F,N,M,W;
    scanf("%d", &F);
    while(F--) {
        scanf("%d%d%d", &N, &M, &W);
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &path[i].start, &path[i].end, &path[i].len);
            path[i+M].init(path[i].end, path[i].start, path[i].len);
        }

        for (int i = 0; i < W; i++) {
            scanf("%d%d%d", &wormhole[i].start, &wormhole[i].end, &wormhole[i].len);
            wormhole[i].len *= -1;
        }

        printf("%s\n", (BellmanFord(N,M,W,1)?"YES":"NO"));

    }
}
