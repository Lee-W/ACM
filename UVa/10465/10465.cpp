#include <cstdio>
#include <cmath>

int main()
{
    int m, n, t;
    int small, large, smallNum, largeNum;
    int max, gap, smallestGap;

    while(scanf("%d%d%d", &m, &n, &t) == 3) {
        small = (m < n ? m : n);
        large = (m > n ? m : n);

        smallNum = t/small;
        largeNum = 0;

        max = smallNum + largeNum;
        gap = t - smallNum * small;
        smallestGap = gap;

        for (int i = 1; i <= t/large; i++) {
            int tmpNum = ceil((double)(large - gap)/small);
            smallNum -= tmpNum;
            largeNum++;
            gap += (tmpNum*small - large);
            if (gap < smallestGap) {
                smallestGap = gap;
                max = largeNum + smallNum;
                if (!gap)
                    break;
            }
        }

        if (smallestGap)
            printf("%d %d\n", max, smallestGap);
        else
            printf("%d\n", max);
    }
}
