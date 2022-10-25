#include <bits/stdc++.h>

using namespace std;

int random(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	int seed = atoi(argv[1]) + 3;
	seed *= seed;
	srand(seed);
	
	int n = 10;
	int m = 9 + 10;
	
	printf("%d %d\n", n, m);
	
	int z = n - 1;
	int w = m - z;
	int q = 2;
	
	for (int i = 0; i < m; i++) {
		if ((z && random(0, 1)) || !w) {
			z--;
			printf("Z %d %d\n", q, random(1, q-1));
			q++;
		} else {
			w--;
			printf("W %d\n", random(1, n));
		}
	}
	
	return 0;
}