#include <cstdio>
#include <map>
using namespace std;

main()
{
    int request, clientID, priority;

    map<int, int>priorityToID;
    map<int, int>::iterator it;

    while(scanf("%d", &request) == 1 && request) {
        switch(request) {
            case 1:
                scanf("%d%d", &clientID, &priority);
                priorityToID[priority] = clientID;
                break;
            case 2:
                if (priorityToID.empty())
                    printf("0\n");
                else {
                    it = --priorityToID.end();
                    printf("%d\n", it->second);
                    priorityToID.erase(it->first);
                }
                break;
            case 3:
                if (priorityToID.empty())
                    printf("0\n");
                else {
                    it = priorityToID.begin();
                    printf("%d\n", it->second);
                    priorityToID.erase(it->first);
                }
                break;
            default:
                break;
        }
    }
}
