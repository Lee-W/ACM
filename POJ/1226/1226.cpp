#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define maxStrNum 105
#define maxStrLen 105

int p[maxStrLen];

void computeP(string);
bool MorrisPratt(string, string);

bool cmp(string, string);

int main()
{
    ios::sync_with_stdio(false);
    int caseNum, stringNum;
    string strs[maxStrNum];

    cin >> caseNum;
    while(caseNum--) {
        cin >> stringNum;
        for (int i = 0; i < stringNum; i++)
            cin >> strs[i];

        sort(strs, strs+stringNum, cmp);

        string shortestWord = strs[0];
        int shortestLen = shortestWord.size();
        bool fail;

        for (int len = shortestLen; len > 0; len--) {
            for (int start = 0; start <= shortestLen - len; start++) {
                string baseStr = shortestWord.substr(start, len);

                string reverseBaseStr = baseStr;
                reverse(reverseBaseStr.begin(), reverseBaseStr.end());

                fail = false;
                for (int i = 1; i < stringNum; i++)
                    if (!MorrisPratt(baseStr, strs[i]) && !MorrisPratt(reverseBaseStr, strs[i])) {
                        fail = true;
                        break;
                    }

                if (!fail)
                    break;
            }

            if (!fail) {
                cout << len << endl;
                break;
            }
        }

        if (fail)
            cout << 0 << endl;
    }
}

void computeP(string str) {
    int size = str.size();

    int k = 0;
    p[1] = 0;
    for (int i = 2; i <= size; i++) {
        while(k>0 && str[k+1]!=str[i])
            k = p[k];

        if (str[k+1] == str[i])
            k++;
        p[i] = k;
    }
}

bool MorrisPratt(string word, string text) {
    int m = word.size();
    int n = text.size();

    word = " " + word;
    text = " " + text;

    computeP(word);
    int q = 0;
    for (int i = 1; i <= n; i++) {
        while (q > 0 && word[q+1]!=text[i])
            q = p[q];

        if (word[q+1] == text[i])
            q++;

        if (q == m) {
            q= p[q];
            return true;
        }
    }
    return false;
}

bool cmp(string s1, string s2) {
    return s1.size() < s2.size();
}
