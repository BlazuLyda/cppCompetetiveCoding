#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m, q;
vector<int> conns[100100];
int val[100100];
int col[100100];
bool oddCycle = false;

multiset<pair<int, bool>> nums;
multiset<int> difs;

void dfs(int w, int o, int c) {
	col[w] = c;
	
	for (auto i : conns[w]) {
		if (i != o) {
			if (col[i] == -1) dfs(i, w, c^1);
			else if (col[i] == c) oddCycle = true;
		}
	}
}

void printSets() {
	printf("nums:\n");
	for (auto i : nums) printf("(%d, %d), ", i.ff, i.ss);
	printf("\ndifs:\n");
	for (auto i : difs) printf("%d, ", i);
	printf("\n\n");
}


int main() {
	scanf("%d %d", &n, &m);
	
	int a, b, c;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		val[i] = a;
		col[i] = -1;
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	dfs(1, 0, 0);
	
	scanf("%d", &q);
	
	// Graf niedwudzielny
	if (oddCycle) {
		while (q--) {
			scanf("%d %d %d", &a, &b, &c);
			if (a) printf("0\n");
		}
		return 0;
	}
	
	// Graf dwudzielny
	//
	// Tworzenie setów
	for (int i = 1; i <= n; i++) {
		nums.insert({val[i], col[i]});
	}
	
	auto it = nums.begin();
	pair<int, bool> last = *it;
	
	for (; it != nums.end(); it++) {
		if (last.ss ^ it->ss) difs.insert(it->ff - last.ff);
		last = *it;
	}
	
	
	// Zapytania
	set<pair<int, bool>>::iterator pre, nex;
	
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		if (a) {
			if (col[b] == col[c]) {
				printf("0\n");
			} else {
				printf("%d\n", *difs.begin());
			}
		} else {
			// usuwanie starej wartości
			it = nums.find({val[b], col[b]});
			pre = prev(it);
			nex = next(it);
			
			if (it != nums.begin() && pre->ss ^ col[b]) {
				difs.erase(difs.find(val[b] - pre->ff));
			}
			
			if (it != prev(nums.end()) && nex->ss ^ col[b]) {
				difs.erase(difs.find(nex->ff - val[b]));
			}
			
			if (it != nums.begin() && it != prev(nums.end()) && pre->ss ^ nex->ss) {
				difs.insert(nex->ff - pre->ff);
			}
			
			nums.erase(it);
			val[b] = c;
			
			// wstawianie nowej wartości
			it = nums.insert({c, col[b]});
			pre = prev(it);
			nex = next(it);
			
			if (it != nums.begin() && pre->ss ^ col[b]) {
				difs.insert(val[b] - pre->ff);
			}
			
			if (it != prev(nums.end()) && nex->ss ^ col[b]) {
				difs.insert(nex->ff - val[b]);
			}
			
			if (it != nums.begin() && it != prev(nums.end()) && pre->ss ^ nex->ss) {
				difs.erase(difs.find(nex->ff - pre->ff));
			}
		}
	}
	
		
	return 0;
}
