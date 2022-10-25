#include <bits/stdc++.h>

using namespace std;

long long p = 1023;

long long fpow(long long a, long long b) {
	long long res = 1;
	
	while (b) {
		if (b & 1LL) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	
	return res;
}

int main()
{
	cout << fpow(1000, 112);
	
	return 0;
}
