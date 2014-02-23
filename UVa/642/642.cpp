// #include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxWordLen 8
#define maxDictNum 105

main()
{
    ios::sync_with_stdio(false);

    vector< vector<string> > dict(maxWordLen);
    string word;
    int wordLen;

    //initial dictionary
    while(cin >> word && word!="XXXXXX") {
        wordLen = word.size();
        dict[wordLen].push_back(word);
    }

    //sort dictionary
    for (int i = 0; i < dict.size(); i++)
        sort(dict[i].begin(), dict[i].end());

    //
    while(cin >> word && word!="XXXXXX") {
        bool found = false;
        string sortedWord;

        sort(word.begin(), word.end());
        wordLen = word.size();

        for (int i = 0; i < dict[wordLen].size(); i++) {
            string sortedWord = dict[wordLen][i];
            sort(sortedWord.begin(), sortedWord.end());

            if (word==sortedWord) {
                found = true;
                cout<<dict[wordLen][i]<<endl;
            }
        }
        if (!found)
            cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
    }
}
