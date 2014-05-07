#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxR 1005
#define maxC 1005
#define maxN maxR*maxC

vector<int>edge[maxN];

int llink[maxN], rlink[maxN];
bool visited[maxN];

int Bipartite(int,int);
bool DFS(int);

int main()
{
    int r, c, n;
    int x, y;
    while(scanf("%d%d%d", &r, &c, &n) && r) {
        while(n--) {
            scanf("%d%d", &y, &x);
            edge[y].push_back(x);
        }
        printf("%d", Bipartite(r, c));

        printf("\n");
        for (int i = 1; i <= r; i++)
            if (!llink[i])
            printf("%d\t" , i);
        printf("\n");
        // for (int i = 1; i <= c; i++)
        //     if (rlink[i])
        //     printf("%d\t", i);
        // printf("\n");
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
