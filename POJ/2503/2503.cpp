#include <cstdio>
// #include <bits/stdc++.h>
#include <map>
#include <iostream>
using namespace std;

main()
{
    ios::sync_with_stdio(false);
    map<string, string>dic;
    string tmp, tmp2;

    while(getline(cin, tmp) && tmp.find(' ')!=-1) {
        int index = tmp.find(' ');
        dic[tmp.substr(index+1)] = tmp.substr(0, index);
    }
    while(cin >> tmp) {
        if (dic.count(tmp))
            cout<<dic[tmp]<<endl;
        else
            cout<<"eh"<<endl;
    }
}
