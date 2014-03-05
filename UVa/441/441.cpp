#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define maxSetSize 50

void backtrack(int [], int, vector<int>);

main()
{
    int k;
    int s[maxSetSize];
    bool firstCase = true;

    while(scanf("%d", &k) && k!=0) {
        if (firstCase)
            firstCase = false;
        else
            printf("\n");

        for (int i = 0; i < k; i++)
            scanf("%d", &s[i]);
        sort(s, s+k);

        vector<int> v;
        v.reserve(6);
        backtrack(s, k, v);
    }
}

void backtrack(int s[maxSetSize], int k, vector<int>v) {
    if (v.size() == 6) {
        for (int i = 0; i < 5; i++)
            printf("%d ", v[i]);
        printf("%d\n", v[5]);
    } else if (v.size() == 0) {
        for (int i = 0; i < k - 5; i++) {
            v.push_back(s[i]);
            backtrack(s, k, v);
            v.pop_back();
        }
    } else if (v.size() < 6) {
        for (int i = 0; i < k; i++) {
            if (v.back() < s[i]) {
                v.push_back(s[i]);
                backtrack(s, k, v);
                v.pop_back();
            }
        }
    }
}
