// current state : not submit yet
// time (first submit) : 66:21
// state (first submit) :
// error reason :


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define maxD 100
using namespace std;

struct destoryNum {
    int cowID;
    int distance;
    int destory;
};

bool cmp(int, int);
bool cmp2(vector<destoryNum>, vector<destoryNum>);

vector< vector<destoryNum> > D(100);

int Dtotal = 0;

main() {
    int cowNum, t, d;
    destoryNum tmp;

    int totalDestory;

    scanf("%d", &cowNum);

    for (int i = 0; i < cowNum; i++) {
        scanf("%d%d", &tmp.distance, &tmp.destory);
        Dtotal += d;

        tmp.cowID = i+1;

        D[tmp.destory-1].push_back(tmp);
    }

    for (int i = 0; i < maxD; i++) {
        sort(D[i].begin(), D[i].end(), cmp);
    }

    cout<<min_element(D.begin(), D.end(), cmp2);

}

bool cmp(int first, int second) {
    return (first > second);
}

bool cmp2(vector<destoryNum>first, vector<destoryNum>second) {
    return (first.distance*(Dtotal - first.destory) < second.distance*(Dtotal - second.destory));
}
