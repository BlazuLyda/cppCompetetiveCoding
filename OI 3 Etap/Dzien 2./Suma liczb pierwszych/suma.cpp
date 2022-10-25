//autor rozwiazania : Błażej Łytkowski

#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1000000100> sieve;
queue<long long> que;

void SieveOfAtkin(long long limit) //zaczerpnięte z: https://www.geeksforgeeks.org/sieve-of-atkin/
{ 
	long long n;
	
	sieve[2] = 1;
	sieve[3] = 1;
	
    /* Mark siev[n] is true if one of the following is true:
    a) n = (4*x*x)+(y*y) has odd number of 
       solutions, i.e., there exist
       odd number of distinct pairs (x, y) 
       that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
    b) n = (3*x*x)+(y*y) has odd number of 
       solutions and n % 12 = 7
    c) n = (3*x*x)-(y*y) has odd number of 
       solutions, x > y and n % 12 = 11 */
       
    for (long long x = 1; x * x < limit; ++x) 
    {
        for (long long y = 1; y * y < limit; ++y) 
        { 
            // Main part of Sieve of Atkin
            n = (4ll * x * x) + (y * y);
            
            if (n <= limit && (n % 12ll == 1ll || n % 12ll == 5ll))
                sieve.flip(n);
  
            n = (3ll * x * x) + (y * y);
            
            if (n <= limit && n % 12ll == 7ll)
                sieve.flip(n);
  
            n = (3ll * x * x) - (y * y);
            
            if (x > y && n <= limit && n % 12ll == 11)
                sieve.flip(n);
        }
    }
  
    // Mark all multiples of squares as non-prime
    for (long long r = 5; r * r < limit; ++r) 
    {
        if (sieve[r])
        {
            for (long long i = r * r; i < limit; i += r * r)
                sieve[i] = 0;
        }
    }
}

int main()
{
	scanf("%lld", &n);
	
	if(n < 2 || n == 4)
	{
		printf("NIE\n");
		return 0;
	}
	
	SieveOfAtkin(n);
	
	if(sieve[n])
	{
		printf("%lld %lld\n", n, n);
		return 0;
	}
	
	/*
	for (long long i = 0; i <= n; i++)
	{
		if(sieve[i])
			printf("%lld ", i);
	}
	printf("\n");
	*/
	
	//gąsienica
	long long sum = 5;
	long long k = 3;
	que.push(2);
	que.push(3);
	
	while(k <= n)
	{
		if(sum == n)
		{
			printf("%lld %lld\n", que.front(), k);
			return 0;
		}
		
		k += 2ll; //wyszukiwanie kolejnej liczby pierwszej
		
		while(!sieve[k] && k <= n)
		{
			k += 2ll;
		}
		
		que.push(k);
		sum += k;
		
		while(sum > n && !que.empty())
		{
			sum -= que.front();
			
			que.pop();
		}
		
		if(que.size() < 2)
		{
			printf("NIE\n");
			return 0;
		}
	}	
	
	return 0;
}