#include <bits/stdc++.h>

using namespace std;

unsigned long long fib[100] = {1, 1};
vector<unsigned long long> rozkl[100];
map<unsigned long long, int> primesNum;
set<unsigned long long> primes; 
int pot[100];

void printVec(vector<unsigned long long> v) {
	printf("\t");
	for (auto i : v) printf("%llu, ", i);
	printf("\n");
}

vector<unsigned long long> rozloz(unsigned long long a) {
	vector<unsigned long long> rozklad;
	
	while (a % 2 == 0) {
		a >>= 1;
		rozklad.push_back(2);
	}
	
	for (unsigned long long i = 3; i * i <= a; i += 2LL) {
		while (a % i == 0) {
			a /= i;
			rozklad.push_back(i);
		}
	}
	
	if (a != 1) rozklad.push_back(a);
	
	return rozklad;
}

int main() {
	for (int i = 2; i <= 90; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		
		unsigned long long a = 1000000000000000000ULL / fib[i];
		while (a) {
			pot[i]++;
			a /= fib[i];
		}
	}
	
	for (int i = 0; i <= 90; i++) {
		rozkl[i] = rozloz(fib[i]);
		
		printf("%d\n", i);
		printf("\t%llu\n", fib[i]);
		printf("\t%d\n", pot[i]);
		printVec(rozkl[i]);
		
		unsigned long long last = 1;
		
		for (auto j : rozkl[i]) {
			if (j == last) continue;
			last = j;
			primes.insert(j);
			primesNum[j]++;
		}
	}
	
	for (auto i : primes) {
		printf("%lld : %d\n", i, primesNum[i]);
	}
	
	for (int i = 0; i < 90; i++) printf("%llu, ", fib[i]);
	
	return 0;
}
