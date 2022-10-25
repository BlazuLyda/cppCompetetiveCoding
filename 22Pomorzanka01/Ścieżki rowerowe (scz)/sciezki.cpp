#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std; 

int n, m;
vector<int> conns[200100];
int jump[200100][19];
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
	jump[w][0] = o;
	
	//printf("w:%d o:%d\n", w, o);
	
	for (auto i : conns[w]) {
		if (i != o) dfs(i, w);
	}
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
	
	
	dfs(1, 1);
	
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= n; i++) {
			jump[i][j] = jump[jump[i][j-1]][j-1];
		}
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
			
			//~ printf("wb1:%d p1:%d\n", fur[rb].ff, p1);
			//~ printf("wb2:%d p2:%d\n", fur[rb].ss, p2);
			//~ printf("wa1:%d d1:%d\n", fur[ra].ff, d1);
			//~ printf("wa2:%d d2:%d\n", fur[ra].ss, d2);
			
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
			
			high = {{dmr[ra], {fur[ra].ff, fur[ra].ss}},
					{dmr[rb], {fur[rb].ff, fur[rb].ss}},
					{d + p + 1, {s1, s2}}
			};
			
			//~ printf("0: %d (%d, %d)\n", high[0].ff, high[0].ss.ff, high[0].ss.ss);
			//~ printf("1: %d (%d, %d)\n", high[1].ff, high[1].ss.ff, high[1].ss.ss);
			//~ printf("2: %d (%d, %d)\n", high[2].ff, high[2].ss.ff, high[2].ss.ss);
			
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
			
			res = max(dep[a] + dep[fur[ra].ff] - 2 * dep[l1],
					  dep[a] + dep[fur[ra].ss] - 2 * dep[l2]
			);
			
			printf("%d\n", res);
		}
	}
	
	return 0;
}
