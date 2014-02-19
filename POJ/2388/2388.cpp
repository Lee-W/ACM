// current state : AC
// time (first submit) : 7:04
// state (first submit) : AC
// error reason : None

#include <cstdio>
#include <algorithm>
#define maxNumOfCows 10000
using namespace std;

main()
{
    int milkOutput[maxNumOfCows];
    int cowNum;

    scanf("%d", &cowNum);
    for (int i = 0; i < cowNum; i++)
        scanf("%d", &milkOutput[i]);

    sort(milkOutput, milkOutput+cowNum);
    printf("%d\n",milkOutput[cowNum/2]);
}
