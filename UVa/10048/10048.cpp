#include <cstdio>
#include <climits>

#define maxC 105
#define maxS 1005
#define maxQ 10005
#define INF INT_MAX/5

int path[maxC][maxC];
int maxNoise[maxC][maxC];

void initPath(int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                path[i][j] = maxNoise[i][j] = 0;
            else
                path[i][j] = maxNoise[i][j] = INF;
}

void Floyd(int n) {
    for (int m = 1; m <= n; m++)
        for (int s = 1; s <= n; s++)
            for (int d = 1; d <= n; d++) {
                int noise = (path[s][m] > path[m][d] ? path[s][m] : path[m][d]);
                if (noise < path[s][d])
                    path[s][d] = noise;
            }
}

void query(int source, int des) {
    if (path[source][des] == INF)
        printf("no path\n");
    else
        printf("%d\n", path[source][des]);
}

main()
{
    int c, s, q;
    int source, des, noise;
    int caseCounter = 1;
    bool isFirstCase = true;

    while (scanf("%d%d%d", &c, &s, &q) && c) {
        initPath(c);
        while(s--) {
            scanf("%d%d%d", &source, &des, &noise);
            path[source][des] = noise;
            path[des][source] = noise;
        }
        Floyd(c);
        if (isFirstCase)
            isFirstCase = false;
        else
            printf("\n");
        printf("Case #%d\n", caseCounter++);
        while(q--) {
            scanf("%d%d", &source, &des);
            query(source, des);
        }
        
    }
}
