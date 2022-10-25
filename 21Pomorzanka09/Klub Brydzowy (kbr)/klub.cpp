#include <bits/stdc++.h>

using namespace std;

struct vert {
	int a, b, p, k;
};

int n, k, p;
vector<vert> conns;
vector<int> outs[202];
int rich[202];

int main() {
	scanf("%d %d", &n, &k);
	p = (1<<n);
	
	int pom;
	
	for (int i = 0; i < p; i++) {
		scanf("%d", &rich[i]);
	}
	
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) {
				pom = i^(1<<j);
				
				outs[i].push_back(conns.size());
				outs[pom].push_back(conns.size()+1);
				
				conns.push_back(i, pom, 1, )
			}
		}
	}
	
	// 5111111 - źródło, 5222222 - ujście
	
	return 0;
}
