// current state : AC
// time (first submit) : on course
// state (first submit) : AC
// error reason : none

#include <cstdio>
#include <queue>
using namespace std;

#define maxSize 30
const int directions[6][3] = {{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};

struct pos {
    int level;
    int row;
    int col;
    bool operator==(pos p) {
        return (this->level == p.level && this->row == p.row && this->col==p.col);
    }
};

bool isValidPos(pos, int, int, int);
void setPos(pos&, int, int, int);

main ()
{
    bool dungeon[maxSize][maxSize][maxSize];
    int visitedSeq[maxSize][maxSize][maxSize];  //set as 0 if not visited

    int level, row, col;

    while(scanf("%d%d%d", &level, &row, &col) ==3 && level!=0 && row!=0 && col!=0) {
        pos start,end;

        //initial
        for (int i = 0; i < level; i++)
            for (int j = 0; j < row; j++)
                for (int k = 0; k < col; k++) {
                    char tmp;
                    while(scanf("%c",&tmp)==1 && tmp!='S' && tmp!='E' && tmp!='.' && tmp!='#');
                    if (tmp == '#')
                        dungeon[i][j][k] = false;
                    else if (tmp == '.')
                        dungeon[i][j][k] = true;
                    else if (tmp == 'S') {
                        dungeon[i][j][k] = true;
                        setPos(start, i, j, k);
                    } else {
                        dungeon[i][j][k] = true;
                        setPos(end, i, j ,k);
                    }
                    visitedSeq[i][j][k] = false;
                }

        int timeUsed = 0;
        bool escaped = false;
        int current;
        queue<pos> q;
        q.push(start);
        visitedSeq[start.level][start.row][start.col] = 1;

        while(!q.empty()) {
            pos top = q.front();
            q.pop();
            current = visitedSeq[top.level][top.row][top.col];

            if (top==end) {
                escaped = true;
                break;
            }

            for (int i = 0; i < 6; i++) {
                pos next;
                setPos(next, top.level + directions[i][0], top.row + directions[i][1], top.col + directions[i][2]);

                if (isValidPos(next, level, row, col))
                    if (dungeon[next.level][next.row][next.col] && !visitedSeq[next.level][next.row][next.col]) {
                        q.push(next);
                        visitedSeq[next.level][next.row][next.col] = current+1;
                    }
            }
        }

        timeUsed = current-1;
        if (escaped)
            printf("Escaped in %d minute(s).\n", timeUsed);
        else
            printf("Trapped!\n");
    }
}

bool isValidPos(pos p, int level, int row, int col) {
    return p.level>-1 && p.level<level && p.row>-1 && p.row< row && p.col>-1 && p.col<col;
}

void setPos(pos& p, int level,int row,int col) {
    p.level = level;
    p.row = row;
    p.col = col;
}
