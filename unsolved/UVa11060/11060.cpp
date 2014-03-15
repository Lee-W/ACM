#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 105
#define maxM 205

main()
{
    int N, M;
    string beverages[maxN];
    map<string, int> beveragesID;
    vector<int> precedence[maxN];

    string first, second;

    vector<int> sequence;
    int visited[maxN];
    int indegrees[maxN];

    int caseCounter = 0;

    while(cin >> N) {
        caseCounter++;
        sequence.clear();
        for (int i = 0; i < N; i++) {
            cin >> first;
            beverages[i] = first;
            beveragesID[first] = i;
            visited[i] = false;
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> first >> second;
            precedence[beveragesID[second]].push_back(beveragesID[first]);
        }

        while(sequence.size() < N) {
            for (int i = 0; i < N; i++)
                if (!precedence[i].size() && !visited[i]) {
                    sequence.push_back(i);
                    visited[i] = true;
                }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < sequence.size(); j++) {
                    vector<int>::iterator it = find(precedence[i].begin(), precedence[i].end(), sequence[j]);
                    if (it != precedence[i].end())
                        precedence[i].erase(it);
                }
            }
        
        }
        cout << "Case #" << caseCounter << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < N; i++)
            cout << " " << beverages[sequence[i]];
        cout << ".\n" << endl;
    }
}
