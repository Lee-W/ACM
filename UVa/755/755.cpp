// current state : AC
// error reason : lost some condition in problem. READ THE PROBLEM SERIOUSLY is a MUST.

#include <iostream>
#include <map>
using namespace std;

#define maxPhoneNum 100005

map<char,char> letterToNum;

void initialLetterToNum();
string getStandardizedPhone(string);

main()
{
    ios::sync_with_stdio(false);

    int caseNum, phoneNum;
    string phone;
    map<string,int> stanardPhones;

    initialLetterToNum();

    cin >> caseNum;
    while(caseNum--) {
        cin >> phoneNum;
        while(phoneNum--) {
            cin >> phone;
            stanardPhones[getStandardizedPhone(phone)]++;
        }
        bool existDuplicate = false;
        for(map<string, int>::iterator it = stanardPhones.begin(); it != stanardPhones.end(); ++it)
            if (it->second > 1) {
                existDuplicate = true;
                cout << it->first << " " << it->second << endl;
            }

        if (!existDuplicate)
            cout << "No duplicates." << endl;

        if (caseNum > 0)
            cout<<endl;

        stanardPhones.clear();
    }
}

void initialLetterToNum() {
    for (char i = 'A'; i <= 'Z'; i++)
        if (i <= 'C')
            letterToNum[i] = '2';
        else if (i <= 'F')
            letterToNum[i] = '3';
        else if (i <= 'I')
            letterToNum[i] = '4';
        else if (i <= 'L')
            letterToNum[i] = '5';
        else if (i <= 'O')
            letterToNum[i] = '6';
        else if (i <= 'S' && i != 'Q')
            letterToNum[i] = '7';
        else if (i <= 'V')
            letterToNum[i] = '8';
        else if (i <= 'Y')
            letterToNum[i] = '9';
}

string getStandardizedPhone(string phone) {
    string tmp;
    for (int i = 0; i < phone.size(); i++) {
        if (tmp.size() == 3)
            tmp += '-';

        if (phone[i] == '-')
            continue;
        else if ('0' <= phone[i] && phone[i] <= '9')
            tmp += phone[i];
        else if ('A' <= phone[i] && phone[i] <= 'Z')
            tmp += letterToNum[phone[i]];
    }
    return tmp;
}
