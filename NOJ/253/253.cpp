#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

#define maxN 105*2
#define maxM 5005
#define INF INT_MAX/10

vector<int> edge[maxN];

int cost[maxN][maxN], capacity[maxN][maxN];
int flow[maxN][maxN], dis[maxN], pre[maxN];

int bToG[maxN][maxN], gToB[maxN][maxN];

void init(int);
int MCMF(int , int, int);
bool SPFA(int, int, int);

int main()
{
    int n, m;
    int point1, point2, co, cap;

    while(scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &bToG[i][j]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &gToB[i][j]);


        init(2*n);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                edge[i].push_back(j+n);
                cost[i][j+n] = -bToG[i][j] * gToB[j][i];
                capacity[i][j+n] = 1;

                edge[j+n].push_back(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            edge[0].push_back(i);
            cost[0][i] = 0;
            capacity[0][i] = 1;

            edge[i].push_back(0);

            edge[n+i].push_back(2*n+1);
            cost[n+i][2*n+1] = 0;
            capacity[n+i][2*n+1] = 1;

            edge[2*n+1].push_back(n+i);
        }

        int minCost = -MCMF(0, 2*n+1, 2*n+2);
        printf("%d\n", minCost);
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));
}

int MCMF(int source, int des, int vertexNum) {
    int maxFlow = 0, minCost = 0;
    while(SPFA(source, des, vertexNum)) {
        int f = INF;

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
    return pre[des] != -1;
}
