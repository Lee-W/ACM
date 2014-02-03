// current state : AC
// time (first submit) : 37:45
// state (first submit) : AC
// error reason : None

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

map< int,vector<string> >dictionary;
void printRearrangedWord(string);

main()
{
    string word;
    int maxWordLen = 0;

    //bulid dictionary
    while(cin>>word && word != "XXXXXX") {
        dictionary[word.size()].push_back(word);
        maxWordLen = max(maxWordLen, (int)word.size());
    }

    for (int i = 1; i <= maxWordLen; i++)
        sort(dictionary[i].begin(), dictionary[i].end());

    while(cin>>word && word != "XXXXXX") {
        sort(word.begin(), word.end());
        printRearrangedWord(word);
    }


}

void printRearrangedWord(string word) {
    string sortedWord;
    bool isValidWord = false;
    int wordLen = word.size();
    for (int i = 0; i < dictionary[wordLen].size(); i++) {
        sortedWord = dictionary[wordLen][i];
        sort(sortedWord.begin(),sortedWord.end());
        if (word == sortedWord) {
            cout<<dictionary[wordLen][i]<<endl;
            isValidWord = true;
        }
    }
    if (!isValidWord)
        cout<<"NOT A VALID WORD"<<endl;

    cout<<"******"<<endl;
}
