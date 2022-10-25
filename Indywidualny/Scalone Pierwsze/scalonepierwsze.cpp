#include <bits/stdc++.h>

using namespace std;

long long ConnNum(long long a, long long b)
{
	long long b2 = b;
	
	while(b2)
	{
		a *= 10LL;
		b2 /= 10LL;
	}
	
	a += b;
	
	return a;
}

vector<long long> primes = {2};
vector<long long> cprimes;

bool CheckPrime(long long num)
{
	for (long long i : primes)
	{
		if(i*i > num)
			break;
			
		if((long long)(num%i) == 0)
			return 0;
	}
	
	return 1;	
}

int main()
{
	long long num = 3;
	
	while(num < 40000LL)
	{
		if(CheckPrime(num))
			primes.push_back(num);	
			
		num += 2LL;
	}
	
	long long con;
	
	for (int i = 0; i < (int)primes.size(); i+=2)
	{
		con = ConnNum(primes[i], primes[i+1]);
		
		if(CheckPrime(con))
			cprimes.push_back(con);
	}
	
	printf("\n\nsize: %d\n\n", (int)cprimes.size());
	
	printf("cprimes[150] = {");
	
	for (int i = 0; i < 150; i++)
	{
		printf("%lld, ", cprimes[i]);
	}
	
	
	return 0;
}