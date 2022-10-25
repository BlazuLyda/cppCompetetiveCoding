#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, k;
int sum;
vector<int> spec;
vector<int> conns[500500];
int anc[500500];

int dfs(int w, int o) {
	int l = 0;
	
	for (auto i : conns[w]) {
		if (i != o) {
			l = max(l, dfs(i, w) + 1);
		}
	}
	
	return l;
}

pair<int, int> dfs2(int w, int o) {
	pair<int, int> l1 = {0, 0}, l2 = {0, 0}, s; //odległość, wierzchołek
	anc[w] = o;
	
	for (auto i : conns[w]) {
		if (i != o) {
			r = dfs(i, w);
			r.ff++;
			if (r.ff > l2.ff) l2 = r;
			if (l2.ff > l1.ff) swap(l1, l2);
		}
	}
	
	return l1;
}

int main() {
	scanf("%d %d", &n, &k);
	
	int a, b;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a);
		spec.push_back(a);
	}
	
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
		
	if (k == 1) {
		int longestPath = dfs(spec[0], 0);
		int result = 2 * (n - 1) - longestPath;
		
		printf("%d\n", result);
		
		return 0;
	}
	
	if (k == 2) {
		int x = spec[0]; y = spec[1];
		
		dfs(x, 0);
		int longestSum = 0, yp = y;
	
		while (yp != x) {
			
		}
	}
	
	return 0;
}
