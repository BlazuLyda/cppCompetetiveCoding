#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007LLU
#define modr 129032259LLU
#define P 31LLU

using namespace std;

int n, q;
array<vector<pair<int, int>>, 500100> dec;
array<char, 1000100> s;
array<set<int>> div;
array<unsigned long long, 500100> mhash;
array<unsigned long long, 500100> p;
array<unsigned long long, 500100> hash;


void sieve() {
	int num, pow;
	
	for (int i = 2; i <= n; i++) {
		if (dec[i].empty()) {
			for (int j = i; j <= n; j += i) {
				pow = 0;
				num = j;
				
				while (!(num % i)) {
					num /= i;
					pow++;
				}
				
				dec[j].push_back({i, pow});
			}
		}
	}
}

void zalg() {
	int s = 1, im, r, l, d;
	unsigned long long hl = 0, hr = 0, chash = 0;

	for (int i = 1; i <= n; i++) {
		im = 2*s - i;
		
		// kopiowanie wartości z i mirrored
		mhash[i] = mhash[im];
		
		for (auto j : div[im]) {
			if (i + j > n) break;
			div[i].insert(j);
		}
		
		// rozszerzanie
		d = *prev(div[i].end());
		r = i + d;
		l = i - d + 1;
		hr = (mhash[i] + ((s[r+1]-'a') * p[d] % mod)) % mod;
		hl = ((s[l-1]-'a') + (mhash[i] * P % mod)) % mod;
		
		while (hl == hr) {
			d++;
			r++;
			l--;
			
			div[i].insert(d);
			mhahs[i] = hr;
			
			hr = (hr + ((s[r+1]-'a') * p[d] % mod)) % mod;
			hl = ((s[l-1]-'a') + (hl * P % mod)) % mod;
		}
		
		// zmiana środka
		if (i + d > s + *prev(div[s].end())) s = i;
	}
}

int check(int a, int b, int d, int pot) {
	
}

array<int, 126> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701};


int main() {
	scanf("%d", &n);
	sieve();
	scanf("%s", &s[1]);
	
	p[0] = 1;
	for (int i = 1; i <= n/2 + 1; i++) p[i] = (p[i-1] * P) % mod;
	
	unsigned long long pmul = 1;
	for (int i = 1; i <= n; i++) {
		hash[i] = (hash[i-1] + (pmul * (s[i] - 'a'))) % mod;
		pmul = (pmul * P) % mod;
	}
	
	s[0] = '#'; s[n+1] = '@';
	zalg();
	
	scanf("%d", &q);
	
	int a, b, l;
	while (q--) {
		scanf("%d %d", &a, &b);
		
		l = (b - a + 1);
		
		for (auto p : dec[l]) {
			for (
			)
		}
	}
	
	return 0;
}
