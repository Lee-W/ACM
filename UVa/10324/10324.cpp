#include <iostream>
using namespace std;

bool query(string input, int start, int end) {
    for (int i = start + 1; i < end; i++)
        if (input[i] != input[start])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    string input;
    int caseCounter = 0;
    int queryNum, first, second;
    while(cin >> input) {
        caseCounter++;
        cout << "Case " << caseCounter << ":" << endl;
        cin >> queryNum;
        while(queryNum--) {
            cin >> first >> second;
            if (query(input, min(first, second), max(first, second) + 1))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

        }

    }
}
