#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxH 45
#define maxW 15

bool map[maxH][maxW];

vector<int>edge[maxH*maxW];

int llink[maxH*maxW], rlink[maxH*maxW];
bool visited[maxH*maxW];

void initEdge(int, int);
int Bipartite(int,int);
bool DFS(int);

int main()
{
    int caseNum;
    int h, w;
    char tmp;
    int numOfInterestPlace;

    scanf("%d", &caseNum);
    while(caseNum--) {
        numOfInterestPlace = 0;
        memset(map, 0, sizeof(map));

        scanf("%d%d", &h, &w);
        scanf("%*c");
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                scanf("%c", &tmp);
                map[i][j] = (tmp == '*');
                if (map[i][j])
                    numOfInterestPlace++;
            }
            scanf("%*c");
        }

        initEdge(h, w);
        printf("%d\n", numOfInterestPlace - Bipartite(h*w,h*w)/2);
    }
}

void initEdge(int h, int w) {
    for (int i = 1; i <= maxH*maxW; i++)
        edge[i].clear();

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!map[i][j])
                continue;
            if (i>1 && map[i][j] && map[i-1][j])    //north
                edge[(i-1)*w + j].push_back((i-2)*w + j);
            if (j>1 && map[i][j] && map[i][j-1])    //west
                edge[(i-1)*w + j].push_back((i-1)*w + j-1);

            if (i<h && map[i][j] && map[i+1][j])    //south
                edge[(i-1)*w + j].push_back(i*w + j);
            if (j<w && map[i][j] && map[i][j+1])    //east
                edge[(i-1)*w + j].push_back((i-1)*w + j+1);
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
