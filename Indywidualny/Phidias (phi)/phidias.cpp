#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int w, h;
int n;
int DP[606][606];
pair<bool, bool> poss[606][606];

int main() {
	scanf("%d %d", &w, &h);
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			DP[i][j] = i * j;
			poss[i][j] = {1, 1};
		}
	}
	
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		DP[a][b] = 0;
	}
	
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			// poszerzenie w prawo
			if (DP[i-1][j] + j < DP[i][j]) {
				DP[i][j] = DP[i-1][j] + j;
				poss[i][j] = poss[i-1][j];
			}
			
			// poszerzenie w dół
			if (DP[i][j-1] + i < DP[i][j]) {
				DP[i][j] = DP[i][j-1] + i;
				poss[i][j] = poss[i][j-1];
			}
			
			// Nie da się wgl stworzyć tej płytki
			if (DP[i][j] == i*j) continue;
			
			// poziomo (1 współrzędna)
			if (poss[i][j].ff) {
				for (int k = 1; k <= w-i; k++) {
					if (DP[k][j] + DP[i][j] < DP[k+i][j]) {
						DP[k+i][j] = DP[k][j] + DP[i][j];
						poss[k+i][j] = {0, 1};
					}
				}
			}
			
			// pionowo (2 współrzędna)
			if (poss[i][j].ss) {
				for (int k = 1; k <= h-j; k++) {
					if (DP[i][k] + DP[i][j] < DP[i][k+j]) {
						DP[i][k+j] = DP[i][k] + DP[i][j];
						poss[i][k+j] = {1, 0};
					}
				}
			}
		}
	}
	
	/*
	for (int j = 1; j <= h; j++) {
		for (int i = 1; i <= w; i++) {
			printf("%d ", DP[i][j]);
		}
		printf("\n");
	}
	*/
	
	printf("%d", DP[w][h]);
	
	return 0;
}