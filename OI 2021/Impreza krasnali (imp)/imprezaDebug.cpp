#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
int tab[100100], same[100100];
long long wyn = 1, wild;
int cert[100100];
int used[100100];

int main() {
    // Wczytywanie
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &tab[i]);

    // Ostatni parzysty i nieparzysty
    int l1, l2;
    l1 = n - !(n % 2);
    l2 = n - (n % 2);
    
    printf("l1:%d l2:%d\n", l1, l2);

    // Szukanie pewnych pozycji dla nieparzystych
    cert[0] = 1;
    cert[n+1] = 1;
    int last = 0;
    
    for (int i = 1; i <= l1; i += 2) {
        used[tab[i]] = 1;
        same[tab[i]]++;
        
		if (last == tab[i]) {
			if (same[tab[i]] > 2) {
				printf("0 (too many %d)\n", tab[i]);
				return 0;
			}
			cert[i-1]++;
		} else if (same[tab[i]] > 1) {
			printf("0 (bad position %d)\n", tab[i]);
			return 0;
		} else if (cert[i-1]) {
			if (cert[i+1]) {
				printf("0 (no place for %d)\n", tab[i]);
				return 0;
			}
			cert[i+1]++;
		}

        last = tab[i];
    }
    
    if (l1 == n) {
		if (cert[n+1] == 2) {
			printf("0 (out of bonds)\n");
			return 0;
		}
		
		for (int i = l1; i >= 1; i -= 2) {
			if (cert[i+1]) cert[i-1]++;
		}
	}

    // Szukanie pewnych pozycji dla parzystych
    last = 0;

    for (int i = l2; i >= 2; i -= 2) {
        if (used[tab[i]] == 1) {
			printf("0 (odd and even at the same time %d)\n", tab[i]);
            return 0;
        }
        used[tab[i]] = 2;
        same[tab[i]]++;

		if (last == tab[i]) {
			if (same[tab[i]] > 2) {
				printf("0 (too many %d)\n", tab[i]);
				return 0;
			}
			cert[i+1]++;	
		} else if (same[tab[i]] > 1) {
			printf("0 (bad position %d)\n", tab[i]);
			return 0;
		} else if (cert[i+1]) {
			if (cert[i-1]) {
				printf("0 (no place for %d)\n", tab[i]);
				return 0;
			}
			cert[i-1]++;
		}

        last = tab[i];
    }
    
    for (int i = 1; i <= n; i++) printf("%d ", (int)tab[i]);
	printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", (int)cert[i]);
	printf("\n");

    // Liczenie wildcardów
    for (int i = 1; i <= n; i++) wild += !used[i];
    
    printf("Wildcards: %lld\n", wild);

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
		
		printf("i: %d wyn: %llu\n", i, wyn);
	}
	
	if (fre) {
		wyn = (wyn * (fre * wild % mod)) % mod;
		wild--;
	}
	printf("Odd finished wyn: %llu\n", wyn);
	
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
		printf("i: %d wyn: %llu\n", i, wyn);
	}
	
	if (fre) {
		wyn = (wyn * (fre * wild % mod)) % mod;
		wild--;
	}

    // Wyspisywanie wyniku
    printf("%lld\n", wyn);

    return 0;
}