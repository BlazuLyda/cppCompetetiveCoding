#include <bits/stdc++.h>
#define inf 1000000
#define ff first
#define ss second

using namespace std;

int n;
vector<int> conns[100100];

pair<int, int> dfs(int w, int o, int k) {
	vector<int> q;
	q.reserve(conns[w].size() - 1);
	
	for (auto i : conns[w]) {
		if (i != o) {
			q.push_back(dfs(i, w, k).ff);
			if (q.back() == -1) {
				//printf("Failed in %d from son %d\n", w, i);
				return {-1, 0};
			}
		}
	}
	
	// matching
	sort(q.begin(), q.end());
	int big = 0;
	
	//~ printf("\tResult from sons of %d:\n\t\t", w);
	//~ for (auto i : q) {
		//~ if (i < k) printf("%d, ", i);
		//~ else printf("inf, ");
	//~ }
	//~ printf("\n");
	
	for (int i = q.size() - 1; i >= 0; i--) {
		if (q[i] < k) break;
		big++;
		q.pop_back();
	}
	
	int l = 0, r = q.size() - 1;
	
	for (; l < r; l++) {
		if (q[l] + q[r] < k) {
			if (big == 0) return {-1, 0};
			big--;
		}
		else r--;
	}
	
	if (l == r) {
		if (big == 0) return {q[r] + 1, 0};
		if (big == 1) return {q[r] + 1, 1};
		return {inf, 1};
	}
	if (big) return {inf, 1};
	return {1, 0};
}

int main() {
	scanf("%d", &n);
	
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	int p = 1, k = n-1, s;
	pair<int, int> wyn;
	
	while (p < k) {
		s = (p+k+1) >> 1;
		//printf("Checking length of path:%d\n", s);
		
		wyn = dfs(1, 0, s);
		
		if (wyn.ff > s || wyn.ff == 1 || wyn.ss) p = s;
		else k = s-1;
	}
	
	printf("%d\n", p);
	
	return 0;
}
