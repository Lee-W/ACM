#include <iostream>
#include <vector>
using namespace std;

#define maxN 30

int matrix[maxN][maxN];

int findMaxMMS(int,int,int);

main()
{
    ios::sync_with_stdio(false);

    string tmp;
    int n, max;

    int caseNum;
    cin >> caseNum;
    while(caseNum--) {
        max = 0;
        cin >> tmp;
        n = tmp.size();
        for (int i = 0; i < n; i++)
            matrix[0][i] = tmp[i] - '0';

        for (int i = 1; i < n; i++) {
            cin >> tmp;
            for (int j = 0; j < n; j++)
                matrix[i][j] = tmp[j] - '0';        
        }

        int tmpMax;
        for (int blockSize = 1; blockSize <= n; blockSize++)
            for (int rowStart = 0; rowStart < n-blockSize+1; rowStart++) {
                tmpMax = findMaxMMS(blockSize, rowStart, n);
                max = (max > tmpMax) ? max : tmpMax;
            }
        cout << max << endl;
        if (caseNum)
            cout << endl;
    }
}


int findMaxMMS(int blockSize, int rowStart, int n) {
    int max = 0;
    vector<int>num,MMS;
    num.resize(n);
    MMS.resize(n);

    //initial MMS
    for (int col = 0; col < n; col++)
        for (int row = rowStart; row < rowStart+blockSize; row++) {
            if (matrix[row][col])
                num[col] += matrix[row][col];
            else
                num[col] = -maxN*maxN;
        }

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
