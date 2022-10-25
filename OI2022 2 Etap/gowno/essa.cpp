#include <bits/stdc++.h>

using namespace std;

int n;

int t = 3;
int rep[1000100];
int ile[2];

int main() {
	scanf("%d", &n);
	
	int a; char c;
	rep[1] = 0;
	rep[2] = 1;
	
	for (int i = 0; i < n; i++) {
		scanf(" %c %d", &c, &a);
		
		if (c == '?') {
			printf("%d\n", ile[rep[a]^1]);
		} else {
			rep[t] = rep[a];
			ile[rep[a]]++;
			
			
			
			t++;
		}
	}
	
	
	return 0;
}
