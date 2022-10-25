#include <bits/stdc++.h>
#define inf 100100
#define ff first
#define ss second

using namespace std;

int n;
vector<pair<int, int>> points;
vector<pair<int, int>> scale;

const int R = 131072;
vector<pair<int, int>> tree[2][R*2];

int query(int w, int t) {
	int s = w, l = -1, res = 0;
	w >>= 1;
	
	while (w) {
		if ( !(s % 2) ) { // wychodzimy z lewego syna
			auto p = upper_bound(tree[t][s+1].begin(), tree[t][s+1].end(), make_pair(l, -1));
			res += tree[t][s+1].end() - p;
			l = p != tree[t][s+1].end() ? tree[t][s+1].back().ff : l;
			
		}
		s = w;
		w >>= 1;
	}
	
	return res;
}

void update(int w, int v, int t) {
	int id = w;
	
	tree[t][w] = {{v, id}};
	w >>= 1;
	
	while (w) {
		for (auto i = tree[t][w].end()-1; i >= tree[t][w].begin() && i->ss > id; i--)
			tree[t][w].pop_back();
		tree[t][w].push_back({v, id});
		w >>= 1;
	}
}

int main() {
	scanf("%d", &n);
	points.resize(n);
	scale.resize(n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d" , &points[i].ff, &points[i].ss);
		scale[i] = {points[i].ss, i};
	}
	
	for (int i = 1; i < R*2; i++) {
		tree[0][i].push_back({-1, -1});
		tree[1][i].push_back({-1, -1});
	}

	// skalowanie
	sort(scale.begin(), scale.end());
	
	int num = 0;
	for (auto i : scale) {
		points[i.ss].ss = num;
		num++;
	}

	sort(points.begin(), points.end());
	
	long long wyn = 0;
	int x, y;
	
	for (int i = 0; i < n; i++) {
		x = points[i].ff;
		y = points[i].ss;
		
		long long a = (long long) query(y + R, 0);
		long long b = (long long) query(inf - y + R, 1);
		
		wyn += a;
		wyn += b;
		
		update(y + R, x, 0);
		update(inf - y + R, x, 1);
	}
	
	printf("%lld", wyn);
	
	return 0;
}