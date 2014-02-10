// current state : WA
// time (first submit) : 72:22
// state (first submit) : WA
// error reason :
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxDicSize 10000
#define maxWordLength 15
using namespace std;

struct wordInDic{
    string word;
    int ID;
};

bool cmp(wordInDic first, wordInDic second) {
    return (first.ID < second.ID);
}

string dic[maxDicSize];
vector<wordInDic> lengthToWord[maxWordLength+2];

main()
{
    int dicCounter = 0;
    while(cin >> dic[dicCounter] && dic[dicCounter] != "#")
        dicCounter++;
    for (int i = 0; i < dicCounter; i++) {
        wordInDic tmp;
        tmp.word = dic[i];
        tmp.ID = i;
        lengthToWord[dic[i].size()].push_back(tmp);
    }

    string checkedWord;
    vector<wordInDic>tmp;

    while(cin >> checkedWord && checkedWord != "#") {
        int wordSize = checkedWord.size();
        bool found = false;

        //check
        for (int i = 0; i < lengthToWord[wordSize].size(); i++)
            if (checkedWord == lengthToWord[wordSize][i].word) {
                printf("%s is correct\n",checkedWord.c_str());
                found = true;
                continue;
            }

        if (found)
            continue;

        //find replacement
        tmp.clear();
        //replace a word
        for (int i = 0; i < lengthToWord[wordSize].size(); i++) {
            int differentNum = 0;
            for (int j = 0; j < wordSize; j++) {
                if (checkedWord[j] != lengthToWord[wordSize][i].word[j])
                    differentNum++;
                if (differentNum > 1)
                    break;
            }
            if (differentNum == 1)
                tmp.push_back(lengthToWord[wordSize][i]);
        }

        //delete a word
        for (int i = 0; i < lengthToWord[wordSize-1].size(); i++) {
            int deleteNum = 0;
            for (int j = 0,k = 0; j < wordSize-1 && k < wordSize; j++,k++) {
                if (checkedWord[k] != lengthToWord[wordSize-1][i].word[j]) {
                    deleteNum++;
                    j--;
                }
                if (deleteNum > 1)
                    break;
            }
            if (deleteNum < 2)
                tmp.push_back(lengthToWord[wordSize-1][i]);
        }

        // insert a word
        for (int i = 0; i < lengthToWord[wordSize+1].size(); i++) {
            int insertNum = 0;
            for (int j = 0,k = 0; j < wordSize+1 && k < wordSize; j++,k++) {
                if (checkedWord[k] != lengthToWord[wordSize+1][i].word[j]) {
                    insertNum++;
                    k--;
                }
                if (insertNum > 1)
                    break;
            }
            if (insertNum < 2)
                tmp.push_back(lengthToWord[wordSize+1][i]);
        }

        sort(tmp.begin(), tmp.end(), cmp);
        printf("%s:", checkedWord.c_str());
        for (int i = 0; i < tmp.size(); i++)
            printf(" %s",tmp[i].word.c_str());
        printf("\n");
    }
}
