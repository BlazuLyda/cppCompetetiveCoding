#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d;

vector<long long> primes = {2};
bitset<40000> nums;
set<long long> s;
queue<long long> que;

void findPrimes()
{
	for (int i = 3; i < 32000; i += 2)
	{
		if(!nums[i])
		{
			primes.push_back(i);
			
			for (int j = i * 3; j < 32000; j += 2 * i)
			{
				nums[j] = 1;
			}
		}
	}
}

int main()
{
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	
	if(a > b)
		swap(a, b);
	
	findPrimes();
	
	long long P = c * d, p, num;
	
	p = P;
	
	s.insert(1);
	
	if(P <= b)
	{
		printf("TAK\n");
		return 0;
	}
	
	for (auto i : primes)
	{
		while(p % i == 0)
		{	
			p /= i;
			
			for (auto j : s)
			{
				num = i*j;
				
				if((min(num, P / num) <= a) && (max(num, P / num) <= b))
				{
					printf("TAK\n");
					return 0;
				}
				
				que.push(num);
			}
			
			while(!que.empty())
			{
				s.insert(que.front());
				que.pop();
			}			
		}
		
		if(p == 1)
			break;
	}
	
	printf("NIE\n");
	
	return 0;
}