#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 505

vector<int>edge[maxN];

int llink[maxN], rlink[maxN];
bool visited[maxN];

int Bipartite(int,int);
bool DFS(int);

int main()
{
    int n, k;
    int r, c;
    scanf("%d%d", &n, &k);
    while(k--) {
        scanf("%d%d", &r, &c);
        edge[r].push_back(c);
    }
    printf("%d", Bipartite(n, n));
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
