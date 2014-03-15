#include <cstdio>
#include <vector>
using namespace std;

#define maxTaskNum 105

main()
{
    int tasks[maxTaskNum];
    vector<int> dependency[maxTaskNum];
    int taskNum, dependencyNum;

    scanf("%d", &taskNum);
    for (int i = 0; i < taskNum; i++)
        scanf("%d", &tasks[i]);

    int first, second;
    scanf("%d", &dependencyNum);
    for (int i = 0; i < dependencyNum; i++) {
        scanf("%d", &first, &second);
        dependency[second].push_back(first);
    }

}
