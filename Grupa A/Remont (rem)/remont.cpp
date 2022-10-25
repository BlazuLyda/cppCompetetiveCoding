#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
vector<int> conns[300300];
long long DP[300300];
long long res[300300];

long long mdiv(long long a) {
	int p = mod - 2LL;
	long long res = 1LL;
	
	while (p) {
		if (p & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		p >>= 1;
	}
	return res == 0 ? mod : res; // 3. zabezpieczenie
}

void compDP(int w, int o) {
	DP[w] = 1;
	
	for (auto i : conns[w]) {
		if (i != o) {
			compDP(i, w);
			DP[w] = (DP[w] * (DP[i] + 1LL)) % mod;
		}
	}
	
	if (DP[w] == 0) DP[w] = mod; // 1. zabezpiecznie
}

void collectRes(int w, int o) {
	long long newDP = (DP[o] * mdiv(DP[w] + 1LL)) % mod;
	DP[w] = (DP[w] * (newDP + 1LL)) % mod;
	res[w] = DP[w] % mod;
	
	if (DP[w] == 0) DP[w] = mod; // 2. zabezpieczenie
	
	for (auto i : conns[w]) {
		if (i != o) collectRes(i, w);		
	}
}

int main() {
	scanf("%d", &n);
	
	int a;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &a);
		conns[a].push_back(i);
		conns[i].push_back(a);
	}
	
	compDP(1, 0);
	res[1] = DP[1] % mod;
	
	for (auto i : conns[1]) {
		collectRes(i, 1);
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%lld ", res[i]);
	}
	
	return 0;
}
