#include <cstdio>
#include <cstring>

#define maxCaseNum 25
#define maxN 100005

int color[maxN]; //-1 to be unknown, 1 to be red, 0 to be black
bool grouped[maxN];

void ask(int first, int second) {
    if (color[first] == -1|| !color[second] == -1)
        printf("Not sure yet.");
    else if (color[first] == color[second])
        printf("In different gangs.");
    else if (color[first] != color[second])
        printf("In the same gang.");
}

void different(int first, int second) {
    if (color[first] == -1 && color[second] == -1) {
        color[first] = 1;
        color[second] = 0;
    } else if (color[first] != -1) {
        color[second] = !color[first];
    } else if (color[second] != -1) {
        color[first] = !color[second];
    }
}

main ()
{
    int caseNum, n, m;
    char cmd;
    int first, second;

    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d%d", &n, &m);
        memset(color, 0, n+1);
        bool isFirstSet = true;

        while (m--) {
            scanf("%c%d%d", &cmd, &first, &second);

            if (cmd == 'A') {
                ask(first, second);
            } else if (cmd ==  'D') {
                different(first, second);

            }
        }
    }

}
