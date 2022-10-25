#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int q;
vector<pair<long long, int>> nums;
bool odp[100100];

long long func(long long num)
{
	long long res = 0;
	
	while(num)
	{
		res += num%10LL;
		num /= 10LL;
	}
	
	return res;
}

long long gfunc(long long num)
{
	long long res = func(num);
	
	res *= res;
	
	return res + num;
}

int main()
{
	scanf("%d", &q);
	
	long long b;
	
	for (int i = 0; i < q; ++i)
	{
		scanf("%lld", &b);
		
		nums.push_back({b, i});
	}
	
	sort(nums.begin(), nums.end());
	
	long long a = 1;
	
	for (auto i : nums)
	{
		b = i.ff;
		
		while(a < b)
			a = gfunc(a);
		
		if(a == b)
			odp[i.ss] = 1;
	}
	
	for (int i = 0; i < q; ++i)
	{
		if(odp[i])
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	
	
	
	
	return 0;
}