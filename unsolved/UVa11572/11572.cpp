// current state :
// time (first submit) : 12:30
// state (first submit) : WA
// error reason : totally misunderstand what the problem said

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

main() {
    int caseNum, snowFlakeNum, snowFlakeID;
    vector<int> snowFlakes;

    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d", &snowFlakeNum);
        snowFlakes.clear();
        int maxPackageSize = 0;
        map<int, int> package;

        for (int i = 0; i < snowFlakeNum; i++) {
            scanf("%d", &snowFlakeID);
            snowFlakes.push_back(snowFlakeID);
        }

        for (int i = 0; i < snowFlakeNum; i++) {
            if (!package[snowFlakes[i]])
                package[snowFlakes[i]] = 1;
            else {
                maxPackageSize = max(maxPackageSize, (int)package.size());
                package.clear();
                package[snowFlakes[i]] = 1;
            }
        }
        maxPackageSize = max(maxPackageSize, (int)package.size());
        package.clear();

        for (int i = snowFlakeNum-1; i >=0; i--) {
            if (!package[snowFlakes[i]])
                package[snowFlakes[i]] = 1;
            else {
                maxPackageSize = max(maxPackageSize, (int)package.size());
                package.clear();
                package[snowFlakes[i]] = 1;
            }
        }
        maxPackageSize = max(maxPackageSize, (int)package.size());
        package.clear();

        printf("%d\n", maxPackageSize);
    }
}
