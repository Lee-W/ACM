#include <iostream>
#include <vector>
using namespace std;

#define maxWordNum 105

vector<string> text1, text2;
int LCS[maxWordNum][maxWordNum], pre[maxWordNum][maxWordNum];

void findLCS(vector<string>, vector<string>);
void findValidSequence(vector<string>, vector<string>);

int main()
{
    ios::sync_with_stdio(false);
    string tmp;

    bool text1Start = true, text2Start = false;

    while (cin >> tmp) {
        if (tmp == "#" && text1Start) {
            text1Start = false;
            text2Start = true;
            continue;
        } else if (tmp == "#" && text2Start) {
            text1Start = true;
            text2Start = false;

            findLCS(text1, text2);
            findValidSequence(text1, text2);


            text1.clear();
            text2.clear();
            continue;
        }

        if (text1Start)
            text1.push_back(tmp);
        else
            text2.push_back(tmp);

    }

}

void findLCS(vector<string>text1, vector<string>text2) {
    int n = text1.size()+1, m = text2.size()+1;

    LCS[0][0] = 0;
    for (int i = 1; i < n; i++)
        LCS[i][0] = 0;
    for (int i = 1; i < m; i++)
        LCS[0][i] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++)
            if (text1[i-1] == text2[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
                pre[i][j] = 0;
            } else {
                    LCS[i][j] = LCS[i-1][j];
                    pre[i][j] = 1;
                if (LCS[i][j-1] > LCS[i][j]) {
                    LCS[i][j] = LCS[i][j-1];
                    pre[i][j] = 2;
                } else {
                }
            }
    }
}

void findValidSequence(vector<string>text1, vector<string>text2) {
    vector<string>result;
    int n = text1.size(), m = text2.size();
    int x = n , y= m;

    while (x > 0  && y > 0) {
        if (pre[x][y] == 0) {
            result.push_back(text1[x-1]);
            x--;
            y--;
        } else if (pre[x][y] == 1)
            x--;
        else
            y--;
    }
    for (int i = result.size()-1; i > 0; i--)
        cout << result[i] << " ";
    cout << result[0] << endl;
}
