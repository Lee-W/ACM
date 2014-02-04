// current state : AC
// time (first submit) : 74:18
// state (first submit) : not submit -> TLE
// error reason : Struct cannot be compared unless operator overloading is written. Also, the original algorithm which using Cmn
//                is not efficient enough. A straight forward way to count is much efficinet.

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define maxNumOfVertex 1000
using namespace std;
typedef pair<double,double> vertice;

main ()
{
    vertice vertex[maxNumOfVertex];
    vector<vertice>mids;
    int caseNum, vertexNum;
    int numOfParallelograms;

    scanf("%d",&caseNum);
    while(caseNum--) {
        scanf("%d", &vertexNum);
        for (int v = 0; v < vertexNum; v++)
            scanf("%lf%lf", &vertex[v].first, &vertex[v].second);
        mids.clear();
        mids.reserve(vertexNum*vertexNum);

        numOfParallelograms = 0;

        for (int i = 0; i < vertexNum-1; i++)
            for (int j = i+1; j < vertexNum; j++) {
                vertice mid;
                mid.first = (vertex[i].first + vertex[j].first)/2;
                mid.second = (vertex[i].second + vertex[j].second)/2;
                mids.push_back(mid);
            }
        sort(mids.begin(), mids.end());

        for (int i = 0; i < mids.size()-1; i++) {
            for (int j = i+1; j < mids.size(); j++) {
                if (mids[i] == mids[j]) {
                    numOfParallelograms++;
                } else
                    break;
            }
        }
        printf("%d\n",numOfParallelograms);
    }
}
