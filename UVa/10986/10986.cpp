#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define INF INT_MAX/5
#define maxN 20005
#define maxM 50005

struct edge {
    int destination;
    int cost;
    void init(int d, int c) {
        destination = d;
        cost = c;
    }
};

vector<edge> e[maxN];
int dis[maxN];

void SPFA(int vertexNum, int source) {
    queue<int> q;

    bool inqueue[vertexNum];
    for (int i = 0; i < vertexNum; i++) {
        dis[i] = INF;
        inqueue[i] = false;
    }
    dis[source] = 0;
    inqueue[source] = true;
    q.push(source);

    while(!q.empty()) {
        int current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = 0; i < e[current].size(); i++) {
            int des = e[current][i].destination;
            int cost = e[current][i].cost;
            if (dis[current] + cost < dis[des]) {
                dis[des] = dis[current] + cost;
                if (!inqueue[des]) {
                    q.push(des);
                    inqueue[des] = true;
                }
            }
        }
        
    }
}

main()
{
    int caseNum, vertexNum, edgeNum, source, destination;
    int start, end, cost;
    edge tmp;

    scanf("%d", &caseNum);

    for (int CASE = 1; CASE <= caseNum; CASE++) {
        scanf("%d%d%d%d", &vertexNum, &edgeNum, &source, &destination);
        for (int i = 0; i < vertexNum; i++)
            e[i].clear();
        while(edgeNum--) {
            scanf("%d%d%d", &start, &end, &cost);
            tmp.init(end, cost);
            e[start].push_back(tmp);
            tmp.init(start, cost);
            e[end].push_back(tmp);
        }

        SPFA(vertexNum, source);

        printf("Case #%d: ", CASE);
        if (dis[destination] == INF)
            printf("unreachable\n");
        else
            printf("%d\n", dis[destination]);
    }
}
