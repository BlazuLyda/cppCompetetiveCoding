//autor rozwiazania : Błażej Łytkowski

#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1000000100> sieve; //tylko liczby nieparzyste bitset[a] <--> a*2+1
queue<long long> que;

void SieveOfAtkin(long long limit) //zaczerpnięte z: https://www.geeksforgeeks.org/sieve-of-atkin/
{ 
	long long n;
	
	sieve[1] = 1;
	
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
                sieve.flip(n/2);
  
            n = (3ll * x * x) + (y * y);
            
            if (n <= limit && n % 12ll == 7ll)
                sieve.flip(n/2);
  
            n = (3ll * x * x) - (y * y);
            
            if (x > y && n <= limit && n % 12ll == 11)
                sieve.flip(n/2);
        }
    }
  
    // Mark all multiples of squares as non-prime
    for (long long r = 5; r * r < limit; r += 2ll) 
    {
        if (sieve[r/2])
        {
            for (long long i = r * r; i < limit; i += 2ll * r * r)
                sieve[i/2] = 0;
        }
    }
}

int main()
{
	scanf("%lld", &n);
	
	long long half = n / 2ll;
	
	if(n < 2 || n == 4)
	{
		printf("NIE\n");
		return 0;
	}
	
	long long d;
	
	if(n % 2ll == 0)
		d = 2;
	else
		d = 3;
	
	SieveOfAtkin(min(n/d + 10000ll, n));
	
	if(sieve[half])
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
	long long k = 1, kp;
	que.push(2);
	que.push(3);
	
	bool p = 1;
	
	while(k <= half)
	{
		if(sum == n)
		{
			printf("%lld %lld\n", que.front(), k*2ll+1ll);
			return 0;
		}
		
		++k; //wyszukiwanie kolejnej liczby pierwszej
		
		while(!sieve[k] && k <= half)
		{
			++k;
		}
		
		kp = k * 2ll + 1ll;
		
		que.push(kp);
		sum += kp;
		
		if(n % kp == 0ll)
			p = 0;
		
		while(sum > n && !que.empty())
		{
			sum -= que.front();
			
			que.pop();
		}
		
		if(que.size() < 2)
		{
			if(p)
				printf("%lld %lld\n", n, n);
			else
				printf("NIE\n");
				
			return 0;
		}
	}	
	
	return 0;
}