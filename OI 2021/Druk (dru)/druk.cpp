#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned llu;

int n, m, s;
char tab[1002][1002];
int block[1002][1002];
int let[26];
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
set<int> pot, odp;

// Hashing
llu base = 31;
//llu sym[26] = {1, 31, 961, 29791, 923521, 28629151, 887503681, 27512614111, 852891037441, 26439622160671, 819628286980801, 25408476896404831, 787662783788549761, 5970802223735490975, 627428198704704065, 1003530086136274399, 12662688596514954753, 5161720944063013407, 12439396676277002689, 16686415490396051039, 770046138410136961, 5424686217004694175, 2144576063759554881, 11141625755417546463, 13349005091172011265, 7990788204722213663};
llu pref[1002][1002];
llu row[1002];

bool check(int k, llu pat, char (&patHash)[1002]) {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			
		}
	}

	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	s = n * m;
	
	for (int i = 1; i <= n; i++) {
		scanf(" %s", &tab[i][1]);
	}
	
	// Prefixy hashów i liczenie literek
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			let[tab[i][j] - 'a']++;
			pref[i][j] = pref[i-1][j] * base + (llu)(tab[i][j] - 'a');
		}
	}
	
	// Prefix pierwszego wiersza
	for (int j = 1; j <= m; j++) {
		row[j] = row[j-1] * base + (llu)(tab[1][j] - 'a');
	}
	
	// Najdłuższe bloczki z tych samych liter
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) block[i][j] = tab[i+1][j] == tab[i][j] ? block[i+1][j] + 1 : 1;
	}
	
	// Szukanie dzielników możliwych długości szablonów
	int cnt;
	bool p;
	
	for (int i = 2; i <= 1000; i++) {
		if (!(n % i) || !(m % i)) {
			cnt = s / i;
			p = 1;
			
			for (int j = 0; j < 26; j++) {
				if (let[j] % cnt) {
					p = 0;
					break;
				}
			}
			
			if (p) pot.insert(i);
		}
	}
	
	// Sprwdzanie czy występuje tylko 1 literka
	int l = 0;
	
	for (auto i : let) {
		if (i) l++;
	}
	
	if (l == 1) {
		pot.insert(1);
		printf("%lu\n", pot.size());
		for (auto k : pot) printf("%d ", k);
		return 0;
	}
	
	// Sprawdzanie szablonów
	llu patHash;
	char pat[1002];
	
	for (auto k : pot) {
		// Szablon pionowy
		if (k <= n) {
			patHash = pref[k][1];
			for (int i = 1; i <= k; i++) pat[i] = tab[i][1];
			
			if (check(k, patHash, pat)) {
				odp.insert(k);
				continue;
			}
		}
		
		// Szablon poziomy
		if (k <= m) {
			patHash = row[k];
			for (int j = 1; j <= k; j++) pat[j] = tab[1][j];
			
			if (check(k, patHash, pat)) odp.insert(k);
		}
	}
	
	
	
	return 0;
}
