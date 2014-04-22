#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

#define maxK 35
#define maxC 205
#define maxN maxK+maxC
#define INF INT_MAX/20

int dis[maxN][maxN];
int capacity[maxN][maxN], flow[maxN][maxN], residual[maxN][maxN];
bool visited[maxN];
int path[maxN], bottleneck[maxN];

void init();
int EdmondsKarp(int, int, int, int);

void floyd(int);
void buildGraph(int,int,int,int,int,int);

main()
{
    int k, c, m;
    scanf("%d%d%d", &k, &c, &m);
    int n = k + c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &dis[i][j]);
            if (!dis[i][j] && i != j)
                dis[i][j] = INF;
        }
    floyd(n);

    int source = 0, des = n + 1;
    int left = INF, right = 0, mid;
    int maxFlow;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] > right && dis[i][j] != INF)
                right = dis[i][j];
            if (dis[i][j] < left && dis[i][j])
                left = dis[i][j];
        }

    while(left < right) {
        mid = (left + right) / 2;
        buildGraph(source, des, c, k , m, mid);
        maxFlow = EdmondsKarp(source, des, n+2, mid);
        if (maxFlow >= c)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", right);
}

void buildGraph(int source, int des, int c, int k, int m, int b) {
    memset(capacity, 0, sizeof(capacity));
    int n = c + k;
    for (int i = 1; i <= k; i++)
        capacity[source][i] = m;
    for (int i = 1; i <= c; i++)
        capacity[k+i][des] = 1;

    for (int i = 1; i <= k; i++)
        for (int j = k+1; j <= n; j++)
            if (dis[i][j] && dis[i][j] != INF)
                capacity[i][j] = 1;
    init();
}

void init() {
    memset(flow, 0, sizeof(flow));
    memcpy(residual, capacity, sizeof(capacity));
    memset(path, -1, sizeof(path));
    memset(bottleneck, 0, sizeof(bottleneck));
}

int BFS(int s, int t, int n, int b) {
    memset(visited, false, sizeof(visited));

    queue<int> q;
    visited[s] = true;
    path[s] = s;
    bottleneck[s] = INF;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
            if (!visited[i] && residual[cur][i] > 0 && dis[cur][i] <= b) {
                visited[i] = true;
                path[i] = cur;
                bottleneck[i] = min(bottleneck[cur], residual[cur][i]);
                q.push(i);

                if (i == t)
                    return bottleneck[t];
            }
    }
    return 0;
}

int EdmondsKarp(int s, int t, int n, int b) {
    int maxFlow = 0, currentFlow;
    while (currentFlow = BFS(s, t ,n, b)) {
        int pre = path[t], cur = t;
        while(pre != cur) {
            flow[pre][cur] = flow[pre][cur] + currentFlow;
            flow[cur][pre] = -flow[pre][cur];
            residual[pre][cur] = capacity[pre][cur] - flow[pre][cur];
            residual[cur][pre] = capacity[cur][pre] - flow[cur][pre];
            cur = pre;
            pre = path[cur];
        }
        maxFlow += currentFlow;
    }
    return maxFlow;
}

void floyd(int n) {
    for (int m = 1; m <= n; m++)
        for (int s = 1; s <= n; s++)
            for (int d = 1; d <= n; d++)
                if (dis[s][m] != INF && dis[m][d] != INF)
                    if (dis[s][d] > dis[s][m] + dis[m][d])
                        dis[s][d] = dis[s][m] + dis[m][d];
}
