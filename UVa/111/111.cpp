#include <cstdio>

#define maxN 25

int ans[maxN], ansSeq[maxN];
int stuAns[maxN], stuAnsSeq[maxN], ansRate[maxN], LIS[maxN];

void findLIS(int n) {
    for (int i = 1; i <= n; i++) {
        LIS[i] = 1;
        for (int j = 1; j < i; j++)
            if (ansRate[i] > ansRate[j] && LIS[j]+1 > LIS[i])
                LIS[i] = LIS[j]+1;
    }
};

main()
{
    int n, tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &ans[i]);

    for (int i = 1; i <= n; i++)
        ansSeq[ans[i]] = i;

    while(scanf("%d", &tmp) == 1) {
        stuAns[1] = tmp;
        for (int i = 2; i <= n; i++)
            scanf("%d", &stuAns[i]);

        for (int i = 1; i <= n; i++)
            stuAnsSeq[stuAns[i]] = i;

        for (int i = 1; i <= n; i++)
            ansRate[i] = ans[stuAnsSeq[i]];

        findLIS(n);
        int max = 0;
        for (int i = 1; i <= n; i++)
            if (max < LIS[i])
                max = LIS[i];
        printf("%d\n",max);

    }
}
