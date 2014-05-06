#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define maxN 505

struct student {
    double height;
    char gender;
    string preferMusic;
    string favouriteSport;
};

student s[maxN];
vector<int>edge[maxN];

int llink[maxN], rlink[maxN];
bool visited[maxN];

bool isHighProbToBecomeCouple(student,student);
void init(int, int&, int&);
int Bipartite(int,int);
bool DFS(int);

int main()
{
    ios::sync_with_stdio(false);

    int caseNum, n;
    int maleNum, femaleNum;

    cin >> caseNum;
    while(caseNum--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> s[i].height >> s[i].gender >> s[i].preferMusic >> s[i].favouriteSport;
        init(n, maleNum, femaleNum);

        cout << n-Bipartite(maleNum, femaleNum) << endl;
    }
}

bool isHighProbToBecomeCouple(student s1, student s2) {
    if ((abs(s1.height - s2.height) <= 40) && (s1.gender != s2.gender) && (s1.preferMusic == s2. preferMusic) && (s1.favouriteSport != s2.favouriteSport))
        return true;
    return false;
}

void init(int n, int& nL, int& nR) {
    nL = nR = 1;
    for (int i = 1; i <= n; i++)
        if (s[i].gender == 'M')
            llink[nL++] = i;
        else if (s[i].gender == 'F')
            rlink[nR++] = i;

    nL--;
    nR--;

    for (int i = 1; i <= nL; i++) {
        edge[i].clear();
        for (int j = 1; j <= nR; j++)
            if ( isHighProbToBecomeCouple(s[llink[i]], s[rlink[j]]) )
                edge[i].push_back(j);
    }
}

int Bipartite(int nL, int nR) {
    int num = 0;
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));

    for (int i = 1; i <= nL; i++) {
        memset(visited, false, sizeof(visited));
        if (DFS(i))
            num++;
    }
    return num;
}

bool DFS(int current) {
    for (int i = 0; i < (int)edge[current].size(); i++) {
        int next = edge[current][i];

        if (!visited[next]) {
            visited[next] = true;

            if (!rlink[next] || DFS(rlink[next])) {
                llink[current] = next;
                rlink[next] = current;
                return true;
            }
        }
    }
    return false;
}
