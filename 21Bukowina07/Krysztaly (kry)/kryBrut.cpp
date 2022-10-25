#include <bits/stdc++.h>

using namespace std;

const int n = 4;
bitset<1000> b;

int main() {
	
	for (int i = 0; i <= 100; ++i) {
		printf("%d: %d\n", i, i^n);
	}
	
	return 0;
}
