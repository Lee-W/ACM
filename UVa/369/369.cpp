#include <cstdio>
#define maxThingNum 105

long double countCombination(int,int);

main()
{
    int n, m;
    long double c;
    while(scanf("%d%d", &n, &m) && n && m) {
        c = countCombination(n, m);
        printf("%d things taken %d at a time is %.0llf exactly.\n", n, m, c);
    }
}

long double countCombination(int n, int m) {
    long double combination = 1;
    int counter = (m < n-m ? m : n-m);
    for (int i = 1; i <= counter; i++) {
        combination *= (n-i+1);
        combination /= i;
    }
    return combination;
}
