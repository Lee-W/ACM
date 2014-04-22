#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define maxM 1005
#define maxN 105
#define INF INT_MAX/1000

int pigHouse[maxM];
bool hasKey[maxN][maxM];
int numberWannaBuy[maxN];

int capacity[maxN][maxN], flow[maxN][maxN], residual[maxN][maxN];
bool visited[maxN];
int path[maxN], bottleneck[maxN];

void buildGraph(int, int);

void init();
int EdmondsKarp(int, int, int);

main()
{
    int m, n;
    int keyNum, key;

    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%d", &pigHouse[i]);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &keyNum);
        while(keyNum--) {
            scanf("%d", &key);
            hasKey[i][key] = true;
        }
        scanf("%d", &numberWannaBuy[i]);
    }
    buildGraph(m, n);
    init();
    printf("%d\n", EdmondsKarp(0, n+1, n+2));
}

void buildGraph(int m, int n) {
    for (int j = 1; j <= m; j++) {
        bool isFirstOpen = true;
        int pre;
        for (int i = 1; i <= n; i++) {
            if (hasKey[i][j] && isFirstOpen) {
                capacity[0][i] += pigHouse[j];
                pre = i;
                isFirstOpen = false;
            } else if (hasKey[i][j]) {
                capacity[pre][i] = INF;
                pre = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        capacity[i][n+1] = numberWannaBuy[i];
}

void init() {
    memset(flow, 0, sizeof(flow));
    memcpy(residual, capacity, sizeof(capacity));
    memset(path, -1, sizeof(path));
    memset(bottleneck, 0, sizeof(bottleneck));
}

int BFS(int s, int t, int n) {
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
            if (!visited[i] && residual[cur][i] > 0) {
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

int EdmondsKarp(int s, int t, int n) {
    int maxFlow = 0, currentFlow;
    while (currentFlow = BFS(s, t ,n)) {
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
