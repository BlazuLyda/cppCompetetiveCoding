#include <bits/stdc++.h>
#define inf 1000000
#define ff first
#define ss second

using namespace std;

int n;
vector<int> conns[100100];
vector<pair<int, int>> points;
map<pair<int, int>, int> vis;

bool check() {
	for (auto i : points) {
		vis[{min(i.ff, i.ss), max(i.ff, i.ss)}]++;
	}
}

void stw(int l) {
	if (l == 0) {
		
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			points.push_back({i, j});
			stw(l-1);
			points.pop_back();
		}
	}
}

bool rozw() {
	for (int i = 1; i <= n/2; i++) {
		
	}
}

int main() {
	scanf("%d", &n);
	
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	int p = 1, k = n-1, s;
	int wyn;
	
	while (p < k) {
		s = (p+k+1) >> 1;
		
		
		if (true) p = s;
		else k = s-1;
	}
	
	printf("%d\n", p);
	
	return 0;
}
