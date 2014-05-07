#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 505

vector<int>edge[maxN];

int llink[maxN], rlink[maxN];
bool visited[maxN];

void initEdge(int);
int Bipartite(int,int);
bool DFS(int);

int main()
{
    int caseNum;
    int n, k;
    int tmp;

    scanf("%d\n", &caseNum);
    for (int caseNo = 1; caseNo <= caseNum; caseNo++) {
        scanf("%d%d", &n, &k);
        initEdge(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++) {
                scanf("%d", &tmp);
                if (tmp)
                    edge[i].push_back(j);
            }

		printf("Case %d: ", caseNo);
		printf("a maximum of %d nuts and bolts ", Bipartite(n, k));
		printf("can be fitted together\n");
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
