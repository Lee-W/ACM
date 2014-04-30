#include <cstdio>
#include <cstring>

#define maxN 105
#define maxM 100005

int A[maxN];
int val[maxN * 10];
bool dp[maxM];

int count(int n, int m) {
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int v = m; v >= val[i]; v--)
            dp[v] = dp[v] || dp[v-val[i]];

    int num = 0;
    for (int i = 1; i <= m; i++)
        if (dp[i])
            num++;
    return num;
}

int main()
{
    int n, m;
    int num;
    int counter;
    while(scanf("%d%d", &n, &m) && n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        memset(val, 0, sizeof(val));
        counter = 0;
        int power2;

        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            power2 = 1;
            while(num >= power2) {
                val[counter] = A[i] * power2;
                num -= power2;
                power2 *= 2;
                counter++;
            }
            if (num) {
                val[counter] = A[i] * num;
                counter++;
            }
         }

        printf("%d\n", count(counter, m));

    }
}
