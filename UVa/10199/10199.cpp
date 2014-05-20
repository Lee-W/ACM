#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define maxN 105

vector<int> edge[maxN];
int low[maxN], dfn[maxN];

vector<int>articulationPoint;

map<string, int>ID;
string name[maxN];

void init(int);
void DFS(int,int,int);

bool cmp(int ID1, int ID2) {
    return name[ID1] < name[ID2];
}

int main()
{
    ios::sync_with_stdio(false);

    int vertexNum, edgeNum;
    string source, destination;
    int caseCounter = 0;
    bool isFirstCase = true;

    while (cin >> vertexNum && vertexNum) {
        caseCounter++;

        init(vertexNum);
        for (int i = 1; i <= vertexNum; i++) {
            cin >> source;
            ID[source] = i;
            name[i] = source;
        }

        cin >> edgeNum;
        while(edgeNum--) {
            cin >> source >> destination;
            edge[ID[source]].push_back(ID[destination]);
            edge[ID[destination]].push_back(ID[source]);
        }

        for (int i = 1; i <= vertexNum; i++)
            if (!dfn[i])
                DFS(i, 0, 1);

        if (isFirstCase)
            isFirstCase = false;
        else
            cout << endl;

        cout << "City map #" << caseCounter << ": "<< articulationPoint.size() <<" camera(s) found" << endl;
        sort(articulationPoint.begin(), articulationPoint.end(), cmp);
        for (int i = 0; i < (int)articulationPoint.size(); i++)
            cout << name[articulationPoint[i]] << endl;
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        edge[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    articulationPoint.clear();
}

void DFS(int current, int parent, int counter) {
    int child = 0;
    bool isArticulationPoint = false;

    dfn[current] = low[current] = counter++;

    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];
        if (!dfn[next]) {
            child++;
            DFS(next, current, counter);
            low[current] = min(low[current], low[next]);

            if (low[next] >= dfn[current] )
                isArticulationPoint = true;
        } else if (next != parent)
            low[current] = min(low[current], dfn[next]);
    }
    if ((child >= 2 || parent > 0) && isArticulationPoint) {
        articulationPoint.push_back(current);
    }
}
