#include <bits/stdc++.h>
#define ff first
#define ss second
#define inf 1000000

using namespace std;

int n, t;
long long wyn;
vector<pair<int, int>> conns[100100];
int siz[100100];
int vis[100100];

int findSize(int w, int o) {
	for (auto i : conns[w]) {
		if (i != o) siz[w] += findSize(i, w);
	}
	return siz[w];
}

int fc(int w, int hs) {
	vis[w] = t;
	bool b = 1;
	
	for (auto i : conns[w]) {
		if (siz[i] > hs) {
			b = 0;
			break;
		}
	}
	
	if (b) return w;
	
	for (auto i : conns[w]) {
		if (vis[i] < t) fc(i, hs);
	}
}

vector<pair<int, int>> cd(int w, int hs) {
	t++;
	int c = fc(w, hs);
}

int main() {
	scanf("%d", &n);
	
	int a, b, c;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		conns[a].push_back({b, c});
		conns[b].push_back({a, c});
	}
	
	// rozmiar
	findSize(1, 0);
	
	return 0;
}
