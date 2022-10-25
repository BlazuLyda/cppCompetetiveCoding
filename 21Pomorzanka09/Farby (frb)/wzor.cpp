#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> col;
int DP[3003][3003];

int main() {
	scanf("%d", &n);
	
	col.reserve(n+5);
	col.push_back(0);
	int last = 0, cur;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cur);
		
		if (cur != last) {
			col.push_back(cur);
			last = cur;
		}
	}
	
	n = col.size() - 1;
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", col[i]);
	}
	printf("\n");
	
	for (int j = 1; j <= n; j++) {
		for (int i = j-1; i >= 1; i--) {
			DP[i][j] = DP[i+1][j-1] + (col[i+1] != col[j] && col[j-1] != col[i]) + (col[i] != col[j]);
			
			printf("(%d, %d): %d\n", i, j, DP[i][j]);
		}
	}
	
	printf("%d", DP[1][n]);
	
	return 0;
}
