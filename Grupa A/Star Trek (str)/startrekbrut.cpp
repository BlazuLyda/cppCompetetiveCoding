#include <bits/stdc++.h>
#define mod 1000000007ll

using namespace std;

int n, d;
long long res;
vector<int> conns[100100];

bool dfs1(int w, int o) {
	int mex = 0;
	bool ret;
	
	for (auto i : conns[w]) {
		if (i != o) {
			ret = dfs1(i, w);
			if (!ret) {
				mex = 1;
				break;
			}
		}
	}
	
	return mex;
}

int main() {
	scanf("%d %d", &n, &d);
	
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	if (d == 1) res = dfs1(1, 0);
	
	printf("%lld", res);
	
	return 0;
}
