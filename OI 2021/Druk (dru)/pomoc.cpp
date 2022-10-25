#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned llu;

vector<int> primes;

int main() {
	bool p = 1;
	
	for (int i = 2; i <= 1000; i++) {
		p = 1;
		for (auto j : primes) {
			if (i % j == 0) {
				p = 0;
				break;
			}
		}
		if (p) primes.push_back(i);
	}
	
	printf("%lu\n", primes.size());
	for (auto i : primes) printf("%d, ", i);
	
	return 0;
}
