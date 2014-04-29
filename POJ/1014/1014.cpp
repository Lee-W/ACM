#include <cstdio>
#include <cstring>

#define maxWeight 6
#define maxMarbleNum 120005

int numOfEachWeight[maxWeight + 1];
int val[maxMarbleNum];
bool dp[maxMarbleNum];

void setVal(int &counter) {
    memset(val, 0, sizeof(val));
    counter = 0;
    int power2;

    for (int i = 1; i <= maxWeight; i++) {
        power2 = 1;
        while(numOfEachWeight[i] >= power2) {
            val[counter] = power2 * i;
            numOfEachWeight[i] -= power2;
            power2 *= 2;
            counter++;
        }
        if (numOfEachWeight[i]) {
            val[counter] = numOfEachWeight[i] * i;
            counter++;
        }
    }
}

bool count(int counter, int sum) {
    if (sum%2)
        return false;

    int target = sum/2;
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    for (int i = 0; i < counter; i++)
        for (int k = target; k >= val[i]; k--)
            dp[k] = dp[k - val[i]];

    return dp[target];
}

int main()
{
    int caseCounter = 0;
    while (scanf("%d", &numOfEachWeight[1]) == 1) {
        caseCounter++;
        for (int i = 2; i <= maxWeight; i++)
            scanf("%d", &numOfEachWeight[i]);

        //exit when all the inputs are 0
        for (int i = 1; i <= maxWeight; i++) {
            if (numOfEachWeight[i])
                break;
            if (i == maxWeight)
                return 0;
        }

        int sum = 0;
        for (int i = 1; i <= maxWeight; i++)
            sum += numOfEachWeight[i] * i;

        int counter;
        setVal(counter);

        printf("Collection #%d:\n", caseCounter);
        printf(count(counter, sum) ? "Can be divided.\n" : "Can't be divided.\n");
        printf("\n");
    }
}
