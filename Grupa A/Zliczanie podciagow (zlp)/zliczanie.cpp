#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n, q;
long long z;
long long DP[50100][21][21];
int tab[50100];

long long fpow(long long a, long long p) {
	long long res = 1;
	while (p) {
		if (p & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return res;
}

int main() {
	scanf("%d %lld", &n, &z);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tab[i]);
		
		for (int p = 1; p <= z; p++) {
			for (int k = 1; k <= z; k++) {
				DP[i][p][k] = DP[i-1][p][k];
				if (DP[i][p][k] >= mod) DP[i][p][k] -= mod;
			}
		}
		
		for (int k = 1; k <= tab[i]; k++) {
			for (int p = 1; p <= z; p++) {
				DP[i][p][v] += DP[i][p][k];
				if (DP[i][p][v] >= mod) DP[i][p][v] -= mod;
			}
		}
		
		DP[i][v][v]++;
		if (DP[i][v][v] >= mod) DP[i][v][v] -= mod;
	}
	
	scanf("%d", &q);
	int l, r;
	long long A[21][21], B[21][21], C[21], D[21];
	long long res;
	
	while (q--) {
		res = 0;
		A = DP[l-1];
		B = DP[r];
		
		for (int p = 1; p <= 20; p++) {
			for (int k = 1; k <= 20; k++) {
				B[p][k] -= A[p][k];
				if (B[p][k] < 0) B[p][k] += mod;
			}
		}
		
		for (int k = 2; k <= 20; k++) {
			for (int p = 1; p <= 20; p++) {
				A[p][k] += A[p][k-1];
				if (A[p][k] >= mod) A[p][k] -= mod;
			}
		}
		
		for (int p = 19; p > 0; p--) {
			for (int k = 1; k <= 20; k++) {
				B[p][k] += B[p+1][k];
				if (B[p][k] >= mod) B[p][k] -= mod;
			}
		}
		
		for (int i = 2; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				B[i][j] = (B[i][j] * fpow(A[]))
			}
		}
	}
	
	return 0;
}
