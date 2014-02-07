// current state : AC
// time (first submit) : 11:51
// state (first submit) : WA
// error reason : Forget to clean the vector

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

main() {
	int N, value;
	vector<int>numbers;

	while( scanf("%d",&N)!=EOF ) {
		numbers.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d", &value);
			numbers.push_back(value);
		}

		int flipNum = 0;
		for (int i = 0; i < N; i++) 
			for (int j = i+1; j < N; j++) 
				if (numbers[i] > numbers[j])
					flipNum++;
			
		printf("Minimum exchange operations : %d\n",flipNum);
	}
}

