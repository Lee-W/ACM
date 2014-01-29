// time (first submit) : 16:53
// state (first submit) : accepted
// error reason :
// current state : accepted (2014/1/27)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int value;
    vector<int>numbers;

    while (scanf("%d",&value)==1) {
        numbers.push_back(value);
        sort(numbers.begin(), numbers.end());

        if (numbers.size()%2)   //odd
            printf("%d\n", numbers[numbers.size()/2]);
        else
            printf("%d\n", (numbers[numbers.size()/2-1] + numbers[numbers.size()/2])/2);
    }
}
