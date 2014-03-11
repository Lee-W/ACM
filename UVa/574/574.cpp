#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

#define maxN 15

void backtrack(int);

int total, listSize;
bool ansExist;
int numbers[maxN];
bool visited[maxN];

vector<int>sumOfN;
map<vector<int>, bool>isAdded;

main()
{
    while(scanf("%d%d", &total, &listSize) && total) {
        sumOfN.clear();
        isAdded.clear();
        ansExist = false;
        for (int i = 0; i < listSize; i++)
            scanf("%d", &numbers[i]);
        memset(visited, false, listSize);

        printf("Sums of %d:\n", total);
        backtrack(0);
        if (!ansExist)
            printf("NONE\n");
    }
}

void backtrack(int start) {
    int sum = accumulate(sumOfN.begin(), sumOfN.end(), 0);
    if (sum > total)
        return;
    else if (sum == total) {
        ansExist = true;
        if (!isAdded[sumOfN]) {
            isAdded[sumOfN] = true;

            for (int i = 0; i < sumOfN.size()-1; i++)
                printf("%d+", sumOfN[i]);
            printf("%d\n", sumOfN.back());
        }
        return;
    } else 
        for (int i = start; i < listSize; i++)
            if (!visited[i]) {
                visited[i] = true;
                sumOfN.push_back(numbers[i]);
                backtrack(i+1);
                visited[i] = false;
                sumOfN.pop_back();
            }
}
