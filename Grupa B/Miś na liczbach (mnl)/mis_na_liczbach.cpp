#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

const long long inf = 1000000000000000000;

long long n, m;

long long fpowm(long long a, long long p, long long m)
{	
	long long res = 1;
	
	while(p)
	{
		if(p&1)
			res = (res * a) % m;
			
		a = (a * a) % m;
		p >>= 1;
	}
	
	return res;
}

long long fpow(long long a, long long p)
{
	long long res = 1;
	
	while(p)
	{
		if(p&1)
			res = res * a;
			
		a = a * a;
		p >>= 1;
	}
	
	return res;
}

pair<long long, long long> max2pot(long long a)
{
	long long result = 0;
	
	while(a%2==0)
	{
		++result;
		a >>= 1;
	}
	
	return make_pair(result, a);
}

long long euler(long long a)
{
	long long result = 1;
	
	pair<long long, long long> p = max2pot(a);
	
	a = p.ss;
	
	if(p.ff)
		result = fpow(2, p.ff-1);
	
	for (long long i = 3; i <= sqrt(a); i+=2)
	{
		if(a % i == 0)
		{
			result *= i-1;
			a /= i;
			
			while(a % i == 0)
			{
				result *= i;
				a /= i;
			}
		}	
	}
	
	if(a > 1)
	{
		result *= a-1;
	}
	
	return result;
}

int main()
{
	long long n, m, k;
	pair<long long, long long> mroz, kroz;
	
	scanf("%lld %lld", &n, &m);
	
	mroz = max2pot(m);
	
	k = euler(mroz.ss);
	
	kroz = max2pot(k);
	
	long long pot = fpowm(2, n - min(n, kroz.ff), kroz.ss) * fpow(2, min(n, kroz.ff));
	
	long long res = fpowm(2, pot - min(pot, mroz.ff), mroz.ss) * fpow(2, min(pot, mroz.ff));
	
	printf("%lld\n", res);
	
	return 0;
}