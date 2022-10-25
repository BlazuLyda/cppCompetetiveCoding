#include <bits/stdc++.h>
#define mod 1000000007LL
#define ff first
#define ss second

using namespace std;

int n;
long long tab[300300];
vector<pair<long long, int>> place;
int idx[300300];
long long sum[300300];

// Drzewa przedziałowe
int S = 1, R = 1;
vector<long long> tree;

long long query(int w, int p, int k, int x, int y) {
	if (k < x || y < p) return 0;
	if (x <= p && k <= y) return tree[w];
	
	int mid = (p + k) / 2;
	long long ret = query(w*2, p, mid, x, y) + query(w*2+1, mid+1, k, x, y);
	if (ret >= mod) ret -= mod;
	return ret;
}

void update(int w, long long v) {
	while (w) {
		tree[w] += v;
		if (tree[w] >= mod) tree[w] -= mod;
		w >>= 1;
	}
}

int main() {
	// Wczytywanie wielkości ciągu
	scanf("%d", &n);
	
	// Poszerzanie tablic
	while (R < n) R <<= 1;
	S = R <<= 1;
	tree.resize(S*2);
	place.resize(n);
	
	// Wczytywanie ciągu
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tab[i]);
	}

	// Wyznaczanie kolejności elementów na drzewie przedziałowym
	for (int i = n-1; i >= 0; i--) {	
		sum[i] = sum[i+1] + tab[i];
		if (sum[i] >= mod) sum[i] -= mod;
		
		place[i] = {sum[i], i};
	}
	
	sort(place.begin(), place.end());
	
	for (int i = 0; i < n; i++) idx[place[i].ss] = i;
	
	// Operacje na drzewie, szukanie wyniku
	long long p = 0, k = 0, q;
	
	for (int i = 0; i < n; i++) {
		// Zapytanie o parzyste [p, k]
		if (p <= k)	{
			q = query(1, 0, S-1, p, k);
		} else {
			q = query(1, 0, S-1, 0, p-1) + query(1, 0, S-1, k+1, n*2-1);
			if (q >= mod) q -= mod;
		}
		
		if (i == 0) q = 1;
		
		printf("i:%d q:%lld\n", i, q);
		
		// Update w punkcie
		if (tab[i] % 2 == 0) {
			update(idx[i]+S, q);
		} else {
			update(idx[i]+S+n, q);
		}
		
		// Przesunięcie parzystości
		if (tab[i] % 2 == 0) {
			p = idx[i];
			k = p + n - 1;
		} else {
			k = (idx[i] - 1 + S) % S;
			p = (k + n + 1) % n;
		}
	}
	
	long long res;
	
	if (p <= k)	{
		res = query(1, 0, S-1, p, k);
	} else {
		res = query(1, 0, S-1, 0, p-1) + query(1, 0, S-1, k+1, n*2-1);
		if (res >= mod) res -= mod;
	}
	
	printf("%lld\n", res);
	
	return 0;
}