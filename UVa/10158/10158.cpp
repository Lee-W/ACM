#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 10005

int p[maxN*2], r[maxN*2];

void initial(int n) {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        p[i+maxN] = i+maxN;
        r[i] = 0;
        r[i+maxN] = 0;
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
        if (r[x] == r[y])
            r[y]++;
    }
}

bool areFriend(int x, int y) {
    if (findSet(x) == findSet(y))
        return true;
    return false;
}

bool areEmeny(int x, int y) {
    if (findSet(x+maxN) == findSet(y) || findSet(y+maxN) == findSet(x))
        return true;
    return false;
}

main()
{
    int n;
    int cmd, x, y;
    int xE,yE;

    scanf("%d", &n);
    initial(n);

    while(scanf("%d%d%d", &cmd, &x, &y) == 3 && cmd) {
        if (cmd == 1) {
            if (areEmeny(x,y)) {
                printf("-1\n");
                continue;
            }
            xE = findSet(x + maxN);
            yE = findSet(y + maxN);
            x = findSet(x);
            y = findSet(y);
            if (x != y) {
                unionSet(x,y);
                unionSet(xE, yE);
            }
        } else if (cmd == 2) {
            if (areFriend(x,y) || x==y) {
                printf("-1\n");
                continue;
            }
            xE = findSet(x + maxN);
            yE = findSet(y + maxN);
            x = findSet(x);
            y = findSet(y);
            if (xE != y)
                unionSet(xE, y);
            if (x != yE)
                unionSet(x, yE);
        } else if (cmd == 3)
            printf("%d\n", areFriend(x,y));
        else if (cmd == 4)
            printf("%d\n", areEmeny(x,y));
    }
}
