#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, k, m;
long long res;
int dis[6][100100];
int anc[6][100100];
int imp[6];
int isImp[100100];
vector<pair<int, long long>> conns[100100]; // <W, koszt>

// Dijkstra
priority_queue<pair<long long, <int, int>>> que; // <-koszt, <A, B>>
int vis[100100];

void dijkstra(int w, int idx) {
	int a, b;
	long long k;
	vis.reset();
	que.push({0, {0, w}});
	
	while (!que.empty()) {
		a = que.top().ss.ff;
		b = que.top().ss.ss;
		k = -que.top().ff;
		que.pop();
		
		if (vis[b] == w) continue; // już tu byliśmy w turze {w}
		vis[b] = w;	
		dis[idx][b] = k;
		anc[idx][b] = a;
	
		for (auto i : conns[b]) {
			if (vis[i.ff] != w) {
				que.push({ -((long long) k + i.ss), i.ff});
			}
		}
	}
}

// Find and Union
int rep[100100];

int find(int a) {
	if (rep[a] != a) {
		rep[a] = find(rep[a]);
	}
	return rep[a];
}

// Backtrack
vector<int> backtrack(int w, int v) { // w - root, v - z tego wierzcholka robimy backtrack
	vector<int> ret;
	int idx = isImp[w];
	
	while (v != w) {
		ret.push(v);
		v = anc[idx][v];
	}
	
	return ret;
}

// Krusgal
priority_queue<pair<long long, pair<int,int>>> vert; // <-koszt, <A, B>>

void krusgal() {
	for (int i = 1; i <= n; i++) {
		rep[i] = i;
	}
	
	int a, b;
	long long k;
	while (true) {
		a = vert.top().ss.ff;
		b = vert.top().ss.ss;
		k = -vert.top().ff;
		vert.pop();
		
		find(a); 
		find(b);
		if (rep[a] != rep[b] && isImp[rep[b]]) {
			rep[rep[a]] = rep[b]; // Union
			res += k;
			for (auto i : backtrack(a, b)) {
				find(i);
				
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &m);
	
	for (int i = 1; i <= k; i++) {
		scanf("%d", &imp[i]);
		isImp[imp[i]] = i;
	}
	
	int a, b;
	long long c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		conns[a].push_back({b, c});
		conns[b].push_back({a, c});
	}
	
	int w;
	for (int i = 1; i <= k; i++) { // Dijkstra dla każdego ważnego wierzchołka
		w = imp[i];
		dijskstra(w, i);
		
		for (int j = 1; j <= n; j++) { // Dodanie wszystkich ścieżek do kolejki
			if (j != w) { // Droga nie do siebie
				vert.push({-dis[w][j], {w, j}});
			}
		}
	}
	 
	// Algorytm Krusgala
	krusgal();
	
	
	return 0;
}
