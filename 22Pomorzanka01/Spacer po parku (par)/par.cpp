#include <bits/stdc++.h>

using namespace std;

int n;
char A[100100], B[100100];
long long wyn;

int main() {
	scanf("%d", &n);
	
	scanf("%s", A);
	scanf("%s", B);	
	
	
	// zwykłe liczenie
	bool full = true;
	long long licz = 0;
	long long pcount = 0;
	A[n] = A[0];
	B[n] = B[0];
	bool p, q;
	
	for (int i = 0; i < n; i++) {
		p = A[i] - '0';
		q = B[i] - '0';
		
		if (p) {
			if (q) {
				wyn += licz;
				licz++;
				pcount++;
			}
		} else {
			full = false;
			if (q) {
				licz = 1;
				pcount++;
			}
		}
		
		//printf("i:%d licz:%lld wyn:%lld\n", i+1, licz, wyn);
	}
	
	for (int i = 0; i < n; i++) {
		p = A[i] - '0';
		q = B[i] - '0';
		
		if (p) {
			if (q) {
				wyn += licz;
			}
		} else {
			break;
		}
		
		//printf("i:%d licz:%lld wyn:%lld\n", i+1, licz, wyn);
	}
	
	if (full) wyn = pcount * (pcount - 1LL);
	wyn += (long long) full;
	
	printf("%lld\n", wyn);
	
	return 0;
}