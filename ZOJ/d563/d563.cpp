#include <cstdio>
using namespace std;

#define maxN 1000005

main()
{
    int numbers[maxN];
    int n;
    int result = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    int leftCounter = 0, rightCounter = n-1;
    int leftSum = numbers[leftCounter], rightSum = numbers[rightCounter];

    while(leftCounter < n && rightCounter >=0) {
        if (leftSum > rightSum)
            rightSum += numbers[--rightCounter];
        else if (leftSum < rightSum)
            leftSum += numbers[++leftCounter];
        else {
            result++;
            leftSum += numbers[++leftCounter];
            rightSum += numbers[--rightCounter];
        }
    }
    printf("%d\n", result);
}
