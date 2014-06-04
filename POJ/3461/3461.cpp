#include <iostream>
using namespace std;

#define maxN 10000005
#define maxM 1000005

int p[maxM];

void computePi(string);
int KMP(string, string);

int main()
{
    ios::sync_with_stdio(false);
    int caseNum;
    string word, text;

    cin >> caseNum;
    while(caseNum--) {
        cin >> word >> text;
        cout << KMP(word, text) << endl;
    }
}

void computePi(string word) {
    int m = word.size();

    p[0] = -1;
    int k = -1;
    for (int i = 1; i < m; i++) {
        while(k > -1 && word[k+1] != word[i])
            k = p[k];

        if (word[k+1] == word[i])
            k++;

        p[i] = k;
    }
}

int KMP(string word, string text) {
    int m = word.size();
    int n = text.size();

    computePi(word);

    int result = 0;

    int q = -1;
    for (int i = 0; i < n; i++) {
        while (q > -1 && word[q+1] != text[i])
            q = p[q];

        if (word[q+1] == text[i])
            q++;

        if (q == m-1) {
            q = p[q];
            result++;
        }
    }
    return result;
}
