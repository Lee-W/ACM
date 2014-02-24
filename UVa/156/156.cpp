#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxDictSize 1005
#define maxWordLen 25

string tranformWord(string s1) {
    for (int i = 0; i < s1.size(); i++)
        s1[i] = (char)tolower(s1[i]);
    sort(s1.begin(), s1.end());
    return s1;
}

main()
{
    ios::sync_with_stdio(false);

    vector<string> dict[maxWordLen], formatedDict[maxWordLen];
    vector<string> ananagrams;

    string word;
    int wordLen;
    while(cin >> word && word!="#") {
        wordLen = word.size();
        dict[wordLen].push_back(word);
        formatedDict[wordLen].push_back(tranformWord(word));
    }
    for (int len = 0; len < maxWordLen; len++)
        for (int i = 0; i < dict[len].size(); i++)
            formatedDict[len].push_back(tranformWord(dict[len][i]));


    for (int len = 0; len < maxWordLen; len++)
        for (int i = 0; i < dict[len].size(); i++) {
            bool isAnanagram = true;
            for (int j = 0; j < dict[len].size(); j++)
                if (i==j)
                    continue;
                else if (formatedDict[len][i]==formatedDict[len][j]) {
                    isAnanagram = false;
                    break;
                }

            if (isAnanagram)
                ananagrams.push_back(dict[len][i]);
        }

    sort(ananagrams.begin(), ananagrams.end());
    for(vector<string>::iterator it = ananagrams.begin(); it != ananagrams.end(); ++it)
        cout << *it << endl;
}
