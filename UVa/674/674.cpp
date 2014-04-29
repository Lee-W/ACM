#include <cstdio>
#include <cstring>

#define sizeOfChangeType 5
#define maxMoney 7500

int changeType[sizeOfChangeType] = {50, 25, 10, 5, 1};
int dp[maxMoney];

int count(int money) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < sizeOfChangeType; i++)
        for (int j = changeType[i]; j <= money; j++)
            if (j - changeType[i] >= 0)
                dp[j] += dp[j - changeType[i]];
    return dp[money];
}

int main()
{
    int money;
    while(scanf("%d", &money) == 1)
        printf("%d\n", count(money));
}
