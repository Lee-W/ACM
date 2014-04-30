#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 105
#define maxK 1005

vector<int>edge[maxK];

int llink[maxN], rlink[maxN];
bool visited[maxN];

void initEdge(int);
int Bipartite(int,int);
bool DFS(int);


int main()
{
    int n, m ,k;
    int i, x, y;

    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        initEdge(n);
        for (int i = 0; i < k; i++) {
            scanf("%d%d%d", &i, &x, &y);
            if (x && y)
                edge[x].push_back(y);
        }
        printf("%d\n", Bipartite(n,m));
    }

}

void initEdge(int n) {
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
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
    for (int i = 0; i < edge[current].size(); i++) {
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
