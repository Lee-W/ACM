// time (first submit) : 42:55
// state (first submit) : TLE
// error reason : The median is (a+b)/2 not (a-b)/2 ......
// current state : accept(2014/1/28)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>D;

int binarySearch(int target) {
    int start = 0;
    int end = D.size()-1;

    int mid = (end + start)/2;

    if (D[end] < target)
        return -1;

    while(start < end) {
        mid = (end + start)/2;
        if (D[mid] < target)
            start = mid + 1 ;
        else
            end = mid;
    }
    return D[end];
}

main()
{
    int numOfCase, numOfStudents, numOfQ;
    int value;

    scanf("%d", &numOfCase);

   for (int i = 0; i < numOfCase; i++) {
        scanf("%d", &numOfStudents);
        D.clear();
        for (int j = 0; j < numOfStudents; j++) {
            scanf("%d", &value);
            D.push_back(value);
        }
        sort(D.begin(), D.end());

        scanf("%d", &numOfQ);
        scanf("%d", &value);
        printf("%d", binarySearch(value));
        for (int j = 1; j < numOfQ; j++) {
            scanf("%d", &value);
            printf(" ");
            printf("%d", binarySearch(value));
        }

        if (i == numOfCase-1)
            break;
        printf("\n");
   }
}
