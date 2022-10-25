#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007LL

using namespace std;

long long fpow(long long a, int p) {
	long long ret = 1;
	while (p) {
		if (p & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return ret;
}

int n, k;
vector<pair<int, int>> inp;
int pref[1000];

int main() {
	scanf("%d %d", &n, &k);
	
	inp.resize(n);
	
	for (int i = 0; i < n; i++) scanf("%d %d", &inp[i].ff, &inp[i].ss);
	
	int q, s;
	long long wyn = 0;
	
	for (int p = 1; p < (1<<n); p++) {
		
		for (int i = 0; i < n; i++) {
			if (p & (1<<i)) {
				pref[inp[i].ff]++;
				pref[inp[i].ss]--;
			}
		}
		
		q = 0;
		s = 0;
		
		//printf("arrr: ");
		for (int i = 1; i <= 2*n; i++) {
			if (!s && (s + pref[i])) q++;
			s += pref[i];
			//printf("%d ", s);
			pref[i] = 0;
		}
		//printf("\n");
		
		wyn += fpow(q, k);
	}
	
	printf("%lld\n", wyn);
	
	return 0;
}
