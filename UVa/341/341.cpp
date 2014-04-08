#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define INF INT_MAX/2
#define maxVertexNum 15

struct edge {
    int destination;
    int cost;
};

vector<edge> e[maxVertexNum];
int dis[maxVertexNum];
int pre[maxVertexNum];

void SPFA(int vertexNum, int source) {
    queue<int> q;
    bool inqueue[vertexNum+1];
    for (int i = 1; i <= vertexNum; i++) {
        dis[i] = INF;
        inqueue[i] = false;
    }
    dis[source] = 0;
    pre[source] = -1;
    inqueue[source] = true;
    q.push(source);
    
    while(!q.empty()) {
        int current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = 0; i < e[current].size(); i++) {
            int destination = e[current][i].destination;
            int cost = e[current][i].cost;
            if (dis[current] + cost < dis[destination]) {
                dis[destination] = dis[current] + cost;
                pre[destination] = current;
                if (!inqueue[destination]) {
                    q.push(destination);
                    inqueue[destination]  = true;
                }
            }
        }
    }
}

main()
{
    int n, edgeNum, source, des;
    int caseCounter = 1;

    while(scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            scanf("%d", &edgeNum);
            while (edgeNum--) {
                edge tmp;
                scanf("%d%d", &tmp.destination, &tmp.cost);
                e[i].push_back(tmp);
            }
        }
        scanf("%d%d", &source, &des);
        SPFA(n, source);

        int last = des;
        vector<int>seq;
        while(pre[last] != -1) {
            seq.push_back(last);
            last = pre[last];
        }
        seq.push_back(source);

        printf("Case %d: Path =", caseCounter++);
        for (int i = seq.size()-1; i >= 0; i--)
            printf(" %d", seq[i]);
        printf("; %d second delay\n", dis[des]);
    }
}
