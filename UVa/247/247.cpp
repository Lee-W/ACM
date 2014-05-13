#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxN 30

map<string, int>customID;

vector<int> edge[maxN];
vector<string> result[maxN];

int dfn[maxN], low[maxN];
bool visited[maxN], inStack[maxN];
stack<int> s;
int num, counter;
int SCC[maxN];

// void uniqueSort(vector<int>&);
void init(int);
void tarjan(int);

int main() {
    ios::sync_with_stdio(false);

    int caseCounter = 0;
    bool isFirstCase = true;

    int n, m;
    string caller, callee;
    int customCounter;

    while (cin >> n >> m && (n || m)) {
        caseCounter++;
        customCounter = 1;
        init(n);

        while (m--) {
            cin >> caller >> callee;
            if (!customID[caller])
                customID[caller] = customCounter++;
            if (!customID[callee])
                customID[callee] = customCounter++;

            edge[customID[caller]].push_back(customID[callee]);
        }
        // for (int i = 1; i <= n; i++)
            // uniqueSort(edge[i]);

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                tarjan(i);

        for (map<string,int>::iterator it = customID.begin(); it != customID.end(); ++it)
            result[SCC[it->second]].push_back(it->first);

        if (isFirstCase)
            isFirstCase = false;
        else
            cout << endl;

        cout << "Calling circles for data set " << caseCounter << ":" << endl;
        for (int i = 1; i <= num; i++) {
            for (int j = 0; j < (int)result[i].size()-1; j++)
                cout << result[i][j] << ", ";
            cout << result[i].back() << endl;
        }
    }
}

// void uniqueSort(vector<int>& v) {
    // sort(v.begin(), v.end());
    // vector<int>::iterator it = unique(v.begin(), v.end());
    // v.erase(it, v.end());
// }

void init(int n) {
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
        result[i].clear();
    }
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(visited, false, sizeof(visited));
    memset(inStack, false, sizeof(inStack));
    while(!s.empty())
        s.pop();
    num = 0;
    counter = 0;
    customID.clear();
}

void tarjan(int current) {
    dfn[current] = low[current] = counter++;

    s.push(current);
    inStack[current] = true;
    visited[current] = true;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];

        if (!visited[next]) {
            tarjan(next);
            low[current] = min(low[current], low[next]);
        } else if (inStack[next])
            low[current] = min(low[current], dfn[next]);
    }

    if (dfn[current] == low[current]) {
        num++;
        SCC[current]= num;

        int next = 0;
        while(current != next) {
            SCC[next] = num;
            next = s.top();
            inStack[next] = false;
            s.pop();
        }
    }
}
