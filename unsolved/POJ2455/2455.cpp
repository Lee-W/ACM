//TODO:multi-trail between two landmark

//1-based
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define maxN 205
#define INF 1000005

int length[maxN][maxN];
int capacity[maxN][maxN], flow[maxN][maxN], residual[maxN][maxN];
bool visited[maxN];
int path[maxN], bottleneck[maxN];

void init();
int EdmondsKarp(int, int, int, int);
void deleteDuplicate(vector<int>&);

main()
{
    int n, p, t;
    int start, end, len;
    vector<int>dis;

    scanf("%d%d%d", &n, &p, &t);
    memset(capacity, 0, sizeof(capacity));
    while(p--) {
        scanf("%d%d%d", &start, &end, &len);
        length[start][end] = length[end][start] = len;
        capacity[start][end] = capacity[end][start] = 1;
        dis.push_back(len);
    }
    init();
    deleteDuplicate(dis);

    int left = 0, right = dis.size(), mid;
    int result;
    while(right >= left) {
        mid = (left + right)/2;
        init();
        int tripNum = EdmondsKarp(1, n, n,dis[mid]);
        if (tripNum >= t) {
            right = mid - 1;
            result = dis[mid];
        } else
            left = mid + 1;
    }
    printf("%d\n", result);
}

void init() {
    memset(flow, 0, sizeof(flow));
    memcpy(residual, capacity, sizeof(capacity));
    memset(path, -1, sizeof(path));
    memset(bottleneck, 0, sizeof(bottleneck));
}

int BFS(int s, int t, int n, int b) {
    memset(visited, false, sizeof(visited));

    queue<int> q;
    visited[s] = true;
    path[s] = s;
    bottleneck[s] = INF;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
            if (!visited[i] && residual[cur][i] > 0 && length[cur][i] <= b) {
                visited[i] = true;
                path[i] = cur;
                bottleneck[i] = min(bottleneck[cur], residual[cur][i]);
                q.push(i);

                if (i == t)
                    return bottleneck[t];
            }
    }
    return 0;
}

int EdmondsKarp(int s, int t, int n, int b) {
    int maxFlow = 0, currentFlow;
    while (currentFlow = BFS(s, t ,n, b)) {
        int pre = path[t], cur = t;
        while(pre != cur) {
            flow[pre][cur] = flow[pre][cur] + currentFlow;
            flow[cur][pre] = -flow[pre][cur];
            residual[pre][cur] = capacity[pre][cur] - flow[pre][cur];
            residual[cur][pre] = capacity[cur][pre] - flow[cur][pre];
            cur = pre;
            pre = path[cur];
        }
        maxFlow += currentFlow;
    }
    return maxFlow;
}

void deleteDuplicate(vector<int>& v) {
    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.erase(it, v.end());
}
