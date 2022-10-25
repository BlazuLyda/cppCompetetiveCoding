#include <bits/stdc++.h>

using namespace std;

int n, m;
char tab[4][1003];
set<int> wyn;

void rozwComp() {
	if (m == 1) return;
	string p1 = {tab[1][1]}, p2;
	string end, b1, b2;
	
	if (tab[1][1] == tab[2][1]) p2 = {tab[1][2]};
	else 						p2 = {tab[2][1]};
	
	//printf("Pattern: [%c%c]\n", p1[0], p2[0]);
	
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
		
		//printf("j:%d same:%d hor:%d block:%d\n", j, same, hor, block);
		
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
				//printf("column: [%s]\n", &s[0]);
				
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

int main()
{
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf("%s", &tab[i][1]);
	
	rozwComp();
	
	wypiszWyn();
	
	return 0;
}
