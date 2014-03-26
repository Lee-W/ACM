#include <cstdio>

#define maxN 1005

double height[maxN];

int LIS[maxN], RLIS[maxN], LDS[maxN];

void findLIS(int n) {
    for (int i = 0; i < n; i++) {
        LIS[i] = 1;
        for (int j = 0; j < i; j++)
            if (height[i] > height[j] && LIS[i] < LIS[j] + 1)
                LIS[i] = LIS[j] + 1;
    }
}

void findRLIS(int n) {
    for (int i = n-1; i > -1; i--) {
        RLIS[i] = 1;
        for (int j = n-1; j > i; j--)
            if (height[i] > height[j] && RLIS[i] < RLIS[j] + 1)
                RLIS[i] = RLIS[j] + 1;
    }
}

void findLDS(int n) {
    for (int i = 0; i < n; i++) {
        LDS[i] = 1;
        for (int j = 0; j < i; j++)
            if (height[i] < height[j] && LDS[i] < LDS[j] + 1)
                LDS[i] = LDS[j] + 1;
    }
}

main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &height[i]);
    findLIS(n);
    findRLIS(n);

    int max = 0, peak;
    for (int i = 0; i < n; i++)
        if (max < LIS[i]+RLIS[i]) {
            max = LIS[i]+RLIS[i]; 
            peak = i;
        }

    int peakNum = 0;
    for (int i = peak+1; i < n; i++)
        if (height[i] == height[peak])
            peakNum++;

    if (peakNum)
        printf("%d\n", n-max);
    else if (!peakNum)
        printf("%d\n", n-max+1);
} 
