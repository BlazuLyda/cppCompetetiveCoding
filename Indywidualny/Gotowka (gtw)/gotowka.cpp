#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
long long ops[20];
long long DP[1<<20];
bool poss[1<<20];

void countSum(int p, int mask, long long s) {
	if (p == n) {
		if(s >= 0) 
			poss[mask] = 1;
		return;
	}
	countSum(p+1, mask^(1<<p), s+ops[p]);
	countSum(p+1, mask, s);
}

char* dexToBin(int d) {
	string s="";
	
	for(int i = 0; i < n; i++) {
		if (d&1)
			s += '1';
		else
			s += '0';
		d >>= 1;
	}
	return &s[0];
}

void countDP(int p, int mask, int k) {
	if (p == n && k) return; // wyszliśmy poza ostatni bit
	
	if (!k) { // Wszystkie bity wykorzystane
		if (!poss[mask]) {
			return; // Ujemna suma
		}
		
		for (int i = 0; i < n; i++) { // Liczenie DP[mask]
			if (mask & (1<<i)) {
				DP[mask] += DP[mask^(1<<i)];
				if (DP[mask] >= mod)
					DP[mask] -= mod;
			}
		}
		
		return;
	}
	
	countDP(p+1, mask^(1<<p), k-1);
	countDP(p+1, mask, k);
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ops[i]);
		if (ops[i] >= 0) DP[1<<i] = 1;
	}
	
	countSum(0, 0, 0);
	
	for (int i = 2; i <= n; i++) {
		countDP(0, 0, i);
	}
	
	printf("%lld", DP[(1<<n)-1]);
	
	return 0;
}
