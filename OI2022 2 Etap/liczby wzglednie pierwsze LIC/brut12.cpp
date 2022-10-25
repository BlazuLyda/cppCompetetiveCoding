#include <bits/stdc++.h>
#define bond 10000000

using namespace std;

long long n, k; 
int c;
vector<int> dis[10000111];
vector<int> odp;

int main() {
	scanf("%lld %lld %d", &n, &k, &c);
	
	// rozklad n
	long long npom = n;
	
	if (!(npom%2)) {
		dis[2].push_back(2);
		
		while (!(npom%2)) npom >>= 1;
	}
	
	for (int i = 3; i*i <= npom; i += 2) {
		if (!(npom%i)) {
			dis[i].push_back(i);
		
			while (!(npom%i)) npom /= i;
		}
	}
	
	if (npom > 1) {
		dis[npom].push_back(npom);
	}
	
	// sito erostatenesa
	odp.reserve(c);
	k--;
	int idx = 2;
	
	while (idx < bond && k > 1) {
		//printf("idx:%d\n", idx);
		
		if (dis[idx].empty()) {
			k--;
			//printf("\twzglednie pierwsza, k:%lld\n", k);
		} else {
			for (auto d : dis[idx]) {
				if (idx + d < bond) {
					dis[idx + d].push_back(d);
				}
			}
		}
		
		idx++;
	}
	
	while (idx < bond && c) {
		//printf("idx:%d\n", idx);
		
		if (dis[idx].empty()) {
			c--;
			odp.push_back(idx);
			//printf("\twzglednie pierwsza, c:%d\n", c);
		} else {
			for (auto d : dis[idx]) {
				if (idx + d < bond) {
					dis[idx + d].push_back(d);
				}
			}
		}
		
		idx++;
	}
	
	for (auto i : odp) {
		printf("%d ", i);
	}
	printf("\n");
	
	return 0;
}
