// current state : AC
// time (first submit) : 18:57
// state (first submit) : CE
// error reason : The algorithm is right.
//                But the reason why it encounter CE isunknown@@
//                POJ compiler thinks upper_bound is int while mine thinks it's long int
//                Current version cast both parameter into int

#include <cstdio>
#include <algorithm>

#define maxCowNum 20000
using namespace std;

main()
{
    int cowNum, consumeLength;
    int cowLength[maxCowNum];
    int fitPairsNum;

    scanf("%d%d", &cowNum, &consumeLength);
    for (int cow = 0; cow < cowNum; cow++)
        scanf("%d",&cowLength[cow]);

    sort(cowLength, cowLength+cowNum);
    for (int cow = 0; cow < cowNum; cow++) {
        int maxLenOfTheOtherOne = consumeLength - cowLength[cow];

        int fitNum = max((int)0, (int)(upper_bound(cowLength, cowLength+cowNum, maxLenOfTheOtherOne)- (cowLength+cow+1)));
        fitPairsNum += fitNum;
    }
    printf("%d\n",fitPairsNum);
}
