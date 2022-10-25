#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct val {
	int len, spec;
};

int t, n;
vector<val> tab;

bool cmp(val a, val b) {
	return a.len > b.len;
}

int main() {
	scanf("%d", &t);
	
	char c;
	int las, len, z, wyn;
	bool q;
	
	while (t--) {
		scanf("%d", &n);
		tab.clear();
		q = 0;
		
		scanf(" %c", &c);
		
		if (c == '0') q = 1;
		las = c - '0';
		len = (c == '0');
		
		for (int i = 1; i < n; i++) {
			scanf(" %c", &c);
			
			if (c == '0') {
				len++;
				las = 0;
			} else {
				if (las == 0) {
					tab.push_back({len, 0});
					len = 0;
				}
				las = 1;
			}
		}
		
		if (las == 0) tab.push_back({len * 2, 1});
		
		if (q) {
			if (tab[0].spec) {
				printf("0\n");
				continue;
			}
			
			tab[0].len *= 2;
			tab[0].spec = 1;
		}
		
		sort(tab.begin(), tab.end(), cmp);
		
		// Algorytm zachłanny
		z = 0;
		wyn = 0;
		
		for (auto i : tab) {
			i.len -= 2*z;
			
			if (i.len <= 0) break;
			
			if (i.spec) {
				wyn += i.len / 2;
				z++;
			} else if (i.len == 2 || i.len == 1) {
				wyn += 1;
				z++;
			} else {
				wyn += i.len - 1;
				z += 2;
			}
		}
		
		printf("%d\n", n - wyn);
	}
	
	return 0;
}
