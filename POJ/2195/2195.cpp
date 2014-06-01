#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

#define maxN 105

#define INF INT_MAX/10

vector< pair<int,int> > man;
vector< pair<int,int> > house;

int cap[maxN*2][maxN*2], cost[maxN*2][maxN*2];
int flow[maxN*2][maxN*2];
int dis[maxN*2], pre[maxN*2], inqueue[maxN*2];

int MCMF(int,int,int);
bool SPFA(int,int,int);

int main()
{
    int rowNum, colNum;
    char identifier;

    int manNum, houseNum, totalSize;

    while(scanf("%d%d", &rowNum, &colNum) && rowNum) {
        scanf("%*c");

        man.clear();
        house.clear();

        for (int row = 0; row < rowNum; row++) {
            for (int col = 0; col < colNum; col++) {
                scanf("%c", &identifier);

                pair<int,int> pos(row,col);
                if (identifier == 'm')
                    man.push_back(pos);
                else if (identifier == 'H')
                    house.push_back(pos);
            }
            scanf("%*c");
        }

        manNum = man.size();
        houseNum = house.size();
        totalSize = manNum + houseNum;

        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));
        memset(flow, 0, sizeof(flow));

        for (int m = 1; m <= manNum; m++)
            for (int h = 1; h <= house.size(); h++) {
                cap[m][h+manNum] = INF;
                cost[m][h+manNum] = abs((double)(man[m-1].first - house[h-1].first)) + abs((double)(man[m-1].second - house[h-1].second));
                cost[h+manNum][m] = -cost[m][h+manNum];
            }

        for (int m = 1; m <= manNum; m++) {
            cap[0][m] = 1;
            cap[m+manNum][manNum+houseNum+1] = 1;
        }

        int minCost = MCMF(0, totalSize + 1, totalSize + 2);
        printf("%d\n", minCost);
    }
}

int MCMF(int source, int des, int size) {
    int maxFlow = 0, minCost = 0;
    while(SPFA(source, des, size)) {
        int f = INF;
        for (int i = des; i != source; i = pre[i]) {
            if (flow[i][pre[i]] > 0)
                f = min(f, flow[i][pre[i]]);
            else if (cap[pre[i]][i] - flow[pre[i]][i] > 0)
                f = min(f, cap[pre[i]][i] - flow[pre[i]][i]);
        }

        for (int i = des; i != source; i = pre[i]) {
            if (flow[i][pre[i]] > 0)
                flow[i][pre[i]] -= f;
            else if (cap[pre[i]][i] - flow[pre[i]][i] > 0)
                flow[pre[i]][i] += f;
        }
        maxFlow += f;
        minCost += f*dis[des];
    }
    return minCost;
}

bool SPFA(int source, int des, int size) {
    queue<int> q;
    memset(inqueue, false, sizeof(inqueue));
    memset(pre, -1, sizeof(pre));
    for (int i = source; i <= des; i++)
        dis[i] = INF;

    dis[source] = 0;
    inqueue[source] = true;
    q.push(source);

    int current;
    while (!q.empty()) {
        current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = source; i <= des; i++) {
    
            if (cap[current][i] - flow[current][i] > 0 && dis[i] > dis[current] + cost[current][i]) {
                dis[i] = dis[current] + cost[current][i];
                pre[i] = current;
                if (!inqueue[i]) {
                    inqueue[i] = true;
                    q.push(i);
                }
            } else if (flow[i][current] > 0 && dis[current] - cost[i][current] < dis[i]) {
                dis[i] = dis[current] - cost[i][current];
                pre[i] = current;
                if (!inqueue[i]) {
                    q.push(i);
                    inqueue[i] = true;
                }
            }
        }   
    }
    return pre[des] != -1;
}
