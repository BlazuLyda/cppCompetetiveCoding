#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d, p;

long long fpow(long long num, long long pot)
{	
	long long res = 1;
	
	while(pot)
	{
		if(pot & 1ll)
			res = (res * num) % p;
			
		num = (num * num) % p;
		pot >>= 1ll;
	}
	
	return res;
}


int main()
{
	scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &p);
	
	long long upp, dwn, res;
	
	while((a % p == 0ll || b % p == 0ll) && (c % p == 0ll || d % p == 0ll))
	{
		if(a % p == 0ll)
			a /= p;
		else
			b /= p;
			
		if(c % p == 0ll)
			c /= p;
		else
			d /= p;
	}
	
	upp = ((a%p) * (b%p)) % p;
	dwn = ((c%p) * (d%p)) % p;
	
	res = (upp * fpow(dwn, p-2ll)) % p;
	
	printf("%lld\n", res);
	
	return 0;
}