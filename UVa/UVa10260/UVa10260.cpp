// current state : AC
// time (first submit) : 17:54
// state (first submit) : WA
// error reason : forget to clean string. original "prevCode" affect the judement in the next wrong

#include <iostream>
#include <map>
using namespace std;

map<char,int>soundex;

void intialSoundex();


main() {
    intialSoundex();

    string str;
    int prevCode, code;

    while(cin >> str) {
        prevCode = 0;
        code = 0;
        for (int i = 0; i < str.size(); i++) {

            if (code = soundex[char(str[i])]) {
                if (prevCode!=code)
                    cout<<code;
            }
            prevCode = code;
        }
        cout<<endl;
    }
}

void intialSoundex() {
    soundex['B'] = 1;
    soundex['F'] = 1;
    soundex['P'] = 1;
    soundex['V'] = 1;
    soundex['C'] = 2;
    soundex['G'] = 2;
    soundex['J'] = 2;
    soundex['K'] = 2;
    soundex['Q'] = 2;
    soundex['S'] = 2;
    soundex['X'] = 2;
    soundex['Z'] = 2;
    soundex['D'] = 3;
    soundex['T'] = 3;
    soundex['L'] = 4;
    soundex['M'] = 5;
    soundex['N'] = 5;
    soundex['R'] = 6;
}
