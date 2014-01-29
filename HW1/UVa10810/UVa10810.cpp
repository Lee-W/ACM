// time (first submit) : 17:38
// state (first submit) : TLE
// error reason : using bubble sort wil cause TLE. Thus, using merge sort to handle this situation.
// current state : accepted (2014/1/22)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSort(int,int,long long int&);
void merge(int,int,int,long long int&);

vector<long long int>numbers;

main()
{
	long long int n, value;
	while(scanf("%lld", &n)==1 && n!=0) {
		numbers.clear();
        long long int round = 0;
		
		for (int i=0; i<n; i++) {
			scanf("%lld", &value);
			numbers.push_back(value);
		}

		mergeSort(0, numbers.size()-1, round);

		printf("%lld\n",round);	
	}
}

void mergeSort(int start, int end, long long int& round) {
	if (end > start) {
		int mid = (start+end)/2;
		mergeSort(start, mid, round);
		mergeSort(mid+1, end, round);
		merge(start, mid, end, round);
	}
}

void merge(int start, int mid, int end, long long int& round) {
	int leftSize = mid - start + 1; 	//includ mid
	int rightSize = end - (mid+1) +1;	//includ end
	
	int left[leftSize];
	int right[rightSize];
	
	for (int i=0; i<leftSize; i++) 
		left[i] = numbers[start+i];

	for (int i=0; i<rightSize; i++) 
		right[i] = numbers[mid+1+i];

	int leftCounter=0;
	int rightCounter=0;
	int resultCounter=0;

	while(leftCounter<leftSize && rightCounter<rightSize) {
        
        if (left[leftCounter] < right[rightCounter]) 
			numbers[start+resultCounter] = left[leftCounter++];
        else {
			numbers[start+resultCounter] = right[rightCounter++];
            round += ((mid+1) + rightCounter) - (start + resultCounter) -1;
        }
		resultCounter++;
	}

	while(leftCounter < leftSize) {
		numbers[start+resultCounter] = left[leftCounter++];
		resultCounter++;
	}
	while(rightCounter < rightSize) {
		numbers[start+resultCounter] = right[rightCounter++];
		resultCounter++;
	}
}
