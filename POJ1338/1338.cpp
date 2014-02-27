#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
    // for (int i = 0; i < uglyNumbers.size(); i++) {
        // cout << uglyNumbers[i] << endl;
    // }


}

void inititalUglyNumbers(vector<int>&uglyNumbers, int n) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 4; k++)
                uglyNumbers.push_back(pow(2,i)*pow(3,j)*pow(5,k));
    sort(uglyNumbers.begin(), uglyNumbers.end());
}
