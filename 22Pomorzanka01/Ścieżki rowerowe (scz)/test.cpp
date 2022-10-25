#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std; 

int n, m;
vector<int> conns[200100], jump[200100];
int dep[200100];
pair<int, int> fur[200100];
int dmr[200100];
vector<pair<bool, pair<int, int>>> ops;

// Find and Union
int rep[200100];

int find(int a) {
	if (a != rep[a]) rep[a] = find(rep[a]);
	return rep[a];
}
//

void dfs(int w, int o) {
	dep[w] = dep[o] + 1;
	
	jump[w].push_back(o);
	int idx = 0, v = o;
	
	while (idx < (int) jump[v].size()) {
		v = jump[v][idx];
		jump[w].push_back(v);
		idx++;
	}
	
	for (auto i : conns[w]) {
		if (i != o) dfs(i, w);
	}
}

int dis(int w) {
	return dep[w] - dep[find(w)];
}

int lca(int a, int b) {
	// b ma być pod a
	if (dep[a] > dep[b]) swap(a, b);
	int dif = dep[b] - dep[a], idx = 0;
	
	// wyrównywanie
	while (dif) {
		if (dif & 1) b = jump[b][idx];
		dif >>= 1;
		idx++;
	}
	
	if (a == b) return a;
	
	// skoki razem
	for (int i = 18; i >= 0; i--) {
		i = min(i, (int) min(jump[a].size(), jump[b].size()) - 1);
		
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	}
	
	return jump[a][0];
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		rep[i] = i;
		fur[i] = {i, i};
	}
	
	ops.resize(m);
	int a, b;
	char c;
	
	for (int i = 0; i < m; i++) {
		scanf(" %c", &c);
		
		if (c == 'Z') {
			scanf("%d %d", &a, &b);
			conns[a].push_back(b);
			conns[b].push_back(a);
			ops[i] = {1, {a, b}}; // update
		} else {
			scanf("%d", &a);
			ops[i] = {0, {a, 0}}; // zapytanie
		}
	}
	
	
	dfs(1, 0);
	
	for (int i = 1; i <= n; i++) {
		printf("%d:\n", i);
		for (auto j : jump[i]) {
			printf("%d, ", j);
		}
		printf("\n");
	}
	
	int ra, p1, p2, l1, l2, d1, d2, res, s1, s2, d, p, rb;
	vector<pair<int, pair<int, int>>> high;
	
	for (auto j : ops) {
		if (j.ff) {
			// update
			a = j.ss.ff;
			b = j.ss.ss;
			
			// podłączam b do a
			if (dep[find(a)] > dep[find(b)]) swap(a, b);
			ra = find(a);
			rb = find(b);
			
			p1 = dep[b] + dep[fur[rb].ff] - 2 * dep[lca(b, fur[rb].ff)];
			p2 = dep[b] + dep[fur[rb].ss] - 2 * dep[lca(b, fur[rb].ss)];
			
			d1 = dep[a] + dep[fur[ra].ff] - 2 * dep[lca(a, fur[ra].ff)];
			d2 = dep[a] + dep[fur[ra].ss] - 2 * dep[lca(a, fur[ra].ss)];
			
			if (p1 > p2) {
				p = p1;
				s1 = fur[rb].ff;
			} else {
				p = p2;
				s1 = fur[rb].ss;
			}
			
			if (d1 > d2) {
				d = d1;
				s2 = fur[ra].ff;
			} else {
				d = d2;
				s2 = fur[ra].ss;
			}
			
			high = {{dmr[a], {fur[ra].ff, fur[ra].ss}},
					{dmr[b], {fur[b].ff, fur[b].ss}},
					{d + p + 1, {s1, s2}}
			};
			
			sort(high.begin(), high.end());
			dmr[ra] = high[2].ff;
			fur[ra] = high[2].ss;
			
			rep[b] = ra;
		} else {
			// zapytanie
			a = j.ss.ff;
			ra = find(a);
			
			l1 = lca(a, fur[ra].ff);
			l2 = lca(a, fur[ra].ss);
			
			//~ printf("\nzapytanie a:%d rep[a]:%d\n", a, ra);
			//~ printf("srednica: (%d, %d) -> %d\n", fur[ra].ff, fur[ra].ss, dmr[ra]);
			//~ printf("dis[a]:%d disFur:(%d, %d) disLca:(%d, %d)\n", dis(a), dis(fur[ra].ff), dis(fur[ra].ss), dis(l1), dis(l2));
			
			res = max(dep[a] + dep[fur[ra].ff] - 2 * dep[l1],
					  dep[a] + dep[fur[ra].ss] - 2 * dep[l2]
			);
			
			printf("%d\n", res);
		}
	}
	
	return 0;
}
