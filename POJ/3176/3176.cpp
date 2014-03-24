#include <cstdio>

#define maxN 355

int bowling[maxN][maxN], sum[maxN][maxN];

void countSum(int);

main()
{
    int max = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            scanf("%d", &bowling[i][j]);
            sum[i][j] = bowling[i][j];
        }

    countSum(n);

    for (int i = 0; i < n; i++)
        if (max < sum[n-1][i])
            max = sum[n-1][i];
    printf("%d\n", max);
}

void countSum(int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j <= i; j++) {
            if (sum[i][j] + bowling[i+1][j] > sum[i+1][j])
                sum[i+1][j] = sum[i][j] + bowling[i+1][j];
            if (sum[i][j] + bowling[i+1][j+1] > sum[i+1][j+1])
                sum[i+1][j+1] = sum[i][j] + bowling[i+1][j+1];
        }
}
