#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>);

int graph[5][5] = { {0,1,1,0,1},
                    {1,0,1,0,1},
                    {1,1,0,1,1},
                    {0,0,1,0,1},
                    {1,1,1,1,0} };

main()
{
    ios::sync_with_stdio(false);
    vector<int> result;
    result.reserve(9);
    result.push_back(0);

    backtrack(result);
}

void backtrack(vector<int> result) {
    if (result.size() < 9) {
        int startPoint = result.back();
        for (int i = 0; i < 5; i++)
            if (graph[startPoint][i]) {
                graph[startPoint][i] = false;
                graph[i][startPoint] = false;
                result.push_back(i);
                backtrack(result);
                result.pop_back();
                graph[startPoint][i] = true;
                graph[i][startPoint] = true;
            }
    } else if (result.size() == 9) {
        for (int i = 0; i < 9; i++)
            cout << result[i]+1;
        cout << endl;
        result.pop_back();
    }
}
