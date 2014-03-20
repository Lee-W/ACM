#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define maxN 100005
#define maxM 100005


int setID[maxN];

void initialSet(int n) {
    for (int i = 0; i <= n; i++)
        setID[i] = i;
}
void unionSet(int p, int q, int n) {
    int originID = setID[p];
    for (int i = 1; i <= n; i++)
        if (setID[i] == originID)
            setID[i] = setID[q];
}

void move(int p, int q) {
    setID[p] = setID[q];
}

void display(int p, int n) {
    int sum = 0, counter = 0;
    for (int i = 1; i <= n; i++)
        if (setID[i] == setID[p]) {
            sum += i;
            counter++;
        }
    printf("%d %d\n", counter, sum);
}

void test(int n) {
    for (int i = 1; i <= n; i++)
        printf("%d ", setID[i]);
    printf("\n");
}

main()
{
    int N, M;
    int command, p, q;

    while(scanf("%d%d", &N, &M) == 2) {
        initialSet(N);

        while(M--) {
            scanf("%d", &command);

            if (command == 1) {
                scanf("%d%d", &p, &q);
                if (setID[p] != setID[q])
                    unionSet(p, q, N);
            } else if (command == 2) {
                scanf("%d%d", &p, &q);
                move(p, q);
            } else if (command == 3) {
                scanf("%d", &p);
                display(p, N);
            }

        }

    }
}
