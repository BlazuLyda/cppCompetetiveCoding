#include <bits/stdc++.h>

using namespace std;

int main() {
	
	for (int i = 1; i <= 3; i++) {
		for (int ii = 1; ii <= 3; ii++) {
			for (int iii = 1; iii <= 3; iii++) {
				for (int iiii = 1; iiii <= 3; iiii++) {
					
					if ((i + iiii != 3) && (ii + iii != 3)) {
						continue;
					}
					
					if ((i + ii != 3) && (iii + iiii != 3)) {
						continue;
					}
					
					printf("%c%c%c%c\n", i+'A'-1, ii+'A'-1, iii+'A'-1, iiii+'A'-1);
				}
			}
		}
	}
	
	return 0;
}
