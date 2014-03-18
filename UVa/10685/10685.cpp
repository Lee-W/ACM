#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define maxCsize 5005

string creatures[maxCsize];
map<string, string>parent;
map<string, int>r;
map<string, int>size;

void unionSet(string c1, string c2) {
    if (r[c1] > r[c2]) {
        parent[c2] = c1;
        size[c1] += size[c2];
    } else {
        parent[c1] = c2;
        size[c2] += size[c1];
        if (r[c1] == r[c2])
            r[c2]++;
    }
}

string findSet(string c) {
    if (parent[c] == c)
        return parent[c];
    return parent[c] = findSet(parent[c]);
}

main()
{
    ios::sync_with_stdio(false);
    int C, R;
    string prey, predator;
    while(cin >> C >> R && C) {
        parent.clear();
        r.clear();
        size.clear();
        for (int i = 0; i < C; i++) {
            cin >> creatures[i];
            parent[creatures[i]] = creatures[i];
            size[creatures[i]] = 1;
        }

        for (int i = 0; i < R; i++) {
            cin >> prey >> predator;
            prey = findSet(prey);
            predator = findSet(predator);
            if (prey != predator) 
                unionSet(prey, predator);
        }

        int max = 0;
        for (map<string,int>::iterator it = size.begin(); it != size.end(); ++it)
            if (it->second > max)
                max = it->second;
        cout << max << endl;
    }
}
