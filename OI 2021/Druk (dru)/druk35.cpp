#include <bits/stdc++.h>

using namespace std;

int n, m;
char tab[4][1003];
int let[26];
set<int> wyn;
bool lin;

void rozwLinear() {
	char up;
	for (int j = 1; j <= m; j++) {
		up = tab[1][j];
		for (int i = 2; i <= n; i++) {
			if (tab[i][j] != up) return;
		}
	}
	lin = 1;
	
	vector<char> pat;
	pat.resize(m+1);
	int idx;
	bool b;
	
	for (int k = 1; k <= m; k++) {
		pat[k] = tab[1][k];
		
		if (m % k == 0) {
			idx = 1;
			b = 1;
			
			for (int j = k+1; j <= m; j++) {
				if (pat[idx] != tab[1][j]) {
					b = 0;
					break;
				}
				
				idx++;
				if (idx > k) idx = 1;
			}
			
			if (b) wyn.insert(k);
		}
	}
}

void rozwBlocks() {
	int hor = 0;
	char pat[4] = {0, tab[1][1]};
	bool same, cor;
	char up = tab[1][1];
	bool startVert;
	
	for (int i = 2; i <= n; i++) {
		pat[i] = tab[i][1];
		
		// Startujemy w pionie
		if (tab[i][1] != pat[1]) startVert = 1;
	}
	
	// Startujemy w poziomie
	if (!startVert) {
		if (m < n) return;
		for (int j = 2; j <= n; j++) pat[j] = tab[1][j];
	}
	
	// Przechodzenie po tablicy
	for (int j = 1; j <= m; j++) {
		same = 1;
		cor = 1;
		up = tab[1][j];
		
		for (int i = 2; i <= n; i++) {
			if (tab[i][j] != up) same = 0;
			if (tab[i][j] != pat[i]) cor = 0;
		}
		
		if (hor) {
			if (same && up == pat[hor]) {
				if (hor == n) hor = 0;
				else hor++;
			} else {
				return;
			}
		} else {
			if (same) {
				if (up == pat[1]) hor = 2;
				else return;
			}
			else if (!cor) return; 
		}
	}
	
	if (hor) return;
	wyn.insert(n);
}

void rozwComp() {
	if (m == 1) return;
	string p1 = {tab[1][1]}, p2;
	string end, b1, b2;
	
	if (tab[1][1] == tab[2][1]) p2 = {tab[1][2]};
	else 						p2 = {tab[2][1]};
	
	int hor = 0;
	bool same;
	int block;
	char up;
	string s;
	
	for (int j = 1; j <= m; j++) {
		same = 1;
		up = tab[1][j];
		
		for (int i = 2; i <= 3; i++) {
			if (tab[i][j] != up) same = 0;
		}
		
		if (hor) {
			if (same && up == p2[0]) hor = 0;
			else return;
		} else {
			if (same) {
				if (up == p1[0]) hor = 2;
				else return;
			} else {
				s = "";
				s.push_back(tab[1][j]); s.push_back(tab[2][j]); s.push_back(tab[3][j]);
				
				if (block) {
					if (block == 1) {
						if (s == b1) block = 2;
						else if (s == end) block = 0;
						else return;
					} else {
						if (s == b2) block = 1;
						else return;
					}
				} else {
					if (s == p1 + p1 + p2) {
						end = p2 + p1 + p2;
						b1 = p2 + p1 + p1;
						b2 = p1 + p2 + p2;
						block = 1;
					} else if (s == p1 + p2 + p1) {
						end = p1 + p2 + p2;
						b1 = p1 + p1 + p2;
						b2 = p2 + p2 + p1;
						block = 1;
					} else return;
				}
			}
		}
	}
	
	if (block) return;
	wyn.insert(2);
}

void wypiszWyn() {
	printf("%lu\n", wyn.size());
	for (auto i : wyn) printf("%d ", i);
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", &tab[i][1]);
		for (int j = 1; j <= m; j++) let[tab[i][j]-'a']++;
	}
	
	// Tylko jedna literka
	int l = 0;
	for (int i = 0; i < 26; i++) {
		if (let[i]) l++;
	}
	
	if (l == 1) {
		for (int i = 1; i <= m; i++) {
			if (m % i == 0) wyn.insert(i);
		}
		if (n == 2) wyn.insert(2);
		else if (n == 3) wyn.insert(3);
		
		wypiszWyn();
		return 0;
	}
	
	
	// Więcej niż jedna literka
	if (n == 1) {
		rozwLinear();
	} else if (n == 2) {
		rozwLinear();
		
		if (!lin) rozwBlocks();
		
	} else if (n == 3) {
		rozwLinear();
		
		if (!lin) {
			rozwBlocks();
			rozwComp();
		}
	}
	
	wypiszWyn();
	
	return 0;
}
