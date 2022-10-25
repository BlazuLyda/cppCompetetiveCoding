#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;
vector<int> conns[500500];

int dmax, far;
long long cnt;

// case 1
void dfs1(int w, int o, int d) {
	if (d > dmax) {
		dmax = d;
		cnt = 1;
		far = w;
	} else if (d == dmax) {
		cnt++;
	}
	
	for (auto i : conns[w]) {
		if (i != o) dfs(i, w, d+1);
	}
}

pair<int, long long> case1() {
	long long p, q;
	
	dfs1(1, 0, 0);
	q = cnt;
	
	dmax = 0; cnt = 0;
	dfs1(far, 0, 0);
	p = cnt;
	
	return {dmax, p * q};
}

// case 2
bitset<500500> vis;
vector<int> cir;
vector<pair<int, long long>> leg;
int r; // długość cyklu

bool dfs2a(int w, int o) {
	if (vis[w]) return true;
	vis[w] = true;
	
	bool ret = false;
	
	for (auto i : conns[w]) {
		if (i != o) {
			if (dfs2(i, w)) {
				cir.push_back(i);
				ret = true;
			}
		}
	}
	
	return ret;
}

int s1, s2;

void dfs2b(int w, int o, int d) {
	if (d > dmax) {
		dmax = d;
		cnt = 1;
		far = w;
	} else if (d == dmax) {
		cnt++;
	}
	
	for (auto i : conns[w]) {
		if (i != o && i != s1 && i != s2) dfs2b(i, w, d+1);
	}
}

pair<int, long long> case2() {
	int ms = 0; long long combs = 0;
	
	// znajdowanie cyklu
	dfs2a(1, 0);
	r = cir.size();
	leg.resize(r+1);
	cir.push_back(cir[0]);
	cir.push_back(cir[1]);

	
	// liczenie długości i liczności odnóg
	int A;
	long long p, q;
	
	for (int i = 1; i <= r; i++) {
		s1 = cir[i-1];
		s2 = cir[i+1];
		
		dfs2b(cir[i], 0, 0);
		leg[i] = {dmax, cnt};
		q = cnt;
	
		dmax = 0; cnt = 0;
		dfs2b(far, 0, 0);
		p = cnt;
	
		if (dmax > ms) {
			ms = dmax;
			combs = p * q;
		} else if (dmax == ms) {
			combs += p * q;
		}
	}
	
	
	// liczenie długości dróg na około
	int mo = 0; long long combo = 0; 
	
	int licz = 0, int ogr = (r + 1) / 2;
	deque<pair<int, pair<int, long long>>> que;
	int dcur;
	int pom;
	
	// 1. okrążenie
	for (int i = 1; i <= r; i++) {
		if (leg[i].ff == 0) leg[i].ss = 1;
		
		while (!que.empty() && i - que.front().ff >= r) {
			que.pop_front();
		}
		
		if (!que.empty()) {
			pom = leg[i].ff + que.front().ss.ff + licz;
			
			if (pom > mo) {
				mo = pom;
				combo = leg[i].ss * que.front().ff.ss;
			} else {
				combo += leg[i].ss * que.front().ff.ss;
			}
		}
		
		dcur = leg[i].ff - licz;
		
		while (!que.empty() && que.front().ss.ff < dcur) {
			que.pop_front();
		}
		
		if (!que.empty() && que.front().ss.ff == dcur) {
			que.front().ss.ss += leg[i].ss;
		}
		
		licz++;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	pair<int, long long> wyn;
	
	if (m == n) wyn = case2();
	else wyn = case1;
	
	printf("%d\n", wyn.ff);
	printf("%lld\n", wyn.ss);
	
	return 0;
}
