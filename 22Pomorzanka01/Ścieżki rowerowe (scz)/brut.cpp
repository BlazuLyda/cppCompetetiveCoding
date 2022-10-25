#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> conns[1000];

int dfs(int w, int o) {
	int mx = 0;
	
	for (auto i : conns[w]) {
		if (i != o) mx = max(mx, dfs(i, w) + 1);
	}
	
	return mx;
}

int main() {
	scanf("%d %d", &n, &m);
	
	int a, b;
	char c;
	
	while (m--) {
		scanf(" %c", &c);
		
		if (c == 'Z') {
			scanf("%d %d", &a, &b);
			conns[a].push_back(b);
			conns[b].push_back(a);
		} else {
			scanf("%d", &a);
			printf("%d\n", dfs(a, 0));
		}
	}
	
	return 0;
}
