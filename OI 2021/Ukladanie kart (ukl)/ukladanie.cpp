#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long res;
long long factorial[1000100], A[1000100];


void compFact() {
	factorial[0] = 1;
	for (long long i = 1; i <= n; i++) {
		factorial[i] = (factorial[i-1] * i) % m;
	}
}

long long fact(int a) {
	return factorial[a];
}

void compA() {
	for (long long i = 1; i <= n; i++) {
		A[i] = (A[i-1] * i) % m;
		A[i] += (((i % 2) ? ((i-1)>>1) * i : (i>>1) * (i-1)) * fact(i-1)) % m;
		if (A[i] >= m) A[i] -= m;
	}
}

int main() {
	scanf("%lld %lld", &n, &m);

	compFact();
	compA();
	
	// Liczenie współczynnika A
	long long mul = 1;
	for (long long i = n-1; i >= 0; i--) {
		res += (A[i] * mul * 2LL) % m;
		if (res >= m) res -= m;
		mul = (mul * i) % m;
	}
	
	// Liczenie reszty
	long long div;
	
	for (long long i = 0; i <= n-1; i++) {
		div = ((i % 2) ? ((i-1)>>1) * i : (i>>1) * (i-1)) % m;
		
		
	}
	
	printf("%lld", res);
	
	return 0;
}
