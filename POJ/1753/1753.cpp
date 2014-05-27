#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

#define boardWidth 4
#define boardHeight 4
#define boardSize boardWidth*boardHeight

#define maxPossible 65540
#define allWhite 65535
#define allBlack 0

struct node {
    int board;
    int level;
};

int flipOffset[boardSize] = {51200, 58368, 29184, 12544,
                             35968, 20032, 10016, 4880,
                             2248, 1252, 626, 305,
                             140, 78, 39, 19};

bool visited[maxPossible];
queue< node > q;

bool BFS();

int main()
{
    int board = 0;
    char tmp;

    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            scanf("%c", &tmp);
            if (tmp == 'w')
                board += pow(2, 15 - 4*i - j);
        } 
        scanf("%c", &tmp);
    }

    memset(visited, false, sizeof(visited));

    node first;
    first.board = board;
    first.level = 0;

    q.push(first);
    visited[first.board] = true;
    if (!BFS())
        printf("Impossible\n");
}

bool BFS() {
    while(!q.empty()) {
        node current = q.front();
        q.pop();

        if (current.board == allWhite || current.board == allBlack) {
            printf("%d\n", current.level);
            return true;
        };

        for (int i = 0; i < boardSize; i++) {
            int nextBoard = (current.board ^ flipOffset[i]);
            if (!visited[nextBoard]) {
                node next;
                next.board = nextBoard;
                next.level = current.level + 1;

                q.push(next);
                visited[nextBoard] = true;
            }
        }
    }
    return false;
}
