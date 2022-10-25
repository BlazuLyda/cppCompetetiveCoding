#include <bits/stdc++.h>

using namespace std;

long long n;

vector<int> num;

int main()
{
	scanf("%lld", &n);
	
	while(n)
	{
		num.push_back(n % 5);
		n /= 5;
	}
	
	for (int i = (int)num.size()-1; i >= 0; --i)
	{
		printf("%d", num[i]*2);
	}
	
	
	return 0;
}