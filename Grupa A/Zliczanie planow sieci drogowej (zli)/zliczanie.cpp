#include <bits/stdc++.h>

using namespace std;

long long n, d, p;
long long Q[201][201][201][2];
long long M[201][201];
long long DP[201][201][201];

int main() {
	scanf("%lld %lld %lld", &n, &d, &p);
	
	// Zliczanie na ile sposobów można stworzyć drzewo z i wierzchołków z maksymalną głębokością j
	for (long long i = 1; i <= (n-d); i++) {
		for (long long j = 1; j <= i; j++) {
			for (long long k = 1; k <= i; k++) {
				// Do wyniku dodaję wynik z tej samej głębokości
				Q[i][j][k][0] = (Q[i-1][j][n][0] * (i-2LL)) % p - Q[i-1][j][n][1];
				if (Q[i][j][k][0] < 0) Q[i][j][k][0] += p;
				
				// Do wyniku dodaję wynik z mniejszej o 1 głębokości
				Q[i][j][k][0] += Q[i-1][j-1][n][1];
				if (Q[i][j][k][0] >= p) Q[i][j][k][0] -= p;
				
				// Tworzę wynik pomnożony przez współczynnik k
				Q[i][j][k][1] = (Q[i][j][k][0] * k) % p;
				
				// Dodaję poprzednie wyniki z k żeby zrobić sumę prefxową 
				Q[i][j][k][0] += Q[i][j][k-1][0];
				Q[i][j][k][1] += Q[i][j][k-1][1];
				
				if (Q[i][j][k][0] >= p) Q[i][j][k][0] -= p;
				if (Q[i][j][k][1] >= p) Q[i][j][k][1] -= p;
				
			}
			
			// Przepisuje sumę wyników - ostatnią komórkę sumy prefixowej
			Q[i][j][n][0] = Q[i][j][(n-d-1)][0];
			Q[i][j][n][1] = Q[i][j][(n-d-1)][1];
		}
	}
	
	// Tablica dodatkowa
	for (int i = 0; i <= (n-d)) {
		for (int j = 1; j <= (n-d)) {
			
		}
	}
	
	
	// Zliczanie właściwego wyniku - liczbę możliwości stworzenia drzewa o n wierzchołkach ze średnicą długości d
	// i - ile zostało nam wierzchołków do wykorzystania
	// j - pozycja na drzewie (1, 2, 3, ..., d-1, d), j : [2, d-1]
	int h1, h2;
	
	for (long long j = 2; j < d; j++) {
		for (long long i = (n-d); i > 0; i--) {
			h1 = j - 1;
			h2 = d - j;
			
		}
	}
	
	return 0;
}
