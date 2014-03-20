#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 10005

//int relation[maxN][maxN]; //1 as friend, -1 as enemy, 0 as unknow
vector<bool> isEmeny[maxN];
int p[maxN], r[maxN];

void initial(int n) {
    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++)
  //          relation[i][j] = 0;

        p[i] = i;
        r[i] = 0;
    }
}

int findSet(int x) {
    if (p[x] == x)
        return p[x];
    return p[x] = findSet(p[x]);
}

void unionSet(int x, int y) {
    if (r[x] > r[y])
        p[y] = x;
    else {
        p[x] = y;
        if (p[x] == p[y])
            p[y]++;
    }
}

bool areFriend(int x, int y) {
    if (findSet(x) == findSet(y))
        return true;
    return false;
}

bool areEmeny(int x, int y) {
//    if (relation[findSet(x)][findSet(y)] == -1)
    if (find(isEmeny[findSet(x)].begin(), isEmeny[findSet(x)].end(), findSet(y)) != isEmeny[findSet(x)].end())
        return true;
    return false;
}

main()
{
    int n;
    int cmd, x, y;

    scanf("%d", &n);
    initial(n);

    while(scanf("%d%d%d", &cmd, &x, &y) == 3 && cmd) {
//        printf("This is cmd %d\t%d\t%d\n", cmd,x,y);
        if (cmd == 1) {
            if (areEmeny(x,y)) {
                printf("-1\n");
                continue;
            }
            x = findSet(x);
            y = findSet(y);
            if (x != y)
                unionSet(x,y);
        } else if (cmd == 2) {
            if (areFriend(x,y)) {
                printf("-1\n");
                continue;
            }
            x = findSet(x);
            y = findSet(y);
            isEmeny[x].push_back(y);
            isEmeny[y].push_back(x);
//            relation[x][y] = relation[y][x]= -1;
  //          relation[findSet(x)][findSet(y)] = relation[findSet(y)][findSet(x)] = -1;
        } else if (cmd == 3) {
            printf("%d\n", areFriend(x,y));
        } else if (cmd == 4) {
            printf("%d\n", areEmeny(x,y));
        }
    }
}
