#include <cstdio>
#include <algorithm>
using namespace std;

#define maxN 10005

int num[maxN], MSS[maxN];

void findMSS(int n) {
    MSS[0] =num[0];
    for (int i = 1; i < n; i++) {
        MSS[i] = num[i];
        if (MSS[i-1] > 0)
            MSS[i] = MSS[i-1]+num[i];
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);

        findMSS(n);
        int max = -1;
        for (int i = 0; i < n; i++)
            if (MSS[i] > max)
                max = MSS[i];

        if (max < 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", max);
    }
}

