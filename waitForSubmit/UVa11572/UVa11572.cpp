// current state :
// time (first submit) : 12:30
// state (first submit) :
// error reason :

#include <cstdio>
#include <map>
using namespace std;

main() {

    map<int,int>packages;
    int castNum, snowFlakeNum, snowFlakeID;

    scanf("%d", &castNum);
    scanf("%d", &snowFlakeNum);
    for (int i = 0; i < snowFlakeNum; i++) {
        scanf("%d", &snowFlakeID);
        packages[snowFlakeID]++;
    }
    printf("%ld",packages.size());


    for (int CASE = 1; CASE < castNum; CASE++) {
        packages.clear();
        scanf("%d", &snowFlakeNum);
        for (int i = 0; i < snowFlakeNum; i++) {
            scanf("%d", &snowFlakeID);
            packages[snowFlakeID]++;
        }
        printf("\n%ld",packages.size());
    }
}
