#include <bits/stdc++.h>

using namespace std;

vector<long long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

struct frac
{
	long long a, b;
	
	long double dec()
	{
		long double res = (long double)a / (long double)b;
		
		return res;
	}
	
	void reduce()
	{
		for (auto i : primes)
		{	
			if((a % i == 0) && (b % i == 0))
			{
				a /= i;
				b /= i;
			}
		}
	}
};

frac operator+(frac f1, frac f2)
{
	frac res;
	
	if(f1.b == f2.b)
	{
		res.a = f1.a + f2.a;
		res.b = f1.b;
	}
	else
	{
		res.a = f1.a * f2.b + f2.a * f1.b;
		res.b = f1.b * f2.b;
	}
	
	return res;
}

frac operator*(frac f1, frac f2)
{
	frac res;
	
	res.a = f1.a * f2.a;
	res.b = f1.b * f2.b;
	
	return res;
}

frac bigger(frac f1, frac f2)
{
	frac res;
	
	res.a = max(f1.a, f2.a);
	res.b = max(f1.a + f2.a, 1LL);
	
	return res;
}

int main()
{
	frac dice1[6], dice2[6], sum = {.a = 0, .b = 1};
	
	frac pom, pom1, add;
	
	pom.a = 0; pom.b = 100;
	pom1.a = 1; pom1.b = 2;
	
	for (int i = 0; i < 6; i++)
	{
		scanf("%lld", &pom.a);
		
		dice1[i] = pom;
	}
	
	for (int i = 0; i < 6; i++)
	{
		scanf("%lld", &pom.a);
		
		dice2[i] = pom;
	}
	
	for (int i = 0; i < 6; i++)
	{
		add = (dice1[i] + dice2[i]) * bigger(dice1[i], dice2[i]) * pom1;
		
		sum = sum + add;
		
		sum.reduce();
		
		//printf("%d... add:%Lf sum:%Lf\n", i, add.dec(), sum.dec());
	}
	
	printf("%.12Lf\n", sum.dec());
	
	return 0;
}