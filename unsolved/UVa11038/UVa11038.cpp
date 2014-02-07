// current state : stuck
// time (first submit) : 30:00
// state (first submit) :
// error reason :

#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int countZero(int);

main()
{
    int m, n;
    while(scanf("%d,%d", &m, &n)==2 & !m<0) {   //n >= m
    }

}

int countZero(int num) {
    stringstream ss;
    ss << num;
    int lengthOfNum = ss.str().size();

    if (num>10) {
        countZero(num);
        countZero(num);

    }
}
