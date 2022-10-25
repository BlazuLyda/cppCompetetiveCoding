#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> pcount;
bitset<200200> notPrime;


int main() {
	scanf("%d %d", &n, &m);
	
	int cnt, jp;
	
	for (int i = 2; i <= m; i++) {
		if (notPrime[i]) continue;
		
		for (int j = i; j <= m; j += i) {
			notPrime[j] = true;
			
			jp = j;
			cnt = 0;
			while (!(jp % i)) {
				jp /= i;
				cnt++;
			}
			
			pcount[j].push_back(cnt);
		}
	}
	
	unsigned long long cur;
	
	for (int i = 1; i <= m; i++) {
		cur = 1;
		
		
	}
	
	
	return 0;
}
