// current state :
// time (first submit) : 12:30
// state (first submit) :
// error reason :

#include <cstdio>
#include <map>
using namespace std;

main() {

    map<int,bool>packages;
    int castNum, snowFlakeNum, snowFlakeID;

    scanf("%d", &castNum);
    for (int CASE = 0; CASE < castNum; CASE++) {
        scanf("%d", &snowFlakeNum);
        for (int i = 0; i < snowFlakeNum; i++) {
            scanf("%d", &snowFlakeID);
            packages[snowFlakeID] = true;
        }
        printf("%ld\n",packages.size());
        packages.clear();
    }
}
