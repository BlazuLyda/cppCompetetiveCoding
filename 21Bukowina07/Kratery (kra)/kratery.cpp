#include <bits/stdc++.h>

using namespace std;

long long n, m, w, h, k;

long long tab[4000][4000];

void fillArea (long long x1, long long y1, long long x2, long long y2) {
	for (long long i = x1; i < x2; ++i) {
		for (long long j = y1; j < y2; ++j) {
			tab[i][j] = 1;
		}
	}
}

void fillTab() {
	for (long long i = 1; i <= w; ++i) {
		for (long long j = 1; j <= h; ++j) {
			tab[i][j] += tab[i][j-1] + tab[i-1][j] - tab[i-1][j-1];
		}
	}
}

long long area (long long x1, long long y1, long long x2, long long y2) {
	return tab[x2][y2] - tab[x2][y1-1] - tab[x1-1][y2] + tab[x1-1][y1-1];
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &m, &w, &h);
	
	long long x1, x2, y1, y2, c;
	
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		
		fillArea(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
	}
	
	fillTab();
	
	for (int i = 0; i < m; ++i) {
		scanf("%lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &c);
		
		x1 = (x1 + k * c) %  w;
		x2 = (x2 + k * c) %  w;
		y1 = (y1 + k * c) %  h;
		y2 = (y2 + k * c) %  h;
		
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		
		k = area(x1 + 1, y1 + 1, x2, y2);
		printf("%lld\n", k);
	}
	
	return 0;
}
