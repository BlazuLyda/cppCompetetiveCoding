#include <bits/stdc++.h>
#define m 1000000000000000ULL

using namespace std;

struct num {
	unsigned long long x, y; // num = x * m, y
	
	void print() {
		if (x) printf("%llu%llu", x, y);
		else printf("%llu", y);
	}
};

int n;
char s[30];

num operator- (num a, num b) {
	if (a.y >= b.y) return {a.x - b.x, a.y - b.y};
	return {a.x - b.x - 1, a.y + m - b.y};
}

bool operator> (num a, num b) {
	if (a.x == b.x) return a.y > b.y;
	return a.x > b.x;
}

num operator* (num a, unsigned long long b) {
	a.y *= b;
	a.x *= b;
	a.x += a.y / m;
	a.y %= m;
	return a;
}

num operator- (num a, unsigned long long b) {
	if (a.y >= b) return {a.x, a.y - b};
	return {a.x - 1, a.y + m - b};
}

num parseString() {
	num a = {0, 1};
	bitset<30> used;
	int c;
	unsigned long long mul = n, pcount;
	
	for (int i = 0; i < n; i++) {
		c = s[i] - 'a';
		pcount = 0;
		
		for (int j = n-1; j > c; j--) {
			pcount += !used[j];
		}
		
		used[c] = 1;
		a = a * mul;
		a = a - pcount;
		mul--;
	}
	
	return a;
}

int main() {
	scanf("%d", &n);
	
	scanf("%s", s);
	num a = parseString();
	
	scanf("%s", s);
	num b = parseString();
	
	num res = a > b ? a - b : b - a;
	res.print();
	
	return 0;
}
