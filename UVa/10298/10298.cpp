#include <iostream>
using namespace std;

#define maxLength 1000005

int p[maxLength];

void computeP(string);

int main()
{
    ios::sync_with_stdio(false);
    string input;
    while(cin >> input && input != ".") {
        computeP(input);

        int m = input.size();
        int wordRemain = m - p[m];
        if (!(m % wordRemain))
            cout <<  m/(wordRemain) << endl;
        else
            cout << 1 << endl;
    }
}

void computeP(string word) {
    int m = word.size();
    word = ' ' + word;  //turn word into 1-based 

    int k = 0;
    p[1] = 0;

    for (int i = 2; i <= m; i++) {
        while(k && word[k+1] != word[i])
            k = p[k];

        if (word[k+1] == word[i])
            k++;

        p[i] = k;
    }
}
