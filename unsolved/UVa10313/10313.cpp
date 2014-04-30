#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

#define maxArgNum 3
#define maxN 300

int n, upper, lower;
int arg[maxArgNum];
int dp[maxN];

void init(int argNum) {
    n = arg[0];
    if (argNum == 1) {
        upper = arg[0];
        lower = 1;
    } else if (argNum == 2) {
        upper = arg[1];
        lower = 1;
    } else if (argNum == 3) {
        upper = arg[2];
        lower = arg[1];
    }
}

int count() {

}

int main()
{
    string input;
    int inputCounter;
    while(getline(cin, input)) {
        stringstream ss;
        ss << input;

        inputCounter = 0;
        while(!ss.eof())
            ss >> arg[inputCounter++];

        init(inputCounter);
        cout << count() << endl;
    }
}
