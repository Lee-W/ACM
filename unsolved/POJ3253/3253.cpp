#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

#define maxN 20005
#define INF 50005

int chargeForEachSplit(int, int);

int length[maxN];

main()
{
    int N;
    int cost;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &length[i]);

    sort(length, length+N);

    cost = chargeForEachSplit(0, N);
    printf("%d\n", cost);

}

int chargeForEachSplit(int start, int end) {
    int cost = accumulate(length + start, length+end, 0);
    int leftSum = length[start], rightSum = cost - length[start];

    int splitPoint = start+1;   //leftEnd and rightStart
    int minDiff = abs(rightSum - leftSum);
    int tmpDiff;

    for (int i = splitPoint; i < end; i++) {
        tmpDiff = abs(minDiff - length[i]*2);
        if (tmpDiff < minDiff) {
            minDiff = tmpDiff;
            splitPoint = i;
        } else
            break;
    }
//    printf("%d\t%d\t%d\n", start, end,cost);

    if (end - start > 2)
        cost += chargeForEachSplit(start, splitPoint+1) + chargeForEachSplit(splitPoint+1, end);
    else if (end - start == 1)
        return 0;

    return cost;
}
