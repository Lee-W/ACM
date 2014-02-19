// current state : AC
// time (first submit) : 11:03
// state (first submit) : AC
// error reason : None
#include <cstdio>
#include <algorithm>

#define maxSizeOfDataBase 100000
using namespace std;

main()
{
    int dataBase[maxSizeOfDataBase];
    int dataBaseSize, queryNum;
    char line[3];
    int query;

    scanf("%d", &dataBaseSize);
    for (int i = 0; i < dataBaseSize; i++)
        scanf("%d", &dataBase[i]);
    sort(dataBase , dataBase+dataBaseSize);

    scanf("%s",line);

    scanf("%d", &queryNum);
    while(queryNum--) {
        scanf("%d", &query);
        printf("%d\n", dataBase[query-1]);
    }
}
