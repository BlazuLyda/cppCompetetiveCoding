#include <bits/stdc++.h>

using namespace std;

int z;
long long n, m, sum;

int main() {
	scanf("%d", &z);
	
	long long a;
	
	while (z--) {
		scanf("%lld", &n);
		sum = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a);
			sum += a;
		}
		
		if (sum % 2) {
			printf("NIE\n");
			continue;
		}
		
		sum /= 2LL;
		m = n - sum;
		
		printf("%s\n", (sum > 0 && sum <= n) ? "TAK" : "NIE");
	}
	
	return 0;
}
