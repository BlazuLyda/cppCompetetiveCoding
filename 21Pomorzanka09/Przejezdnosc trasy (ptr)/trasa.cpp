#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int t;
vector<int> conns[100100];
vector<int> sons[100100];
int hei[100100];
int high[100100];
// int rev[100100];
bitset<100100> vis;
int anc[100100];
int tin[100100], tout[100100];

int createGraph(int w, int h) {
	vis[w] = 1;
	hei[w] = h;
	high[w] = h;
	tin[w] = t;
	
	for (auto i : conns[w]) {
		if (vis[i]) {
			if (i != anc[w]) high[w] = min(high[w], hei[i]);
		} else {
			anc[i] = w;
			sons[w].push_back(i);
			++t; // zwiększa się czas przed wejściem do wierzchołka
			high[w] = min(high[w], createGraph(i, h+1));
		}
	}
	
	tout[w] = t;
	
	//~ printf("\tWierzcholek: %d\n", w);
	//~ printf("Wysokosc: %d\n", hei[w]);
	//~ printf("Funkcja high: %d\n", high[w]);
	//~ printf("Synowie: ");
	//~ for (auto i : sons[w]) {
		//~ printf("%d, ", i);
	//~ }
	//~ printf("\nTin: %d  Tout: %d\n\n", tin[w], tout[w]);
	
	return high[w];
}

bool sonOf(int a, int b) {
	return (tin[b] <= tin[a] && tout[a] <= tout[b]);
}

int bin(int b, int a) {
	// Binsearch po synach a
	int p = 0, k = sons[a].size()-1, s;
	while (p != k) {
		s = (p + k) / 2;
		if (tout[b] <= tout[sons[a][s]]) k = s;
		else p = s+1;
	}
	
	return sons[a][p];
}

bool ansA(int v, int w, int a, int b) {
	if (hei[b] < hei[a]) swap(a, b);
	// a znajduje się teraz nad b
	
	// Zlikwidowana krawędź jest krawędzią dodatkową
	if (anc[b] != a) return 1;
		
	// Zlikwidowana krawędź jest krawędzią zwykłą
	bool sw = sonOf(w, b);
	bool sv = sonOf(v, b);
	
	// I w i v są w poddrzewie b lub ani w ani v nie są w poddrzewie b
	if ((sw && sv) || (!sw && !sv)) return 1;
	
	// albo w albo v jest w poddrzewie b
	return high[b] < hei[b];
}

bool ansB(int v, int w, int a) {
	bool sw = sonOf(w, a);
	bool sv = sonOf(v, a);
	
	// I w i v są w poddrzewie a
	if (sw && sv) {
		int p = bin(w, a);
				
		// p to teraz syn a w którego drzewie znajduje się w
		if (sonOf(v, p)) { 
			// w i v znajdują się w tym samym poddrzewie
			return 1;
		} else {
			return (high[p] < hei[a] && high[bin(v, a)] < hei[a]);
		}
	}
	
	// albo w albo v jest w poddrzewie a
	if (sw) return high[bin(w, a)] < hei[a];
	if (sv) return high[bin(v, a)] < hei[a];
	
	// ani w ani v nie są w poddrzewie a
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	
	// Tworzenie grafu
	hei[0] = 100100;
	createGraph(1, 1);
	
	
	// Odpowiadanie na pytania
	scanf("%d", &q);
	
	int z;
	int v, w;
	bool res;
	
	while(q--) {
		scanf("%d", &z);
		
		if (z == 1) {
			scanf("%d %d %d %d", &v, &w, &a, &b);
			res = ansA(v, w, a, b);
		} else {
			scanf("%d %d %d", &v, &w, &a);
			res = ansB(v, w, a);
		}
		
		printf("%s\n", res ? "TAK" : "NIE");
	}
	
	return 0;
}
