#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct query {
	int ts, a, b, c, d;
	int id;
	int wyn = 0;
};

int n, m, q;
vector<pair<bitset<8>, int>> lights[15005];
vector<int> tim[850];
vector<query> quest;
char align[850]; // 'v' - pionowe, 'h' - poziome
vector<int> walls[850];
int sum[850];

int main() {
	scanf("%d %d %d", &n, &m, &q);
	
	// Wczytywanie świateł
	char s[10];
	int p;
	
	for (int i = 0; i < n; i++) {
		lights[i].resize(m+1);
		
		for (int j = 0; j < m; j++) {
			scanf("%s", s);
			
			for (p = 0; s[p]; p++) lights[i][j].ff[p] = s[p] - '0';
			
			lights[i][j].ss = p+1;
		}
	}
	
	// Wczytywanie zapytań
	int t, a, b, c, d;
	quest.resize(n);
	
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d %d", &t, &a, &b, &c, &d);
		
		quest[i] = {t, a, b, c, d, i};
		tim[t % 840].push_back(i);
	}
	
	// Preprocessing ścian
	int mod;
	
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			mod = lights[i][j].ss;
			
			for (int k = 0; k < 840; k++) sum[k] += !lights[i][j].ff[k % mod];
		}
		
		for (int k = 0; k < 840; k++) {
			if (sum[k] == n) {
				align[k] = 'v';
				walls[k].push_back(j);
			}
			
			sum[k] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mod = lights[i][j].ss;
			
			for (int k = 0; k < 840; k++) sum[k] += lights[i][j].ff[k % mod];
		}
		
		for (int k = 0; k < 840; k++) {
			if (sum[k] == n) {
				align[k] = 'h';
				walls[k].push_back(i);
			}
			
			sum[k] = 0;
		}
	}
	
	// Wykonywanie zapytań
	queue <pair<int, pair<int, int>>> active, pom;
	
	for (t = 0; t < 840; t++) {
		for (auto i : quest[t]) active.push({i.id, {i.a, i.b}});
		
		if (align[t] = 'h') {
			
		} else if (align[t] = 'v') {
			
		} else {
			
		}
	}
	
	return 0;
}
