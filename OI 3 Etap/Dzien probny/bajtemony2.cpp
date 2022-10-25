#include <bits/stdc++.h>

using namespace std;

long long a, b, num1, num2, wyn1, wyn2;
int n;

long long NWD(long long x, long long y)
{
	if(x < y)
		swap(x, y);
		
	while(y != 0)
	{	
		x %= y;
		swap(x, y);
	}
	
	return x;
}

int main()
{
	scanf("%d", &n);
	
	scanf("%lld %lld", &a, &b);
	
	for (int i = 1; i < n; i++)
	{
		scanf("%lld %lld", &num1, &num2);
		
		wyn1 = max(NWD(num1, a), NWD(num1, b));
		wyn2 = max(NWD(num2, a), NWD(num2, b));
		
		a = wyn1;
		b = wyn2;
	}
	
	printf("%lld\n", max(a, b));
	
	return 0;
}