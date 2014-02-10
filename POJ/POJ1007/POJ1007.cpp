// current state : AC
// time (first submit) : 22:54
// state (first submit) : AC
// error reason : None

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 50
#define maxM 100
using namespace std;

struct DNA{
    string DNAstring;
    int unsortness;
};

bool cmp(DNA first, DNA second) {
    return (first.unsortness < second.unsortness);
}

main()
{
    int m,n;
    DNA DNAs[maxM];

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        cin >> DNAs[i].DNAstring;
        DNAs[i].unsortness = 0;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n-1; j++)
            for (int k = j+1; k < n; k++)
                if (DNAs[i].DNAstring[j] > DNAs[i].DNAstring[k])
                    DNAs[i].unsortness++;

    sort(DNAs, DNAs+m, cmp);

    for (int i = 0; i < m; i++)
        printf("%s\n", DNAs[i].DNAstring.c_str());
}
