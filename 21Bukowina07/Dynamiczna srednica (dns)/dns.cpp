#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long

using namespace std;

//program variables
ll n, q, w, last;
const int R = 131072;
int tin[R], tout[R], anc[R];
vector<pair<int, ll>> graph[R];
int t = 0;

//segment tree of nodes' distances to root
ll tree[R*2], puss[R*2];

void push(int w) {
	tree[w*2] += puss[w];
	tree[w*2+1] += puss[w];
	puss[w] = 0;
}

pair<int, ll> query(int w, int p, int k, int x, int y) {
	if (y < p || k < x) return {w, 0}
	if (x <= p && k <= y) return {w, tree[w]}
	
	if (puss[w] != 0) push(w);
	
	pair<int, ll> one = query(w*2, p, (p+k)/2, x, y);
	pair<int, ll> two = query(w*2+1, (p+k)/2+1, k, x, y);
	
	if (one.ss > two.ss) return one;
	return two;
}

void update(int w, int p, int k, int x, int y, long long v) {
	if (y < p || k < x) return;
	if (x <= p && k <= y) {
		tree[w] += v;
		push[w] += v;
		return;
	}
	
	update(w*2, p, (p+k)/2, x, y, v);
	update(w*2+1, (p+k)/2+1, k, x, y, v);
}

//LCA in O(logn)

int DFS_order[R], DFS_idx;
vector<int> DFS_order_idx[R]; 
int depth[R];
vector<pair<int,int>> LCArr[R];

void fillLCArr() {
	int len = 1;
	
	for (int j = 1; j <= n; ++j) {
		LCArr[j] = {DFS_order[j], depth[DFS_order[j]]};
	}
	
	for (int i = 1; i <= 16; ++i) {
		for (int j = 1; (j + len - 1) <= n; ++j) {
			if(LCArr[j][i-1].ss < LCArr[j + (len>>1)][i-1].ss)	LCArr[j][i] = LCArr[j][i-1];
			else 	LCArr[j][i] = LCArr[j + (len>>1)][i-1];
		}
		
		len <<= 1; //kolejna potęga dwójki
	}
	
}

int LCA(int w, int v) {
	int len = abs(v - w) + 1;
}

int DFS(int w, int o, long long dis) {
	DFS_order[DFS_idx] = w;
	DFS_order_idx[w].push_back(DFS_idx);
	DFS_idx++;
	
	ANC[w] = o;
	tin[w] = ++t;
	depth[w] = depth[o] + 1;
	
	for (auto i : graph[w]) {
		if (i.ff == o) continue;
		
		DFS(i.ff, dis + i.ss);
	}
	
	DFS_order[DFS_idx] = w;
	DFS_order_idx[w].push_back(DFS_idx);
	DFS_idx++;
	
	tout[w] = t;
}

int main() {
	scanf("%lld %lld %lld", &n, &q, &w);
	
	long long a, b, c;
	
	for (int i = 1; i < n; ++i)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	DFS(1, 0);
	
	long long d, e;
	
	while (q--) {
		scanf("%lld %lld", &d, &e);
		
		d = (d + last) % (n-1);
		e = (e + last) % w;
		
		
	}
	
	return 0;
}
