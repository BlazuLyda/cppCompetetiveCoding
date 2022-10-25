#include <bits/stdc++.h>

using namespace std;

struct node {
	long long m, mh, p, ph;
};

const int R = (1<<19);
node tree[R*2];

void push(int w) {
	if (w < R) {
		tree[w*2].p += tree[w].p;
		tree[w*2].ph = max(tree[w*2].ph, tree[w*2].p);
		tree[w*2+1].p += tree[w].p;
		tree[w*2+1].ph = max(tree[w*2+1].ph, tree[w*2+1].p);
	}
	tree[w].mh = max(tree[w].mh, tree[w].m + tree[w].ph);
	tree[w].m += tree[w].p;
	tree[w].p = 0;
	tree[w].ph = 0;
}

void update(int w, int p, int k, int x, int y, int v) {
	if (k < x || y < p) {
		return;
	}
	
	if (x <= p && k <= y) {
		tree[w].p += v;
		tree[w].ph = max(tree[w].ph, tr);
		push(w);
		return;
	}
	
	push(w);
	update(w*2, p, (p+k)/2, x, y, v);
	update(w*2+1, (p+k)/2+1, k, x, y, v);
}

long long query(int w, int p, int k, int x, int y) {
	if (k < x || y < p) {
		return 0;
	}
	
	push(w);
	
	if (x <= p && k <= y) {
		return tree[w].mh;
	}
	
	return max(query(w*2, p, (p+k)/2, x, y), query(w*2+1, (p+k)/2+1, k, x, y));
}

int n, q;

int main() {
	scanf("%d %d", &n, &q);
	
	int t, a, b;
	long long c;
	
	while (q--) {
		scanf("%d", &t);
		
		if (t == 1) {
			scanf("%d %d %lld", &a, &b, &c);
			update(1, 1, R, a, b, c);
		} else if (t == 3) {
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(1, 1, R, a, b));
		} else {
			printf(":(\n");
		}
	}
	
	return 0;
}
