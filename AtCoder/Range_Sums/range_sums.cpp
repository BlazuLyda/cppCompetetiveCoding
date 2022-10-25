#include <bits/stdc++.h>

using namespace std;

int N, Q;

vector<int> conns[400400]; // 2n-entrance, 2n+1-exit
bitset<400400> vis;

void dfs(int w) {
	if (vis[w]) return;
	vis[w] = true;
	
	//printf("w:%d m:%d\n", w>>1, w&1);
	
	if (w&1) { // moved here frontwards
		for (auto v : conns[w+1]) {
			if (!vis[v]) dfs(v);
		}
		
		for (auto v : conns[w]) {
			if (!vis[v]) dfs(v);
		}
	} else { // moved here backwards
		for (auto v : conns[w]) {
			if (!vis[v]) dfs(v);
		}
		
		for (auto v : conns[w-1]) {
			if (!vis[v]) dfs(v);
		}
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	
	int l, r;
	
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &l, &r);
		
		conns[l*2].push_back(r*2+1);
		conns[r*2+1].push_back(l*2);
	}
	
	dfs(2);
	
	printf("%s\n", vis[N*2+1] ? "Yes" : "No");
	
}