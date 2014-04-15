#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

#define maxN 105
#define INF INT_MAX/2

int regulatorCapacity[maxN];
bool isEntry[maxN];

int flow[maxN*2][maxN*2];
int capacity[maxN*2][maxN*2];
int path[maxN*2];
bool visited[maxN*2];

void buildGraph(int);

void init();
int FordFulderson(int,int,int);
bool DFS(int,int,int);
int findFlow(int,int);

main()
{
    int n, m;
    int start, end, cap;
    int b, d, entry;

    int Bindex = 0, Dindex;

    while (scanf("%d", &n) == 1) {
        init();
        for (int i = 1; i <= n; i++)
            scanf("%d", &regulatorCapacity[i]);

        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &start, &end, &cap);
            capacity[start][end] = cap;
        }

        scanf("%d%d", &b, &d);
        while (b--) {
            scanf("%d", &entry);
            capacity[Bindex][entry] = regulatorCapacity[entry];
            isEntry[entry] = true;
        }
        Dindex = n + 1;
        while (d--) {
            scanf("%d", &entry);
            capacity[entry][Dindex] = regulatorCapacity[entry];
            isEntry[entry] = true;
        }
        buildGraph(n);
        printf("%d\n", FordFulderson(Bindex, Dindex, Dindex));
    }
}

void buildGraph(int n) {
    for (int i = 1; i <= n; i++)
        for (int j  = 1; j <= n; j++) {
            int min = std::min(std::min(capacity[i][j], regulatorCapacity[i]), regulatorCapacity[j]);
            capacity[i][j] = min;
        }
}

void init() {
    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));
    memset(visited, 0, sizeof(visited));
    memset(path, 0, sizeof(path));
}

int FordFulderson(int source, int sink, int n) {
    int maxFlow = 0;
    while(1) {
        memset(visited, 0, sizeof(visited));
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
        if (capacity[current][i] - flow[current][i] > 0 || flow[i][current] > 0) {
            path[i] = current;
            if (DFS(i, sink, n))
                return true;
        }
    }
    return false;
}

int findFlow(int source, int sink) {
    int pre;
    int f = INF;
    for (int i = sink; i != source; i = path[i]) {
        pre = path[i];
        if (capacity[pre][i] - flow[pre][i] > 0)
            f = std::min(f, capacity[pre][i] - flow[pre][i]);
        else
            f = std::min(f, flow[i][pre]);
    }

    for (int i = sink; i != source; i = path[i]) {
        pre = path[i];
        if (capacity[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else
            flow[i][pre] -= f;
    }
    return f;
}
