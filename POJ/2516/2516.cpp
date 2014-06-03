#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

#define maxN 105
#define INF INT_MAX/10

int shopkeepers[maxN][maxN], suppliers[maxN][maxN], transCost[maxN][maxN][maxN];

vector<int> edge[maxN];

int cost[maxN][maxN], capacity[maxN][maxN], flow[maxN][maxN];
int dis[maxN], pre[maxN];

void init(int);
int MCMF(int , int, int, int);
bool SPFA(int, int, int);

int main()
{
    int n, m, k;

    while(scanf("%d%d%d", &n, &m, &k) && n) {
        for (int sh = 1; sh <= n; sh++)
            for (int good = 1; good <= k; good++)
                scanf("%d", &shopkeepers[good][sh]);

        for (int sup = 1; sup <= m; sup++)
            for (int good = 1; good <= k; good++)
                scanf("%d", &suppliers[good][sup]);

        for (int good = 1; good <= k; good++)
            for (int sh = 1; sh <= n; sh++)
                for (int sup = 1; sup <= m; sup++)
                    scanf("%d", &transCost[good][sh][sup]);

        int minCost = 0, target;
        bool fail = false;
        for (int good = 1; good <= k ; good++) {
            init(n+m+2);
            target = 0;

            for (int sup = 1; sup <= m; sup++) {
                edge[0].push_back(sup);
                capacity[0][sup] = suppliers[good][sup];
                cost[0][sup] = 0;

                edge[sup].push_back(0);
                
                for (int sh = 1; sh <= n; sh++) {
                    edge[sup].push_back(sh + m);
                    capacity[sup][sh+m] = INF;
                    cost[sup][sh+m] = transCost[good][sh][sup];

                    edge[sh + m].push_back(sup);
                }
            }

            for (int sh = 1; sh <= n; sh++) {
                edge[sh+m].push_back(n+m+1);
                capacity[sh+m][n+m+1] = shopkeepers[good][sh];
                cost[sh+m][n+m+1] = 0;

                edge[n+m+1].push_back(sh+m);

                target += shopkeepers[good][sh];
            }

            int currentCost = MCMF(0, n+m+1, n+m+2, target);
            if (currentCost == -1) {
                fail = true;
                break;
            }
            minCost += currentCost;
        }

        if (fail)
            printf("-1\n");
        else
            printf("%d\n", minCost);
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));
}

int MCMF(int source, int des, int vertexNum, int leastFlow) {
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
    if (maxFlow < leastFlow)
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

    return pre[des] != -1;
}
