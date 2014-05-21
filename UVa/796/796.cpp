#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

#define maxN 105

vector<int> edge[maxN];
int low[maxN], dfn[maxN];

vector< pair<int,int> >bridge;

void init(int);
void DFS(int,int,int);

bool cmp(pair<int,int> b1, pair<int,int> b2) {
    if (b1.first == b2.first)
        return b1.second < b2.second;
    return b1.first < b2.first;
}

int main()
{
    int vertexNum;
    int source, edgeNum, destination;
    while (scanf("%d", &vertexNum) == 1) {
        init(vertexNum);
        for (int i = 1; i <= vertexNum; i++) {
            scanf("%d (%d)", &source, &edgeNum);
            while(edgeNum--) {
                scanf("%d", &destination);
                edge[source+1].push_back(destination+1);
                edge[destination+1].push_back(source+1);
            }
        }

        for (int i = 1; i <= vertexNum; i++)
            if (!dfn[i])
                DFS(i, 0, 1);

        sort(bridge.begin(), bridge.end(), cmp);
        printf("%d critical links\n", (int)bridge.size());
        for (int i = 0; i < (int)bridge.size(); i++)
            printf("%d - %d\n", bridge[i].first-1, bridge[i].second-1);
        printf("\n");
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    bridge.clear();
}

void DFS(int current, int parent, int counter) {
    int child = 0;

    dfn[current] = low[current] = counter++;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];
        if (!dfn[next]) {
            child++;
            DFS(next, current, counter);
            low[current] = min(low[current], low[next]);

            if (low[next] > dfn[current]) {
                pair<int,int>tmp;
                tmp.first = min(current ,next);
                tmp.second = max(current ,next);
                bridge.push_back(tmp);
            }
        } else if (next != parent)
            low[current] = min(low[current], dfn[next]);
    }
}
