// current state : AC
// time (first submit) : 05:14
// state (first submit) : AC
// error reason : none

#include <cstdio>
#define maxSetNum 15
using namespace std;

main() {
    int numbers[maxSetNum][maxSetNum];
    int setNum, a, b;

    scanf("%d", &setNum);

    for (int i = 0; i < setNum; i++) {
        scanf("%d%d", &a, &b);
        if (a == b)
            printf("=\n");
        else if (a > b)
            printf(">\n");
        else if (a < b)
            printf("<\n");
    }
}