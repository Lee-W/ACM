#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

#define maxN 105*2
#define maxM 5005
#define INF INT_MAX/10
#define eps 1e-8

vector<int> edge[maxN];

double cost[maxN][maxN];
int capacity[maxN][maxN];
double flow[maxN][maxN], dis[maxN];
int pre[maxN];

double map[maxN][maxN];

void init(int);
double MCMF(int , int, int);
bool SPFA(int, int, int);

int main()
{
    int n, m;
    int point1, point2, co, cap;

    while (scanf("%d%d", &n, &m) && n) {
        init(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%lf", &map[j][i]);

        for (int i = 1; i <= m; i++) {
            edge[0].push_back(i);
            cost[0][i] = 0;
            capacity[0][i] = 1;

            edge[i].push_back(0);

            for (int j = 1; j <= n; j++) {
                edge[i].push_back(j+m);
                cost[i][j+m] = map[i][j];
                capacity[i][j+m] = 1;

                edge[j+m].push_back(i);
            }
        }

        for (int j = 1; j <= m; j++) {
            edge[j+m].push_back(n+m+1);
            cost[j+m][n+m+1] = 0;
            capacity[j+m][n+m+1] = 1;
            
            edge[n+m+1].push_back(j+m);
        }

        double minCost = MCMF(0, n+m+1, n+m+2);
        printf("%.2lf\n", minCost/n+eps);
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));
}

double MCMF(int source, int des, int vertexNum) {
    double maxFlow = 0, minCost = 0;
    while(SPFA(source, des, vertexNum)) {
        double f = INF;

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
            
            if (flow[next][current] > 0 && dis[current] - cost[next][current] + eps < dis[next]) {
                dis[next] = dis[current] - cost[next][current];
                pre[next] = current;

                if (!inqueue[next]) {
                    q.push(next);
                    inqueue[next] = true;
                }
            } else if (capacity[current][next] - flow[current][next] > 0 && dis[current] + cost[current][next] + eps < dis[next]) {
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
