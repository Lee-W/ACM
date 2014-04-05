//這題cin會TLE@@
#include <cstdio>
#include <cstring>

#define maxCaseNum 25
#define maxN 100005

//  1-based
int p[maxN*2], r[maxN*2];
int caseNum, n, m;

void initSet() {
    for (int i = 1; i <= n*2; i++) {
        p[i] = i;
        r[i] = 1;
    }
}

int findSet(int x) {
    if (p[x] == x)
        return x;
    return p[x] = findSet(p[x]);
}

void unionSet(int x, int y) {
    if (r[x] > r[y])
        p[y] = p[x];
    else {
        p[x] = p[y];
        if (r[x] == r[y])
            r[y]++;
    }
}

void ask(int x, int y) {
    int xE = findSet(x+n);
    int yE = findSet(y+n);
    x = findSet(x);
    y = findSet(y);
    if (x == y)
        printf("In the same gang.\n");
    else if (x == yE || y == xE)
        printf("In different gangs.\n");
    else
        printf("Not sure yet.\n");
}

void different(int x, int y) {
    int xE = findSet(x+n);
    int yE = findSet(y+n);
    x = findSet(x);
    y = findSet(y);

    unionSet(x, yE);
    unionSet(y, xE);
}

main ()
{
    char cmd;
    int first, second;

    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d%d%*c", &n, &m);   //%*c to ignore \n since scanf(%c) would get \n
        initSet();
        while (m--) {
            scanf("%c%d%d%*c", &cmd, &first, &second);
            if (cmd == 'A')
                ask(first, second);
            else if (cmd == 'D')
                different(first, second);
        }
    }
}
