#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
int tab[100100], same[100100];
long long wyn = 1, wild;
int cert[100100];
int used[100100];

long long rozw() {
		// Ostatni parzysty i nieparzysty
		int l1, l2;
		l1 = n - !(n % 2);
		l2 = n - (n % 2);

		// Szukanie pewnych pozycji dla nieparzystych
		cert[0] = 1;
		cert[n+1] = 1;
		int last = 0;
		
		for (int i = 1; i <= l1; i += 2) {
			used[tab[i]] = 1;
			same[tab[i]]++;
			
			if (last == tab[i]) {
				if (same[tab[i]] > 2) return 0;
				
				cert[i-1]++;
			} else if (same[tab[i]] > 1) {
				return 0;
			} else if (cert[i-1]) {
				if (cert[i+1]) return 0;
				
				cert[i+1]++;
			}

			last = tab[i];
		}
		
		if (l1 == n) {
			if (cert[n+1] == 2) return 0;
			
			for (int i = l1; i >= 1; i -= 2) {
				if (cert[i+1]) cert[i-1]++;
			}
		}

		// Szukanie pewnych pozycji dla parzystych
		last = 0;

		for (int i = l2; i >= 2; i -= 2) {
			if (used[tab[i]] == 1) return 0;
			
			used[tab[i]] = 2;
			same[tab[i]]++;

			if (last == tab[i]) {
				if (same[tab[i]] > 2) return 0;
				
				cert[i+1]++;	
			} else if (same[tab[i]] > 1) {
				return 0;
			} else if (cert[i+1]) {
				if (cert[i-1]) return 0;
				
				cert[i-1]++;
			}

			last = tab[i];
		}
		
		// Liczenie wildcardów
		for (int i = 1; i <= n; i++) wild += !used[i];

		// Liczenie wyniku
		long long fre = 0;
		
		for (int i = 1; i <= l1; i += 2) {
			if (cert[i]) {
				if (fre) {
					wyn = (wyn * (fre * wild % mod)) % mod;
					wild--;
				}
				fre = 0;
			} else {
				fre++;
			}
		}
		
		if (fre) {
			wyn = (wyn * (fre * wild % mod)) % mod;
			wild--;
		}
		
		fre = 0;
		
		for (int i = 2; i <= l2; i += 2) {
			if (cert[i]) {
				if (fre) {
					wyn = (wyn * (fre * wild % mod)) % mod;
					if (wyn >= mod) wyn -= mod;
					wild--;
				}
				fre = 0;
			} else {
				fre++;
			}
		}
		
		if (fre) {
			wyn = (wyn * (fre * wild % mod)) % mod;
			wild--;
		}

		// Wyspisywanie wyniku
		return wyn;
}

int main() {
    // Wczytywanie
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &tab[i]);

    // Wyspisywanie wyniku
    long long wypisz = rozw();
    
    printf("%lld\n", wypisz);

    return 0;
}