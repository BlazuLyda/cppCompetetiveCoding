#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<int> DP[303][303];

void step(int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			DP[i][j].push_back(max(max(DP[max(1, i-1)][j][k-1], DP[min(n, i+1)][j][k-1]), max(DP[i][max(1, j-1)][k-1], DP[i][min(1, j+1)][k-1])));
		}
	}
}

int main() {
	scanf("%d", &n);
	
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			scanf("%d", &a);
			DP[i][j].push_back(a);
		}
	}
	
	scanf("%d", &t);
	
	int x, y, k;
	int mk = 0;
	
	while (t--) {
		scanf("%d %d %d", &x, &y, &k);
		
		while (mk < k) {
			mk++;
			step(mk);
		}
		
		printf("%d\n", max(max(DP[x-1][y][k-1], DP[x+1][y][k-1]), max(DP[x][y-1][k-1], DP[x][y+1][k-1])));
	}
	
	return 0;
}