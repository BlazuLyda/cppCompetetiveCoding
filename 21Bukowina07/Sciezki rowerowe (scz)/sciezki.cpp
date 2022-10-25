#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> graph[200200];

int DFS(int w, int o) {
	int res = 0;
	
	for (auto i : graph[w]) {
		
		if (i == o) continue;
		res = max(res, DFS(i, w));
	}
	
	return res + 1;
}

int main() {
	scanf("%d %d", &n, &m);
	
	char c;
	int a, b;
	
	for (int i = 0; i < m; ++i) {
		scanf(" %c", &c);
		
		if (c == 'Z') {
			scanf("%d %d", &a, &b);
			
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		else {
			scanf("%d", &a);
			
			printf("%d\n", DFS(a, 0) - 1);	
		}
	}
	
	return 0;
}
