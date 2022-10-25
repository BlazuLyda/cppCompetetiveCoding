#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007LL

using namespace std;

struct Node {
	int x, y, id;
	long long wyn;
};

int n, m, t = 2;
vector<Node> nodes(2); // 0 - puste, 1 - ściana
queue<pair<int, int>> que[3003]; // [y-idx] <x-idx, node idx>
int vis[3003][3003]; // która spójna to odwiedziła, 0 - nieodwiedzone, 1 - ściana
char s[3003];
vector<long long> conns;

int find(int w) {
	if (nodes[w].id != w) nodes[w].id = find(nodes[w].id);
	return nodes[w].id;
}

void bfs(int x, int y, int v) {
	int id = find(v);
	Node* w = &nodes[id];
	
	// dodawanie 1 możliwości z uwagi na zmianę wysokości
	if (w->y > y) {
		w->y = y;
		w->wyn += 1LL;
		if (w->wyn >= mod) w->wyn -= mod;
	}
	
	// już odwiedzone, podłączam się
	if (vis[x][y]) {
		printf("%d:%d, vis\n", x, y);
		// doszedł tu ten sam reprezentant
		if (vis[x][y] == id) return;
		
		nodes[vis[x][y]].wyn = (nodes[vis[x][y]].wyn * w->wyn) % mod;
		w->id = vis[x][y];
		return;
	}
	
	// jeszcze nie odwiedzone
	printf("\t%d:%d, new\n", x, y);
	int x_org = x;
	
	vis[x][y] = id;
	if (!vis[x][y-1]) que[y-1].push({x, id});
	
	// przemieszczanie się w lewo, jeżeli brak ściany to rozszerzam do góry
	while (!vis[--x][y]) {
		vis[x][y] = id;
		if (!vis[x][y-1]) que[y-1].push({x, id});
	}
	
	// przemieszczanie się w prawo, jeżeli brak ściany to rozszerzam do góry
	x = x_org;
	while (!vis[++x][y]) {
		vis[x][y] = id;
		if (!vis[x][y-1]) que[y-1].push({x, id});
	}
}

void createNew(int x, int y) {
	nodes.push_back(Node{x, y, t, 1});
	
	vis[x][y] = t;
	if (!vis[x][y-1]) que[y-1].push({x, t});
	
	// przemieszczanie się w prawo, jeżeli brak ściany to rozszerzam do góry
	while (!vis[++x][y]) {
		vis[x][y] = t;
		if (!vis[x][y-1]) que[y-1].push({x, t});
	}
	
	++t;
}

int main() {
	scanf("%d %d", &n, &m);
	
	// wczytywanie tablicy
	for (int j = 0; j < n; j++) {
		scanf("%s", s);
		for (int i = 0; i < m; i++) {
			if (s[i] == '#') vis[i][j] = 1;
		}
	}
	
	// przemieszczanie się po tablicy od dołu do góry
	for (int j = n-2; j > 0; j--) {
		// opróżnianie kolejki
		while (!que[j].empty()) {
			bfs(que[j].front().ff, j, que[j].front().ss);
			que[j].pop();
		}
		
		// szukanie nowych
		for (int i = 1; i < m-1; i++) {
			if (!vis[i][j]) createNew(i, j);
		}
	}
	
	// obliczanie wyniku
	long long res = 1;
	for (int i = 2; i < t; i++) {
		if (nodes[i].id == i) res = (res * (nodes[i].wyn + 1LL)) % mod;
	}
	
	printf("%lld", res);
	
	return 0;
}
