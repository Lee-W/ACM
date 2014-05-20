#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 1005

// for articulation point
vector<int> edge[maxN];
int low[maxN], dfn[maxN];

vector<int>articulationPoint;

//for tarjan
bool visited[maxN], inStack[maxN];
stack<int> s;
int num, counter;
int SCC[maxN];

void init();
void DFS(int,int,int);
void initTarjan(int);
void tarjan(int, int ap);

int main()
{
    int first, second;
    int start, end;
    int caseNum = 0;

    while (scanf("%d", &first) && first) {
        caseNum++;
        start = maxN, end = 0;

        init();
        while (first) {
            scanf("%d", &second);

            end = max(end, max(first, second));
            start = min(start, min(first, second));

            edge[first].push_back(second);
            edge[second].push_back(first);
            scanf("%d", &first);
        }
        DFS(1,0,1);
        sort(articulationPoint.begin(), articulationPoint.end());

        printf("Network #%d\n", caseNum);

        if (!articulationPoint.size())
            printf("  No SPF nodes\n");
        else {
            int n = end - start + 1;
            for (int i = 0; i < articulationPoint.size(); i++) {

                initTarjan(n);
                for (int j = start; j <= end; j++)
                    if (!visited[j] && j != articulationPoint[i])
                        tarjan(j, articulationPoint[i]);

                printf("  SPF node %d leaves %d subnets\n", articulationPoint[i], num);
            }
        }
        printf("\n");
    }
}

void init() {
    for (int i = 0; i <= maxN; i++)
        edge[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    articulationPoint.clear();
}

void DFS(int current, int parent, int counter) {
    int child = 0;
    bool isArticulationPoint = false;

    dfn[current] = low[current] = counter++;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];
        if (!dfn[next]) {
            child++;
            DFS(next, current, counter);
            low[current] = min(low[current], low[next]);

            if (low[next] >= dfn[current])
                isArticulationPoint = true;
        } else if (next != parent)
            low[current] = min(low[current], dfn[next]);
    }
    if ((child >= 2 || parent > 0) && isArticulationPoint) {
        articulationPoint.push_back(current);
    }
}


void initTarjan(int n) {
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(visited, false, sizeof(visited));
    memset(inStack, false, sizeof(inStack));
    while(!s.empty())
        s.pop();
    num = 0;
    counter = 0;
}

void tarjan(int current, int ap) {
    dfn[current] = low[current] = counter++;

    s.push(current);
    inStack[current] = true;
    visited[current] = true;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];
        if (next == ap)
            continue;

        if (!visited[next]) {
            tarjan(next, ap);
            low[current] = min(low[current], low[next]);
        } else if (inStack[next])
            low[current] = min(low[current], dfn[next]);
    }

    if (dfn[current] == low[current]) {
        num++;
        SCC[current]= num;

        int next = 0;
        while(current != next) {
            SCC[next] = num;
            next = s.top();
            inStack[next] = false;
            s.pop();
        }
    }
}
