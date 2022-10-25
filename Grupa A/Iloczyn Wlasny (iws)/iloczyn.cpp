#include <bits/stdc++.h>

using namespace std;

int tab[100001];

int iloczyn(int a) {
	int b = a;
	while (a) {
		b *= a%10;
		a /=10;
	}
	return b;
}

int main()
{
	for (int i = 1; i <= 100000; i++) {
		tab[max(0, min(100000,iloczyn(i)))]++;
	}
	
	for (int i = 1; i < 100000; i++) {
		printf("%d ", tab[i]);
	}
	
	return 0;
}
