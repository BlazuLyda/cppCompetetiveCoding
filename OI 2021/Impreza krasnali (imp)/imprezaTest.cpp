#include <bits/stdc++.h>
#define mod 1000000007LL

using namespace std;

int n;
int tab[100100], same[100100];
long long wyn, wild;
int cert[100100];
int used[100100];
char s[100100];
char ch;
char boutString[20];
long long bout, wout;

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
				if (same[tab[i]] > 2) {
					return 0;
				}
				cert[i-1]++;
			} else if (same[tab[i]] > 1) {
				return 0;
			} else if (cert[i-1]) {
				if (cert[i+1]) {
					return 0;
				}
				cert[i+1]++;
			}

			last = tab[i];
		}
		
		if (l1 == n) {
			if (cert[n+1] == 2) {
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
				return 0;
			}
			used[tab[i]] = 2;
			same[tab[i]]++;

			if (last == tab[i]) {
				if (same[tab[i]] > 2) {
					return 0;
				}
				cert[i+1]++;	
			} else if (same[tab[i]] > 1) {
				return 0;
			} else if (cert[i+1]) {
				if (cert[i-1]) {
					return 0;
				}
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
	ifstream file;
	file.open("./out8");
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for (int q = 1; q <= 17650827; q++) {
		printf("%d\n", q);
		
		// Wczytywanie
		file >> s;
		file >> boutString;
		
		n = 0;
		wyn = 1;
		wild = 0;
		
		// Decoding
		for (int i = 0; s[i]; i++) {
			n++;
			ch = s[i];
			tab[n] = atoi((const char*)&ch);
		}
		
		fill(same, same+n+1, 0);
		fill(cert, cert+n+1, 0);
		fill(used, used+n+1, 0);
		
		bout = atoi(boutString);
		wout = rozw();
		
		if (wout != bout) {
			printf("WRONG ANSWER!\n");
			printf("wout: %lld\n", wout);
			printf("bout: %lld\n", bout);
			break;
		}
	}
	
	file.close();
	printf("------BEGIN MESSAGE------\n");
	printf("Everything perfectly good\n");
	printf("------END MESSAGE--------\n");

    return 0;
}