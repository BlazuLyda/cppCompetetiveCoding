#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

struct val {
	long long v;
	int idx;
};

bool cmp(val a, val b) {
	return a.v < b.v;
}

int n;
vector<val> ryby;
bitset<500500> odp;

int main() {
	scanf("%d", &n);
	ryby.resize(n);
	
	long long a, suma = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		
		suma += a;
		ryby[i] = {a, i};
	}
	
	sort(ryby.begin(), ryby.end(), cmp);
	
	
	// Długość ciągu najmniejszych ryb
	int q = 0;
	
	while (q + 1 < n && ryby[q+1].v == ryby[0].v) q++;
	
	// Algorytm
	long long mini = 0;
	int p;

	for (p = n-1; p > q; p--) {
		if (suma < mini) break;
		
		odp[ryby[p].idx] = true;
		suma -= ryby[p].v;
		mini = max(ryby[p].v + 1LL, mini - ryby[p].v);
	}
	
	// Wypisz odpowiedź
	for (int i = 0; i < n; i++) {
		printf("%c", odp[i] ? 'T' : 'N');
	}
	
	return 0;
}
