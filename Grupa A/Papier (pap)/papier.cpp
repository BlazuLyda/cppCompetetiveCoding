#include <bits/stdc++.h>
#define ff first
#define ss second
#define ull unsigned long long

using namespace std;

	
ull hsh(ull a, ull b, ull c) {
	ull h = (a + b * 751 + c * 64001);
	return h;
}

int n;
vector<ull> used;
ull tab[550];
int ile[550];

int main() {
	scanf("%d", &n);
	
	used.reserve(n*n*n);
	
	for (int i = 1; i <= n; i++) scanf("%llu", &tab[i]);
	
	for (int i = 1; i <= n - 2; i++) {
		ile[tab[i]]++;
		
		for (int j = i+1; j <= n - 1; j++) {
			ile[tab[j]]++;
			
			for (int k = j+1; k <= n; k++) {
				ile[tab[k]]++;
				
				//printf("(%llu, %llu, %llu)\n", tab[i], tab[j], tab[k]);
				//printf("\t1:%d 2:%d 3:%d 4:%d\n", ile[1], ile[2], ile[3], ile[4]);
				
				if (ile[tab[i]] + ile[tab[j]] + ile[tab[k]] == 3) {
					//printf("---> push (%llu, %llu, %llu)\n", tab[i], tab[j], tab[k]);
					used.push_back(hsh(tab[i], tab[j], tab[k]));
				}
			}
			
			for (int k = j+1; k <= n; k++) ile[tab[k]]--;
		}
		
		for (int j = i+1; j <= n - 1; j++) ile[tab[j]]--;
		
		ile[tab[i]]--;
	}
	
	ull wyn = unique(used.begin(), used.end()) - used.begin();
	
	printf("%lld", wyn);
	
	return 0;
}
