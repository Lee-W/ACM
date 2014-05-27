#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 25
#define sideNum 4

int sticksLen[maxN];
bool visited[maxN];

bool backtrack(int current, int sum, int successNum, int stickNum, int bound) {
    bool isSuccess = false;
    if (sum == bound) {
        successNum++;

        if (successNum == sideNum-1)
            return true;

        sum = 0;
        current = 0;
    }

    for (int i = current; i < stickNum; i++)
        if (!visited[i]) {
            sum += sticksLen[i];
            visited[i] = true;

            if (sum <= bound) {
                isSuccess = backtrack(i, sum, successNum, stickNum, bound);

                if (isSuccess)
                    return isSuccess;
            } else {
                sum -= sticksLen[i];
                visited[i] = false;
                break;
            }

            sum -= sticksLen[i];
            visited[i] = false;
        }

    return isSuccess;
}

int main() 
{
    int caseNum;
    int stickNum;
    int sideLen;
    
    scanf("%d", &caseNum);
    while (caseNum--) {
        sideLen = 0;
        memset(visited, false, sizeof(visited));

        scanf("%d", &stickNum);
        for (int i = 0; i < stickNum; i++) {
            scanf("%d", &sticksLen[i]);
            sideLen += sticksLen[i];
        }
        sort(sticksLen, sticksLen+stickNum);

        if (sideLen%4 || sticksLen[stickNum-1] > (sideLen/=4)) {
            printf ("no\n");
            continue;
        }

        printf ("%s\n", (backtrack(0, 0, 0, stickNum, sideLen)? "yes": "no" ));
    }
}
