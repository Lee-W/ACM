#include <cstdio>
#include <cmath>
#include <cstring>

#define maxSize 4

main()
{
    int grid[(int)pow(maxSize, 2)][(int)pow(maxSize, 2)];

    int size;
    while(scanf("%d", &size) == 1) {
        for (int i = 0; i < pow(size, 2); i++)
            for (int j = 0; j < pow(size, 2); j++)
                scanf("%d", &grid[i][j]);

        backtrack();

    }
}
