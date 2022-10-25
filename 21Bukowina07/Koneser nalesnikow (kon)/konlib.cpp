#include <stdlib.h>
#include <stdio.h>
#include <vector>

namespace {

	const long long limit = 1000000000;
	bool uninitialised=1, finished=0;
	long long cost=0;
	int pancakes;
	std::vector <long long> prefix;

	inline void init() {
		if (finished) exit(0);
		if (uninitialised) {
			if (scanf("%d",&pancakes)!=1) {
				printf("Niepoprawny format wejscia\n");
				exit(0);
			}

			prefix.resize(pancakes+1); prefix[0]=0;

			for (int i=1; i<=pancakes; i++) {
				if (scanf("%lld",&prefix[i])!=1) {
					printf("Niepoprawny format wejscia\n");
					exit(0);
				}
			}
			for (int i=2; i<=pancakes; i++) prefix[i]+=prefix[i-1];

			uninitialised=0;
		}
	}

}

int nalesniki() {
	init();
	return pancakes;
}

long long lepszy(int a, int b, int c, int d) {
	init();
	//printf("lepszy(%d, %d, %d, %d)\n", a, b, c, d);
	if (
		a>b || c>d || 
		0 >= a || a >= (int)prefix.size() || 
		0 >= b || b >= (int)prefix.size() || 
		0 >= c || c >= (int)prefix.size() || 
		0 >= d || d >= (int)prefix.size()
	) {
		printf("Niepoprawne zapytanie lepszy(%d,%d,%d,%d)\n",a,b,c,d);
		exit(0);
	}
	cost += b-a+1;
	cost += d-c+1;
	if (cost > limit) {
		printf("Przekroczono limit kosztu\n");
		exit(0);
	}
	return (prefix[b]-prefix[a-1])>(prefix[d]-prefix[c-1]);
}

void odpowiedz(int a, int b) {
	init();
	if (
		a>b || 
		0 >= a || a >= (int)prefix.size() || 
		0 >= b || b >= (int)prefix.size() 
	) {
		printf("Bledna odpowiedz\n");
	} else {
		printf("%lld\n",prefix[b]-prefix[a-1]);
	}
	finished=1;
}