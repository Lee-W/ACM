// current state : AC
// time (first submit) : 21:37
// state (first submit) : TLE
// error reason : BinarySearch  stuck in while loop. In this case, using vector is not efficient enough.

#include <cstdio>
#include <algorithm>

#define maxStudent 100000
using namespace std;

int binarySearch(int[], int, int);
int problemSolved[maxStudent];

main() {
    int testCaseNum, studentNum, limitSetSize;
    int value;

    scanf("%d", &testCaseNum);
    for (int CASE = 0; CASE < testCaseNum; CASE++) {

        scanf("%d", &studentNum);
        for (int stu = 0; stu < studentNum; stu++) {
            scanf("%d", &problemSolved[stu]);
        }
        sort(problemSolved, problemSolved+studentNum);

        scanf("%d", &limitSetSize);
        scanf("%d", &value);
        printf("%d", binarySearch(problemSolved, studentNum, value));
        for (int limitNo = 1; limitNo < limitSetSize; limitNo++) {
            scanf("%d", &value);
            printf("% d", binarySearch(problemSolved, studentNum, value));
        }

        if (CASE < testCaseNum-1)
            printf("\n");
    }
}

int binarySearch(int problemSolved[maxStudent],int studentNum, int target) {
    int start = 0;
    int end = studentNum-1;
    int mid = (start+end)/2 + 1;

    if (problemSolved[start] > target)
        return 0;
    if (problemSolved[end] <= target)
        return end+1;

    while(end > start) {
        mid = (start+end)/2 + 1;
        if (problemSolved[mid] > target)
            end = mid - 1;
        else
            start = mid;
    }
    return start+1;
}
