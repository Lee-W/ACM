#include <cstdio>
#include <cstring>

#define maxABC 25
#define impossibleValue -1 


int W[maxABC][maxABC][maxABC];

void initW() {
    for (int i = 0; i < maxABC; i++)
        for (int j = 0; j < maxABC; j++)
            for (int k = 0; k < maxABC; k++)
                W[i][j][k] = impossibleValue;
    W[20][20][20] = 1048576;
}


int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a >= 20 || b >= 20 || c >= 20) {
        return (W[20][20][20] == impossibleValue ? W[20][20][20] = w(20, 20, 20): W[20][20][20]);
    } else if (a < b && b <c) {
        int first, second, third;
        first = (W[a][b][c-1] == impossibleValue ? W[a][b][c-1] = w(a, b, c-1): W[a][b][c-1]);
        second = (W[a][b-1][c-1] == impossibleValue ? W[a][b-1][c-1] = w(a, b-1, c-1): W[a][b-1][c-1]);
        third = (W[a][b-1][c] == impossibleValue ? W[a][b-1][c] = w(a, b-1, c): W[a][b-1][c]);
        return W[a][b][c] = first + second - third;
    } else {
        int first, second, third, forth;
        first = (W[a-1][b][c] == impossibleValue ? W[a-1][b][c] = w(a-1, b, c): W[a-1][b][c]);
        second = (W[a-1][b-1][c] == impossibleValue ? W[a-1][b-1][c] = w(a-1, b-1, c): W[a-1][b-1][c]);
        third = (W[a-1][b][c-1] == impossibleValue ? W[a-1][b][c-1] = w(a-1, b, c-1): W[a-1][b][c-1]);
        forth = (W[a-1][b-1][c-1] == impossibleValue ? W[a-1][b-1][c-1] = w(a-1, b-1, c-1): W[a-1][b-1][c-1]);
        return W[a][b][c] = first + second + third - forth;
    }
}

main()
{
    initW();
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) == 3 && !( a == -1 && b == -1 && c == -1))
        printf("w(%d, %d, %d) = %d\n", a,b,c, w(a,b,c));
}
