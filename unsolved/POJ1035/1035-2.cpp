// current state : TLE
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

main()
{
    string dic[maxDicSize];
    string tmp[maxDicSize];
    string checkedWord;

    int dicCounter = 0;
    while(cin >> dic[dicCounter] && dic[dicCounter] != "#")
        dicCounter++;

    while(cin >> checkedWord && checkedWord != "#") {
        int wordSize = checkedWord.size();
        bool found = false;
        int counter = 0;

        for (int i = 0; i < dicCounter; i++) {
            if (wordSize == dic[i].size()) {
                if (checkedWord == dic[i]) {
                    printf("%s is correct\n",checkedWord.c_str());
                    found = true;
                    break;
                } else {
                    int differentNum = 0;
                    for (int j = 0; j < wordSize; j++) {
                        if (checkedWord[j] != dic[i][j])
                            differentNum++;
                        if (differentNum > 1)
                            break;
                    }
                    if (differentNum == 1)
                        tmp[counter++] = dic[i];
                }
            } else if (wordSize == dic[i].size()+1) {   //delete
                int deleteNum = 0;
                for (int j = 0,k = 0; j < wordSize-1 && k < wordSize; j++,k++) {
                    if (checkedWord[k] != dic[i][j]) {
                        deleteNum++;
                        j--;
                    }
                    if (deleteNum > 1)
                        break;
                }
                if (deleteNum < 2)
                    tmp[counter++] = dic[i];
            } else if (wordSize == dic[i].size()-1) {   //insert
                int insertNum = 0;
                for (int j = 0,k = 0; j < wordSize+1 && k < wordSize; j++,k++) {
                    if (checkedWord[k] != dic[i][j]) {
                        insertNum++;
                        k--;
                    }
                    if (insertNum > 1)
                        break;
                }
                if (insertNum < 2)
                    tmp[counter++] = dic[i];
            }
        }
        if (!found) {
            printf("%s:",checkedWord.c_str());
            for (int i = 0; i < counter; i++)
                printf(" %s",tmp[i].c_str());
            printf("\n");
        }
    }
}

