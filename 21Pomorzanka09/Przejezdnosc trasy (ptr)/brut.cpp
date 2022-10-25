#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int a, b, c;
int t = 1;
vector<int> conns[1000];
int vis[1000];
bool odp;

void dfs(int w) {
	if (w == b) {
		odp = 1;
		return;
	}
	
	vis[w] = t;
	
	for (auto i : conns[w]) {
		if (vis[i] != t) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	int x, y;
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		conns[x].push_back(y);
		conns[y].push_back(x);
	}
	
	scanf("%d", &q);
	
	int xd;
	
	while (q--) {
		scanf("%d %d %d %d", &xd, &a, &b, &c);
		t++;
		
		odp = 0;
		vis[c] = t; 
		dfs(a);
		
		odp ? printf("TAK\n") : printf("NIE\n");
	}
	
	return 0;
}
