#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define maxN 100005
#define maxM 100005

int setID[maxN];
vector<int> set[maxN];

void unionSet(int p, int q) {
    int ID1 = setID[p];
    int ID2 = setID[q];

    for (int i = 0; i < set[ID1].size(); i++) {
        set[ID2].push_back(set[ID1][i]);
        setID[set[ID1][i]] = ID2;
    }
    set[ID1].clear();
}

void move(int p, int q) {
    int ID1 = setID[p];
    int ID2 = setID[q];

    setID[p] = ID2;
    set[ID2].push_back(p);
    set[ID1].erase(find(set[ID1].begin(),set[ID1].end(),p));
}

void display(int p) {
    int sum = accumulate(set[setID[p]].begin(), set[setID[p]].end(),0);
    printf("%d %d\n", (int)set[setID[p]].size(), sum);
}

main()
{
    int N, M;
    int command, p, q;

    while(scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i <= N; i++) {
            setID[i] = i;
            set[i].push_back(i);
        }

        while(M--) {
            scanf("%d", &command);

            if (command == 1) {
                scanf("%d%d", &p, &q);
                unionSet(p, q);
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                move(p, q);
            } else if (command == 3) {
                scanf("%d", &p);
                display(p);
            }
        }
    }
}
