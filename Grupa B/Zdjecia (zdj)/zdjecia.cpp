#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct node {
	int val, push;
};

struct line {
	int x, v, y[2];
};

bool cmp(line a, line b) {
	if (a.x == b.x) return a.v > b.v;
	return a.x < b.x;
}

int n, res;
vector<line> lines;
vector<pair<int, pair<int*, int*>>> scale;

const int R = 262144;
node tree[R*2];

void push(int w) {
	int l = w<<1;
	int r = l+1;
	
	tree[l].val += tree[w].push;
	tree[l].push += tree[w].push;
	tree[r].val += tree[w].push;
	tree[r].push += tree[w].push;
	tree[w].push = 0;
}

void add(int w, int p, int k, int x, int y, int v) {
	if (k < x || y < p) return;
	if (x <= p && k <= y) {
		tree[w].val += v;
		tree[w].push += v;
		return;
	}
	
	push(w);
	
	int mid = (p+k)>>1;
	add((w<<1), p, mid, x, y, v);
	add((w<<1)+1, mid+1, k, x, y, v);
	
	tree[w].val = max(tree[w<<1].val, tree[(w<<1)+1].val);
}

int query(int w, int p, int k, int x, int y) {
	if (k < x || y < p) return 0;
	if (x <= p && k <= y) return tree[w].val;
	
	push(w);
	
	int mid = (p+k)>>1;
	return max(query((w<<1), p, mid, x, y), query((w<<1)+1, mid+1, k, x, y));	
}

int main() {
	scanf("%d", &n);
	
	int x0, x1, y0, y1, pom;
	
	lines.reserve(n*2);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		
		pom = lines.size();
		lines.push_back({x0, 1, {1, 2}});
		lines.push_back({x1, -1, {3, 4}});
		
		scale.push_back({y0, {&lines[pom].y[0], &lines[pom+1].y[0]}});
		scale.push_back({y1, {&lines[pom].y[1], &lines[pom+1].y[1]}});
	}
	
	// skalowanie
	int last = 1000000, num = 0;
	sort(scale.begin(), scale.end());
	
	for (auto i : scale) {
		if (i.ff != last) {
			num++;
			last = i.ff;
		}
		
		*i.ss.ff = num;
		*i.ss.ss = num;
	}
	
	sort(lines.begin(), lines.end(), cmp);
	
	for (auto i : lines) {
		//printf("LINE... x:%d y0:%d y1:%d p/k:%d\n", i.x, i.y[0], i.y[1], i.v);
		add(1, 0, R-1, i.y[0], i.y[1], i.v);
		
		if (i.v == 1) { // Rozpoczecie
			res = max(res, query(1, 0, R-1, 0, R-1));
		}
	}
	
	printf("%d", res);
	
	return 0;
}
