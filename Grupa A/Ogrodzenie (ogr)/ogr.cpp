#include <bits/stdc++.h>

using namespace std;

struct Field {
	int x[2], y[2];
	
	long long size() {
		return (long long)(((long long)x[1] - (long long)x[0]) * ((long long)y[1] - (long long)y[0]));
	}
	
	bool in(int p, int q) {
		return (x[0] <= p && p <= x[1] && y[0] <= q && q <= y[1]);  
	}
};

int n, a, b;
int s = 1;
vector<int> conns[100100];
vector<Field> fields;
long long smal, big;

void DFS(int w, int x, int y, int d) {
	//printf("w : %d\n", w);
	
	if (conns[w].size() == 0) {
		conns[w].push_back(s);
		conns[w].push_back(s+1);
		
		int xo[2] = {fields[w].x[0], fields[w].x[1]};
		int yo[2] = {fields[w].y[0], fields[w].y[1]};
		
		if (d == 1) {
			fields[s] = {{xo[0], xo[1]}, {yo[0], y}};
			fields[s+1] = {{xo[0], xo[1]}, {y, yo[1]}};
		} else {
			fields[s] = {{xo[0], x}, {yo[0], yo[1]}};
			fields[s+1] = {{x, xo[1]}, {yo[0], yo[1]}};
		}
		
		
		
		smal = fields[s].size();
		big = fields[s+1].size();
		s += 2;
		if (smal > big) swap(big, smal);
		return;
	}
	
	for (auto i : conns[w]) {
		if (fields[i].in(x, y)) {
			DFS(i, x, y, d);
			return;
		}
	}
}

int main() {
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	
	fields.resize(n+1);
	fields[0] = {{0, a}, {0, b}};
	
	int x, y, d;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &x, &y, &d);
		
		DFS(0, x, y, d);
		
		printf("%lld %lld\n", smal, big);
	}
	
	
	
	return 0;
}
