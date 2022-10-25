#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct bond {
	int x, y[2];
};

bool cmp(bond a, bond b) {
	return a.x < b.x;
}

int n, res = 0;
vector<bond> bonds;
int cords[200200];
vector<pair<int, pair<int, int>>> scale; // y-value, idx, y[]

const int R = 131072;
int tree[R*2];

void update(int w, int p, int k, int x, int y, int v) {
	if (w==1) printf("\tUpdate... x:%d y:%d\n", x, y);
	if (k < x || y < p) return;
	if (x <= p && k <= y) { tree[w] += v; return; }
	
	int mid = (p+k)>>1;
	update((w<<1), p, mid, x, y, v);
	update((w<<1)+1, mid+1, k, x, y, v);	
}

int query(int w) {
	int ret = 0;
	while (w) {
		ret += tree[w];
		w >>= 1;
	}
	return ret;
}

int main() {
	// wczytywanie
	scanf("%d", &n);
	
	int k;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
	
		for (int j = 0; j < k; j++) {
			scanf("%d", &cords[j]);
		}
		
		for (int j = 2; j < k; j += 2) {	
			scale.push_back({cords[j-1], {bonds.size(), 0}});
			scale.push_back({cords[j+1], {bonds.size(), 1}});
			bonds.push_back({cords[j]});
		}
		scale.push_back({cords[k-1], {bonds.size(), 0}});
		scale.push_back({cords[1], {bonds.size(), 1}});
		bonds.push_back({cords[0]});
	}
	
	// skalowanie
	sort(scale.begin(), scale.end());
	int last = -1, num = 0;
	
	for (auto i : scale) {
		if (i.ff != last) {
			num++;
			last = i.ff;
		}
		bonds[i.ss.ff].y[i.ss.ss] = num;
	}
	
	// zamiatanie
	sort(bonds.begin(), bonds.end(), cmp);
	
	bool op;
	for (auto i : bonds) {
		op = i.y[0] > i.y[1]; // czy krawędz otwierajaca
		
		if (op) {
			printf("Opening... x:%d y0:%d y1:%d\n", i.x, i.y[0], i.y[1]);
			res = max(res, query(i.y[0] + R) + 1);
			update(1, 0, R-1, i.y[1], i.y[0], 1);
		} else {
			printf("Closing... x:%d y0:%d y1:%d\n", i.x, i.y[0], i.y[1]);
			update(1, 0, R-1, i.y[0], i.y[1], -1);
		}
	}
	
	// wynik
	printf("%d", res);
	
	return 0;
}