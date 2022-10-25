#include <bits/stdc++.h>

using namespace std;

int random(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	int seed = atoi(argv[1]);
	seed *= seed;
	srand(seed);
	
	int n = random(5, 10);
	int m = n-1 + random(1, 5);
	
	printf("%d %d\n", n, m);
	
	for (int i = 2; i <= n; i++) {
		printf("%d %d\n", random(1, i-1), i);
	}
	
	int a, b, c;
	
	for (int i = 0; i <= m - n; i++) {
		a = random(1, n);
		
		do {
			b = random(1, n);
		} while (a == b);
		
		printf("%d %d\n", a, b);
	}
	
	int q = 5;
	
	printf("%d\n", q);
	
	for (int i = 0; i < q; i++) {
		a = random(1, n);
		
		do {
			b = random(1, n);
		} while (a == b);
		
		do {
			c = random(1, n);
		} while (a == c || b == c);
		
		printf("2 %d %d %d\n", a, b, c);
	}
	
	return 0;
}
