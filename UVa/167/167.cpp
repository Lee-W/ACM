#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int,int> point;
void backtrack();
bool isValidPos(point);

vector<point> choosed;
int chessBoard[8][8];
int maxSum = 0;

main()
{
    int caseNum;
    scanf("%d", &caseNum);
    while(caseNum--) {
        choosed.reserve(8);
        maxSum = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                scanf("%d", &chessBoard[i][j]);

        backtrack();
        printf("%5d\n", maxSum);
        choosed.clear();
    }
}

void backtrack() {
    if (choosed.size() < 8) {
        point p;
        p.first = choosed.size();
        for (int col = 0; col < 8; col++) {
            p.second = col;
            if (isValidPos(p)) {
                choosed.push_back(p);
                backtrack();
                choosed.pop_back();
            }
        }
    } else if (choosed.size() == 8) {
        int sum = 0;
        for (int i = 0; i < choosed.size(); i++)
            sum += chessBoard[choosed[i].first][choosed[i].second];
        if (sum > maxSum)
            maxSum = sum;
    }
}

bool isValidPos(point p) {
    for (int i = 0; i < choosed.size(); i++) {
        if (p.first == choosed[i].first || p.second == choosed[i].second)
            return false;
        double slope = (double)(p.first-choosed[i].first)/(double)(p.second-choosed[i].second);
        if (slope == 1 || slope == -1)
            return false;
    }
    return true;
}
