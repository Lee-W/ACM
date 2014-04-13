#include <cstdio>

#define maxN 105
#define maxM 105

struct exchangeRule {
    int source;
    int destination;
    double rate;
    double commision;
};

exchangeRule e[maxM*2];


void BellmanFord(int n, int m, int source, int number) {
    double money[n+1];
    for (int i = 1; i <= n; i++)
        money[i] = 0;
    money[source] = number;

    for (int i = 0; i < n-1; i++) 
        for (int j = 0; j < 2*m; j++) 
            if ((money[e[j].source]-e[j].commision)*e[j].rate > money[e[j].destination])
                money[e[j].destination] = (money[e[j].source]-e[j].commision)*e[j].rate;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            if (e[i].destination == source)
                money[e[j].source] = (money[e[j].source]-e[j].commision) * e[j].rate;

    for (int i = 1; i <= n; i++)
        if (money[i] > number) {
            printf( "YES\n" );
            return;
        }
    printf("NO\n");
        
    
}

main()
{
    int n, m, s;
    double v;
    int a, b;
    double Rab, Cab, Rba, Cba;
    exchangeRule tmp;

    scanf("%d%d%d%lf", &n, &m, &s, &v);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lf%lf%lf%lf", &e[i].source, &e[i].destination, &e[i].rate, &e[i].commision, &e[i+m].rate, &e[i+m].commision);
        e[i+m].source = e[i].destination;
        e[i+m].destination = e[i].source;
    }
    BellmanFord(n, m, s, v);
}
