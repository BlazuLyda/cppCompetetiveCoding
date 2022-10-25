#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n;
int anc[200200], lasPos[200200];
int R = 1;
vector<int> tree;

void maxi(int w, int mx) {
	while (w) {
		tree[w] = max(tree[w], mx);
		w >>= 1;
	}
}

int query(int w, int p, int k, int x, int y) {
	if (k < x || y < p) return 0;
	if (x <= p && k <= y) return tree[w];
	
	int mid = (p + k) >> 1;
	return max(query((w<<1), p, mid, x, y), query((w<<1)+1, mid+1, k, x, y));
}

int main() {
	scanf("%d", &n);
	
	while (R < n) {
		R <<= 1;
	}
	
	tree.resize((R<<1), 0);
	
	int a, l, res;
	queue<pair<int, int>> que;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		
		anc[i] = lasPos[a];
		lasPos[a] = i;
		l = anc[i];
		
		while (l) {
			res = (i - l) > 1 ? query(1, 1, R, l+1, R) + 2 : 2;
			que.push({res, l});
			l = anc[l];
		}
		
		while (!que.empty()) {
			maxi(que.front().ss + R - 1, que.front().ff);
			que.pop();
		}
	}
	
	printf("%d", query(1, 1, R, 1, R));
	
	return 0;
}
