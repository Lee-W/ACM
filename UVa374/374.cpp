#include <cstdio>

int modifiedModular(int,int,int);

main()
{
    int B,P,M;
    int R;
    while(scanf("%d%d%d", &B, &P, &M) == 3) {
        R = modifiedModular(B,P,M);
        printf("%d\n", R);
    }
}

int modifiedModular(int B, int P, int M) {
    if (P==1 || P==0 || B==1 || B==0) {
        return (P ? B%M : 1);
    } else if (B >= M) {
        return modifiedModular(B%M, P, M);
    } else {
        return modifiedModular(B*B, P/2, M) * (P%2 ? B%M: 1) %M;
    }
}
