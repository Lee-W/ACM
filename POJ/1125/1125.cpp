#include <cstdio>
#include <climits>
#include <numeric>
#include <algorithm>

#define maxStockholderNum 105

int dis[maxStockholderNum][maxStockholderNum];

void Floyd(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}

main()
{
    int stockholderNum, pairNum, contact, time;
    while(scanf("%d", &stockholderNum) && stockholderNum) {
        //initial dis
        for (int i = 1; i <= stockholderNum; i++) {
            for (int j = 1; j <= stockholderNum; j++)
                dis[i][j] = INT_MAX/2;
            dis[i][i] = 0;

            scanf("%d", &pairNum);
            while(pairNum--) {
                scanf("%d%d", &contact, &time);
                dis[i][contact] = time;
            }
        }
        Floyd(stockholderNum);

        int sum = INT_MAX, tmpSum;
        int source, max = 0;
        for (int i = 1; i <= stockholderNum; i++) {
            if (std::find(dis[i]+1, dis[i]+stockholderNum+1, INT_MAX/2) != dis[i]+stockholderNum+1) {
                continue;
            } else
                tmpSum = std::accumulate(dis[i]+1, dis[i]+stockholderNum+1, 0);

            if (tmpSum < sum) {
                source = i;
                sum = tmpSum;
            }
        }

        if (sum != INT_MAX) {
            max = *std::max_element(dis[source]+1, dis[source]+stockholderNum+1);
            printf("%d %d\n", source, max);
        }
        else
            printf("disjoint\n");   //測資好像沒這個也會AC@@
    }
}
