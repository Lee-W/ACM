#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

#define maxN 105

vector<int> edge[maxN];
int low[maxN], dfn[maxN];

vector<int>articulationPoint;

void init(int);
void DFS(int,int,int);

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string input;
    int source, des;

    while(cin >> n && n) {
        init(n);
        while(getline(cin, input) && input[0] != '0') {
            stringstream ss;
            ss << input;

            ss >> source;
            while(!ss.eof()) {
                ss >> des;
                edge[source].push_back(des);
                edge[des].push_back(source);
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            cout << i << "\t"; 
            for (int j = 0; j < edge[i].size(); j++)
                cout << edge[i][j] << " ";
            cout << endl;
        }*/
        DFS(1, 0, 1);
        cout << articulationPoint.size() << endl;
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

            if (low[next] >= dfn[current])
                isArticulationPoint = true;
        } else if (next != parent)
            low[current] = min(low[current], dfn[next]);
    }
    if ((child >= 2 || parent > 0) && isArticulationPoint) {
        articulationPoint.push_back(current);
    }
}
