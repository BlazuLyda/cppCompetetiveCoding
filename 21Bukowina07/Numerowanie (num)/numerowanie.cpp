#include <bits/stdc++.h>

using namespace std;

const long long M = 1000000007;

long long n;
vector<int> graph[200200];
long long silnia[200200], invSilnia[200200], DP[200200], siz[200200], comb[200200], res[200200];

long long modInv(long long a) {
	long long res = 1;
	long long pot = 1000000005;
	
	while (pot) {
		if (pot & 1) res = (res * a) % M;
		a = (a * a) % M;
		pot >>= 1;
	}
	
	return res;
}

void DFS1(int w, int o) {
	comb[w] = 1;
	
	for (auto i : graph[w]) {
		if (i == o) continue;
		DFS1(i, w);
		siz[w] += siz[i] + 1;
		comb[w] = (comb[w] * ((comb[i] * silnia[ siz[i] ]) % M) ) % M;
		comb[w] = (comb[w] * invSilnia[ siz[i] + 1 ]) % M;
	}
	
	//printf("%d siz:%lld comb:%lld res:%lld\n", w, siz[w], comb[w], (comb[w] * silnia[siz[w]])%M );
}

void DFS2(int w, int o) {
	long long lastComb, lastSiz;
	lastComb = comb[o]; lastSiz = siz[o];
	
	comb[o] = (comb[o] * modInv((comb[w] * silnia[ siz[w] ]) % M) ) % M;
	comb[o] = (comb[o] * silnia[ siz[w] + 1 ]) % M;
	siz[o] -= siz[w] + 1;
	
	comb[w] = (comb[w] * ((comb[o] * silnia[ siz[o] ]) % M) ) % M;
	comb[w] = (comb[w] * invSilnia[ siz[o] + 1]) % M;
	siz[w] += siz[o] + 1;
	
	res[w] = (comb[w] * silnia[ siz[w] ]) % M; //wzór na wynik dla wierzchołka
	
	for (auto i : graph[w]) {
		if(i != o) DFS2(i, w);
	}
	
	comb[o] = lastComb; siz[o] = lastSiz;
}

int main() {
	scanf("%lld", &n);
	
	silnia[0] = 1;
	invSilnia[0] = 1;
	
	for (long long i = 1; i <= (long long)n; ++i) {
		silnia[i] = (silnia[i-1] * i) % M;
		invSilnia[i] = (invSilnia[i-1] * modInv(i)) % M;
	}
	
	int a, b;
	
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	DFS1(1, 0);
	
	res[1] = (comb[1] * silnia[ siz[1] ]) % M;
	
	for (auto i : graph[1])
		DFS2(i, 1);
	
	for (int i = 1; i <= n; i++)
		printf("%lld\n", res[i]);
	
	return 0;
}
