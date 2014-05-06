#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 105


int A[maxN], B[maxN];

vector<int>edge[maxN];

int llink[maxN], rlink[maxN];
bool visited[maxN];

void initEdge(int n, int m);
int Bipartite(int,int);
bool DFS(int);


int main()
{
    int caseNum;
    int n, m;
    int caseCounter = 1;
    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);

        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &B[i]);

        initEdge(n, m);

        printf("Case %d: %d\n", caseCounter++, Bipartite(n,m));
    }
}

void initEdge(int n, int m) {
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
        for (int j = 1; j <= m; j++)
            if (!A[i] && !B[j])
                edge[i].push_back(j);
            else if (A[i] && !(B[j] % A[i]))
                edge[i].push_back(j);
    }
}

int Bipartite(int nL, int nR) {
    int num = 0;
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));

    for (int i = 1; i <= nL; i++) {
        memset(visited, false, sizeof(visited));
        if (DFS(i))
            num++;
    }
    return num;
}

bool DFS(int current) {
    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];

        if (!visited[next]) {
            visited[next] = true;

            if (!rlink[next] || DFS(rlink[next])) {
                llink[current] = next;
                rlink[next] = current;
                return true;
            }
        }
    }
    return false;
}
