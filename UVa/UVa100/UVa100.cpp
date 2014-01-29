// time (first submit) : 23:34
// state (first submit) : wrong answer
// error reason : The problem didn't say that i must less than j. Thus, such situation should be handled. 
// current state : accepted (2014/1/21)

#include <iostream>
#include <algorithm>
using namespace std;
void printMaxCycleTime(int,int);
int algorithm(double); 

main() {
	int i, j;
	while(cin>>i>>j) { 
		cout<<i<<" "<<j<<" ";
		printMaxCycleTime(i,j);
	}
}

void printMaxCycleTime(int i, int j) {
	long long int maxCycleTime = 0;
	if (i>j)
		swap(i,j);
	for (int k = i; k<=j; k++)
		if (algorithm(k) > maxCycleTime)
			maxCycleTime = algorithm(k);
	cout<<maxCycleTime<<endl;
}

int algorithm(double n){
	int cycleTime = 1;
	while(n != 1){
		if (n/2 - (int)n/2 >0) 		//it can be replace by n%2
			n = 3*n + 1 ;
		else
			n /= 2;
		cycleTime++;
	}
	return cycleTime;
}
