// current state : AC
// time (first submit) : 15:57
// state (first submit) : AC
// error reason : None

#include <cstdio>
using namespace std;

void printWave(int);

main ()
{
    int numOfCase, amplitude, frequcecy;

    scanf("%d", &numOfCase);

    scanf("%d%d", &amplitude, &frequcecy);
    printWave(amplitude);
    for (int i = 1; i < frequcecy; i++) {
        printf("\n");
        printWave(amplitude);
    }

    for (int CASE = 1; CASE < numOfCase; CASE++) {
        scanf("%d%d", &amplitude, &frequcecy);
        for (int i = 0; i < frequcecy; i++) {
            printf("\n");
            printWave(amplitude);
        }
    }
}

void printWave(int amplitude) {
    for (int i = 1; i <= amplitude; i++) {
        for (int j = 0; j < i; j++)
            printf("%d",i);
        printf("\n");
    }
    for (int i = amplitude-1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            printf("%d",i);
        printf("\n");
    }
}
