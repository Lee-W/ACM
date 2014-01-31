// current state : AC
// time (first submit) : 24:31
// state (first submit) : CE 
// error reason : Wrong submission. G++ should be chosen instead of C++ or main function without return type will not be accept


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct characteristic {
	int id;
	int a;
	int b;
};


bool cmp(characteristic first, characteristic second) {
	return first.a > second.a;
}

bool cmp2(characteristic first, characteristic second) {
	return first.b > second.b;
}

int main() 
{
	long int n, k;
	long int a, b;

	vector<characteristic>chs;

	scanf("%ld%ld", &n, &k);

	for (int i=0; i<n; i++) {
		scanf("%ld%ld", &a, &b);
		characteristic tmp;
		tmp.id = i+1;
		tmp.a = a;
		tmp.b = b;
		chs.push_back(tmp);
	}

	sort(chs.begin(), chs.end(), cmp);
	sort(chs.begin(), chs.begin()+k, cmp2);
	printf("%d",chs[0].id);	
	return 0;
}
