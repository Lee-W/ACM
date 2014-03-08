#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 105

main()
{
    vector<int> predence[maxN];
    vector<int> sequence;
    int visited[maxN];

    int n, m;
    while (scanf("%d%d", &n, &m) && (n || m)) {
        sequence.reserve(n);
        for (int i = 0; i < n; i++) {
            predence[i].clear();
            visited[i] = false;
        }
        sequence.clear();

        int first, second;
        while(m--) {
            scanf("%d%d", &first, &second);
            predence[second-1].push_back(first-1);
        }
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < predence[i].size(); j++)
                printf("%d\t", predence[i][j]);
            printf("\n");
        }
        */
        while(sequence.size() < n) {
            for (int i = 0; i < n; i++)
                if (!predence[i].size() && !visited[i]) {
                    sequence.push_back(i);
                    visited[i] = true;
                }

           for (int i = 0; i < n; i++)
               for (int j = 0; j < sequence.size(); j++) {
                   vector<int>::iterator it = find(predence[i].begin(), predence[i].end(), sequence[j]);
                   if (it != predence[i].end())
                       predence[i].erase(it);
                }
        }

        for (int i = 0 ; i < sequence.size()-1; i++)
            printf("%d ", sequence[i]+1);
        printf("%d\n", sequence.back()+1);
    }
}
