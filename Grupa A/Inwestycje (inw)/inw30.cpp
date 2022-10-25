#include <bits/stdc++.h>
#define inf 1000000000000LL

using namespace std;

int n;
long long x;
long long DP[2000][2000];
long long w[2000];
long long z[2000];

int main() {
	scanf("%d %lld", &n, &x);
	
	for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &z[i]);
	
	// DP
	for (int i = 0; i <= n; i++) DP[i][0] = x;
	for (int j = 1; j <= n; j++) DP[0][j] = -1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			DP[i][j] = max(
				DP[i-1][j],
				DP[i-1][j-1] >= w[i] ? DP[i-1][j-1] - w[i] + z[i] : -1
			);
		}
		for (int j = i+1; j <= n; j++) DP[i][j] = -1;
	}
	
	// Result
	for (int j = n; j >= 0; j--) {
		if (DP[n][j] >= 0) {
			printf("%d", j);
			return 0;
		}
	}
	
	return 0;
}
