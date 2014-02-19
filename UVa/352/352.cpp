// current state : AC
// time (first submit) : on course
// state (first submit) : WA
// error reason : using wrong variable

#include <cstdio>
#define maxDiemention 25
using namespace std;

void search(int,int);

int graph[maxDiemention][maxDiemention];
int visited[maxDiemention][maxDiemention];
const int directions[8][2] = {{-1,-1},{0,-1},{1,-1},
                          {-1,0},{1,0},
                          {-1,1},{0,1},{1,1}};


int dimention, eagleNum;
main ()
{
    int caseCounter = 0;

    while(scanf("%d", &dimention) == 1) {
        eagleNum = 0;
        caseCounter++;

        //initial
        for (int i = 0; i < dimention; i++)
            for (int j = 0; j < dimention; j++) {
                char tmp;
                while(scanf("%c", &tmp)==1 && tmp!='1' && tmp!='0');
                graph[i][j] = tmp-'0';
                visited[i][j] = 0;
            }

        //search
        for (int i = 0; i < dimention; i++)
            for (int j = 0; j < dimention; j++)
                if (graph[i][j] && !visited[i][j]) {
                    eagleNum++;
                    visited[i][j] = 1;
                    search(i,j);
                }
        printf("Image number %d contains %d war eagles.\n", caseCounter, eagleNum);
    }
}

void search(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nextX = x + directions[i][0];
        int nextY = y + directions[i][1];

        if (nextX > -1 && nextY > -1 && nextX < dimention && nextY < dimention)
            if (graph[nextX][nextY] && !visited[nextX][nextY]) {
                visited[nextX][nextY] = 1;
                search(nextX, nextY);
            }
    }
}
