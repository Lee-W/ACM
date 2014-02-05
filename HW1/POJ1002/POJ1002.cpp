// current state : TLE
// time (first submit) : 45:44
// state (first submit) : CE -> TLE
// error reason :

// #include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

void turnToStandardFrom(string&);
void printElement(pair<string,int>);

main()
{
    int numOfTel;
    string tel;
    map<string,int>numOfEachTel;

    cin >> numOfTel;

    while (numOfTel--) {
        cin >> tel;
        turnToStandardFrom(tel);
        numOfEachTel[tel]++;
    }

    for_each(numOfEachTel.map<string,int>::lower_bound(1),numOfEachTel.end(),printElement);
}

void turnToStandardFrom(string& tel) {
    string standardTel;
    for (int i = 0; i < tel.size(); i++) {
        if (standardTel.size() == 3)
            standardTel += '-';

        if ('0'<=tel[i] && tel[i]<='9') {
            standardTel += tel[i];
            continue;
        }

//
//         if ('A'<=tel[i] && tel[i]<='C')
//             standardTel += '2';
//         else if ('D'<=tel[i] && tel[i]<='F')
//             standardTel += '3';
//         else if ('G'<=tel[i] && tel[i]<='I')
//             standardTel += '4';
//         else if ('J'<=tel[i] && tel[i]<='L')
//             standardTel += '5';
//         else if ('M'<=tel[i] && tel[i]<='O')
//             standardTel += '6';
//         else if ('P'<=tel[i] && tel[i]<='S' && tel[i] != 'Q')
//             standardTel += '7';
//         else if ('T'<=tel[i] && tel[i]<='V')
//             standardTel += '8';
//         else if ('W'<=tel[i] && tel[i]<='Y')
//             standardTel += '9';
    }
    tel = standardTel;
}

void printElement(pair<string,int>p) {
    if (p.second > 1)
        cout << p.first << " " << p.second<<endl;
}
