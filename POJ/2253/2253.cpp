#include <cstdio>
#include <cmath>
#include <utility>

#define maxN 205

typedef std::pair<int,int> point;

point p[maxN];
float dis[maxN][maxN];


void countDis(int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            dis[i][j] = sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));
            dis[j][i] = dis[i][j];
        }
}

void Floyd(int n) {
    for (int m = 0; m < n; m++)
        for (int s = 0; s < n; s++)
            for (int d = 0; d < n ; d++) {
                float distance = (dis[s][m] > dis[m][d] ? dis[s][m] : dis[m][d]);
                if (distance < dis[s][d])
                    dis[s][d] = distance;
            }
}

main()
{
    int n, x ,y;
    int caseCounter = 1;
    while(scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].first, &p[i].second);

        countDis(n);
        Floyd(n);
        printf("Scenario #%d\n", caseCounter++);
        printf("Frog Distance = %.3f\n\n", dis[0][1]);
    }
}
