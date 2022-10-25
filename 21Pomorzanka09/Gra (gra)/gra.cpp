#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct point {
	long long x, y;
	int idx;
	
	void read(int idx1) {
		scanf("%lld %lld", &x, &y);
		idx = idx1;
	}
	
	point friend operator - (point a, point b) {
		return {a.x - b.x, a.y - b.y, a.idx};
	}
	
	long long dis() {
		return x*x + y*y;
	}
};

bool cmp(point a, point b) {
	return a.x*a.x + a.y*a.y > b.x * b.x + b.y * b.y;
}

int n, m, l;
bool conns[505][505]; // Matryca połączeń [1MB]
vector<int> peers[505]; // Vektory połączeń dla każdego [16KB]
point nodes[505]; // Zapisane współrzędne każdego punktu
vector<pair<int, int>> query; // [1MB]

// inne
long long maxi[505][505]; // [2MB]
bool add[505][505]; // Czy para a, b występuje w tablicy niżej --v-- [1MB]
vector<point> nei[505]; // Dla każdego wierzchołka a lista sąsiadów wierzchołków x, gdzie występuje zapytanie (a, x) [5MB]
vector<int> bel[505][505]; // Dla każdej pary a, b lista wierzchołków x które mają połączenie z b i jest zapytanie (a, x); [8MB]


int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		nodes[i].read(i);
	}
	
	scanf("%d", &m);
	
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		conns[a][b] = 1;
		conns[b][a] = 1;
		peers[a].push_back(b);
		peers[b].push_back(a);
	}
	
	scanf("%d", &l);
	query.resize(l);
	
	for (int i = 0; i < l; i++) {
		scanf("%d %d", &a, &b);
		query[i] = {a, b};
		
		for (auto j : peers[b]) {
			bel[a][j].push_back(b);
			if (!add[a][j]) {
				nei[a].push_back(nodes[j] - nodes[a]);
				add[a][j] = 1;
			}
		}
		for (auto j : peers[a]) {
			bel[b][j].push_back(a);
			if (!add[b][j]) {
				nei[b].push_back(nodes[j] - nodes[b]);
				add[b][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		sort(nei[i].begin(), nei[i].end(), cmp);
		
		for (auto j : nei[i]) {
			for (auto k : bel[i][j.idx]) {
				if (!maxi[i][k]) maxi[i][k] = j.dis();
			}
		}
	}
	
	for (auto i : query) {
		printf("%Lf\n", sqrtl(maxi[i.ff][i.ss] > maxi[i.ss][i.ff] ? maxi[i.ff][i.ss] : maxi[i.ss][i.ff]));
	}
	
	return 0;
}
