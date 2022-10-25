#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
long long m, p, h;
long long plecak[100100], pom[100100];
long long items[26];
long long res;

void insert() {
	fill(pom, pom+m, 0);
	
	for (auto i : items) {
		//printf("item: %lld\n", i);
		for (int j = i; j < m; j++) { // bez przeskoku
			pom[j] += plecak[j-i];
		}
		for (int j = 0; j < i; j++) { // z przeskokiem
			pom[j] += plecak[j-i+m];
		}
	}
	
	//printf("\n------------------\n");
	
	for (int i = 0; i < m; i++) {
		if (pom[i] >= mod) pom[i] %= mod;
		//if (pom[i]) printf("%d: %lld\n", i, pom[i]);
	}
	
	swap(plecak, pom);
}

int main() {
	scanf("%d %lld %lld %lld", &n, &m, &p, &h);
	
	long long cp = 1, num;
	
	plecak[0] = 1;
	
	for (int i = 0; i < n; i++) {
		num = 0;
		
		for (long long j = 0; j <= 25; j++) {
			num += cp;
			if (num >= m) num -= m;
			
			items[j] = num;
		}
		
		insert();
		
		cp = (cp * p) % m;
	}
	
	printf("%lld\n", plecak[h]);
	
	return 0;
}
