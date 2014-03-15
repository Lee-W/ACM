#include <cstdio>
#include <algorithm>

#define maxArrayNum 755
#define INF 1000005

main()
{
    int arrayNum;
    int arrays[maxArrayNum][maxArrayNum];
    int indexes[maxArrayNum];
    int minSums[maxArrayNum];

    while(scanf("%d", &arrayNum) == 1) {
        for (int i = 0; i < arrayNum; i++) {
            for (int j = 0; j < arrayNum; j++)
                scanf("%d", &arrays[i][j]);
            std::sort(arrays[i], arrays[i]+arrayNum);
            indexes[i] = 0;
            minSums[i] = 0;
        }

        for (int sumRate = 0; sumRate < arrayNum; sumRate++) {
            for (int arrayID = 0; arrayID < arrayNum; arrayID++) 
                minSums[sumRate] += arrays[arrayID][indexes[arrayID]];

            int minDiff = INF, minDiffID, diff;

            for (int arrayID = 0; arrayID < arrayNum; arrayID++) {
                diff = arrays[arrayID][indexes[arrayID]+1] - arrays[arrayID][indexes[arrayID]];
                if (diff < minDiff) {
                    minDiff = diff;
                    minDiffID = arrayID;
                }

            }
            indexes[minDiffID]++;
        }

        for (int i = 0; i < arrayNum; i++) 
            printf("%d ", minSums[i]);
        printf("\n");
    }
}
