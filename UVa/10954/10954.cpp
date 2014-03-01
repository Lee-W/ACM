#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define maxN 100000

main()
{
    int N, value;

    priority_queue<int, vector<int>, greater<int> > numbers;
    int totalCost;

    while(scanf("%d", &N) == 1 && N) {
        while(N--) {
            scanf("%d", &value);
            numbers.push(value);
        }

        totalCost = 0;
        int min, secondMin, cost;
        while(numbers.size() != 1) {
            min = numbers.top();
            numbers.pop();
            secondMin = numbers.top();
            numbers.pop();

            cost = min + secondMin;
            numbers.push(cost);
            totalCost += cost;
        }
        printf("%d\n", totalCost);
        numbers.pop();
    }
}
