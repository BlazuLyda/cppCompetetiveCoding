#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;
vector<int> graph[200200];
int rep[200200];
pair<int, int> ends[200200];
vector<pair<bool, pair<int,int>>> ops;

int DFSorder[200200], depth[200200], DFSidx[200200];
int maxPot2[400400], pot2[20];
int idx;
vector<int> LCA[200200];

void DFS(int w, int o, int d) {
	depth[w] = d;
	DFSorder[idx] = w;
	DFSidx[w] = idx;
	idx++;
	
	for (auto i : graph[w]) {
		if (i != o)	DFS(i, w, d+1);
	}
	
	DFSorder[idx] = w;
	idx++;
}

void fillLCA() {
	int pot;
	
	for (int p = 0; p < 18; p++) {
		pot = pot2[p];
		
		for (int j = 0; j + 2*pot < 2*n; j++) {
			if (depth[LCA[j].back()] < depth[LCA[j+pot].back()]) LCA[j].push_back(LCA[j].back());
			else LCA[j].push_back(LCA[j+pot].back());
		}
	}
}

void getLCA(int a, int b) {
	if (DFSidx[a] > DFSidx[b])	swap(a, b);

	int p = maxPot2[DFSidx[b] - DFSidx[a]];	
	int w = LCA[DFSidx[a][p];
	int v = LCA[DFSidx[b-(1<<p)+1)][p];
	
	if (depth[v] < depth[w]) return v;
	return w;
}

int main() {
	scanf("%d %d", &n, &m);
	
	char c;
	int a, b;
	
	ops.reserve[m];
	
	while (m--) {
		scanf(" %c", &c);
		
		if (c == 'Z') {
			scanf("%d %d", &a, &b);
			
			graph[a].push_back(b);
			graph[b].push_back(a);
			ops.push_back({0, {a, b}});
		}
		else {
			scanf("%d", &a);
			
			ops.push_back({1, {a, 0}});
		}
	}
	
	//starting values and preprocessing
	for (int i = 1; i <= n; i++) { rep[i] = i; ends[i] = {i, i}; }
	for (int i = 0; i <= 18; i++) { rep[1<<i] = i; pot2[i] = (1<<i); }
	for (int i = 1; i <= 2*n; i++) { maxPot2[i] = max(maxPot2[i-1], maxPot2[i]); }
	
	for (auto i : ops) {
		if (i.ff) { //zapytanie
			
		}
		else {
			
		}
	}
	
	return 0;
}
