// current state : TLE
// time (first submit) : 37:08
// state (first submit) : TLE
// error reason :

#include <cstdio>
#include <vector>
#include <algorithm>

#define maxCityNumInEachSide 1000
using namespace std;

int countCrossing(vector<int>[], int);
bool isCrossing(vector<int>, vector<int>);

vector<int> superHighway[maxCityNumInEachSide];

main() {
    int caseNum, eastCityNum, westCityNum, shwNum;
    int east, west;

    scanf("%d", &caseNum);

    for (int CASE = 1; CASE <= caseNum; CASE++) {
        scanf("%d%d%d", &eastCityNum, &westCityNum, &shwNum);

        //clean the vector
        for (int i = 0; i < eastCityNum; i++)
            superHighway[i].clear();

        //initial superHighway
        for (int j = 0; j < shwNum; j++) {
            scanf("%d%d", &east, &west);
            superHighway[east-1].push_back(west);
        }
        for (int i = 0; i < eastCityNum; i++)
            sort(superHighway[i].begin(), superHighway[i].end());

        printf("Test cast %d: %d", CASE, countCrossing(superHighway, eastCityNum));
    }
}

int countCrossing(vector<int>superHighway[maxCityNumInEachSide], int eastCityNum) {
    int crossingNum = 0;

    for (int i = 0; i < eastCityNum-1; i++)
        for (int j = 0; j < superHighway[i].size(); j++)
            for (int k = 0; k < eastCityNum; k++)
                crossingNum += lower_bound(superHighway[k].begin(), superHighway[k].end(), superHighway[i][j])-superHighway[k].begin();
    return crossingNum;
}


