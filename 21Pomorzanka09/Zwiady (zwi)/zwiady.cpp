#include <bits/stdc++.h>
#define inf 1000000

using namespace std;

struct nodeBeats {
	int m1, m2, count, p; 
};

struct node {
	long long v, p; 
};

int n, q;
int R = 1;
vector<nodeBeats> treeBeats;
vector<node> tree;

void push(int w) {
	tree[(w<<1)].p += tree[w].p >> 1;
	tree[(w<<1) + 1].p += tree[w].p >> 1;
	tree[(w<<1)].v += tree[w].p >> 1;
	tree[(w<<1) + 1].v += tree[w].p >> 1;
	tree[w].p = 0;
}

void add(int w, int p, int k, int x, int y, long long v) {
	if (k < x || y < p) return;
	if (x <= p && k <= y) {
		tree[w].p += v;
		tree[w].v += v;
		return;
	}
	
	push(w);
	
	int mid = (p + k) >> 1;
	add((w<<1), p, mid, x, y, (v>>1));
	add((w<<1)+1, mid+1, k, x, y, (v>>1)); 
}

long long query(int w, int p, int k, int x, int y) {
	if (k < x || y < p) return 0;
	if (x <= p && k <= y) return tree[w].v;
	
	push(w);
	
	int mid = (p+k) >> 1;
	return query((w<<1), p, mid, x, y) + query((w<<1)+1, mid+1, k, x, y);
}

// Segment tree beats
void pushBeats(int w) {
	treeBeats[(w<<1)].p = min(treeBeats[(w<<1)].p, treeBeats[w].p);
	treeBeats[(w<<1)+1].p = min(treeBeats[(w<<1)+1].p, treeBeats[w].p);
	treeBeats[w].p = inf;
}

void update(int w) {
	nodeBeats * s1 = & treeBeats[(w<<1)];
	nodeBeats * s2 = & treeBeats[(w<<1)+1];

	if (s1->m1 > s2->m1) {
		treeBeats[w].m1 = s1->m1;
		treeBeats[w].count = s1->count;
		treeBeats[w].m2 = max(s1->m2, s2->m1);
	} else if (s1->m1 < s2->m1) {
		treeBeats[w].m1 = s2->m1;
		treeBeats[w].count = s2->count;
		treeBeats[w].m2 = max(s1->m1, s2->m2);
	} else {
		treeBeats[w].m1 = s1->m1;
		treeBeats[w].count = s1->count + s2->count;
		treeBeats[w].m2 = max(s1->m2, s2->m2);
	}
}

void buildTrees() {
	while (R < n) {
		R <<= 1;
	}
	
	tree.resize(R<<1);
	treeBeats.resize(R<<1);
	
	for (int i = 0; i < R; i++) {
		tree[i+R].v = 1;
		
		treeBeats[i+R].m1 = i + 1;
		treeBeats[i+R].m2 = -1;
		treeBeats[i+R].count = 1;
		treeBeats[i+R].p = inf;
	}
	
	for (int i = R-1; i >= 1; i--) {
		tree[i].v = tree[(i<<1)].v + tree[(i<<1)+1].v;
		
		treeBeats[i].p = inf;
		update(i);
	}
}

int setBeats(int w, int p, int k, int x, int v) {
	if (k < x || x < p) return 0;
	if (x == p && k == x) {
		//~ printf("Found old city %d in w: %d\n", x, w);
		//~ printf("p: %d\n", treeBeats[w].p);
		//~ printf("Before minning: %d\n", treeBeats[w].m1);
		treeBeats[w].m1 = min(treeBeats[w].m1, treeBeats[w].p);
		treeBeats[w].p = inf;
		int old = treeBeats[w].m1;
		treeBeats[w].m1 = v;
		return old;
	}
	
	pushBeats(w);
	
	int mid = (p+k) >> 1;
	int res = setBeats((w<<1), p, mid, x, v) + setBeats((w<<1)+1, mid+1, k, x, v);
	
	update(w);
	return res;
}

void mini(int w, int p, int k, int x, int y, int v) {
	if (k < x || y < p || treeBeats[w].m1 <= v) return;
	if (x <= p && k <= y && treeBeats[w].m2 < v) {
		add(1, 1, R, v+1, treeBeats[w].m1, -treeBeats[w].count*R);
		treeBeats[w].m1 = min(treeBeats[w].m1, v);
		treeBeats[w].p = v;
		return;
	}
	
	pushBeats(w);
	
	int mid = (p+k) >> 1;
	mini((w<<1), p, mid, x, y, v);
	mini((w<<1)+1, mid+1, k, x, y, v);
	
	update(w);
}

int main() {
	scanf("%d %d", &n, &q);
	
	buildTrees();
	
	int t, a, b;
	int prev;
	
	while (q--) {
		scanf("%d %d %d", &t, &a, &b);
		
		if (t == 1) { 
			// update
			mini(1, 1, R, 1, a-1, a-1);
			prev = setBeats(1, 1, R, a, b);
			printf("prev for %d: %d\n", a, prev);
			printf("new for %d: %d\n\n", a, b);
			add(1, 1, R, prev+1, b, R);
			
		} else { 
			// zapytanie
			printf("%lld\n", query(1, 1, R, a, b));
		}
	}
	
	return 0;
}
