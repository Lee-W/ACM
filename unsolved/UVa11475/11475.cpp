#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxLen 100005

int p[maxLen];
void computeP(string);

int main()
{
    ios::sync_with_stdio(false);

    string input, rInput;
    int size;

    while (cin >> input) {
        size = input.size();

        rInput = input;
        reverse(input.begin(), input.end());

        for (int i = 0; i < size; i++) {
            if (input[size-i-1]!)
        }
    }
}

void computeP(string str) {
    int size = str.size() - 1;
    int k = 0;
    memset(p, 0, sizeof(p));

    for (int i = 2; i <= size; i++) {
        while (k > 0 && str[k+1]!=str[i])
            k = p[k];

        if (str[k+1] == str[i])
            k++;

        p[i] = k;
    }
    
}
