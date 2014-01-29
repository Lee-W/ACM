// time (first submit) : 37:08
// state (first submit) : TLE
// error reason :
// current state :

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int countCrossing(vector< vector<int> >);
bool cmp(vector<int>, vector<int>);
bool isCrossing(vector<int>, vector<int>);

main() {
    int caseNum, eastCityNum, westCityNum, shwNum;
    int east, west;
    vector< vector<int> >superHighway;
    vector<int>tmp;

    scanf("%d", &caseNum);

    for (int i = 0; i < caseNum; i++) {
        scanf("%d%d%d", &eastCityNum, &westCityNum, &shwNum);

        for (int j = 0; j < shwNum; j++) {
            scanf("%d%d", &east, &west);
            tmp.clear();
            tmp.push_back(east);
            tmp.push_back(west);
            superHighway.push_back(tmp);
        }
        printf("Test cast %d: %d", i+1, countCrossing(superHighway));
    }
}

int countCrossing(vector< vector<int> >superHighway) {
    int crossingNum = 0;
    sort(superHighway.begin(), superHighway.end(), cmp);

    for (int i = 0; i < superHighway.size()-1; i++)
        for (int j = i+1; j < superHighway.size(); j++) {
            if (isCrossing(superHighway[i], superHighway[j]))
                crossingNum++;
        }
    return crossingNum;
}

bool cmp(vector<int> first, vector<int>second) {
    return first.front() < second.front();
}

bool isCrossing(vector<int> first, vector<int> second) {
    return (first[0]!=second[0] && first[1] > second[1]);
    // return (first[0]>second[0] && first[1]<second[1]);//|| (first[0]<second[0] && first[1]>second[1])));
}
