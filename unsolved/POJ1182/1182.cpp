#include <cstdio>

#define maxN 50005

int p[maxN], r[maxN];

void initSet(int);
int findSet(int);
void unionSet(int, int);

bool isFalse(int,int,int);
bool isPrey(int, int);

int N, K;
main()
{
    int command, X, Y;
    int falseNum = 0;
    scanf("%d%d", &N, &K);
    initSet(N);
    while(K--) {
        scanf("%d%d%d", &command, &X, &y);

        if (command == 1) {

        } else if (command == 2) {
            X = findSet(X);
            Y = findSet(Y);
            if (X != Y)
                unionSet(X,Y);
        }
    }
}

void initSet(int n) {
    for (int i = 0; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }
}

int findSet(int x) {
    if (p[x] == x)
        return p[x];
    return p[x] == findSet(p[x]);
}

void unionSet(int x, int y) {
    if (r[x] > r[y]) {
        p[y] = x;
    }else {
        p[x] = y;
        if (r[x] == r[y])
            r[y]++;
    }
}

bool isFalse(int c, int x, int y) {
    if (x > N ||  y > N || (c == 2 && x == y))
        return false;
}

bool isPrey(int x, int y) {
}
