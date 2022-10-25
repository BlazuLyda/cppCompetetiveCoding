#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n, m;
long long addx[1010], addy[1010];
long long subx[1010][1010], suby[1010][1010];
long long res = 1;

int main() {
	scanf("%d %d", &n, &m);
	
	int x, xpos, ypos;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			
			res = (i == 1) && (j == 1) ? 1 : addx[i] + addy[j];
			if (res >= mod) res -= mod;
			
			addx[i] += mod + res - subx[i][j];
			while (addx[i] >= mod) addx[i] -= mod;
			
			addy[j] += mod + res - suby[i][j];
			while (addy[j] >= mod) addy[j] -= mod;
			
			xpos = min(1003, i+x);
			ypos = min(1003, j+x);
			
			subx[i][ypos] += res;
			if (subx[i][ypos] >= mod) subx[i][ypos] -= mod;
			
			suby[xpos][j] += res;
			if (suby[xpos][j] >= mod) suby[xpos][j] -= mod;
		}
	}
	
	printf("%lld", res);
	
	return 0;
}
