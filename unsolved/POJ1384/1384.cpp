#include <cstdio>

#define maxN 505

int P[maxN], W[maxN];

int main()
{
    int caseNum;
    int E, F, N;

    int moneyWeight;

    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d%d", &E, &F, &N);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &P[i], &W[i]);
        moneyWeight = F - E;
        count(n, moneyWeight);
    }
}
