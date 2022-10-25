#include <bits/stdc++.h>

using namespace std;

int n;
int tab[4][1001][1001];

struct rec {
	int x[2], y[2], z, v;
};

vector<rec> obj;

bool cmp(rec a, rec b) {
	if (a.z == b.z) return a.v > b.v;
	return a.z < b.z;
}

void update(int x, int y, int v, int t) {
	for (int i = x; i < 1000; i += (i&-i)) {
		for (int j = y; j < 1000; j += (j&-j)) {
			tab[t][i][j] += v;
		}
	}
}

long long query(int x, int y, int t) {
	long long ret = 0;
	
	for (int i = x; i > 0; i -= (i&-i)) {
		for (int j = y; j > 0; j -= (j&-j)) {
			ret += (long long)tab[t][i][j];
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	obj.reserve(2*n);
	
	int x[2], y[2], z[2];
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &x[0], &y[0], &z[0], &x[1], &y[1], &z[1]);
		
		if (x[0] > x[1]) swap(x[0], x[1]);
		if (y[0] > y[1]) swap(y[0], y[1]);
		if (z[0] > z[1]) swap(z[0], z[1]);
		
		obj.push_back(rec{{x[0], x[1]}, {y[0], y[1]}, z[0], 1});
		obj.push_back(rec{{x[0], x[1]}, {y[0], y[1]}, z[1], -1});
	}
	
	sort(obj.begin(), obj.end(), cmp);
	
	long long res = 0;
	
	// 0 - pg 
	// 1 - lg  |1 0|
	// 2 - ld  |2 3|
	// 3 - pd   
	
	for (auto i : obj) {
		// query
		if (i.v == 1) {
			res += query(i.x[1], i.y[1], 2) - query(i.x[0] - 1, i.y[1], 3) - query(i.x[1], i.y[0] - 1, 1) + query(i.x[0] - 1, i.y[0] - 1, 0);
		}
		
		// update
		update(i.x[1], i.y[1], i.v, 0);
		update(i.x[0], i.y[1], i.v, 1);
		update(i.x[0], i.y[0], i.v, 2);
		update(i.x[1], i.y[0], i.v, 3);
	}
	
	printf("%lld", res);
	
	return 0;
}