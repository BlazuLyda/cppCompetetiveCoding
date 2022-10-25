#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;
int t = -1;

vector<int> conns[250250];
int d[250250];
pair<int, int> tim[250250];

void dfs(int w, int o) {
	t++;
	tim[w].ff = t;
	d[w] = d[o] + 1;
	
	for (auto i : conns[w]) {
		if (i != o) dfs(i, w);
	}
	
	tim[w].ss = t;
}


// segment tree
const int R = (1 << 18);
int tree[R << 1];

void update(int w, int p, int k, int x, int y) {
	if (y < p || k < x) return;
	if (x <= p && k <= y) {
		tree[w]++;
		return;
	}
	
	int mid = (p + k) >> 1;
	update(w*2, p, mid, x, y);
	update(w*2+1, mid+1, k, x, y);
}

int query(int w) {
	int ret = 0;
	
	while (w) {
		ret += tree[w];
		w >>= 1;
	}
	
	return ret;
}

int main() {
	scanf("%d", &n);
	
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	d[0] = -1;
	dfs(1, 0);
	
	// for (int i = 1; i <= n; i++) { printf("w:%d tin:%d tout:%d\n", i, tim[i].ff, tim[i].ss); }
	
	scanf("%d", &m);
	char c;
	
	for (int i = 1; i < n+m; i++) {
		scanf(" %c", &c);
		
		if (c == 'A') {
			scanf("%d %d", &a, &b);
			
			if (tim[a].ff < tim[b].ff) swap(a, b);
			
			update(1, 0, R-1, tim[a].ff, tim[a].ss);
		} else {
			scanf("%d", &a);
			
			printf("%d\n", d[a] - query(tim[a].ff + R));
		}
	}
	
	return 0;
}
