#include <bits/stdc++.h>

using namespace std;

int w, h;
int tab[4040][4040];
int depth[4040][4040];
int vis[4040][4040];
int cnt, wyn = 1;

struct element {
	int x, y;
};

queue<element> q1, q2;

void BFS() {
	int x, y, d, r;
	
	while (cnt) {
		if (q1.empty()) {
			swap(q1, q2);
			wyn++;
		}
		
		x = q1.front().x;
		y = q1.front().y;
		q1.pop();
		
		if (vis[x][y] == 2) continue;
		
		d = depth[x][y];
		r = tab[x][y];
		
		vis[x][y] = 2;
		
		cnt--;
		
		//printf("(%d, %d) - r:%d d:%d cnt:%d\n", x, y, r, d, cnt);

		if (!vis[x+1][y]) {
			if (tab[x+1][y] == r) { depth[x+1][y] = d; q1.push({x+1, y}); vis[x+1][y] = 1;}
			else { depth[x+1][y] = d+1; q2.push({x+1, y}); }
		}
		if (!vis[x-1][y]) {
			if (tab[x-1][y] == r) { depth[x-1][y] = d; q1.push({x-1, y}); vis[x-1][y] = 1;}
			else { depth[x-1][y] = d+1; q2.push({x-1, y}); }
		}
		if (!vis[x][y+1]) {
			if (tab[x][y+1] == r) { depth[x][y+1] = d; q1.push({x, y+1}); vis[x][y+1] = 1;}
			else { depth[x][y+1] = d+1; q2.push({x, y+1}); }
		}
		if (!vis[x][y-1]) {
			if (tab[x][y-1] == r) { depth[x][y-1] = d; q1.push({x, y-1}); vis[x][y-1] = 1;}
			else { depth[x][y-1] = d+1; q2.push({x, y-1}); }
		}
	}
}

int main() {
	scanf("%d %d", &h, &w);
	
	char c;
	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %c", &c);
			if (c == 'R') {
				tab[i][j] = 2;
				cnt++;
			}
			else if (c == 'F') {
				tab[i][j] = 3;
				cnt++;
			}
			else vis[i][j] = 2;
		}
	}
	
	for (int i = 0; i <= h+1; i++) {
		vis[i][0] = 1; vis[i][w+1] = 2;
	}
	for (int j = 0; j <= w+1; j++) {
		vis[0][j] = 1; vis[h+1][j] = 2;
	}
	
	depth[1][1] = 1;
	q1.push({1, 1});
	
	BFS();
	
	/*
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (depth[i][j] == 20000000) printf("_");
			else printf("%d", depth[i][j]);
		}
		printf("\n");
	}
	*/
	
	printf("%d", wyn);
	
	return 0;
}
