#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
char s[8008];
long long lasPref[8008], curPref[8008];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	
	lasPref[1] = 1;
	
	int idx = 0;
	
	while (s[idx]) {
		if (s[idx] == '<') {
			// zbieram prefixy
			for (int i = 1; i <= idx+2; i++) {
				curPref[i] = curPref[i-1] + lasPref[i-1];
				
				if (curPref[i] >= mod) curPref[i] -= mod;
			}
		} else {
			// zbieram sufixy
			for (int i = 1; i <= idx+2; i++) {
				curPref[i] = curPref[i-1] + (lasPref[idx+1] - lasPref[i-1]) + mod;
				
				if (curPref[i] >= mod) curPref[i] -= mod;
				if (curPref[i] >= mod) curPref[i] -= mod;
			}
		}
		
		swap(lasPref, curPref);
		idx++;
	}
	
	printf("%lld", lasPref[n]);
	
	return 0;
}
