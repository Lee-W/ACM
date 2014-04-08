#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define maxN 105
#define maxEdgeNum 10000
#define nINF INT_MAX/5*-1

vector<int> edge[maxEdgeNum];
int dis[maxN];

void LPFA(int n, int source) {
    queue<int> q;
    bool inqueue[n+1];
    for (int i = 1; i <= n; i++) {
        inqueue[i] = false;
        dis[i] = nINF;
    }

    dis[source] = 0;
    inqueue[source] = true;
    q.push(source);

    while(!q.empty()) {
        int current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = 0; i < edge[current].size(); i++) {
            int des = edge[current][i];
            if (dis[current] + 1 > dis[des]) {
                dis[des] = dis[current] + 1;
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
    int n, s, p, q;
    int caseCounter = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        scanf("%d", &s);
        while(scanf("%d%d", &p, &q) && p && q)
            edge[p].push_back(q);
        
        LPFA(n, s);

        int maxLen = 0, des;
        for (int i = 1; i <= n; i++)
            if (maxLen < dis[i]) {
                maxLen = dis[i];
                des = i;
            }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", caseCounter, s, maxLen, des);
        printf("\n");
        caseCounter++;
    }
}
