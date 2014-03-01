#include <cstdio>
#include <algorithm>

#define maxTransactionNum 30005

main()
{
    int caseNum, M, N;
    int A[maxTransactionNum], u[maxTransactionNum];

    while(scanf("%d", &caseNum) == 1) {
        while(caseNum--) {
            scanf("%d%d", &M, &N);
            for (int i = 0; i < M; i++)
                scanf("%d", &A[i]);
            for (int i = 0; i < N; i++)
                scanf("%d", &u[i]);

            int getCounter = 0;
            for (int i = 0; i < N; i++) {
                std::nth_element(A,A+getCounter,A+u[i]);
                printf("%d\n", A[getCounter++]);
            }

            if (caseNum)
                printf("\n");
        }
    }
}
