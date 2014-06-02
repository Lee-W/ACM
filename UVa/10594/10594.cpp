#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define maxN 105
#define maxM 5005
#define INF 10000000000000000LL

vector<long long int> edge[maxN];

long long int cost[maxN][maxN], capacity[maxN][maxN];
long long int flow[maxN][maxN], dis[maxN], pre[maxN];

void init(int);
long long int MCMF(int , int, int, int);
bool SPFA(int, int, int);

int main()
{
    int n, m;
    int point1, point2, c;
    int dataAmount, cap;

    while(scanf("%d%d", &n, &m) == 2) {
        init(n);
        while(m--) {
            scanf("%d%d%d", &point1, &point2, &c);
            edge[point1].push_back(point2);
            edge[point2].push_back(point1);
            cost[point1][point2] = cost[point2][point1] = c;
        }
        scanf("%d%d", &dataAmount, &cap);

        memset(capacity, 0, sizeof(capacity));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < edge[i].size(); j++)
                capacity[i][edge[i][j]] = cap;

        capacity[0][1] = dataAmount;
        cost[0][1] = 0;
        edge[0].push_back(1);

        long long int minCost = MCMF(0, n, n+1, dataAmount);
        if (minCost != -1)
            printf("%lld\n", minCost);
        else
            printf("Impossible.\n");
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(flow, 0, sizeof(flow));
}


long long int MCMF(int source, int des, int vertexNum, int dataAmount) {
    long long int maxFlow = 0, minCost = 0;
    while(SPFA(source, des, vertexNum)) {
        long long int f = INF;

        for (int i = des; i != source; i = pre[i]) {
            if (flow[i][pre[i]] > 0)
                f = min(f, flow[i][pre[i]]);
            else if (capacity[pre[i]][i] - flow[pre[i]][i] > 0)
                f = min(f, capacity[pre[i]][i] - flow[pre[i]][i]); 
        }

        for (int i = des; i != source; i = pre[i]) {
            if (flow[i][pre[i]] > 0)
                flow[i][pre[i]] -= f;
            else if (capacity[pre[i]][i] - flow[pre[i]][i] > 0)
                flow[pre[i]][i] += f;
        }

        maxFlow += f;
        minCost += f * dis[des];
    }
    if (maxFlow < dataAmount)
        return -1;
    return minCost;
}

bool SPFA(int source, int des, int vertexNum) {
    bool inqueue[vertexNum];
    queue<int>q;
    for (int i = source; i <= vertexNum; i++)
        dis[i] = INF;
    
    memset(inqueue, false, sizeof(inqueue));
    memset(pre, -1, sizeof(pre));

    dis[source] = 0;
    inqueue[source] = true;
    q.push(source);

    int current, next;
    while(!q.empty()) {
        current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = 0; i < edge[current].size(); i++) {
            next = edge[current][i];
            
            if (flow[next][current] > 0 && dis[current] - cost[next][current] < dis[next]) {
                dis[next] = dis[current] - cost[next][current];
                pre[next] = current;

                if (!inqueue[next]) {
                    q.push(next);
                    inqueue[next] = true;
                }
            } else if (capacity[current][next] - flow[current][next] > 0 && dis[current] + cost[current][next] < dis[next]) {
                dis[next] = dis[current] + cost[current][next];
                pre[next] = current;

                if (!inqueue[next]) {
                    q.push(next);
                    inqueue[next] = true;
                }
            }
        }
    }

    if (pre[des] == -1)
        return false;
    else
        return true;
}
