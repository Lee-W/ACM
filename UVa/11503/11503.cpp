#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#define maxM 100005

map <string, string> p;
map <string, int> r;
map <string, int> size;

string findSet(string);
void unionSet(string, string);

main()
{
    ios::sync_with_stdio(false);

    int caseNum, relationNum;
    string first, second, currentRoot;

    cin >> caseNum;
    while(caseNum--) {
        p.clear();
        r.clear();
        size.clear();
        int setCounter = 0;

        cin >> relationNum;
        while(relationNum--) {
            cin >> first >> second;
            first = findSet(first);
            second = findSet(second);

            if (first != second)
                unionSet(first, second);

            currentRoot = findSet(first);
            cout << size[currentRoot] << endl;
        }
    }
}

string findSet(string s) {
    if (p[s] ==  "") {
        p[s] = s;
        size[s] = 1;
        return s;
    }
    if (s == p[s])
        return s;
    return p[s] = findSet(p[s]);
}

void unionSet(string s1, string s2) {
    if (r[s1] > r[s2]) {
        p[s2] = s1;
        size[s1] += size[s2];
    } else {
        p[s1] = s2;
        size[s2] += size[s1];
        if (r[s1] == r[s2])
            r[s2]++;
    }
}
