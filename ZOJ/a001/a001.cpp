// current state : AC
// time (first submit) : 02:09
// state (first submit) : NA
// error reason : output "Hello" instead of "hello"

#include <iostream>
using namespace std;

main()
{
    string str;
    while(cin >> str)
        cout << "hello, "<< str << endl;
}
