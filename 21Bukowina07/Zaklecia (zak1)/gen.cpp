#include <bits/stdc++.h>

using namespace std;

int random(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	int seed = atoi(argv[1]);
	seed *= seed;
	srand(seed);
	
	int T = 40;
	string s;
	int n;
	
	cout << T << "\n";
	
	while (T--) {
		n = random(10, 30);
		s = "";
		
		while (n--) {
			s += (char) random((int)'a', (int)'d');
		}
		
		cout << s << "\n";
	}
	
	return 0;
}
