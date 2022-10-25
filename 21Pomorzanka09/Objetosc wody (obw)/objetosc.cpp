#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007LL 

using namespace std;

int n, k;
long long DP[25005][26][2][2];
int tab[25005];
int lef[25005], rig[25005];

// Drzewo przedziałowe
const int R = 32768;
int tree[R*2];

void update(int w) {
	while (w) {
		tree[w]++;
		w >>= 1;
	}
}

void query(int w, int p, int k, int x, int y) {
	if (y < p || k < x) {
		return 0;
	}
	
	if (p <= x && y <= k) {
		return tree[w];
	}
	
	return query(w*2, p, (p+k)/2, x, y) + query(w*2+1, (p+k)/2+1, k, x, y);
}

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tab[i]);
	}
	
	// Szukanie pierwszego mniejszego równego z lewej i z prawej --------> O(n)
	set<pair<int, int>> hei; // wysokość wstawiam z minusem
	
	hei.insert({0, 0});
	for (int i = 1; i <= n; i++) {
		auto p = hei.lower_bound({tab[i], 100000});
		lef[i] = p->ss; // index pierwszego mniejszego lub równego z lewej
		hei.insert({-tab[i], i});
	}
	
	hei.clear();
	hei.insert({0, n+1});
	for (int i = n; i >= 1; i--) {
		auto p = hei.lower_bound({tab[i], 100000});
		rig[i] = p->ss; // index pierwszego mniejszego lub równego z prawej
		hei.insert({-tab[i], i});
	}
	
	// Obliczanie DP[i (1;n)][j (0;k)][s (0;1)][p (0;1)];
	
	
	return 0;
}
