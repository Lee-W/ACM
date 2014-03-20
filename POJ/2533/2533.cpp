#include <cstdio>

#define maxN 1005

int sequence[maxN], LIS[maxN];

void findLIS(int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        LIS[i] = 1;
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i] && LIS[j]+1 > LIS[i])
                LIS[i] = LIS[j]+1;
        }
            if (LIS[i] > max)
                max = LIS[i];
    }
    printf("%d\n", max);

}

main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &sequence[i]);

    findLIS(n);
}
