#include <bits/stdc++.h>

using namespace std;

int n, m, k;
long long tab[808];
vector<int> conns[808];

void find(int w, ) {
	
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	int a, b;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		
		conns[a].push_back(b+400);
		conns[b+400].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tab[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &tab[i+400]);
	}
	
	for (int i = 1; i <= n; i++) {
		find(i);
	}
	
	return 0;
}
