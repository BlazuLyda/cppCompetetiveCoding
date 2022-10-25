#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007LLU
#define modr 129032259LLU
#define P 31LLU

using namespace std;

int n, q;
array<vector<pair<int, int>>, 500100> dcp;
array<char, 500100> s;
array<unsigned long long, 500100> hsh;
array<unsigned long long, 500100> p;


void sieve() {
	int num, pow;
	
	for (int i = 2; i <= n; i++) {
		if (dcp[i].empty()) {
			for (int j = i; j <= n; j += i) {
				pow = 0;
				num = j;
				
				while (!(num % i)) {
					num /= i;
					pow++;
				}
				
				dcp[j].push_back({i, pow});
			}
		}
	}
}


int check(const int a, int b, const int d, const int pot) {
	int ret = 1;
	int len = (b - a + 1);
	int r = len / d;
	unsigned long long wzor, cur;
	bool ok = true;
	
	for (int k = 0; k < pot; k++) {
		wzor = hsh[a + r - 1] - hsh[a - 1] + mod;
		if (wzor >= mod) wzor -= mod;
		
		//printf("a:%d b:%d r:%d wzor:%llu \n", a, b, r, wzor);
		
		for (int i = a + r; i <= b; i += r) {
			wzor = (wzor * p[r]) % mod;
			cur = hsh[i + r - 1] - hsh[i - 1] + mod;
			if (cur >= mod) cur -= mod;
			
			//printf("\ti:%d hsh:%llu wzor:%llu\n", i, cur, wzor);
			
			if (wzor != cur) {
				ok = false;
				break;
			}
		}
		
		if (ok)  {
			ret *= d;
			r /= d;
			b = a + (b - a + 1) / d - 1;
		}
		else break;
	}
	
	//printf("divides by:%d\n", ret);
	return ret;
}

int main() {
	scanf("%d", &n);
	sieve();
	scanf("%s", &s[1]);
	
	unsigned long long pmul = 1;
	for (int i = 1; i <= n; i++) {
		hsh[i] = (hsh[i-1] + (pmul * (s[i] - 'a'))) % mod;
		pmul = (pmul * P) % mod;
	}
	
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (p[i-1] * P) % mod;
	}
	
	scanf("%d", &q);
	
	int a, b, l;
	int div;
	
	while (q--) {
		scanf("%d %d", &a, &b);
		
		l = (b - a + 1);
		div = 1;
		
		//printf("|... a=%d b=%d ...|\n", a, b);
		
		for (auto p : dcp[l]) {
			//printf("Checking p=%d pot=%d:\n", p.ff, p.ss);
			div *= check(a, b, p.ff, p.ss);
			//printf("Now div is:%d\n", div);
		}
		
		printf("%d\n", l / div);
	}
	
	return 0;
}
