#include <bits/stdc++.h>

using namespace std;

int n;
int ones;
char lett[4] = {'a', 'c', 'g', 'o'};
int quan[4];

int main() {
	scanf("%d", &n);
	
	char c;
	
	for (int i = 0; i < n; i++) {
		cin >> c;
		printf("i:%d c:%c\n", i, c);
		if (c == '1') ones++;
	}
	
	//~ ones -= 3 * n;
	
	//~ if (ones < 0 || ones > 3*n) {
		//~ printf("NIE\n");
		//~ return 0;
	//~ }
	
	//~ quan[3] = ones / 3;
	//~ ones %= 3;
	
	//~ if (ones == 2) quan[2]++;
	//~ else if (ones == 1) quan[1]++;
	
	//~ quan[0] = n - quan[1] - quan[2] - quan[3];
	
	//~ for (int i = 0; i < quan[0]; i++) printf("a");
	//~ for (int i = 0; i < quan[1]; i++) printf("c");
	//~ for (int i = 0; i < quan[2]; i++) printf("g");
	//~ for (int i = 0; i < quan[3]; i++) printf("o");
	
	return 0;
}
