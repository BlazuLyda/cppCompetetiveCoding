#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;
pair<int, int> p1, p2;
bool path[1010][1010];
char s[1010];
int port[1010][1010][4]; // 0 - góra, 1 - dół, 2 - prawo, 3 - lewo
bool vis[1010][1010];

char tab[1010][1010];

queue<pair<int, int>> que1, que2, que3;

//~ void printTab(int x, int y) {
	//~ for (int i = 0; i <= n+1; i++) {
		//~ for (int j = 0; j <= m+1; j++) {
			//~ if (i == x && j == y) printf("T");
			//~ else if (!path[i][j]) printf("#");
			//~ else printf("%c", tab[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n\n");
//~ }

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
			vis[i][j] = true;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", &s[1]);
		
		for (int j = 1; j <= m; j++) {
			tab[i][j] = s[j];
			
			if (s[j] != '#') {
				path[i][j] = true;
				vis[i][j] = false;
				
				if (s[j] == 'S') 		p1 = {i, j};
				else if (s[j] == 'C') 	p2 = {i, j};
			}
		}
	}
	
	int las;
	
	for (int j = 1; j <= m; j++) {
		for (int i = n+1; i >= 0; i--) {
			if (!path[i][j]) las = i - 1;
			else port[i][j][0] = las;
		}
		
		for (int i = 0; i <= n+1; i++) {
			if (!path[i][j]) las = i + 1;
			else port[i][j][1] = las;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = m+1; j >= 0; j--) {
			if (!path[i][j]) las = j - 1;
			else port[i][j][2] = las;
		}
		
		for (int j = 0; j <= m+1; j++) {
			if (!path[i][j]) las = j + 1;
			else port[i][j][3] = las;
		}
	}
	
	int k = 0;
	que1.push(p1);
	pair<int, int> pos;
	bool nearWall;
	
	vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	
	while (true) { 
		while (!que1.empty()) {
			pos = que1.front();
			que1.pop();
			
			if (vis[pos.ff][pos.ss]) continue;
			vis[pos.ff][pos.ss] = true;
			
			//printf("Position:(%d, %d) k:%d\n", pos.ff, pos.ss, k);
			
			if (pos == p2) {
				printf("%d\n", k);
				return 0;
			}
			
			nearWall = false;
			
			for (pair<int,int> op : moves) {
				if (!vis[pos.ff + op.ff][pos.ss + op.ss])	que3.push({pos.ff + op.ff, pos.ss + op.ss});
				
				if (!path[pos.ff + op.ff][pos.ss + op.ss])	nearWall = true;
			}
			
			if (nearWall) {
				int (&a)[4] = port[pos.ff][pos.ss];
				//printf("I can teleport\n");
				//printf("Down to i:%d | Up to i:%d | Right to j:%d | Left to j:%d\n", a[0], a[1], a[2], a[3]);
				
				if (!vis[a[0]][pos.ss])	que2.push({a[0], pos.ss}); // góra   +x
				if (!vis[a[1]][pos.ss])	que2.push({a[1], pos.ss}); // dół    -x
				if (!vis[pos.ff][a[2]])	que2.push({pos.ff, a[2]}); // prawo  +y
				if (!vis[pos.ff][a[3]])	que2.push({pos.ff, a[3]}); // lewo   -y
			}
			
			//printTab(pos.ff, pos.ss);
			
			while (!que3.empty()) {
				que2.push(que3.front());
				que3.pop();
			}
		}
		
		swap(que1, que2);
		k++;
	}	
	
	return 0;
}