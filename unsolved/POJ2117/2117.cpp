#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 10005

// for articulation point
vector<int> edge[maxN];
int low[maxN], dfn[maxN];

vector<int>articulationPoint;

//for tarjan
bool visited[maxN], inStack[maxN];
stack<int> s;
int num, counter;
int SCC[maxN];

void init(int);
void DFS(int,int,int);
void initTarjan(int);
void tarjan(int, int);

int main()
{
    int P, C;
    int first, second;
    int caseNum = 0;
    int maxNum;

    while (scanf("%d%d", &P, &C) && (P||C)) {
        maxNum = 0;
        init(P);
        while(C--) {
            scanf("%d%d", &first, &second);
            edge[first + 1].push_back(second + 1);
            edge[second + 1].push_back(first + 1);
        }

        DFS(1,0,1);
        if (!articulationPoint.size()) {
            initTarjan(P);
            for (int j = 1; j <= P; j++)
                if (!visited[j])
                    tarjan(j, 0);
            printf("%d\n", num);
        } else if (!C) {
            printf("%d\n", P-1);
        } else {
            for (int i = 0; i < articulationPoint.size(); i++) {

                initTarjan(P);
                for (int j = 1; j <= P; j++)
                    if (!visited[j] && j != articulationPoint[i])
                        tarjan(j, articulationPoint[i]);
                maxNum = max(maxNum, num);
            }
            printf("%d\n", maxNum);
       }
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
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
