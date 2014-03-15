#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define maxN 1505

void inititalUglyNumbers(vector<int>&, int);

main()
{
    vector<int>uglyNumbers;
    inititalUglyNumbers(uglyNumbers, maxN);
    int p;
    while(cin >> p && p) {
        cout << uglyNumbers[p-1] << endl;
    }


}

void inititalUglyNumbers(vector<int>&uglyNumbers, int n) {
    int twoCounter = 0, threeCounter = 0, fiveCounter = 0;
    int uglyNum = 0;
    while(uglyNum  <= INT_MAX) {
        uglyNum = pow(2, twoCounter) * pow(3, threeCounter) * pow(5, fiveCounter);
        uglyNumbers.push_back(uglyNum);
        twoCounter++;
        uglyNum = pow(2, twoCounter) * pow(3, threeCounter) * pow(5, fiveCounter);
        uglyNumbers.push_back(uglyNum);
        threeCounter++;
        uglyNum = pow(2, twoCounter) * pow(3, threeCounter) * pow(5, fiveCounter);
        uglyNumbers.push_back(uglyNum);
        fiveCounter++;
        if (uglyNumbers.size() > 1500)
            break;
    }
    sort(uglyNumbers.begin(), uglyNumbers.end());
}
