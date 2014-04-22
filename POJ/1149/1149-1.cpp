#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxM 1005
#define maxN 105
#define INF INT_MAX/1000

int pigHouse[maxM];
bool hasKey[maxN][maxM];
int numberWannaBuy[maxN];

int cap[maxN][maxN];
int flow[maxN][maxN];
int path[maxN];
bool visited[maxN];

void buildGraph(int, int);

void init();
int FordFulkerson(int, int, int);
bool DFS(int, int, int);
int findFlow(int, int);

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
    init();
    buildGraph(m, n);
    printf("%d\n", FordFulkerson(0, n+1, n+2));
}

void init() {
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    memset(path, 0, sizeof(path));
    memset(visited, 0, sizeof(visited));
}

void buildGraph(int m, int n) {
    for (int j = 1; j <= m; j++) {
        bool isFirstOpen = true;
        int pre;
        for (int i = 1; i <= n; i++) {
            if (hasKey[i][j] && isFirstOpen) {
                cap[0][i] += pigHouse[j];
                pre = i;
                isFirstOpen = false;
            } else if (hasKey[i][j]) {
                cap[pre][i] = INF;
                pre = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cap[i][n+1] = numberWannaBuy[i];
}

int FordFulkerson(int source, int sink, int n) {
    int maxFlow = 0;

    while(1) {
        memset(visited, false, sizeof(visited));
        if (!DFS(source, sink, n))
            break;
        maxFlow += findFlow(source, sink);
    }
    return maxFlow;
}

bool DFS(int current, int sink, int n) {
    visited[current] = true;
    if (current == sink)
        return true;

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        if (cap[current][i] - flow[current][i] > 0 || flow[i][current]) {
            path[i] = current;
            if (DFS(i, sink, n))
                return true;
        }
    }
    return false;
}

int findFlow(int s, int t) {
    int pre;
    int f = INF*2;
    for (int i = t; i != s; i = path[i]) {
        pre = path[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            f = std::min(f, cap[pre][i] - flow[pre][i]);
        else
            f = std::min(f, flow[i][pre]);
    }
    for (int i = t; i != s; i = path[i]) {
        pre = path[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else
            flow[i][pre] -= f;
    }
    return f;
}
