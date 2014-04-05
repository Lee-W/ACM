#include <cstdio>

#define maxBugNum 2005

//1-based
int p[maxBugNum*2], r[maxBugNum*2];

void initSet(int n) {
    for (int i = 1; i <= 2*n; i++) {
        p[i] = i;
        r[i] = 1;
    }
}

int findSet(int x) {
    if (p[x] == x)
        return x;
    return p[x] = findSet(p[x]);
}

void unionSet(int x, int y) {
    if (r[x] > r[y])
        p[y] = p[x];
    else {
        p[x] = p[y];
        if (r[x] == r[y])
            r[y]++;
    }
}

main()
{
    int caseNum, bugNum, interactionNum;
    int bug1, bug2;
    int bug1Oppsite, bug2Oppsite;

    scanf("%d", &caseNum);
    for (int i = 1; i <= caseNum; i++) {
        bool isSuspicious = false;

        scanf("%d%d", &bugNum, &interactionNum);
        initSet(bugNum);
        while(interactionNum--) {
            scanf("%d%d", &bug1, &bug2);
            if (!isSuspicious) {
                bug1Oppsite = findSet(bug1+bugNum);
                bug2Oppsite = findSet(bug2+bugNum);
                bug1 = findSet(bug1);
                bug2 = findSet(bug2);

                if (bug1 == bug2)
                    isSuspicious = true;
                else {
                    unionSet(bug1, bug2Oppsite);
                    unionSet(bug2, bug1Oppsite);
                }
            }
        }
        printf("Scenario #%d:\n", i);
        printf((isSuspicious ? "Suspicious bugs found!\n" : "No suspicious bugs found!\n"));
        printf("\n");
    }
}
