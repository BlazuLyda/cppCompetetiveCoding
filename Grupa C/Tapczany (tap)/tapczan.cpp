#include <bits/stdc++.h>
#define ff first
#define ss seconds

using namespace std;

struct Obj {
	int c, w, id;
};

int n;
vector<Obj> obj;
vector<int> wyn;

bool cmp (Obj a, Obj b) {
	return a.c < b.c;
}

int main() {
	scanf("%d", &n);
	obj.reserve(n);
	
	int c, w;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &c, &w);
		obj.push_back({c, w, i});
	}
	
	sort(obj.begin(), obj.end(), cmp);
	
	int lw = 0;
	for (auto i : obj) {
		if (lw > i.w) wyn.push_back(i.id);
		lw = max(lw, i.w);
	}
	
	sort(wyn.begin(), wyn.end());
	
	printf("%d\n", (int) wyn.size());
	for (auto i : wyn) {
		printf("%d ", i);
	}
	printf("\n");
	
	return 0;
}