#include <cstdio>

#define maxS 20005

int line[maxS], MMS[maxS];

void findMMS(int);
int findMaxInMMS(int);
void findLongestRoute(int,int,int&,int&);

main()
{
    int max, start, end;

    int routeNum, stopNum, lineSize;
    scanf("%d", &routeNum);
    for (int routeID = 1; routeID <= routeNum; routeID++) {
        scanf("%d", &stopNum);
        lineSize = stopNum-1;
        for (int i = 0; i < lineSize; i++)
            scanf("%d", &line[i]);

        findMMS(lineSize);
        max = findMaxInMMS(lineSize);
        findLongestRoute(lineSize, max, start, end);
        
        if (max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", routeID, start+1, end+2);
        else
            printf("Route %d has no nice parts\n", routeID);
    }
}

void findMMS(int n) {
    MMS[0] = line[0];
    for (int i = 1; i < n; i++)
        if (MMS[i-1] > 0)
            MMS[i] = MMS[i-1] + line[i];
        else
            MMS[i] = line[i];
}

int findMaxInMMS(int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < MMS[i])
            max = MMS[i];
    return max;
}

void findLongestRoute(int n, int max, int& start, int& end) {
    start = 1, end = 0;
    int tmpStart, tmpEnd;
    
    for (int i = 0; i < n; i++) {
        if (MMS[i] == max)
            tmpEnd = i;
        else
            continue;

        for (int j = tmpEnd; j >= 0; j--)
            if (MMS[j] >= 0)
                tmpStart =j;
            else
                break;

        if (tmpEnd - tmpStart > end - start) {
            end = tmpEnd;
            start = tmpStart;
        }
    }
}
