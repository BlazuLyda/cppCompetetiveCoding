#include <bits/stdc++.h>

using namespace std;

int main() {
	int wyn = 0;
	
	for (int i = 1; i <= 600; i++) {
		for (int j = 1; j <= 600; j++) {
			wyn += i/2 + j/2;
		}
	}
	
	printf("%d", wyn);
}