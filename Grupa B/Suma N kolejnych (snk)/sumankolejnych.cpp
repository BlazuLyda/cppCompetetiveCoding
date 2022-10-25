#include <bits/stdc++.h>

using namespace std;

const long long mod = 1009;
long long n, wyn;

int main()
{
	scanf("%lld", &n);
	
	if(n % 2 == 0)
	{
		wyn = (((n/2ll) % mod) * ((n+1ll) % mod)) % mod;
	}
	else
	{
		wyn = ((n % mod) * (((n+1ll)/2ll) % mod)) % mod;
	}
	
	printf("%lld", wyn);
	
	return 0;
}