#include <bits/stdc++.h>

using namespace std;

long long x, y;

int main()
{
	scanf("%lld %lld", &x, &y);
	
	int wyn = 0;
	
	while(x <= y)
	{
		++wyn;
		x <<= 1;
	}
	
	printf("%d\n", wyn);
	
	return 0;
}