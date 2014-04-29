#include <cstdio>
#include <cstring>
#include <cmath>

#define maxCash 100005
#define maxN 10*10 + 5

int number[maxN], value[maxN];
bool dp[maxCash];

int count(int n, int cash) {
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int k = cash; k >= value[i]; k--)
            dp[k] = dp[k] || dp[k - value[i]];

    int max = 0;
    for (int i = 1; i <= cash; i++)
        if (dp[i] && i > max)
            max = i;
    return max;
}

int main()
{
    int cash, n;
    int num, val;

    while(scanf("%d%d", &cash, &n) == 2) {
        int counter = 0, power2;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &num, &val);

            power2 = 1;
            while (num >= power2) {
                number[counter] = power2;
                value[counter] = power2 * val;
                num -= power2;
                power2 *= 2;
                counter++;
            }
            if (num) {
                number[counter] = num;
                value[counter] = num * val;
                counter++;
            }
        }

        printf("%d\n", count(counter, cash));
    }
}
