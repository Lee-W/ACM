#include <iostream>
#include <cstring>
using namespace std;

#define maxLength 1000005

int p[maxLength];

void computeP(string);

int main()
{
    ios::sync_with_stdio(false);
    int size;
    string str;

    int caseCounter = 0;

    while (cin >> size && size) {
        caseCounter++;

        cin >> str;
        str = " " + str;    //turn str to 1-based
        computeP(str);

        cout << "Test case #" << caseCounter << endl;
        for (int i = 1; i <= size; i++) {
            int remainWordLen = i-p[i];
            if (!(i%remainWordLen) && i/remainWordLen > 1)
                cout << i << " " << i/remainWordLen << endl;
        }
        cout << endl;
    }
}

void computeP(string str) {
    int size = str.size() - 1;  //due to the first element offset

    int k = 0;
    memset(p, 0, sizeof(p));

    for (int i = 2; i <= size; i++) {
        while (k > 0 && str[k+1]!=str[i])
            k = p[k];

        if (str[k+1]==str[i])
            k++;

        p[i] = k;
    }
}
