#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define maxL 1000005
#define maxN 100005

struct fuelStop {
    int distance;
    int fuelLeft;
    bool operator<(const fuelStop f) const{
        return this->distance<f.distance;
    };
    bool operator==(const fuelStop f) const{
        return this->distance==f.distance;
    };
    bool operator>(const fuelStop f) const{
        return this->distance>f.distance;
    };
};

main ()
{
    int numOfStop, distanceFromTown, fuel;
    fuelStop fuelStops[maxN];
    int numOfStopPassed = 0;

    scanf("%d", &numOfStop);
    for (int i = 0; i < numOfStop; i++) {
        fuelStop tmp;
        scanf("%d%d", &tmp.distance, &tmp.fuelLeft);
        fuelStops[i] = tmp;
    }
    sort(fuelStops, fuelStops+numOfStop, greater<fuelStop>());
    scanf("%d%d", &distanceFromTown, &fuel);
    for (int i = 0; i < numOfStop; i++)
        fuelStops[i].distance = distanceFromTown - fuelStops[i].distance;

    fuelStops[numOfStop].distance = distanceFromTown;
    fuelStops[numOfStop].fuelLeft = 0;

    priority_queue<int> stopFuels;
    for (int i = 0; i < numOfStop+1; i++) {
        while(fuel < fuelStops[i].distance && !stopFuels.empty()) {
            fuel += stopFuels.top();
            stopFuels.pop();
            numOfStopPassed++;
        }
        if (fuel < fuelStops[i].distance)
            break;

        stopFuels.push(fuelStops[i].fuelLeft);
    }

    printf("%d\n", (fuel < distanceFromTown ? -1: numOfStopPassed));
}
