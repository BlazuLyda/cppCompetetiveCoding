#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct point {
	int x, y, t, id;
};

bool cmp(point a, point b) {
	if (a.x == b.x) {
		return a.y > b.y;
	}
	return a.x < b.x;
}

set <pair<int, int>> brush; // x-cord, id 
int n;
vector<point> points;
pair<int, int> ext[500500]; // x-cord, y-cord

int main() {
	scanf("%d", &n);
	
	int x, y;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		points.push_back({x, y, 0, i});
		ext[i] = {x, y};
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		points.push_back({x, y, 1, i});
	}
	
	sort(begin(points), end(points), cmp);
	
	long long res = 0;
	vector<pair<int, int>> conns;
	
	for (auto i : points) {
		if (i.t) { // punkt dystrybucji gazu
			auto peer = brush.lower_bound({i.y, 0});
			brush.erase(peer);
			
			res += (long long)(i.x - ext[peer->ss].ff) + (ext[peer->ss].ss - i.y); // odległość pomiędzy punktami
			conns.push_back({peer->ss, i.id}); // połączenie punktu poboru i dystrybucji
		} else { // punkt wydobycia gazu
			brush.insert({i.y, i.id});
		}
	}
		
	printf("%lld\n", res);
	for (auto i : conns) {
		printf("%d %d\n", i.ff, i.ss);
	}
}