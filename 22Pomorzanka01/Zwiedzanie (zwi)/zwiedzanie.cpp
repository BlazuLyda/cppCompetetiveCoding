#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> conns;

int wyn[100100][2], las[100100];

int main() {
	scanf("%d %d", &n, &m);
	conns.resize(m);
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		conns[i] = {c, {a, b}};
	}
	
	sort(conns.begin(), conns.end());
	
	for (auto i : conns) {
		c = i.ff;
		a = i.ss.ff;
		b = i.ss.ss;
		
		if (las[a] < c) {
			las[a] = c;
			wyn[a][0] = wyn[a][1];
		}
		if (las[b] < c) {
			las[b] = c;
			wyn[b][0] = wyn[b][1];
		}
		
		wyn[a][1] = max(wyn[a][1], wyn[b][0] + 1);
		wyn[b][1] = max(wyn[b][1], wyn[a][0] + 1);
	}
	
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, wyn[i][1]);
	}
	
	printf("%d\n", mx);
	
	return 0;
}
