#include <cstdio>
#include <vector>
using namespace std;

#define maxN 105

int rec[maxN][maxN];
int num[maxN], MMS[maxN];

int findMaxMMS(int,int,int);

main()
{
    int max = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &rec[i][j]);

    int tmpMax;
    for (int blockSize = 1; blockSize < n; blockSize++)
        for (int rowStart = 0; rowStart < n-blockSize+1; rowStart++) {
            tmpMax = findMaxMMS(blockSize, rowStart, n);
            max = (max > tmpMax) ? max : tmpMax;
        }

    printf("%d\n", max);
}

int findMaxMMS(int blockSize, int rowStart, int n) {
    int max = 0;
    vector<int>num,MMS;
    num.resize(n);
    MMS.resize(n);

    //initial MMS
    for (int col = 0; col < n; col++)
        for (int row = rowStart; row < rowStart+blockSize; row++)
            num[col] += rec[row][col];

    //findMMS
    MMS[0]= num[0];
    for (int i = 1; i < n; i++)
        if (MMS[i-1] > 0)
            MMS[i] = MMS[i-1] + num[i];
        else
            MMS[i] = num[i];

    //max
    for (int i = 0; i < n; i++)
        if (MMS[i] > max)
            max = MMS[i];

    return max;
}
