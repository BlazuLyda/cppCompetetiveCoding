#include <bits/stdc++.h>

using namespace std;

int n, m, t;
vector<int> conns[200200];
vector<int> jump[200200];
int dep[200200];

void DFS(int w, int o) {
	dep[w] = dep[o] + 1;
	jump[w].push_back(o);
	
	int idx = 0, v = o;
	
	while (idx < (int)jump[v].size()) {
		jump[w].push_back(jump[v][idx]);
		v = jump[w].back();
		idx++;
	}
	
	for (auto i : conns[w]) {
		if (i != o) DFS(i, w);
	}
}

int LCA(int a, int b) {
	if (dep[b] > dep[a]) swap(a, b);
	
	int hei = dep[a] - dep[b];
	int idx = 0;
	
	while (hei) {
		if (hei & 1) a = jump[a][idx];
		idx++;
		hei >>= 1;
	}
	
	if (a == b) return a;
	
	for (int i = 20; i >= 0; i--) {
		i = min(i, (int) min(jump[a].size(), jump[b].size()) - 1);
		
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	}
	
	return jump[a][0];
}

int main() {
	scanf("%d %d %d", &n, &m, &t);
	
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	DFS(1, 0);
	
	//~ for (int i = 1; i <= n; i++) {
		//~ printf("%d:\n", i);
		//~ for (auto j : jump[i]) printf("%d, ",j);
		//~ printf("\n");
	//~ }
	
	int odp;
	while (t--) {
		scanf("%d %d", &a, &b);
		
		odp = dep[a] + dep[b] - 2 * dep[LCA(a, b)];
		
		printf("%d\n", odp);
	}
	
	return 0;
}
