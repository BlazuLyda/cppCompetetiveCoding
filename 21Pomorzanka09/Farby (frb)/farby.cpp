#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> col;
vector<int> pre[3003];
vector<int> preCol[3003];
int DP[3003][3003];

vector<int> invert(vector<int> v) {
	vector<int> res;
	res.reserve(v.size());
	
	for (int i = v.size()-1; i >= 0; i--) {
		res.push_back(v[i]);
	}
	
	return res;
}

int main() {
	scanf("%d", &n);
	
	int a, last = 0;
	col.reserve(3003);
	col.push_back(0);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		
		if (a != last) {
			col.push_back(a);
			last = a;
		}
	}
	
	// zredukowana tablica
	n = col.size() - 1;
	
	for (int i = 1; i <= n; i++) {
		pre[i] = invert(preCol[col[i]]);
		preCol[col[i]].push_back(i);
	}
	
	for (int j = 1; j <= n; j++) {
		for (int i = j - 1; i >= 1; i--) {
			DP[i][j] = DP[i][j-1];
			
			for (auto k : pre[j]) {				
				if (k <= i) {
					if (k == i) {
						DP[i][j] = max(DP[i][j], 1 + DP[i+1][j-1]);
					}
					break;
				}
				DP[i][j] = max(DP[i][j], (col[i] == col[j]) + DP[i][k-1] + 1 + DP[k+1][j-1]);
			}
			
			//printf("(%d, %d) -> %d\n", i, j, DP[i][j]);
		}
	}
	
	printf("%d", n - DP[1][n] - 1);
	
	return 0;
}
