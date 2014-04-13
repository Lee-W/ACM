#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define maxRoomNum 105
#define nINF INT_MAX/5*(-1)

struct room {
    int energy;
    vector<int>exits;
};

room rooms[maxRoomNum];
int dis[maxRoomNum];

bool LPFA(int n, int source, int des) {
    queue<int> q;
    bool inqueue[n+1];
    int count[n+1];
    for (int i = 1; i <= n; i++) {
        dis[i] = nINF;
        inqueue[i] = false;
        count[i] = 0;
    }

    dis[source] = 100;
    inqueue[source] = true;
    q.push(source);

    while(!q.empty()) {
        int current = q.front();
        inqueue[current] = false;
        q.pop();

        for (int i = 0; i < rooms[current].exits.size(); i++) {
            int des = rooms[current].exits[i];
            if (dis[current] + rooms[des].energy > dis[des]) {
                dis[des] = rooms[des].energy + dis[current];
                if (!inqueue[des]) {
                    q.push(des);
                    inqueue[des] = true;
                    count[des]++;
                    if (count[des] >= n) return true;
                }
            }
        }

    }

    if (dis[des] > 0)
        return true;
    else
        return false;
}

main()
{
    int roomNum;
    int energy, exitNum, des;

    while (scanf("%d", &roomNum) && roomNum != -1) {
        for (int i = 1; i <= roomNum; i++) {
            rooms[i].exits.clear();

            scanf("%d%d", &rooms[i].energy, &exitNum);
            while(exitNum--) {
                scanf("%d", &des);
                rooms[i].exits.push_back(des);
            }
        }
        printf("%s\n", (LPFA(roomNum, 1, roomNum))?"winnable":"hopeless");
    }
}
