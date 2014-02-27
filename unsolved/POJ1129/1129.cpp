#include <iostream>
using namespace std;

#define maxRepeaterNum 30

bool network[maxRepeaterNum][maxRepeaterNum];
bool visited[maxRepeaterNum];

void initialNetwork();
void setNetwork(string);
void initialVisited();
int countChannelNeeded(int);
void dfs(bool[], int, int);

main()
{
    ios::sync_with_stdio(false);

    int repeaterNum;
    string repeaterInfo;

    while(cin >> repeaterNum && repeaterNum) {
        initialNetwork();
        initialVisited();
        for (int i = 0 ; i < repeaterNum; i++) {
            cin >> repeaterInfo;
            setNetwork(repeaterInfo);
        }
        int channelNeeded = countChannelNeeded(repeaterNum);

        if (channelNeeded > 2)
            cout << channelNeeded << " channels needed." << endl;
        else
            cout << "1 channel needed." << endl;
    }
}

void initialNetwork() {
    for (int i = 0; i < maxRepeaterNum; i++)
        for (int j = 0; j < maxRepeaterNum; j++)
            if (i != j)
                network[i][j] = true;
            else
                network[i][j] = false;
}

void setNetwork(string info) {
    int start = info[0] - 'A';
    int end;
    for (int i = 2; i < info.size(); i++) {
        end = info[i] - 'A';
        network[start][end] = false;
    }
}
void initialVisited() {
    for (int i = 0; i < maxRepeaterNum; i++)
        visited[i] = 0;
}

int countChannelNeeded(int repeaterNum) {
    int channelNeeded = 0;

    for (int start = 0; start < repeaterNum; start++) {
        if (visited[start])
            continue;
        dfs(visited, repeaterNum, start);
        channelNeeded++;
    }
    return channelNeeded;
}

void dfs(bool visited[maxRepeaterNum], int repeaterNum, int start) {
    for (int end = 0; end < repeaterNum; end++) {
        if (network[start][end] && !visited[end]) {
            visited[end] = true;
            dfs(visited, repeaterNum, end);
        }
    }
}
