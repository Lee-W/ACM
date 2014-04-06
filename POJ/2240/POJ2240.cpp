#include <iostream>
#include <map>
using namespace std;

#define maxN 35
#define maxM 500    // combiantion(30,2)


map<string, int>currencyID;
double exchangeRates[maxN][maxN];

void init(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                exchangeRates[i][j] = 1;
            else
                exchangeRates[i][j] = 0;
}

bool Floyd(int n) {
    for (int k = 0; k < n; k++)
        for (int s = 0; s < n; s++)
            for (int d =0; d < n; d++)
                if (exchangeRates[s][k] * exchangeRates[k][d] > exchangeRates[s][d])
                    exchangeRates[s][d] = exchangeRates[s][k] * exchangeRates[k][d];

    for (int i = 0; i < n; i++)
        if (exchangeRates[i][i] > 1)
            return true;
    return false;
}

main()
{
    ios::sync_with_stdio(false);

    int n,m;
    string currency, source, destination;
    double rate;

    int caseCounter = 1;

    while(cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> currency;
            currencyID[currency] = i;
        }
        init(n);

        cin >> m;
        while (m--) {
            cin >> source >> rate >> destination;
            exchangeRates[currencyID[source]][currencyID[destination]] = rate;
        }

        cout << "Case " << caseCounter << ": " << (Floyd(n) ? "Yes" : "No") << endl;
        caseCounter++;
    }
}
