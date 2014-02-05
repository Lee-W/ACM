// current state :
// time (first submit) : 45:44
// state (first submit) : CE ...
// error reason :

// #include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

void turnToStandardFrom(string&);
void printElement(pair<int,string>);

void reverseDuplicate(pair<string,int> p,map<int, string>&m) {
    m[p.second] = p.first;
}

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

    map<int,string>tmpMap;
    // for_each(numOfEachTel.begin(),numOfEachTel.end(),bind2nd(ptr_fun(reverseDuplicate),tmpMap));


    // for_each(tmpMap.begin(), tmpMap.end(),printElement);
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

        if ('A'<=tel[i] && tel[i]<='C')
            standardTel += '2';
        else if ('D'<=tel[i] && tel[i]<='F')
            standardTel += '3';
        else if ('G'<=tel[i] && tel[i]<='I')
            standardTel += '4';
        else if ('J'<=tel[i] && tel[i]<='L')
            standardTel += '5';
        else if ('M'<=tel[i] && tel[i]<='O')
            standardTel += '6';
        else if ('P'<=tel[i] && tel[i]<='S' && tel[i] != 'Q')
            standardTel += '7';
        else if ('T'<=tel[i] && tel[i]<='V')
            standardTel += '8';
        else if ('W'<=tel[i] && tel[i]<='Y')
            standardTel += '9';
    }
    tel = standardTel;
}

void printElement(pair<int,string>p) {
    if (p.first > 1)
        cout << p.second << " " << p.first<<endl;
}
//
// Compile Error
//
// In file included from stl_function.h:712,
//                  from string:50,
//                  from locale_classes.h:42,
//                  from ios_base.h:43,
//                  from ios:43,
//                  from ostream:40,
//                  from iostream:40,
//                  from F:\temp\12497237.92535\Main.cc:6:
// binders.h: In instantiation of 'std::binder2nd<std::pointer_to_binary_function<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&, void> >':
// F:\temp\12497237.92535\Main.cc:34:   instantiated from here
// binders.h:141: error: forming reference to reference type 'std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&'
// binders.h: In function 'std::binder2nd<_Operation> std::bind2nd(const _Operation&, const _Tp&) [with _Operation = std::pointer_to_binary_function<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&, void>, _Tp = std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >]':
// F:\temp\12497237.92535\Main.cc:34:   instantiated from here
// binders.h:162: error: no matching function for call to 'std::binder2nd<std::pointer_to_binary_function<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&, void> >::binder2nd(const std::pointer_to_binary_function<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&, void>&, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&)'
// binders.h:135: note: candidates are: std::binder2nd<std::pointer_to_binary_function<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&, void> >::binder2nd(const std::binder2nd<std::pointer_to_binary_function<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>, std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >&, void> >&)
//  
