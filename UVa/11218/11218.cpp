#include <cstdio>
#include <algorithm>
using namespace std;

#define maxN 85

struct group {
    int member[3];

    bool operator==(group g) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (member[i] == g.member[j])
                    return true;
        return false;
    }

    bool operator!=(group g) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (member[i] == g.member[j])
                    return false;
        return true;
    }
};

group g[maxN];
int score[maxN];

int main()
{
    int caseCounter = 0;
    int n;
    int a, b, c, s;

    int maxScore;

    while (scanf("%d", &n) && n) {
        caseCounter++;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &g[i].member[0], &g[i].member[1], &g[i].member[2], &score[i]);
        }

        maxScore = -1;
        for (int i = 1; i <= n - 2; i++)
            for (int j = i + 1; j <= n-1 ;j++) 
                if (g[i] != g[j])
                    for (int k = j + 1; k <= n; k++)
                        if (g[i] != g[k] && g[j] != g[k])
                            maxScore = max(maxScore, score[i] + score[j] + score[k]);

        printf("Case %d: %d\n", caseCounter, maxScore);
    }
}
