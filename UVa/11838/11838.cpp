#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

#define maxN 2005

vector<int> edge[maxN];
int dfn[maxN], low[maxN];
bool visited[maxN], inStack[maxN];
stack<int> s;
int num;

void init(int);
void tarjan(int, int);
int main()
{
    int n, m;
    int v, w, p;
    while(scanf("%d%d", &n, &m) && n) {
        init(n);
        while(m--) {
            scanf("%d%d%d", &v, &w, &p);
            edge[v].push_back(w);

            if (p == 2)
                edge[w].push_back(v);
        }

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                tarjan(i, 1);

        printf("%d\n", num == 1);
    }
}
void init(int n) {
    for (int i = 1; i <= n; i++)
        edge[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(visited, false, sizeof(visited));
    memset(inStack, false, sizeof(inStack));
    while(!s.empty())
        s.pop();
    num = 0;
}

void tarjan(int current, int counter) {
    dfn[current] = low[current] = counter++;

    s.push(current);
    inStack[current] = true;
    visited[current] = true;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];

        if (!visited[next]) {
            tarjan(next, counter);
            low[current] = min(low[current], low[next]);
        } else if (inStack[next])
            low[current] = min(low[current], low[next]);
    }

    if (dfn[current] == low[current]) {
        int next = s.top();
        inStack[next] = false;
        s.pop();
        while(current != next) {
            next = s.top();
            inStack[next] = false;
            s.pop();
        }
        num++;
    }
}
