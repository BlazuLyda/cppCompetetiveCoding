#include <bits/stdc++.h>

using namespace std;

long long n, d, p;
long long Q[201][201][201];
long long R[201][201][201];
long long S[201][201];
long long DP[201][201][201];

long long fpow(long long a, long long b) {
	long long res = 1;
	
	while (b) {
		if (b & 1LL) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	
	return res;
}

int main() {
	scanf("%lld %lld %lld", &n, &d, &p);

	
	// Liczenie pomocnych tablic
	// i - ilość wierzchołków - suma prefixowa 
	// j - głębokość
	// k - ilość wierzchołków na ostatniej warstwie - suma prefixowa
	for (long long i = 1; i <= (n-d); i++) {
		for (long long j = 1; j <= i; j++) {
			for (long long k = 1; k <= n; k++) {
				
				// Wynik
				Q[i][j][k] = R[i-1][j-1][n];
				R[i][j][k] = (Q[i][j][k] * k) % p;
								
				// Prefix
				Q[i][j][k] += Q[i-1][j][k] + Q[i][j][k-1] - Q[i-1][j][k-1] + p;
				R[i][j][k] += R[i-1][j][k] + R[i][j][k-1] - R[i-1][j][k-1] + p;
				
				// Modulo
				while (Q[i][j][k] >= p) Q[i][j][k] -= p;
				while (R[i][j][k] >= p) R[i][j][k] -= p;
			}
			
			S[i][j] = Q[i][j][n] + S[i][j-1];
			if (S[i][j] >= p) S[i][j] -= p;
		}
	}
	
	
	
	// Liczenie właściwego wyniku
	// Zliczanie właściwego wyniku - liczbę możliwości stworzenia drzewa o n wierzchołkach ze średnicą długości d
	// i - ile zostało nam wierzchołków do wykorzystania
	// j - ile zostało na poprzedniej pozycji z którą chcemy połączyć wynik
	// k - pozycja na drzewie (1, 2, 3, ..., d-1, d), j : [2, d-1]
	int h;
	
	for (long long k = 2; k < d; k++) {
		for (long long i = 0; i <= (n-d); i++) {
			for (long long j = i; j <= (n-d); j++) {
				h = min(j - 1, d - j);
				
				DP[i][k] += (DP[j][k] * S[j-i][h]) % mod;
				
				if (DP[i][k] >= p) DP[i][k] -= p;
			}
		}
	}
	
	// Wynik
	long long res = (DP[0][d-1] * fpow(2LL, p-2LL)) % mod;
	
	printf("%lld", res);
	
	return 0;
}
