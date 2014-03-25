#include <cstdio>
#include <vector>
using namespace std;

vector<int>missile, LIS;

void findLIS() {
    LIS.resize(missile.size());
    for (int i = 0; i < LIS.size(); i++) {
        LIS[i] = 1;
        for (int j = 0; j < i; j++)
            if (missile[j] >= missile[i] && LIS[j]+1 > LIS[i])
                LIS[i] = LIS[j] + 1;
    }
}

main()
{
    int caseCounter = 1;
    int tmp;
    int max;

    while(scanf("%d", &tmp) == 1) {
        if (tmp == -1) {
            findLIS();

            max  = 0;
            for (int i = 0; i < LIS.size(); i++)
                if (max < LIS[i])
                    max = LIS[i];

            if (LIS.size()) {
                if (caseCounter > 1)
                    printf("\n");
                printf("Test #%d:\n  maximum possible interceptions: %d\n", caseCounter, max);
                caseCounter++;
            }
            missile.clear();
            continue;
        }
        missile.push_back(tmp);
    }
}
