#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxN 1005
#define maxW 35

int price[maxN], weight[maxN];
int mw[maxN];

int dp[maxN][maxW];

void DP(int n, int w) {
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= w; j++)
            if (j < weight[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-weight[i]] + price[i]);
}

main()
{
    int t, n, g;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &price[i], &weight[i]);

        scanf("%d", &g);
        for (int i = 1; i <= g; i++)
            scanf("%d", &mw[i]);

        int sum = 0;
        DP(n, maxW);
        for (int i = 1; i <= g; i++) {
            sum += dp[n][mw[i]];
        }
        printf("%d\n", sum);
    }
}
