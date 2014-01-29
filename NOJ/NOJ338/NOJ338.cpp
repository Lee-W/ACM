// time (first submit) : 21:37
// state (first submit) : TLE
// error reason :
// current state :

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>, int);

main() {
    int testCaseNum, studentNum, limitSetSize;
    int value;
    vector<int>problemSolved;

    scanf("%d", &testCaseNum);
    for (int CASE = 0; CASE < testCaseNum; CASE++) {
        problemSolved.clear();

        scanf("%d", &studentNum);
        for (int stu = 0; stu < studentNum; stu++) {
            scanf("%d", &value);
            problemSolved.push_back(value);
        }
        sort(problemSolved.begin(), problemSolved.end());

        scanf("%d", &limitSetSize);
        scanf("%d", &value);
        printf("%d", binarySearch(problemSolved, value));
        for (int limitNo = 1; limitNo < limitSetSize; limitNo++) {
            scanf("%d", &value);
            printf("% d", binarySearch(problemSolved, value));
        }

        if (CASE < testCaseNum-1)
            printf("\n");
    }
}

int binarySearch(vector<int>problemSolved, int target) {
    int start = 0;
    int end = problemSolved.size()-1;
    int mid = (start+end)/2;

    if (problemSolved[start] > target)
        return 0;
    if (problemSolved[end] < target)
        return end+1;

    while(end > start) {
        mid = (start+end)/2;
        if (problemSolved[mid] > target)
            end = mid - 1;
        else
            start = mid;
    }
    return start+1;
}
