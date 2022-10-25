#include <bits/stdc++.h>
#define neginf = -100000000;

using namespace std;

int n, m;
int DP[101][524288];
vector<int> back;
int item[25];

bool cmp(int x, int y) {
	return x > y;
}

void countDP(int pref, int mask, int id, int pcount) {
	int res = neginf;
	int pom;
	
	if (!pcount) {
		for (int i = 0; i < n; i++) {
			if (mask & (1<<i)) {
				pom = DP[ pref ][ mask^(1<<i) ] - item[id];
				if (pom >= 0) res = max(res, pom);
				res = max(res, DP[ pref-1 ][ mask^(1<<i) ] - item[id] + back[pref]);
			}
		}
		return;
	}
	
	countDP(pref, mask, id+1, pcount);
	countDP(pref, mask^(1<<id), id+1, pcount-1);
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &item[i]);
	}
	
	int a;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		back.push_back(a);
	}
	
	sort(back.begin(), back.end(), cmp);
	
	for (int i = 0; i < m; i++) {
		
	}
	
	return 0;
}
