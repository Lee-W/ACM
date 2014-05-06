#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 35

int map[maxN][maxN];

vector<int>edge[maxN*maxN];

int llink[maxN*maxN], rlink[maxN*maxN];
bool visited[maxN*maxN];

void initEdge(int,int);
int Bipartite(int,int);
bool DFS(int);

int main()
{
    int m, n, k;
    int x, y;
    scanf("%d%d%d", &m, &n, &k);
    memset(map, 1, sizeof(map));
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        map[y][x] = 0;
    }
    initEdge(m, n);
    printf("%s\n", (Bipartite(m*n, m*n)+k == m*n)? "YES" : "NO");
}

void initEdge(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!map[i][j])
                continue;
            if (map[i][j] && map[i+1][j] && i < m)
                edge[(i-1)*n + j].push_back(i*n + j);
            if (map[i][j] && map[i][j+1] && j < n)
                edge[(i-1)*n + j].push_back((i-1)*n + (j+1));

            if (map[i][j] && map[i-1][j] && i > 1)
                edge[(i-1)*n + j].push_back((i-2)*n + j);
            if (map[i][j] && map[i][j-1] && j > 1)
                edge[(i-1)*n + j].push_back((i-1)*n + (j-1));
        }
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
