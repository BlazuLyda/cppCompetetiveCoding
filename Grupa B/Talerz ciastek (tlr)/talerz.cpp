#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int p, k, s;
int cur, sum;
int vis[1010][1010];
int cake[1010][1010];
char buff[1010];

void fillLeft(int x, int y, int d);

void fillUp(int x, int y, int d) {
	if (d == 0 || vis[x][y] >= t) return;
	
	vis[x][y] = t;
	
	if (cake[x][y] >= s) 
		d = s;
		
	//printf("\t\tFillUp: {%d,%d}", x, y);
	
	fillLeft(x, y-1, s-1);
	fillUp(x-1, y, d-1);
}

void fillLeft(int x, int y, int d) {
	if (d == 0 || vis[x][y] >= t) return;
	
	vis[x][y] = t;
	
	//printf("\t\tFillLeft : {%d,%d}\n", x, y);
	
	if (cake[x][y] >= s) {
		fillLeft(x, y-1, s-1);
		fillUp(x-1, y, s-1);
	} else {
		fillLeft(x, y-1, d-1);
	}
}

bool check() {
	for (int i = 1; i <= n; i--) {
		for (int j = 1; j <= m; j--) {
			//printf("\t{%d,%d} ", i, j);
			if (vis[i][j] >= t) {
				//printf("already filled\n");
				continue;
			}
			
			//printf("filling from here\n");
			fillUp(i, j, s);
		}
	}
	
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", buff);
		
		for (int j = 1; j <= m; j++) { 
			if (buff[j-1] == '#') {
				cake[i][j] = min(cake[i-1][j-1], min(cake[i-1][j], cake[i][j-1])) + 1;
				sum++;
			} else {
				vis[i][j] = 2137;
			}
		}
	}
	
	// nie ma żadnego piernika na planszy
	if (!sum) {
		printf("0\n");
		return 0;
	}
	
	// beansearch
	p = 1, 
	k = min(n, m);
	
	while (p < k) {
		//printf("[%d:%d]\n", p, k);
		s = (p + k + 1) >> 1;
		
		cur = 0;
		t++;
		check();
		
		if (cur == sum) p = s;
		else k = s-1;
	}
	
	printf("%d\n", p);
	
	return 0;
}
