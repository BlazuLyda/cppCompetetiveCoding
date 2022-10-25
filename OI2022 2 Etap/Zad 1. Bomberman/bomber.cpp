#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct Point {
	int x, y;
};
struct Far{
	int upp, dow, lef, rig;
};

bool operator<(pair<int, Point> a, pair<int, Point> b) {
	return a.ff < b.ff;
}

int n;
Point P, K;
int tab[1024][1024];
Far rock[1024][1024];
int odl[1024][1024][2]; // [x][y][0] - odl od P, [x][y][1] - odl od K
int vis[1024][1024];
vector<Point> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> names = {'G', 'D', 'L', 'P'};

// szukanie miejsca na bombę
int ly[1024], lx;

queue<Point> que1, que2;
int t, v;

void bfs(Point s, int z) {
	Point p;
	t = 0;
	v++;
	que1.push(s);
	
	while (true) {
		if (que1.empty()) {
			if (que2.empty()) break;
			
			t++;
			swap(que1, que2);
		}
		
		p = que1.front();
		que1.pop();
		
		// printf("I am in (%d, %d)\n", p.x, p.y);
		
		if (vis[p.x][p.y] == v) continue;
		vis[p.x][p.y] = v;
		odl[p.x][p.y][z] = t;
		
		if (tab[p.x][p.y] == 1) {
			// droga
			// printf("Walking from (%d, %d)\n", p.x, p.y);
			for (Point mv : moves) {
				if (tab[p.x + mv.x][p.y + mv.y] && vis[p.x + mv.x][p.y + mv.y] != v) {
					// printf("\tGoing to (%d, %d)\n", p.x+mv.x, p.y+mv.y);
					que2.push({p.x + mv.x, p.y + mv.y});
				}
			}
		}
	}
}


// Struktura danych
int pushx, pushy[1024];
set<pair<int, int>> pos[1024][2][2]; 
// pair <wartość, idx>
// [0][][] - set w x, [1][][]:[1000][][] - sety w y
// [][0][] - zwiększająca się, [][1][] - zmniejszająca się
// [][][0] - odległość od P, [][][1] - odległość od K

// ta funkcja symuluję przesunięcie środka o 1 jednostkę
void pushRig(int x, int z, int val, int dis, int idx, int push) {
	// zrzucam z prawego seta przestarzały element na lewy
	pos[x][1][z].erase({val + dis, idx});
	pos[x][0][z].insert({val - push, idx});
}

// zwrócenie idx najmniejszej wartości z prawego i lewego seta
pair<int, int> findSmal(int x, int z) {
	int idxl = pos[x][0][z].empty() ? -1 : pos[x][0][z].begin()->ss;
	int idxr = pos[x][1][z].empty() ? -1 : pos[x][1][z].begin()->ss;
	
	return {idxl, idxr};	
}


// backtrack
vector<char> backtrack(Point A, int where) {
	int licz = odl[A.x][A.y][where];
	vector<char> route;
	route.reserve(licz);
	
	while (licz) {
		for (int k = 0; k < 4; k++) {
			if (odl[A.x + moves[k].x][A.y + moves[k].y][where] < licz) {
				A.x += moves[k].x;
				A.y += moves[k].y;
				licz--;
				route.push_back(k);
			}
		}
	}
	
	return route;
}


//~ // debug
//~ void printOdl(int z) {
	//~ for (int i = 1; i <= n; i++) {
		//~ for (int j = 1; j <= n; j++) {
			//~ if (i == P.x && j == P.y) printf("P ");
			//~ else if (i == K.x && j == K.y) printf("K ");
			//~ else printf("%d ", tab[i][j] ? odl[i][j][z] : -1);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
//~ }

//~ void printTab() {
	//~ for (int i = 1; i <= n; i++) {
		//~ for (int j = 1; j <= n; j++) {
			//~ printf("%d ", tab[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
//~ }


int main() {
	scanf("%d", &n);

	char s[1024], c;
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		
		for (int j = 1; j <= n; j++) {
			c = s[j-1];
			
			if (c != 'X') {
				if (c == '#') {
					tab[i][j] = 2;
				} else {
					if (c == 'P')		P = {i, j};
					else if (c == 'K') 	K = {i, j};
					tab[i][j] = 1;
				}
			}
		}
	}
	
	// ustawianie odl na max
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			odl[i][j][0] = 1100100;
			odl[i][j][1] = 1100100;
		}
	}
	
	// preprocessing
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			rock[i][j].lef = tab[i][j] && tab[i][j-1] ? rock[i][j-1].lef + 1 : 0;
			rock[i][j].upp = tab[i][j] && tab[i-1][j] ? rock[i-1][j].upp + 1 : 0;
		}
	}
	
	for (int i = n; i > 0; i--) {
		for (int j = n; j > 0; j--) {
			rock[i][j].rig = tab[i][j] && tab[i][j+1] ? rock[i][j+1].rig + 1 : 0;
			rock[i][j].dow = tab[i][j] && tab[i+1][j] ? rock[i+1][j].dow + 1 : 0;
		}
	}
	
	// bfs od P i K
	bfs(P, 0);
	bfs(K, 1);
	
	//printOdl(0);
	//printOdl(1);
	
	
	// szukanie miejsca na bombę
	int mini = 1100100;
	Point wP = {-1, -1}, wK = {-2, -2}, S = {-3, -3}; // ostateczna ścieżka będzie wyglądała tak: P -> wP -> S -> wK -> K
	
	// zmienne pomocnicze
	pair<int, Point> toP[4], toK[4];
	pair<int, int> ret;
	
	// iteruję się po współrzędnych wybuchu bomby
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//printf("cur S : (%d, %d)\n", i, j);
			
			if (!tab[i][j]) {
				//printf("\tIt is a rock, emptying all of the sets\n");
				
				// jeżeli jesteśmy na skale opróżniamy sety
				pos[0][0][0].clear(); // set w x, lewa strona, odl od P
				pos[0][1][0].clear(); // set w x, prawa strona, odl od P
				pos[0][0][1].clear(); // set w x, lewa strona, odl od K
				pos[0][1][1].clear(); // set w x, prawa strona, odl od K
				
				pos[j][0][0].clear(); // set w y, góra, odl od P
				pos[j][1][0].clear(); // set w y, dół, odl od P
				pos[j][0][1].clear(); // set w y, góra, odl od K
				pos[j][1][1].clear(); // set w y, dół, odl od K
				
				lx = 0;
				ly[j] = 0;
				
				continue;
			}
			
			//printf("\tIt isn't a rock\n");
			
			// czy set x jest pusty
			if (lx == 0) {
				//printf("\tFilling set x\n");
				// wypełniam set w x
				pushx = 0;
				lx = 1;
				
				for (int k = 0; tab[i][j+k]; k++) {
					pos[0][1][0].insert({odl[i][j+k][0] + k, j+k}); // set w x, prawa strona, odl od P
					pos[0][1][1].insert({odl[i][j+k][1] + k, j+k}); // set w x, prawa strona, odl od K
				}
			} else {
				pushRig(0, 0, odl[i][j-1][0], rock[i][j-1].lef, j-1, pushx);
				pushRig(0, 1, odl[i][j-1][1], rock[i][j-1].lef, j-1, pushx);
				pushx++;
			}
			
			// czy set y jest pusty	
			if (ly[j] == 0) {
				//printf("\tFilling set y\n");
				// wypełniam set w y
				pushy[j] = 0;
				ly[j] = 1;
				
				for (int k = 0; tab[i+k][j]; k++) {
					pos[j][1][0].insert({odl[i+k][j][0] + k, i+k}); // set w y, prawa strona, odl od P
					pos[j][1][1].insert({odl[i+k][j][1] + k, i+k}); // set w y, prawa strona, odl od K
				}
			} else {
				pushRig(j, 0, odl[i-1][j][0], rock[i-1][j].upp, i-1, pushy[j]);
				pushRig(j, 1, odl[i-1][j][1], rock[i-1][j].upp, i-1, pushy[j]);
				pushy[j]++;
			}
			
			// szukanie najmniejszych i najlepszego sparowania ścieżki od P ze ścieżką od K
			//printf("\tLooking for smalest pair\n");
			
			ret = findSmal(0, 0);
			toP[0] = {ret.ff == -1 ? 1100100 : abs(j - ret.ff) + odl[i][ret.ff][0], {i, ret.ff}}; // odległość lewa, prawa do P
			toP[1] = {ret.ss == -1 ? 1100100 : abs(j - ret.ss) + odl[i][ret.ss][0], {i, ret.ss}};
			
			ret = findSmal(j, 0);
			toP[2] = {ret.ff == -1 ? 1100100 : abs(i - ret.ff) + odl[ret.ff][j][0], {ret.ff, j}}; // odległość góra, dół do P
			toP[3] = {ret.ss == -1 ? 1100100 : abs(i - ret.ss) + odl[ret.ss][j][0], {ret.ss, j}};
			
			ret = findSmal(0, 1);
			toK[0] = {ret.ff == -1 ? 1100100 : abs(j - ret.ff) + odl[i][ret.ff][1], {i, ret.ff}}; // odległość lewa, prawa do K
			toK[1] = {ret.ss == -1 ? 1100100 : abs(j - ret.ss) + odl[i][ret.ss][1], {i, ret.ss}};
			
			ret = findSmal(j, 1);
			toK[2] = {ret.ff == -1 ? 1100100 : abs(i - ret.ff) + odl[ret.ff][j][1], {ret.ff, j}}; // odległość góra, dół do K
			toK[3] = {ret.ss == -1 ? 1100100 : abs(i - ret.ss) + odl[ret.ss][j][1], {ret.ss, j}};
			
			sort(toP, toP + 4);
			sort(toK, toK + 4);
			
			//printf("\t\tSmalest pair is: (%d, %d) and (%d, %d), dis:%d\n", toP[0].ss.x, toP[0].ss.y, toK[0].ss.x, toK[0].ss.y, toP[0].ff + toK[0].ff);
			
			if (toP[0].ff + toK[0].ff < mini) {
				mini = toP[0].ff + toK[0].ff;
				wP = toP[0].ss;
				wK = toK[0].ss;
				S = {i, j};
			}
		}
		
		// opróżnianie setu x na koniec linijki
		lx = 0;
		pos[0][0][0].clear(); // set w x, lewa strona, odl od P
		pos[0][1][0].clear(); // set w x, prawa strona, odl od P
		pos[0][0][1].clear(); // set w x, lewa strona, odl od K
		pos[0][1][1].clear(); // set w x, prawa strona, odl od K
	}
	
	// debug
	//~ printf("P : (%d, %d)\n", P.x, P.y);
	//~ printf("wP : (%d, %d)\n", wP.x, wP.y);
	//~ printf("S : (%d, %d)\n", S.x, S.y);
	//~ printf("wK : (%d, %d)\n", wK.x, wK.y);
	//~ printf("K : (%d, %d)\n", K.x, K.y);
	
	// jeżeli się nie da
	if (mini >= 1000100 && odl[P.x][P.y][1] >= 1000100) {
		printf("NIE\n");
		return 0;
	}
	
	// jeżleli ustawienie bomby nie polepsza wyniku
	vector<char> route;
	
	if (mini >= odl[P.x][P.y][1]) {
		printf("%d\n", odl[P.x][P.y][1]);
		printf("%d %d\n", K.x, K.y);
		
		route = backtrack(P, 1);
		for (auto i : route) printf("%c", names[i]);
		printf("\n");
		
		return 0;
	}
	
	// backtrack z przejściem przez miejsce wybuchu
	// ścieżka: P -> wP -> S -> wK -> K
	
	printf("%d\n", mini);
	printf("%d %d\n", S.x, S.y);
	
	// wP -> P
	route = backtrack(wP, 0);
	for (int i = route.size() - 1; i >= 0; i--) printf("%c", names[route[i] ^ 1]);
	
	// wP -> S
	if (wP.x == S.x) {
		if (wP.y < S.y) {
			for (int i = 0; i < S.y - wP.y; i++) printf("P");
		} else {
			for (int i = 0; i < wP.y - S.y; i++) printf("L");
		}
	} else {
		if (wP.x < S.x) {
			for (int i = 0; i < S.x - wP.x; i++) printf("D");
		} else {
			for (int i = 0; i < wP.x - S.x; i++) printf("G");
		}
	}
	
	// S -> wK
	if (wK.x == S.x) {
		if (wK.y < S.y) {
			for (int i = 0; i < S.y - wK.y; i++) printf("L");
		} else {
			for (int i = 0; i < wK.y - S.y; i++) printf("P");
		}
	} else {
		if (wK.x < S.x) {
			for (int i = 0; i < S.x - wK.x; i++) printf("G");
		} else {
			for (int i = 0; i < wK.x - S.x; i++) printf("D");
		}
	}
	
	// wK -> K
	route = backtrack(wK, 1);
	for (auto i : route) printf("%c", names[i]);
	printf("\n");
	
	return 0;
}
