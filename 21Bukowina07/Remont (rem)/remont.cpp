#include <bits/stdc++.h>
#define mod  1000000007LL

using namespace std;

int n;
vector<int> graph[300300];
long long DP[300300];
long long wyn[300300];

long long DFS1(int w, int o) {
	DP[w] = 1;
	
	for (auto i : graph[w]) {
		if (i != o) DP[w] = (DP[w] * ((DFS1(i, w) + 1LL)) % mod) % mod;
	}
	
	//printf("DP[%d]:%lld\n", w, DP[w]);
	
	return DP[w];
}

long long rev(long long a) {
	long long pot = 1000000005LL, res = 1LL;
	
	while (pot) {
		if (pot & 1LL) res = (res * a) % mod;
		a = (a * a) % mod;
		pot >>= 1LL;
	}
	
	return res;
}

void DFS2(int w, int o) {
	long long last = DP[o];
	DP[o] = (DP[o] * rev((DP[w] + 1LL) % mod)) % mod;
	DP[w] = (DP[w] * ((DP[o] + 1LL)) % mod) % mod;
	wyn[w] = DP[w];
	
	for (auto i : graph[w]) {
		if (i != o) DFS2(i, w);
	}
	
	DP[o] = last;
}

int main() {
	scanf("%d", &n);
	
	int a;
	
	for (int i = 2; i <= n; i++) {
		scanf("%d", &a);
		
		graph[i].push_back(a);
		graph[a].push_back(i);
	}
	
	DFS1(1, 0);
	
	for (auto i : graph[1]) {
		DFS2(i, 1);
	}
	
	printf("%lld ", DP[1]);
	
	for (int i = 2; i <= n; i++) {
		printf("%lld ", wyn[i]);
	}
	
	return 0;
}
