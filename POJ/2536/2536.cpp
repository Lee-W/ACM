#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

#define MAX 105

typedef std::pair<double, double> point;

point gopher[MAX], hole[MAX];
vector<int>edge[MAX];

int llink[MAX], rlink[MAX];
bool visited[MAX];

void initEdge(int,int,int);
int Bipartite(int,int);
bool DFS(int);

int main()
{
    int n, m, s, v;

    while(scanf("%d%d%d%d", &n, &m, &s, &v) == 4) {
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &gopher[i].first, &gopher[i].second);
        for (int i = 1; i <= m; i++)
            scanf("%lf%lf", &hole[i].first, &hole[i].second);
        initEdge(n, m, s*v);
        printf("%d\n", n - Bipartite(n, m));
    }
}

void initEdge(int n, int m, int limit) {
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
        for (int j = 1; j <= m; j++) {
            double dis = sqrt(pow(gopher[i].first - hole[j].first, 2) + pow(gopher[i].second - hole[j].second, 2));
            if (dis <= limit)
                edge[i].push_back(j);
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
